
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

	int data;

	Link* next;

};





int main() {

	Link mylink(100);
	mylink.next = new Link(10);

	delete mylink.next;

	stack<Link*> ptrs;
	ptrs.push(new Link(5));

	for(int i = 0; i < 100; ++i) {
		Link head = *ptrs.top();
		head.next = new Link(i);
		ptrs.push(head.next);

	}
	for(int i = 0; i <= 100; ++i) {
		Link head = *ptrs.top();
		delete ptrs.top();
		ptrs.pop();
		cout << head.data << endl;

	}
	cout << "size of ptrs: " << ptrs.size() << endl;


	return 0;
}
