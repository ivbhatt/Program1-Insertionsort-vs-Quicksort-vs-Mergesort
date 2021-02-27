#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Linked list structure
typedef struct Node{
	int value;
	struct Node *next;
}Node;

// Utility to print linked list
void printList(Node * itterator){
	while(itterator != NULL){
		printf("%d\n", itterator->value);
		itterator = itterator->next;
	}
}

//Function to retrieve stdin numbers and create a linked list for the algorithms
Node* makeList(){
    int temp;
    Node* root = NULL;
    Node* rootLast = NULL;

	//Scanf will return -1 if it fails to read a new line
	//Otherwise, it will read each line and insert it into a linked list
	while(scanf("%d", &temp) != -1){
		Node* tempNode = (Node *) malloc(sizeof(Node));
    	tempNode->value = temp;
    	tempNode->next = NULL;

    	if(root == NULL){
    		root = tempNode;
    		rootLast = root;
    	}
    	else{
    		rootLast -> next = tempNode;
    		rootLast = rootLast -> next;
    	}
    }

	//Return newly created linked list
   	return root;
}