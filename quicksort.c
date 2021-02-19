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

Node* quickSort(Node * head){


    // three lists

    // first we find the size of the input node
    int length = 0;
    Node* temp = head;
    // Node* left_head = NULL;
    // Node* right_head = NULL;
    // Node* pivots_head = NULL;

    Node* left = NULL; 
    Node* pivots = NULL;
    Node* right = NULL;


    int pivot_index = 0;
    int pivot = 0;
    int i =0;

    while(temp != NULL){
        temp = temp -> next;
        length++;

    }
    if(length == 0)
        return head;
    // printf("QuickSort called\n");
    // printList(head);    
    // printf("Length: %d", length);

    srand(time(NULL));
    pivot_index = rand() % length;

    temp = head;
    for(i=0; i < pivot_index; i++)
        temp = temp -> next;
    pivot = temp ->value;

    // printf("Pivot: %d \n", pivot);

    temp = head;
    Node* tempNext = temp -> next;
    
    while(temp != NULL){
        // printf("Looking at value: %d \n", temp -> value);
        tempNext = temp -> next;
        temp -> next = NULL;

        if(temp -> value == pivot){
            pivots = append(pivots, temp);
            // printf("Inserted in pivot\n");
        }else if(temp -> value < pivot){
            left = append(left, temp);
            // printf("Inserted in left\n");
        
        }else if(temp -> value > pivot){
            right = append(right, temp);
            // printf("Inserted in right\n");
        }
        temp = tempNext;
    }

    // printf("LEFT:\n");
    // printList(left);

    // printf("PIVOTS:\n");
    // printList(pivots);

    // printf("RIGHT:\n");
    // printList(right);


    left = quickSort(left);
    right = quickSort(right);

    // printf("SortedLEFT:\n");
    // printList(left);
    
    if(left != NULL){
        temp = left;
        while(temp->next != NULL)
            temp = temp -> next;
        temp -> next = pivots;
    }else
        temp = pivots;
    while(temp->next != NULL)
        temp = temp -> next;
    temp -> next = right;

    if(left!= NULL)
        return left;
    return pivots;
}


int main(int argc, char const *argv[]){
	int len = 8;
	Node * list = makeNewRandomList(len);
    printf("INPUT LIST:\n");
    printList(list);

	Node* answer = quickSort(list);
	
    printf("OUTPUT LIST:\n");
    printList(answer);
	return 0;
}