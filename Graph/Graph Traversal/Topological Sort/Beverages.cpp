#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m;
map <string, int> map1;
vector <vi> a;
vector <string> names;
int indeg[105];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int cas = 1;
    string u, v;
    while(cin >> n){
        cout << "Case #" << cas << ": Dilbert should drink beverages in this order:";
        map1.clear(); a.clear(); names.resize(n);
        a.resize(n);
        for(int i=0; i<n; i++){
            cin >> names[i];
            map1[names[i]] = i;
        }
        memset(indeg, 0, sizeof indeg);
        cin >> m;
        for(int i=0; i<m; i++){
            cin >> u >> v;
            a[map1[u]].push_back(map1[v]);
            indeg[map1[v]]++;
        }
        priority_queue <int, vector <int>, greater <int> > q;
        for(int i=0; i<n; i++) if(indeg[i] == 0) q.push(i);
        while(!q.empty()){
            int current = q.top(); q.pop();
            for(auto el:a[current]){
                indeg[el]--;
                if(indeg[el] == 0) q.push(el);
            }
            cout << " " << names[current];
        }
        cout << ".\n\n";
        cas++;
    }
    return 0;
}
