#pragma once
#include <iostream>
#include <assert.h>
#include <cassert>

template<typename T>
struct CQueueNode
{
private:
	template<typename T>
	friend class CQueueList;
public:
	CQueueNode() : m_pNext(nullptr), m_Data() {}
	~CQueueNode(){}
private:
	CQueueNode<T>* m_pNext;
	T m_Data;	
};

template<typename T>
class CQueueList
{
public:
	CQueueList(): m_pFirst(nullptr), m_pLast(nullptr) {}
	~CQueueList()
	{
		clear();
	}
private:
	typedef CQueueNode<T> NODE;
	typedef CQueueNode<T>* P_NODE;
private:
	P_NODE m_pFirst;
	P_NODE m_pLast;
	int m_iCount;
public:
	void push(const T& data);
	bool empty();
	T pop();
	void clear();
};

template<typename T>
inline void CQueueList<T>::push(const T& data)
{
	P_NODE pNewNode = new NODE;
	pNewNode->m_Data = data;
	if (m_pLast != nullptr)
	{
		m_pLast->m_pNext = pNewNode;
	}
	m_pLast = pNewNode;
	if (m_pFirst == nullptr)
	{
		m_pFirst = pNewNode;
	}
	m_iCount++;

}

template<typename T>
inline bool CQueueList<T>::empty()
{
	return m_iCount == 0;
}

template<typename T>
inline T CQueueList<T>::pop()
{
	if (empty())
	{
		assert(false);
	}
	//첫번째 노드 다음 노드의 주소를 저장
	P_NODE pNextNode = m_pFirst->m_pNext;

	//첫번째 노드의 데이터를 저장한다.
	T data = m_pFirst->m_Data;

	//첫번째 노드 지움
	delete(m_pFirst);

	//저장해둔 첫번째 노드의 다음 노드로 m_pFirst노드로 갱신힌다.
	m_pFirst = pNextNode;
	//예외처리. 만약 첫번째 노드가 nullptr이였다면, 가장 마지막 노드를 지웠다는 의미이므로 전부 nullptr로 삽입.
	if (m_pFirst == nullptr)
	{
		m_pLast = nullptr;
	}
	m_iCount--;

	return data;
}

template<typename T>
inline void CQueueList<T>::clear()
{
	P_NODE pNode = m_pFirst;
	//nullptr로 될떄까지.(마지막 노드)
	while (pNode)
	{
		//현재 지우고 싶은 다음 노드 저장
		P_NODE pNextNode = pNode->m_pNext;
		//노드 지운다
		delete(pNode);
		//다음 노드로 갱신
		pNode = pNextNode;
	}
	m_iCount = 0;
	m_pFirst = nullptr;
	m_pLast = nullptr;
}
