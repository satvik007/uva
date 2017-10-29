#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

vector <string> names;
map <string, int> map1;
vector <vi> a;
int n, visited[205], check, ans, counter[205];

bool diff(int i, int j){
    if(names[i].size() != names[j].size()) return false;
    int counter = 0;
    for(int k=0; k<names[i].size(); k++){
        if(names[i][k] != names[j][k]) counter++;
    }
    if(counter == 1) return true;
    return false;
}

void bfs(int u, int v){
    memset(visited, 0, sizeof visited);
    memset(counter, 0, sizeof counter);
    visited[u] = 1;
    queue <int> q;
    q.push(u);
    while(!q.empty()){
        int current = q.front(); q.pop();
        if(current == v) break;
        for(auto el:a[current]){
            if(!visited[el]){
                visited[el] = 1;
                q.push(el);
                counter[el] = counter[current]+1;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    string line, u, v;
    while(t--){
        names.clear(); map1.clear(); a.clear();
        int k = 0;
        while(true){
            cin >> line;
            if(line == "*") break;
            names.push_back(line);
            map1[line] = k++;
        }
        n = names.size();
        a.resize(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(diff(i, j)) a[i].push_back(j), a[j].push_back(i);
            }
        }
        //k = 0;for(auto row:a){ cout << (k++) << " - "; for(auto el:row) cout << el << " "; cout << "\n"; }
        cin.ignore();
        while(cin.peek() != '\n' && cin.peek() != EOF){
            cin >> u >> v; cin.ignore();
            bfs(map1[u], map1[v]);
            cout << u << " " << v << " " << counter[map1[v]] << '\n';
        }
        if(t) cout << '\n';
    }
    return 0;
}
