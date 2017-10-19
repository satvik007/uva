#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int R, C;
int n;
vector <string> a;

int dr[] = {1,1,0,-1,-1,-1, 0, 1}; // trick to explore an implicit 2D grid
int dc[] = {0,1,1, 1, 0,-1,-1,-1}; // S,SE,E,NE,N,NW,W,SW neighbors
int floodfill(int r, int c, char c1, char c2) { // returns the size of CC
    if (r < 0 || r >= R || c < 0 || c >= C) return 0; // outside grid
    if (a[r][c] != c1) return 0; // does not have color c1
    int ans = 1; // adds 1 to ans because vertex (r, c) has c1 as its color
    a[r][c] = c2; // now recolors vertex (r, c) to c2 to avoid cycling!
    for (int d = 0; d < 8; d++)
        ans += floodfill(r + dr[d], c + dc[d], c1, c2);
    return ans; // the code is neat due to dr[] and dc[]
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, cas = 1, counter;
    cin >> t; cin.ignore();
    string line;
    int u, v;
    int ans;
    while(t--){
        cin.ignore();
        a.clear();
        while(cin.peek() > '9'){
            cin >> line; cin.ignore();
            a.push_back(line);
        }
        R = a.size();
        C = a[0].size();
        vector <string> grid(a);
        while(cin.peek() != '\n' && cin.peek() != EOF){
            cin >> u >> v; cin.ignore();
            a = grid;
            ans = floodfill(u-1, v-1, 'W', '.');
            cout << ans << "\n";
        }
        if(t != 0) cout << "\n";
    }
}
