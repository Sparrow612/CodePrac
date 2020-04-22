#include <iostream>
#include <vector>

using namespace std;

struct node {
	int val;
	node * next;
	node(int x):val(x),next(NULL){}
};

node * selectmin(vector<node*>& lists, int k) {
	int index=0, val = INT_MAX;
	for (int i = 0; i < k; i++) {
		if (lists[i]) {
			if (lists[i]->val < val) {
				val = lists[i]->val;
				index = i;
			}
		}
	}
	node * res = lists[index];
	lists[index] = lists[index]->next;
	return res;
}

//int main() {
//	int k, n, tot = 0;
//	cin >> k;
//	getchar();
//	vector<node*> lists;
//	for (int i = 0; i < k; i++) {
//		node * head=NULL, *ptr=NULL;
//		while (cin.peek() != '\n') {
//			cin >> n;
//			tot++;
//			node * tmp = new node(n);
//			if (!head) head = tmp;
//			if (ptr) ptr->next = tmp;
//			ptr = tmp;
//		}
//		getchar();
//		lists.push_back(head);
//	}
//	node *res=NULL, *cur=NULL;
//	for (int i = 0; i < tot; i++) {
//		node * tmp = selectmin(lists, k);
//		if (cur) cur->next = tmp;
//		if (!res) res = tmp;
//		cur = tmp;
//		cout << tmp->val;
//		if (i < tot - 1) cout << ' ';
//	}	
//}
