#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct Node{
	int value;
	struct Node *next;
}Node;

// not used
void swap(Node * n1, Node * n2 ){
	static int temp;
	temp = n1 -> value;
	n1 -> value = n2 -> value;
	n2 -> value = temp;
}

Node* append(Node* root, Node* node){

	Node* temp = root;

	if(root == NULL)
		return node;

	while(temp->next != NULL)
		temp = temp -> next;
	temp -> next = node;

	return root;
}

void printList(Node * itterator){
	while(itterator != NULL){
		printf("%d\n", itterator->value);
		itterator = itterator->next;
	}
}


Node * makeList(const char* path){

    FILE* in_file;
    int temp;
   	int i =0;
    Node* root = NULL;


    if ((in_file = fopen(path,"r")) == NULL){
        printf("Error! opening file");
        return 0;
    }

	while(fscanf(in_file, "%d", &temp) != -1){
		Node* tempNode = (Node *) malloc(sizeof(Node));
    	tempNode->value = temp;
    	tempNode->next = NULL;

        root = append(root, tempNode);

    }

    fclose(in_file); 

   return root;
}

