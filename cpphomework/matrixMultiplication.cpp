<<<<<<< HEAD
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string operator +(string a, string b) {
	string tmp = a.append(b);
	string res = "";
	for (char c : tmp) {
		bool isnew = true;
		for (char r : res) {
			if (r == c) isnew = false;
		}
		if (isnew) res += c;
	}
	return res;
}

string operator * (string a, string b) {
	return a.append(b);
}

template <typename T>
inline T mul(T a, T b) {
	return a * b;
}

template <typename T>
inline T add(T a, T b) {
	return a + b;
}

template <typename AnyType>
class Matrix{
private:
	int type;
	int n, m;
	vector<vector<AnyType>> src;
public:
	Matrix(int t,int N,int M, vector<vector<AnyType>> s):type(t),n(N),m(M),src(s){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> src[i][j];
			}
		}
	}
	void multipy(Matrix& tar) {
		int rt = this->type*tar.type;
		cout << rt << endl;
		if (tar.type ==-1|| this->type==-1) {
			for (int i = 0; i < this->n; i++) {
				for (int j = 0; j < tar.m; j++) {
					string res = "";
					for (int k = 0; k < tar.n; k++) {
						res = add(res,mul(this->src[i][k], tar.src[k][j]));
					}
					cout << res;
					if (j < tar.m - 1) cout << ' ';
				}
				cout << endl;
			}
		}
		else {
			for (int i = 0; i < this->n; i++) {
				for (int j = 0; j < tar.m; j++) {
					double res = 0;
					for (int k = 0; k < tar.n; k++) {
						res = add(res, mul(stod(this->src[i][k]), stod(tar.src[k][j])));
					}
					if (abs(res - int(res)) < 1e-7) cout << (int)res;
					else cout << res;
					if (j < tar.m - 1) cout << ' ';
				}
				cout << endl;
			}
		}
	}
};

//int main() {
//	int type, n, m;
//	cin >> type >> n >> m;
//	Matrix<string> a = Matrix<string>(type, n, m, vector<vector<string>>(n,vector<string>(m,"")));
//	cin >> type >> n >> m;
//	Matrix<string> b = Matrix<string>(type, n, m, vector<vector<string>>(n, vector<string>(m, "")));
//
//	cout << fixed << setprecision(4);
//	a.multipy(b);
//}
=======
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string operator +(string a, string b) {
	string tmp = a.append(b);
	string res = "";
	for (char c : tmp) {
		bool isnew = true;
		for (char r : res) {
			if (r == c) isnew = false;
		}
		if (isnew) res += c;
	}
	return res;
}

string operator * (string a, string b) {
	return a.append(b);
}

template <typename T>
inline T mul(T a, T b) {
	return a * b;
}

template <typename T>
inline T add(T a, T b) {
	return a + b;
}

template <typename AnyType>
class Matrix{
private:
	int type;
	int n, m;
	vector<vector<AnyType>> src;
public:
	Matrix(int t,int N,int M, vector<vector<AnyType>> s):type(t),n(N),m(M),src(s){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> src[i][j];
			}
		}
	}
	void multipy(Matrix& tar) {
		int rt = this->type*tar.type;
		cout << rt << endl;
		if (tar.type ==-1|| this->type==-1) {
			for (int i = 0; i < this->n; i++) {
				for (int j = 0; j < tar.m; j++) {
					string res = "";
					for (int k = 0; k < tar.n; k++) {
						res = add(res,mul(this->src[i][k], tar.src[k][j]));
					}
					cout << res;
					if (j < tar.m - 1) cout << ' ';
				}
				cout << endl;
			}
		}
		else {
			for (int i = 0; i < this->n; i++) {
				for (int j = 0; j < tar.m; j++) {
					double res = 0;
					for (int k = 0; k < tar.n; k++) {
						res = add(res, mul(stod(this->src[i][k]), stod(tar.src[k][j])));
					}
					if (abs(res - int(res)) < 1e-7) cout << (int)res;
					else cout << res;
					if (j < tar.m - 1) cout << ' ';
				}
				cout << endl;
			}
		}
	}
};

//int main() {
//	int type, n, m;
//	cin >> type >> n >> m;
//	Matrix<string> a = Matrix<string>(type, n, m, vector<vector<string>>(n,vector<string>(m,"")));
//	cin >> type >> n >> m;
//	Matrix<string> b = Matrix<string>(type, n, m, vector<vector<string>>(n, vector<string>(m, "")));
//
//	cout << fixed << setprecision(4);
//	a.multipy(b);
//}
>>>>>>> 1bb2aa6d868593b4787d219d1e5f07f6378bc0fc
