#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int t, n, m, fx, fy;
vector <string> a, b;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void floodfill(int r, int c){
    if(r < 0 || r >= n || c < 0 || c >= a[r].size() || (a[r][c] != ' ' && a[r][c] != '-' && a[r][c] != '*')) return;
    a[r][c] = '#';
    for(int i=0; i<4; i++){
        floodfill(r+dr[i], c+dc[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> t; cin.ignore();
    while(t--){
        string line; a.clear();
        m = 0;
        n = 0;
        int p;
        while(1){
            getline(cin, line);
            if(line[0] == '_') {
                p = line.size();
                break;
            }
            if(line.find('*') != string::npos){
                fx = n;
                fy = line.find('*');
            }
            a.push_back(line); n++;
            m = max(m, (int)line.size());
        }
        floodfill(fx, fy);
        for(int i=0; i<n; i++) cout << a[i] << "\n";
        for(int i=0; i<p; i++) cout << "_"; cout << "\n";
    }
    return 0;
}