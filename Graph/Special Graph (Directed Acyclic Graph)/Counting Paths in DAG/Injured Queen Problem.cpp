#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf (int)1e9

string line;
int n, visited[256];
ll memo[40][40];
map <char, int> map1;

ll solve(int current, int last){
    if(current == n) return 1;
    if(memo[current][last] != -1) return memo[current][last];
    ll ans = 0;
    if(line[current] != '?'){
        if(abs(map1[line[current]] - last) > 1) return memo[current][last] = solve(current + 1, map1[line[current]]);
        return memo[current][last] = 0;
    }
    for(int i=0; i<n; i++){
        if(abs (i - last) > 1){
           ans += solve(current + 1, i);
        }
    }
    return memo[current][last] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    for(int i=1; i<10; i++){
        map1[i+'0'] = i-1;
    }
    map1['A'] = 9; map1['B'] = 10; map1['C'] = 11; map1['D'] = 12;
    map1['E'] = 13; map1['F'] = 14;
    while(cin >> line){
        memset(visited, 0, sizeof visited);
        memset(memo, -1, sizeof memo);
        n = (int)line.size();
        for(int i=0; i<n; i++){
            if(line[i] != '?'){
                visited[i*n + map1[line[i]]] = 1;
            }
        }
        ll ans = 0;
        if(line[0] == '?'){
            for(int i=0; i<n; i++){
                ans += solve(1, i);
            }
        }
        else ans += solve(1, map1[line[0]]);
        cout << ans << "\n";
    }
    return 0;
}