#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

string u, v;
int n, m;
int dp[40][40];
int path[40][40];

void print_path(int i, int j){
    if(i == 0 && j == 0) return;
    if(path[i][j] == 1){
        print_path(i-1, j-1);
    }else if(path[i][j] == 2){
        print_path(i-1, j-1);
        cout << "C" <<  v[j-1] << setw(2) << setfill('0') << (j) ;
    }else if(path[i][j] == 3){
        print_path(i-1, j);
        cout << "D" <<  u[i-1] << setw(2) << setfill('0') << (j+1);
    }else{
        print_path(i, j-1);
        cout << "I" <<  v[j-1] << setw(2) << setfill('0') << (j);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> u, u != "#"){
        cin >> v;
        n = (int)u.size(), m = (int)v.size();
        memset(dp, 0, sizeof dp);
        memset(path, -1, sizeof path);
        for(int i=0; i<25; i++){
            path[i][0] = 3;
            path[0][i] = 4;
            dp[i][0] = dp[0][i] = i;
        }
        path[0][0] = -1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(u[i-1] == v[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                    path[i][j] = 1;
                }else{
                    dp[i][j] = dp[i-1][j-1] + 1;
                    path[i][j] = 2;
                }
                if(dp[i-1][j] + 1 < dp[i][j]){
                    dp[i][j] = dp[i-1][j] + 1;
                    path[i][j] = 3;
                }
                if(dp[i][j-1] + 1 < dp[i][j]){
                    dp[i][j] = dp[i][j-1] + 1;
                    path[i][j] = 4;
                }
            }
        }
        print_path(n, m); cout << "E\n";
    }
    return 0;
}