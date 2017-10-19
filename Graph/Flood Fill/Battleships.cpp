#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int R, C;
int n;
vector <string> a;
int ans;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void floodfill(int r, int c){
    if(r < 0 || r>=R || c<0 || c>=C) return;
    if(a[r][c] == '.') return;
    a[r][c] = '.';
    for(int i=0; i<4; i++){
        floodfill(r+dr[i], c+dc[i]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, cas = 1, counter;
    cin >> t;
    while(t--){
        cin >> n;
        a.clear(); a.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];
        R = n; C = n;
        counter = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(a[i][j] == 'x'){
                    floodfill(i, j);
                    counter++;
                }
            }
        }
        cout << "Case " << cas << ": " << counter << "\n";
        cas++;
    }
}
