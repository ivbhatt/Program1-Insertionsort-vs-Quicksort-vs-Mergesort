#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "insertion.h"


Node * makeNewRandomList(int len){
	srand( time(NULL));
	Node * head = (Node *) malloc(sizeof(Node));
	head->value = rand() % 50; //random integer less than 50
	head->next = NULL; //next value unknow currently
	head->prev = NULL; //No previous value as head of the list
	Node * itt = head; // itterator for the loop 

	//create len many nodes
	for (int i = 0; i < len -1  ; i++){
		Node *temp = (Node *) malloc(sizeof(Node)); //create a new node
		temp->value = rand() % 50; //Assign new node random value
		temp->next = NULL; //Assign Null because curent itteration is tail of the list
		temp->prev = itt; //Previous element is the itterator
		itt->next = temp; //Make previous element point to the next
		itt = temp;//Advance the itterator
	}
	return head;
}

Node * makeNewSortedList(int len){
	srand( time(NULL));
	Node * head = (Node *) malloc(sizeof(Node));
	head->value = 0; //0
	head->next = NULL; //next value unknow currently
	head->prev = NULL; //No previous value as head of the list
	Node * itt = head; // itterator for the loop 

	//create len many nodes
	for (int i = 1; i < len -1  ; i++){
		Node *temp = (Node *) malloc(sizeof(Node)); //create a new node
		temp->value = i; //Assign new node random value
		temp->next = NULL; //Assign Null because curent itteration is tail of the list
		temp->prev = itt; //Previous element is the itterator
		itt->next = temp; //Make previous element point to the next
		itt = temp;//Advance the itterator
	}
	return head;
}

void freeListMemory(Node * list){
	while(list != NULL){
		Node *itterator = list;
		list = list -> next;
		free(itterator);
	}
}

/**
 * should return the head of the list
 */
void swap(Node * n1, Node * n2 ){
	static int temp;
	temp = n1 -> value;
	n1 -> value = n2 -> value;
	n2 -> value = temp;
}

// int main(int argc, char const *argv[]){

// 	int len = 10;
// 	Node * list = makeNewRandomList(len);
// 	//this is how to traverse a linked list
// 	Node *itterator = list;
// 	while(itterator != NULL){
// 		printf("%d\n", itterator->value);
// 		itterator = itterator->next;
// 	}

// 	Node *x = list ->next;
// 	printf("This is x %d\n", x->value);
// 	Node *y = x->next;
// 	printf("This is y %d\n", y->value);
// 	swap(x,y);

// 	itterator = list;
// 	while(itterator != NULL){
// 		printf("%d\n", itterator->value);
// 		itterator = itterator->next;
// 	}
// 	freeListMemory(list);
// }
