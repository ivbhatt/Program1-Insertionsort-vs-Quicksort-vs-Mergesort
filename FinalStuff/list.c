#include "dependencies.h"


/**
 * should return the head of the list
 */
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
