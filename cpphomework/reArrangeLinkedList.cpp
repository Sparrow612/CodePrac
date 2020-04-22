#include <iostream>
#include <vector>

using namespace std;

struct node {
	int val;
	node * next;
};

//int main() {
//	int n, cur=0;
//	vector<int> repo;
//	while (cin.peek()!='\n'&&cin.peek()!='\0') {
//		cin >> n;
//		repo.push_back(n);
//		cur++;
//	}
//	int base;
//	cin >> base;
//	node  *smaller=NULL, *larger=NULL, *smallend=NULL, *largeend=NULL;
//	for (int i = 0; i < cur; i++) {
//		node * tmp=new node;
//		tmp->val = repo[i];
//		tmp->next = NULL;
//		if (repo[i] < base) {
//			if (!smaller) smaller = tmp;
//			if (smallend) smallend->next = tmp;
//			smallend = tmp;
//		}
//		else {
//			if (!larger) larger = tmp;
//			if (largeend) largeend->next = tmp;
//			largeend = tmp;
//		}
//	}
//	if (smaller) smallend->next = larger;
//	else smaller = larger;
//	node * ptr = smaller;
//	for (int i = 0; i < cur; i++) {
//		cout << ptr->val;
//		if (i < cur - 1) cout << '-' << '>';
//		else cout << endl;
//		ptr = ptr->next;
//	}
//}
