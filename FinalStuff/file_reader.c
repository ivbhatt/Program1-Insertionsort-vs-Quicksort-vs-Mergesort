// demo code

#include "dependencies.h"

int main(int argc, char const *argv[]){
	int i =0;
	int temp;

    // FILE *in_file  = fopen("inputs_txt\\input_1.txt", "r"); // read only 

	Node* list = makeList("inputs_txt\\input_1.txt");

	printList(list);
	
	print("%d", CLOCKS_PER_SEC);
	return 0;
}

