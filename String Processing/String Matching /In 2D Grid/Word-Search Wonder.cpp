#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

vector <string> a;

int dr[] = {0, 1, 0, 1, -1, 1, -1};
int dc[] = {1, 0, -1, 1, -1, -1, 1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n; cin >> n; a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    string u;
    ii ans1, ans2;
    while(cin >> u, u != "0"){
        int flag = 0;
        for(int i=0; i<n && !flag; i++){
            for(int j=0; j<n && !flag; j++){
                if(a[i][j] == u[0]){
                    int x, y;
                    for(int k=0; k<7; k++){
                        x = i; y = j; flag = 1;
                        for(int m=1; m<u.size(); m++){
                            x += dr[k]; y += dc[k];
                            if(x >= 0 && x < n && y >= 0 && y < n && a[x][y] == u[m]);// cout << a[x][y] << endl;
                            else {
                                flag = 0; break;
                            }
                        }
                        if(flag){
                            ans1.first = i; ans1.second = j;
                            ans2.first = i + dr[k]*((int)u.size()-1);
                            ans2.second = j + dc[k]*((int)u.size()-1);
                            break;
                        }
                    }
                    if(flag) break;
                }
            }
        }
        if(!flag) cout << "Not found\n";
        else cout << ans1.first+1 << "," << ans1.second +1<< " " << ans2.first+1 <<
          "," << ans2.second+1 << endl;
    }
    return 0;
}