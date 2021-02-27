// demo code

#include "dependencies.h"

int main(int argc, char const *argv[]){
	int i =0;
	int temp;
    time_t t;

    srand((unsigned) time(&t));

	for( i = 0 ; i < 10 ; i++ ) {
      printf("%d\n", rand() % 50);
    }
    printf("++++++\n");
    // FILE *in_file  = fopen("inputs_txt\\input_1.txt", "r"); // read only 

	Node* list = makeList("inputs_txt\\input_1.txt");

	printList(list);
	
	printf("%d", CLOCKS_PER_SEC);
	return 0;
}

