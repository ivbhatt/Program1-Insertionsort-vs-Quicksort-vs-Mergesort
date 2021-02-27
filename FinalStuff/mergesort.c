#include "dependencies.h"


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


int main(int argc, char const *argv[]){
	char const *path = argv[1];
    clock_t start, end;
    float time_taken;

	Node * list = makeList(path);


	start = clock();
    Node* answer = mergeSort(list);
    end = clock();

    time_taken = (end - start)/CLOCKS_PER_SEC;

    printf("comparisions: %d\n", comparisions);
    printf("time_taken: %f\n", time_taken);

	return 0;
}