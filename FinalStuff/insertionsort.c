#include "dependencies.h"

// Global Variables
int comparisions = 0;

/* inserts an element into a sorted list
 * Node * element: the element to be inserted
 * Node * list: the list to which the element is to be inserted
 */
Node * insert(Node * element, Node * list){
	Node * previous = NULL; //keep track of previous node
	Node * current = list; //current element is the start of the list
	//loop over list finding the spot where the element should be inserted
	while (current != NULL && element->value < current->value){
		previous = current; 
		current = current->next;
		comparisions ++;
	}

	element -> next = current; //have the element point to its next value
	if(previous == NULL){ //case for the where the element needs to be inserted before the head
		list = element;
	} else {
		previous->next = element; //have the previous point to the element
	}
	return list;
}

/* uses the insertion sort algoritum to sort a linked list
 * Node * head: the head of the list to be sorted
 * Returns: Node * that points to the sorted list
 */
Node * insertionSort(Node * head){
	Node * sorted = head; //The first element is already sorted
	Node * unsorted = head->next; //The seocnd element is the head of the unsorted list
	Node * nextIndex; //Teporary pointer used to increment the unsorted list
	sorted ->next = NULL; //sets the tail of the sorted list to null

	//Loop through all elements in the unsorted list inseting them into the sorted list
	while (unsorted != NULL){
		nextIndex = unsorted -> next; //save off next index to incrment the list since unsorted 
		 							  //element pointer will be modified in the insert method
		sorted = insert(unsorted, sorted); //sort head of the unsorted list into the sorted list
		//printf("%d\n", unsorted -> value);
		unsorted =  nextIndex; //incremnt the list
	}
	return sorted;
}

int main(int argc, char const *argv[]){
	char const *path = argv[1];
    clock_t start, end;
    float time_taken;

	Node * list = makeList(path);

	start = clock();
    Node* answer = insertionSort(list);
    end = clock();

    time_taken = (end - start)/(float)CLOCKS_PER_SEC;

    printf("comparisions: %d\n", comparisions);
    printf("time_taken: %f\n", time_taken);

	return 0;
}