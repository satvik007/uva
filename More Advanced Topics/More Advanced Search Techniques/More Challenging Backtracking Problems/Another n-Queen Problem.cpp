#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

vector <string> a;
int k, n;

void solve(int row, int col, int dig1, int dig2){
    if(row == n){
        k++; return;
    }
    for(int i=0; i<n; i++){
        if(a[row][i] == '*' || (col & (1 << i))) continue;
        if((dig1 & (1 << (row - i + n))) || (dig2 & (1 << (row + i)))) continue;
        solve(row+1, col | (1<<i), dig1 | (1 << (row - i + n)), dig2 | (1 << (row + i)));
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas=1;
    while(cin >> n, n){
        a.resize(n); for(int i=0; i<n; i++) cin >> a[i];
        k=0; solve(0, 0, 0, 0);
        cout << "Case " << cas++ << ": " << k << "\n";
    }
    return 0;
}