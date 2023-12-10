#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node* next;
}

Node* CreateNode(int x)
{
	Node *p = new Node;
	p -> info = x;
	p -> next = NULL;
	return NULL;
}

int main()
{
	
}
