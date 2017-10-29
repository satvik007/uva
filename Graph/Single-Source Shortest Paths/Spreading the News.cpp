#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n;
vector <vi> a;
int visited[2505], counter[2505], status[2505], ans;

void bfs(int u){
    memset(visited, 0, sizeof visited);
    memset(counter, 0, sizeof counter);
    visited[u] = 1;
    queue <int> q;
    q.push(u);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto el:a[v]){
            if(!visited[el]){
                visited[el] = 1;
                counter[el] = counter[v] + 1;
                q.push(el);
            }
        }
    }
    int max1 = *max_element(counter, counter+n);
    memset(status, 0, sizeof status);
    for(int i=0; i<n; i++){
        status[counter[i]]++;
    }
    int current = 0;
    ans = -1;
    for(int i=1; i<n; i++){
        if(status[i] > current){
            ans = i; current = status[i];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n; a.resize(n);
    int size, u, v, t;
    for(int i=0; i<n; i++){
        cin >> size;
        for(int j=0; j<size; j++){
            cin >> u;
            a[i].push_back(u);
        }
    }
    cin >> t;
    while(t--){
        cin >> u;
        bfs(u);
        //for(int i=0; i<n; i++){ cout << counter[i] << " "; } cout << endl;
        if(ans == -1) cout << "0\n";
        else cout << status[ans] << " " << ans << "\n";
    }
    return 0;
}
