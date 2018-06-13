
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HASHNUM 101


typedef struct 
{
	int key;
	int value;
} Pair;


typedef struct list_pair
{
	Pair *pair;
	struct list_pair *next;
} ListPair;


typedef struct
{
	ListPair *arr[HASHNUM];
} HashTable;



unsigned char hash(char *arr, int n)
{
	unsigned char control_sum = 0;
	for(int i = 0; i < n; ++i)
		control_sum = (control_sum + arr[i]) % HASHNUM;
	return control_sum;
}



void Init(HashTable *hash_talbe)
{
	for(int i = 0; i < HASHNUM; ++i)
		hash_talbe->arr[i] = NULL;
}


void PrintHashTable(HashTable *hash_table)
{
	for(int i = 0; i < HASHNUM; ++i)
		if(hash_table->arr[i])
		{
			ListPair *cur_node = hash_table->arr[i];
			printf("Hash: %d\n", hash((char *)&hash_table->arr[i]->pair->key, sizeof(int)));
			while(cur_node)
			{
				printf("key = %d value = %d\n", cur_node->pair->key, cur_node->pair->value);
				cur_node = cur_node->next;
			}
		}
}


int IsExist(HashTable *hash_table, int key)
{
	unsigned char index = hash((char *)&key, sizeof(key));
	if(hash_table->arr[index] == NULL)
		return 0;
	else
	{
		ListPair *cur_pair = hash_table->arr[index];
		while(cur_pair)
		{		
			if(cur_pair->pair->key == key)
				return 1;
			cur_pair = cur_pair->next;
		}
	}
	return 0;	
}

void Remove(HashTable *hash_table, int key)
{
	unsigned char index = hash((char *)&key, sizeof(key));
	if(hash_table->arr[index] == NULL)
	{
		printf("Element by %d key doesn't exist!\n", key);
		return;
	}
	else
	{
		ListPair **cur_pair = &hash_table->arr[index];
		if((*cur_pair)->pair->key == key)
		{
			ListPair *time_pair = *cur_pair;
			*cur_pair = (*cur_pair)->next;
			free(time_pair);
		}
		else
		{
			while((*cur_pair)->next)
			{
				if((*cur_pair)->next->pair->key == key)
				{
					ListPair *time_pair = (*cur_pair)->next;
					(*cur_pair)->next = (*cur_pair)->next->next;
					free(time_pair);
				}
			}
			cur_pair = &(*cur_pair)->next;
		}
	}
}

void Add(HashTable *hash_table, int key, int value)
{
	unsigned char index = hash((char *)&key, sizeof(key));
	Pair *pair = (Pair *)malloc(sizeof(Pair)); 
	pair->value = value;
	pair->key = key;
	if(hash_table->arr[index] == NULL)
	{
		hash_table->arr[index] = (ListPair *)malloc(sizeof(ListPair));
		hash_table->arr[index]->pair = pair;
		hash_table->arr[index]->next = NULL;
	}
	else
	{	
		ListPair *cur_pair = hash_table->arr[index];
		while(cur_pair->next)
		{
			if(cur_pair->pair->key == key)
			{
				printf("Key %d already exist!\n", key);
				free(pair);
				return;
			}
			cur_pair = cur_pair->next;
		}
		if(cur_pair->pair->key == key)
		{
			printf("Key %d already exist\n", key);
			free(pair);
			return;
		}
		cur_pair->next = (ListPair *)malloc(sizeof(ListPair));
		cur_pair->next->pair = pair;
		cur_pair->next->next = NULL;
	}
}


int Get(HashTable *hash_table, int key)
{
	unsigned char index = hash((char *)&key, sizeof(key));
	if(IsExist(hash_table, key))
	{
		ListPair *cur_pair = hash_table->arr[index];
		while(cur_pair)
		{
			if(cur_pair->pair->key == key)
				return cur_pair->pair->value;
			cur_pair = cur_pair->next;
		}
	}
}


int main()
{
	HashTable hash_table;
	Init(&hash_table);
	for(int i = 0; i < 200; ++i)
		Add(&hash_table, i, rand() % 1000);

	PrintHashTable(&hash_table);
//	printf("Get: %d\n", Get(&hash_table, 1));
  //    printf("Get: %d\n", Get(&hash_table, 2));
	Remove(&hash_table, 102);
	printf("\n-------\n");
	PrintHashTable(&hash_table);
	return 0;
}
