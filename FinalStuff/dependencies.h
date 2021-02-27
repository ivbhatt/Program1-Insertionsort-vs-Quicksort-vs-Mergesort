#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct Node{
	int value;
	struct Node *next;
}Node;


void printList(Node * itterator){
	while(itterator != NULL){
		printf("%d\n", itterator->value);
		itterator = itterator->next;
	}
}

Node* makeList(){

    int temp;
    Node* root = NULL;
    Node* rootLast = NULL;
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

   return root;
}