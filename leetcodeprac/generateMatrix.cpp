#include <vector>

using namespace std;

int cur = 1;

void generate(vector< vector<int> >& matrix, int t, int b, int l, int r){
    if (t>b || l>r) return;
    for (int i=l;i<=r;i++){
        matrix[t][i] = cur++;
    }
    if (t<b){
        for (int i = t+1;i<=b;i++){
            matrix[i][r] = cur++;
        }
        for (int i = r - 1;i>=l;i--){
            matrix[b][i] = cur++;
        }
        for (int i = b-1;i>t;i--){
            matrix[i][l] = cur++;
        }
    }
    generate(matrix, t+1, b-1, l+1, r-1);
}

vector< vector<int> > generateMatrix(int n) {
    vector< vector<int> > matrix(n, vector<int>(n));
    generate(matrix, 0, n-1, 0, n-1);
    return matrix;
}