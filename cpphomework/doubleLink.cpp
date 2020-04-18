#include <iostream>
#include <string>

using namespace std;

struct node {
	int val;
	node * prev;
	node * next;
	node(int x,node * pre):val(x),prev(pre),next(NULL){}
	node(int x,node* pre, node*nex):val(x),prev(pre),next(nex){}
};

void print(node * begin) {
	while (begin) {
		cout << begin->val;
		begin = begin->next;
		if (begin) cout << ' ';
		else cout << endl;
	}
}

void addbegin(node* &begin, node*&end,int n) {
	node * tmp = new node(n, NULL);
	tmp->next = begin;
	if (begin)begin->prev = tmp;
	else end = tmp;
	begin = tmp;
	print(begin);
}

void addend(node* &begin,node *&end, int n) {
	node * tmp = new node(n, end);
	if (end) end->next = tmp;
	else begin = tmp;
	end = tmp;
	print(begin);
}

void addmin(node * tar, int n, int index) {
	node * pre=NULL;
	while (index) {
		pre = tar;
		tar = tar->next;
		index--;
	}
	node*tmp = new node(n, pre, tar);
	pre->next = tmp;
	tar->prev = tmp;
}

void search(node* tar, int val) {
	int cur = 0;
	while (tar->val != val) {
		tar = tar->next;
		cur++;
	}
	cout << cur << endl;
}

void del(node * tar, int pos,node*&begin,node*&end) {
	while (pos--) {
		tar = tar->next;
	}
	if (tar->next)tar->next->prev = tar->prev;
	else end = tar->prev;
	if (tar->prev)tar->prev->next = tar->next;
	else begin = tar->next;
	delete tar;
	print(begin);
}

void count(node * tar) {
	int num = 0;
	while (tar) {
		num++;
		tar = tar->next;
	}
	cout << num << endl;
}

void reverse(node * tar,node* &begin,node* &end) {
	end = tar;
	while (tar) {
		node* cur = tar;
		begin = cur;
		tar = tar->next;
		swap(cur->prev, cur->next);
	}
	print(begin);
}

//int main() {
//	int n;
//	node * begin = NULL, *cur = begin;
//	while (cin.peek() != '\n') {
//		cin >> n;
//		node * tmp = new node(n, cur);
//		if (!begin) begin = tmp;
//		if (cur) cur->next = tmp;
//		cur = tmp;
//	}
//	string req;
//	while (cin >> req) {
//		int op1, op2;
//		if (req == "addbegin") {
//			cin >> op1;
//			addbegin(begin, cur, op1);
//		}
//		else if (req == "addend") {
//			cin >> op1;
//			addend(begin, cur, op1);
//		}
//		else if (req == "addmid") {
//			cin >> op1 >> op2;
//			addmin(begin, op1, op2);
//			print(begin);
//		}
//		else if (req == "search") {
//			cin >> op1;
//			search(begin, op1);
//		}
//		else if (req == "delete") {
//			cin >> op1;
//			del(begin, op1, begin, cur);
//		}
//		else if (req == "count") count(begin);
//
//		else if (req == "reverse") reverse(begin, begin, cur);
//
//	}
//}
