typedef struct Node Node;
Node * makeNewRandomList(int len);
void freeListMemory(Node * list);
void swap(Node * n1, Node * n2 );

typedef struct Node{
	int value;
	struct Node *next;
	struct Node *prev;
}Node;