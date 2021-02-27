#include "dependencies.h"

// Global Variables
int comparisions = 0;



Node* quickSort(Node * head){

    // initializing some values 
    int length = 0;
    Node* temp = head;
    int pivot_index = 0;
    int pivot = 0;
    int i =0;

    time_t t;

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


    
    temp = head;
    Node* tempNext = temp -> next;
    
    Node* leftLast = NULL;
    Node* pivotsLast = NULL;
    Node* rightLast = NULL;

    while(temp != NULL){

        tempNext = temp -> next;
        temp -> next = NULL;

        if(temp -> value == pivot){
            if(pivots == NULL){
                pivots = temp;
                pivotsLast = temp;
            }else{
                pivotsLast -> next = temp;
                pivotsLast = temp;
            }

            // pivots = append(pivots, temp);

        }else if(temp -> value < pivot){
            if(left == NULL){
                left = temp;
                leftLast = temp;
            }else{
                leftLast -> next = temp;
                leftLast = temp;
            }

            // left = append(left, temp);
        
        }else if(temp -> value > pivot){
            if(right == NULL){
                right = temp;
                rightLast = temp;
            }else{
                rightLast -> next = temp;
                rightLast = temp;
            }

            //right = append(right, temp);
        }
        temp = tempNext;
    }

    


    left = quickSort(left);
    right = quickSort(right);

    
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
    char const *path = argv[1];
    clock_t start, end;
    float time_taken;

    Node * list = makeList(path);


    start = clock();
    Node* answer = quickSort(list);
    end = clock();

    time_taken = (end - start)/(float)CLOCKS_PER_SEC;

    printf("comparisions: %d\n", comparisions);
    printf("time_taken: %f\n", time_taken);

    return 0;
}