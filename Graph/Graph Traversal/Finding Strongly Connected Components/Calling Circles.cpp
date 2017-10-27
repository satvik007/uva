#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf 100000000

int a[30][30];
int visited[30];
int n, m;
vector <string> names;
map <string, int> map1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    string u, v;
    int cas = 1;
    while(cin >> n >> m, n||m){
        if(cas != 1) cout << "\n";
        int k = 0;
        names.clear();
        map1.clear();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) a[i][j] = inf;
            a[i][i] = 0;
        }
        for(int i=0; i<m; i++){
            cin >> u >> v;
            if(map1.find(u) == map1.end()) names.push_back(u), map1[u] = k++;
            if(map1.find(v) == map1.end()) names.push_back(v), map1[v] = k++;
            a[map1[u]][map1[v]] = 1;
        }
        for(int k=0; k<n; k++) for(int i=0; i<n; i++) for(int j=0; j<n; j++)
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
        memset(visited, 0, sizeof visited);
        vi ans;
        cout << "Calling circles for data set " << cas << ":\n";
        for(int i=0; i<n; i++){
            if(!visited[i]){
                ans.clear();
                for(int j=0; j<n; j++){
                    if(!visited[j] && a[i][j] != inf && a[j][i] != inf){
                        visited[j] = 1;
                        ans.push_back(j);
                    }
                }
                cout << names[ans[0]];
                for(int k=1; k<ans.size(); k++){
                    cout << ", " << names[ans[k]];
                }
                cout << "\n";
            }
        }
        cas++;
    }
    return 0;
}