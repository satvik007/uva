#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
char c2, c1 = '0';
vector <string> a;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int floodfill(int r, int c){
    if(r<0 || r>=n) return 0;
    if(a[r][(c+m)%m] != c2) return 0;
    a[r][(c+m)%m] = c1;
    int ans = 1;
    for(int i=0; i<4; i++){
        ans += floodfill(r+dr[i], c+dc[i]);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int u, v;
    while(cin >> n >> m){
        a.clear(); a.resize(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        cin >> u >> v;
        c2 = a[u][v];
        floodfill(u, v);
        int max1 = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] == c2) max1 = max(max1, floodfill(i, j));
            }
        }
        cout << max1 << "\n";
    }
}