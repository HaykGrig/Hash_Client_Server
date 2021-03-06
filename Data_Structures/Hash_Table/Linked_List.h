#include <stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
struct Linked_List
{
	struct Node *head;
	struct Node *tail;	
	unsigned int size;
};
void LL_Erase(struct Linked_List *obj);
void LL_Init(struct Linked_List *obj);
void LL_Push_Front(struct Linked_List *obj,int val);
void LL_Push_Back(struct Linked_List *obj,int val);
void LL_Pop_Front(struct Linked_List *obj);
int *LL_Front(struct Linked_List* obj);
int *LL_Back(struct Linked_List* obj);
