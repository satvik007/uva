#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

int b[100][100];
ii p[100][100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    string u, v;
    while(cin.peek() != EOF){
        getline(cin, u); getline(cin, v);
        if(cas != 1) cout << "\n"; cas++;
        memset(b, 0, sizeof b);
        int n = (int)u.size(), m = v.size();
        for(int i=1; i<=n; i++) {
            b[i][0] = i; p[i][0].first = i - 1; p[i][0].second = 0;
        }
        for(int i=1; i<=m; i++){
            b[0][i] = i; p[0][i].first = 0; p[0][i].second = i-1;
        }
        int c1, c2;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                b[i][j] = b[i-1][j-1] + (u[i-1] == v[j-1] ? 0 : 1);
                p[i][j].first = i - 1; p[i][j].second = j - 1;
                c1 = b[i-1][j] + 1; c2 = b[i][j-1] + 1;
                if(b[i][j] > c1){
                    b[i][j] = c1; p[i][j].second = j;
                }
                if(b[i][j] > c2){
                    b[i][j] = c2; p[i][j].first = i; p[i][j].second = j - 1;
                }
            }
        }
        cout << b[n][m] << endl;
        vector <ii> ans;
        int x=n, y=m, tx, ty;
        ans.push_back({n, m});
        while(x | y){
            tx = p[x][y].first; ty = p[x][y].second;
            x = tx; y = ty;
            ans.push_back({x, y});
        }
        reverse(ans.begin(), ans.end());
        //for(auto el:ans) cout << el.first << " " << el.second << endl; cout << endl;
        int cnt = 1;
        tx = ty = 0;
        for(int i=1; i<ans.size(); i++){
            x = (ans[i].first - ans[i-1].first);
            y = (ans[i].second - ans[i-1].second);
            if(x == 1 && y == 0){
                cout << cnt++ << " Delete " << ty+1 << "\n"; tx++;
            }else if(x == 0 && y == 1){
                cout << cnt++ << " Insert " << ty+1 << "," << v[ty] << "\n"; ty++;
            }else if(x == 1 && y == 1){
                if(u[tx] == v[ty]) ;
                else cout << cnt++ << " Replace " << ty+1 << "," << v[ty] << "\n";
                tx++; ty++;
            }
        }
    }
    return 0;
}