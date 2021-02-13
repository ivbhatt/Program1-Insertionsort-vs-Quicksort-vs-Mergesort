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

void mergeSort(Node * head){

    // find middle of the linkedlist

    if(head != NULL && head -> next != NULL){
        Node* fast_pointer = head;
        Node* slow_pointer = head;
        Node* prev_slow = head;
        
        while(fast_pointer != NULL && fast_pointer->next != NULL){
            fast_pointer = fast_pointer -> next -> next;
            
            prev_slow = slow_pointer;
            slow_pointer = slow_pointer -> next;
        }

        Node* right = slow_pointer;
        Node* left = head;

        prev_slow -> next = NULL;

        mergeSort(left);
        mergeSort(right);

        Node* left_counter = left;
        Node* right_counter = right;
        
        Node* sorted_counter = NULL;

        if (left_counter->value <= right_counter->value){
            sorted_counter = left_counter;
            left_counter = left_counter -> next; 
        }else{
            sorted_counter = right_counter;
            right_counter = right_counter -> next;
        }
        Node* answer = sorted_counter;

        while(left_counter != NULL && right_counter != NULL){

            if (left_counter->value <= right_counter->value){
                sorted_counter = left_counter;
                left_counter = left_counter -> next; 
            }else{
                sorted_counter = right_counter;
                right_counter = right_counter -> next;
            }
        }

        if (left_counter != NULL)
            sorted_counter->next = left_counter;

        if (right_counter != NULL)
            sorted_counter->next = right_counter;

        head = answer;

    }

    return;
}


int main(int argc, char const *argv[]){
	int len = 10;
	Node * list = makeNewRandomList(len);
	mergeSort(list);
	printList(list);
	return 0;
}