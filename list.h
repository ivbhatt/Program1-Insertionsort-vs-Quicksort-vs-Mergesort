typedef struct Node Node;
Node * makeNewRandomList(int len);
Node * makeNewSortedList(int len);

void freeListMemory(Node * list);
void swap(Node * n1, Node * n2 );
Node* append(Node* root, Node* node);
typedef struct Node{
	int value;
	struct Node *next;
	struct Node *prev;
}Node;