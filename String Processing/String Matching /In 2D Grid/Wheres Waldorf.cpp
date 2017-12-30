#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

vector <string> a;

int dr[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dc[] = {0, 1, 0, -1, 1, -1, -1, 1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--){
        int n, w; cin >> n >> w; a.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++){
            for(int j=0; j<w; j++){
                a[i][j] = tolower(a[i][j]);
            }
        }
        string u;
        ii ans1, ans2;
        int q; cin >> q;
        while(q--){
            cin >> u;
            for(int i=0; i<u.size(); i++) u[i] = tolower(u[i]);
            int flag = 0;
            for(int i=0; i<n && !flag; i++){
                for(int j=0; j<w && !flag; j++){
                    if(a[i][j] == u[0]){
                        int x, y;
                        for(int k=0; k<8; k++){
                            x = i; y = j; flag = 1;
                            for(int m=1; m<u.size(); m++){
                                x += dr[k]; y += dc[k];
                                if(x >= 0 && x < n && y >= 0 && y < w && a[x][y] == u[m]);// cout << a[x][y] << endl;
                                else {
                                    flag = 0; break;
                                }
                            }
                            if(flag){
                                ans1.first = i; ans1.second = j;
                                break;
                            }
                        }
                        if(flag) break;
                    }
                }
            }
            if(!flag) cout << "Not found\n";
            else cout << ans1.first+1 << " " << ans1.second +1<< "\n";
        }
        if(tc) cout << "\n";
    }

    return 0;
}