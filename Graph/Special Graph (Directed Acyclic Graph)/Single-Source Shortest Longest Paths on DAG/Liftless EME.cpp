#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf (int)1e9

string cas;
int n, m, a[140][20][20];
int memo[140][20];

int solve(int current, int hole){
    if(current == n-1) return 0;
    if(memo[current][hole] != -1) return memo[current][hole];
    int ans = inf;
    for(int i=0; i<m; i++){
        ans = min(ans, 2 + solve(current + 1, i) + a[current][hole][i]);
    }
    return memo[current][hole] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> cas){
        cin >> n >> m;
        memset(memo, -1, sizeof memo);
        cout << cas << "\n";
        for(int k=0; k<n-1; k++)
            for(int i=0; i<m; i++)
                for(int j=0; j<m; j++)
                    cin >> a[k][i][j];
        int min1 = inf;
        for(int i=0; i<m; i++){
            min1 = min(min1, solve(0, i));
        }
        cout << min1 << "\n";
    }

    return 0;
}