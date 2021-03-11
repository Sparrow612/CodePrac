#include <iostream>
#include <string>

using namespace std;

typedef int(*func)(int, int);

int encrypt(func f, int x, int y) {
	x = ((x + 52) / 2 + 13) * 3;
	y = (y - 18) * 4 + 12;
	return f(x, y);
}

int add(int x, int y) {
	return x + y;
}

int sub(int x, int y) {
	return x - y;
}

int mul(int x, int y) {
	return x * y;
}

int divide(int x, int y) {
	return x / y;
}

func func_pool[4] = { add,sub,mul,divide };

int trans(string s) {
	if (s == "add") return 0;
	if (s == "sub") return 1;
	if (s == "mul") return 2;
	if (s == "div") return 3;
    return NULL;
}

//int main() {
//	int n;
//	cin >> n;
//	string req;
//	int x, y;
//	for (unsigned i = 0; i < n; i++) {
//		cin >> req >> x >> y;
//		func f = func_pool[trans(req)];
//		cout << encrypt(f, x, y) << endl;
//	}
//}
