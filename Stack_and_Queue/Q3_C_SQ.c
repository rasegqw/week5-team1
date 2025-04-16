//////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 Data Structures
Lab Test: Section C - Stack and Queue Questions
Purpose: Implementing the required functions for Question 3 */

//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//////////////////////////////////   linked list /////////////////////////////////

typedef struct _listnode{
   int item;
   struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
   ListNode *tail;
} LinkedList;

////////////////////////////////// stack //////////////////////////////////////////

typedef struct stack{
	LinkedList ll;
} Stack;

////////////////////////// function prototypes ////////////////////////////////////

// You should not change the prototypes of these functions
int isStackPairwiseConsecutive(Stack *s);

void push(Stack *s, int item);
int pop(Stack *s);
int peek(Stack *s);
int isEmptyStack(Stack *s);

void printList(LinkedList *ll);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);
void removeAllItems(LinkedList *ll);

//////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int c, value;

    Stack s;

    s.ll.head=NULL;
	s.ll.size =0;
	s.ll.tail =NULL;

    c =1;

    printf("1: Insert an integer into the stack:\n");
    printf("2: Check the stack is pairwise consecutive:\n");
    printf("0: Quit:\n");

    while (c != 0)
	{
		printf("Please input your choice(1/2/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Input an integer that you want to insert into the stack: ");
			scanf("%d", &value);
			push(&s, value);
			printf("The stack is: ");
            printList(&(s.ll));
			break;
		case 2:
            if(isStackPairwiseConsecutive(&s))
            {
                printf("The stack is pairwise consecutive.\n");
            }
            else{
                printf("The stack is not pairwise consecutive.\n");
            }
            removeAllItems(&(s.ll));
            break;
		case 0:
			removeAllItems(&(s.ll));
			break;
		default:
			printf("Choice unknown;\n");
			break;
		}
	}

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////

// ListNode
// 	int item;
// 	struct _listnode *next;
 
//  LinkedList
// 	int size;
// 	ListNode *head;
// 	ListNode *tail;
 
//  Stack
// 	 LinkedList ll;


// int isStackPairwiseConsecutive(Stack *s);

// void push(Stack *s, int item);
// int pop(Stack *s);
// int peek(Stack *s);
// int isEmptyStack(Stack *s);

// void printList(LinkedList *ll);
// ListNode * findNode(LinkedList *ll, int index);
// int insertNode(LinkedList *ll, int index, int value);
// int removeNode(LinkedList *ll, int index);
// void removeAllItems(LinkedList *ll);


// case 2:
// if(isStackPairwiseConsecutive(&s))
// {
// 	printf("The stack is pairwise consecutive.\n");
// }
// else{
// 	printf("The stack is not pairwise consecutive.\n");
// }
// removeAllItems(&(s.ll));
// break;


int isStackPairwiseConsecutive(Stack *s)
{
	// if(s->ll.head == NULL)
	// 	return 0;
	
	// LinkedList *new_list = malloc(sizeof(LinkedList));
	// new_list->head = NULL;
	// new_list->tail = NULL;
	// new_list->size = 0;

	
	// for(int i = 0 ; i < s->ll.size ; i++)
	// {
	// 	ListNode *temp = malloc(sizeof(ListNode));
	// 	temp->item = findNode(&(s->ll), i)->item;
	// 	temp->next = NULL;

	// 	if (new_list->head == NULL)
	// 	{
	// 		new_list->head = temp;
	// 		new_list->size++;
	// 	}
	// 	else
	// 	{
	// 		int val = new_list->head->item;

	// 		if (temp->item - 1 == val || temp->item + 1 == val)
	// 		{
	// 			temp->next = new_list->head;
	// 			new_list->head = temp;
	// 			new_list->size++;
	// 		}
	// 		else
	// 		{
	// 			if (new_list->size == 1)
	// 			{
	// 				for (int j = 0; j < new_list->size-1 ; j++)
	// 				{
	// 					ListNode *y = new_list->head;
	// 					new_list->head = new_list->head->next;

	// 					free(y);
	// 				}
	// 				free(new_list->head);				
	// 				free(new_list);
	// 				free(temp);
					
	// 				return 0;
	// 			}
	// 			else
	// 			{
	// 				for (int j = 0; j < new_list->size-1 ; j++)
	// 				{
	// 					ListNode *y = new_list->head;
	// 					new_list->head = new_list->head->next;

	// 					free(y);
	// 				}
	// 				free(new_list->head);
					
	// 				new_list->head = temp;
	// 				new_list->size = 1;
	// 			}
	// 		}
	// 	}
		
	// }

	// for (int j = 0; j < new_list->size-1 ; j++)
	// {
	// 	ListNode *y = new_list->head;
	// 	new_list->head = new_list->head->next;

	// 	free(y);
	// }
	// free(new_list->head);
	// free(new_list);
	
	// return 1;


	// ver2. 좀 더 짧아지긴 했지만, 스택의 특성을 잘 사용하진 못함.

	// if (s->ll.head == NULL)
	// 	return 0;

	// LinkedList *new_list = malloc(sizeof(LinkedList));
	// new_list->head = NULL;
	// new_list->size = 0;
	// new_list->tail = NULL;

	// while (s->ll.head != NULL)
	// {
	// 	int temp = pop(s);
		
	// 	if (new_list->size == 0)
	// 		insertNode(new_list, 0, temp);
	// 	else
	// 	{
	// 		ListNode *cur = new_list->head;
	// 		while (cur->next != NULL)
	// 			cur = cur->next;
			
	// 		if (cur->item - temp == 1 || cur->item - temp == -1)
	// 			insertNode(new_list, new_list->size, temp);
			
	// 		else {
	// 			if (new_list->size % 2 == 0)
	// 				insertNode(new_list, new_list->size, temp);
	// 			else
	// 			{
	// 				removeAllItems(new_list);
	// 				free(new_list);					
	// 				return 0;
	// 			}				
	// 		}
	// 	}
	// }

	// int res = new_list->size % 2;

	// removeAllItems(new_list);
	// free(new_list);

	// if (res)
	// 	return 0;
	// else
	// 	return 1;


	// ver3. Stack 특성 활용

    if (s->ll.head == NULL)
        return 0;

    Stack tempStack;
    tempStack.ll.head = NULL;
    tempStack.ll.size = 0;

    int pairwise = 1;

    while (!isEmptyStack(s))
    {
        int first = pop(s);
        int second = pop(s);

        if (abs(first - second) != 1)
        {
			pairwise = 0;

			push(&tempStack, first);
			push(&tempStack, second);

			break;
		}    


        push(&tempStack, first);
        push(&tempStack, second);
    }

    // 원래 스택 복구
    while (!isEmptyStack(&tempStack))
    {
        push(s, pop(&tempStack));
    }

    return pairwise;
	
}

//////////////////////////////////////////////////////////////////////////////////

void push(Stack *s, int item){
   insertNode(&(s->ll), 0, item);
}

int pop(Stack *s){
   int item;
   if(!isEmptyStack(s)){
    item = ((s->ll).head)->item;
    removeNode(&(s->ll), 0);
    return item;
   }
    return INT_MIN;
}

int peek(Stack *s){
   return ((s->ll).head)->item;
}

int isEmptyStack(Stack *s){
   if ((s->ll).size == 0)
      return 1;
   return 0;
}

//////////////////////////////////////////////////////////////////////////////////

void printList(LinkedList *ll){

	ListNode *cur;
	if (ll == NULL)
		return;
	cur = ll->head;

	if (cur == NULL)
		printf("Empty");
	while (cur != NULL)
	{
		printf("%d ", cur->item);
		cur = cur->next;
	}
	printf("\n");
}

ListNode * findNode(LinkedList *ll, int index){

	ListNode *temp;

	if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;

	temp = ll->head;

	if (temp == NULL || index < 0)
		return NULL;

	while (index > 0){
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
}

int insertNode(LinkedList *ll, int index, int value){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	// If empty list or inserting first node, need to update head pointer
	if (ll->head == NULL || index == 0){
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}


	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	return -1;
}


int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){

		if (pre->next == NULL)
			return -1;

		cur = pre->next;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 0;
	}

	return -1;
}

void removeAllItems(LinkedList *ll)
{
	ListNode *cur = ll->head;
	ListNode *tmp;

	while (cur != NULL){
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	ll->head = NULL;
	ll->size = 0;
}
