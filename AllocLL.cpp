//============================================================================
// Name        : AllocLL.cpp
// Author      : Jason Cox
//============================================================================

#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct Link {

public:
	Link(int x) {

		data = x;
	}

	Link() {}

	int data;
	Link* next;

	~Link() {
		if(next) delete next;
		data = NULL;
	}
};


Link* createLL(Link* head, int val, int start, int end) {
	/* Recursively constructs linked list 'end' times with value of val*/

	if(start < end) {
		head = new Link(val);
		head->next = createLL(head->next, val+1, start+1, end);
	}
	return head;
}

void traverseLL(Link* head) {
	if(head) {
		cout << head->data << endl;
		if(head->next) {
			traverseLL(head->next);
		}
	}
}


int main() {

	Link* mylink = new Link();
	mylink = createLL(mylink, 0, 0, 100000);
	traverseLL(mylink);
	delete mylink;
	mylink = NULL;

	//As long as the pointer is deleted and subsequently set to NULL,
	//the linked list will be safely deleted and an attempt to traverse it will not print anything.

	traverseLL(mylink);

	return 0;
}
