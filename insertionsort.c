#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "insertion.h"
void printList(Node * itterator){
	printf("Here is the list: \n");
	while(itterator != NULL){
		printf("%d\n", itterator->value);
		itterator = itterator->next;
	}
	printf("\n");
}

void insertionSort(Node * head){
	int key;
	Node * itterator;
	Node * index = head;
	 //start on the second element because the first is sorted
	//loop through entire list
	while(index != NULL){
		//printList(head);
		itterator = index;
		index = head -> next;//advance the list
		//key = index -> value;//get the key of the element to insert
		while((itterator != NULL) && ((itterator -> value) > (itterator -> next -> value))){
			printf("I got here\n");
			swap(itterator, itterator -> next);
			itterator = itterator -> prev;
		}
	}

}

int main(int argc, char const *argv[]){
	int len = 10;
	Node * list = makeNewRandomList(len);
	insertionSort(list);
	printList(list);
	return 0;
}