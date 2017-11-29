#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef map <string, int> msi;
#define inf 1000000000

int n, m, V;
msi map1;
int a[205][205];
vector <string> names;

void floyd(){
    V = (int)map1.size();
    for(int k=0; k<V; k++){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    queue <int> s;
    for(int i=0; i<V; i++) {
        for(int j=i+1; j<V; j++){
            if(a[i][j] == inf && a[j][i] == inf) {
                s.push(i); s.push(j);
            }
        }
    }
    if(s.empty()) cout << "no concurrent events.\n";
    else{
        cout << (s.size()/2) << " concurrent events:\n";
        int j = 2;
        while(j--){
            if(!s.empty()){
                cout << "(" << names[s.front()]; s.pop();
                cout << "," << names[s.front()] << ") "; s.pop();
            }
        }
        cout << "\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int u, v;
    string line, temp;
    int cas = 1;
    while(cin >> n, n){
        map1.clear(); names.clear();
        int k=0;
        for(int i=0; i<200; i++) for(int j=0; j<200; j++) a[i][j] = inf;
        for(int i=0; i<n; i++){
            cin >> u;
            for(int j=0; j<u; j++){
                cin >> line;
                if(j>0) a[k-1][k] = 1;
                map1[line] = k++;
                names.push_back(line);
            }
        }
        cin >> m;
        for(int i=0; i<m; i++){
            cin >> line >> temp;
            u = map1[line]; v = map1[temp];
            a[u][v] = 1;
        }
        cout << "Case " << (cas++) << ", ";
        floyd();
    }
    return 0;
}