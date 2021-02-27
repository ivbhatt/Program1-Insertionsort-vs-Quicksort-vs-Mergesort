#include"dependencies.h"


// Global Variables
int comparisions = 0;

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
    
        
    
        Node* left_counter = left;
        Node* right_counter = right;
        
        Node* sorted_counter = NULL;


       	comparisions++;
    	// printf("comparing: %d and %d \n", left_counter->value, right_counter->value);
        if (left_counter->value <= right_counter->value){
        	sorted_counter = left_counter;
            left_counter = left_counter -> next; 

        }else{
            sorted_counter = right_counter;
            right_counter = right_counter -> next;
        }
        Node* answer = sorted_counter;

        while(left_counter != NULL && right_counter != NULL){
        	comparisions++;
        	// printf("comparing: %d and %d \n", left_counter->value, right_counter->value);
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


        return answer;

    }

    return head;
}



Node* quickSort(Node * head){

    // initializing some variables
    int length = 0;         // length of list
    Node* temp = head;      // Node* temp used for list-traversal
    int pivot_index = 0;    // index of the pivot
    int pivot = 0;          // value of the pivot
    int i =0;               // integer used for traversal

    time_t t;               // time_t used for random seeding (pick random pivot)

    // Three lists
    Node* left = NULL; 
    Node* pivots = NULL;
    Node* right = NULL;

    // finding out the length of the supplied linked-list; cost:O(n)
    while(temp != NULL){
        temp = temp -> next;
        length++;
    }

    // if List contains <=1 element return the list as it is already sorted
    if(length <= 1)
        return head;

    // we know that the number of comparisions in quick sort at a level with N elements is N 
    comparisions += length;
   
    // now that we know the length, we can generate a random index for the pivot
    srand((unsigned) time(&t));
    pivot_index = rand() % length;

    // traversing the list again to get the value of the pivot; cost:O(n)
    temp = head;
    for(i=0; i < pivot_index; i++)
        temp = temp -> next;
    pivot = temp ->value;


    // Three pointers looking at the last-element of each list
    // If we call append without any context, each append will cost O(n)
    // If we maintain last pointers, new node can be appended in constant time!
    Node* leftLast = NULL;
    Node* pivotsLast = NULL;
    Node* rightLast = NULL;


    // Now breaking down the given list to left, right and pivots
    temp = head;
    Node* tempNext = temp -> next;
    while(temp != NULL){
        tempNext = temp -> next;
        temp -> next = NULL;

        // if temp -> < pivot, we append it to left
        // if temp -> = pivot, we append it to pivots
        // if temp -> > pivot, we append it to right
        
        if(temp -> value == pivot){
            if(pivots == NULL){
                pivots = temp;
                pivotsLast = temp;
            }else{
                pivotsLast -> next = temp;
                pivotsLast = temp;
            }
        }else if(temp -> value < pivot){
            if(left == NULL){
                left = temp;
                leftLast = temp;
            }else{
                leftLast -> next = temp;
                leftLast = temp;
            }
        }else if(temp -> value > pivot){
            if(right == NULL){
                right = temp;
                rightLast = temp;
            }else{
                rightLast -> next = temp;
                rightLast = temp;
            }
        }
        temp = tempNext;
    }

    
    // Now, we call quickSort recursively on the three lists
    left = quickSort(left);
    // pivots is already sorted
    right = quickSort(right);

    // At this point, we have three sorted lists. 
    // We need only link them and return the output.
    

    // The below logic links left -> pivots -> right
    
    // we have to take special care in case left == NULL
    // if left is NULL, we have to return pivots -> right 
    // pivots cannot be null since pivot is chosen from the list.
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


/* inserts an element into a sorted list
 * Node * element: the element to be inserted
 * Node * list: the list to which the element is to be inserted
 */
Node * insert(Node * element, Node * list){
	Node * previous = NULL; //keep track of previous node
	Node * current = list; //current element is the start of the list
	//loop over list finding the spot where the element should be inserted
	while (current != NULL){
		comparisions ++;
		if(element->value < current->value){
			previous = current; 
			current = current->next;
		}else
			break;
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
