
#include <stdio.h>
#include <stdlib.h>


typedef struct list
{
	int value;
	struct list *next;
} List;

typedef struct
{
	List *first;
	List *last;
} Queue;


void InitQueue(Queue *queue)
{
	queue->first = NULL;
	queue->last = NULL;
}

int IsEmpty(Queue *queue)
{
	if(queue->first == NULL)
		return 1;
	else
		return 0;
}


void Push(Queue *queue, int value)
{
	List *new_node = (List *)malloc(sizeof(List));
	new_node->value = value;
	new_node->next = NULL;
	if(IsEmpty(queue))
	{
		queue->first = new_node;
		queue->last = new_node;
	}
	else
	{
		queue->last->next = new_node;
		queue->last = new_node;
	}
}

int Remove(Queue *queue)
{
	List *time_node = queue->first;
	int value = time_node->value;
	queue->first = queue->first->next;
	free(time_node);
	return value;
}


void PrintQueue(Queue *queue)
{
	List *cur_node = queue->first;
	while(cur_node)
	{
		printf("%d ", cur_node->value);
		cur_node = cur_node->next;
	}
}





int main()
{
	Queue queue;
	InitQueue(&queue);

	for(int i = 0; i < 10; ++i)
		Push(&queue, i);
	PrintQueue(&queue);
	while(!IsEmpty(&queue))
		printf("Remove: %d\n", Remove(&queue));
	return 0;
}
