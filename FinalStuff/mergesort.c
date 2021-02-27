#include"sorting_algos.h" 

int main(int argc, char const *argv[]){
    // variables to measure time
    clock_t start, end;
    float time_taken;

    // utility that takes numbers from stdin and build a LinkedList
    Node * list = makeList();


    // sorting
    start = clock();
    Node* answer = mergeSort(list);
    end = clock();

    // calculate time
    time_taken = (end - start)/(float)CLOCKS_PER_SEC;

    // report statistics on std err
    fprintf(stderr, "comparisions: %d\n", comparisions);
    fprintf(stderr, "time_taken: %.1f\n", time_taken);

    // print answer on stdout
    printList(answer);

    return 0;
}