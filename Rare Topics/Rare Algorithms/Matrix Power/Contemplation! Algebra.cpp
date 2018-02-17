#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

#define MAX_N 2 // Fibonacci matrix, increase/decrease this value as needed
struct Matrix { ll mat[MAX_N][MAX_N]; };

Matrix matMul(Matrix a, Matrix b) {
    Matrix ans; int i, j, k;
    for (i = 0; i < MAX_N; i++)
        for (j = 0; j < MAX_N; j++)
            for (ans.mat[i][j] = k = 0; k < MAX_N; k++)
                ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
    return ans;
}

Matrix matPow(Matrix base, int p) {
    Matrix ans; int i, j;
    for (i = 0; i < MAX_N; i++) for (j = 0; j < MAX_N; j++)
            ans.mat[i][j] = (i == j);
    while (p) {
        if (p & 1) ans = matMul(ans, base);
        base = matMul(base, base);
        p >>= 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ll p, q, n;
    Matrix satvik, sourabh;
    sourabh.mat[0][1] =  sourabh.mat[1][1] = 0;
    while(cin >> p >> q >> n){
        satvik.mat[0][0] = p; satvik.mat[0][1] = -q;
        satvik.mat[1][0] = 1; satvik.mat[1][1] = 0;
        sourabh.mat[0][0] = p; sourabh.mat[1][0] = 2;
        Matrix ans = matMul(matPow(satvik, n), sourabh);
        cout << ans.mat[1][0] << "\n";
    }
    return 0;
}