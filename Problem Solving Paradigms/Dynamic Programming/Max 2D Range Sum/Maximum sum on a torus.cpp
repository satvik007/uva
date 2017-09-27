#include<bits/stdc++.h>
#define SIZE 350
using namespace std;

int grid[SIZE][SIZE];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tc, n;
    cin >> tc;
    for(int i = 0; i < tc; ++i){
        cin >> n;
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < n; ++k){
                cin >> grid[j][k];
                grid[j + n][k] = grid[j][k + n] = grid[j + n][k + n] = grid[j][k];
            }
        }
        for(int j = 0; j < 2*n; ++j){
            for(int k = 0; k < 2*n; ++k){
                if(j > 0) grid[j][k] += grid[j-1][k] ;
                if(k > 0) grid[j][k] += grid[j][k - 1];
                if(j > 0 && k > 0) grid[j][k] -= grid[j - 1][k - 1];
            }
        }
        int maxRect = INT_MIN;
        int subRect = INT_MIN;

        for(int j = 0; j < n; ++j) for(int k = 0; k < n; ++k)
            for(int l = j; l < n + j && l < 2*n; ++l) for(int m = k; m < n + k && m < 2*n; ++m){
                subRect = grid[l][m];
                    if(j > 0) subRect -= grid[j-1][m];
                    if(k > 0) subRect -= grid[l][k -1];
                    if(j > 0 && k > 0) subRect += grid[j-1][k-1];
                    maxRect = max(maxRect, subRect);
                }
        cout << maxRect << "\n";
    }
    return 0;

}
