#include <iostream>
#include "queue.h"
//model number : 38586-A-g.
int main(void)
{
	CQueueList<int> queue;
	for (int i = 0; i < 10; i++)
	{
		queue.push(i + 1);
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", queue.pop());
	}
	return 0;
}