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

Node* mergeSort(Node * head){

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

        right = mergeSort(right);
        left = mergeSort(left);
    
        // printf("=======\n");
        // printf("LEFT:\n");
        // printList(left);
        // printf("RIGHT:\n");
        // printList(right);
        // printf("=======\n");
    
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
        // printf("=====");
        // printf("left: %d; right: %d", left_counter->value, right_counter->value);
        // printf("=====\n");
        
            if (left_counter->value <= right_counter->value){
                sorted_counter->next = left_counter;
                sorted_counter = sorted_counter ->next;
                left_counter = left_counter -> next; 
            }else{
                sorted_counter->next = right_counter;
                sorted_counter = sorted_counter ->next;
                right_counter = right_counter -> next;
            }
        }

        if (left_counter != NULL)
            sorted_counter->next = left_counter;

        if (right_counter != NULL)
            sorted_counter->next = right_counter;


        // printf("==ANSWER==\n");
        // printList(answer);
        // printf("==========\n");


        // printf("==HEAD==\n");
        // printList(head);
        // printf("==========\n");

        return answer;

    }

    return head;
}


int main(int argc, char const *argv[]){
	int len = 8;
	Node * list = makeNewRandomList(len);
    printf("INPUT LIST:\n");
    printList(list);

	Node* answer = mergeSort(list);
	
    printf("OUTPUT LIST:\n");
    printList(answer);
	return 0;
}