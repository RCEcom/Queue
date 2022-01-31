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
	//ù��° ��� ���� ����� �ּҸ� ����
	P_NODE pNextNode = m_pFirst->m_pNext;

	//ù��° ����� �����͸� �����Ѵ�.
	T data = m_pFirst->m_Data;

	//ù��° ��� ����
	delete(m_pFirst);

	//�����ص� ù��° ����� ���� ���� m_pFirst���� ��������.
	m_pFirst = pNextNode;
	//����ó��. ���� ù��° ��尡 nullptr�̿��ٸ�, ���� ������ ��带 �����ٴ� �ǹ��̹Ƿ� ���� nullptr�� ����.
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
	//nullptr�� �ɋ�����.(������ ���)
	while (pNode)
	{
		//���� ����� ���� ���� ��� ����
		P_NODE pNextNode = pNode->m_pNext;
		//��� �����
		delete(pNode);
		//���� ���� ����
		pNode = pNextNode;
	}
	m_iCount = 0;
	m_pFirst = nullptr;
	m_pLast = nullptr;
}
