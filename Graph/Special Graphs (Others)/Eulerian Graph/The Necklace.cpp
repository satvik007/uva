#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef pair <int, bool> ib;

int t, n;
vector <vector <ib>> a;
list <ii> cycle;
vi deg(50);

void euler_tour(int u, list <ii>:: iterator next){
    for(auto &el:a[u]){
        if(el.second){
            el.second = false;
            for(auto &v:a[el.first]){
                if(v.first == u && v.second){
                    v.second = false;
                    break;
                }
            }
            euler_tour(el.first, cycle.insert(next, {el.first, u}));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> t;
    int u, v;
    int cas = 1;
    while(t--){
        if(cas-1) cout << "\n";
        cin >> n; deg.assign(50, 0);
        a.clear(); a.resize(50); cycle.clear();
        for(int i=0; i<n; i++){
            cin >> u >> v;
            a[u-1].push_back({v-1, true});
            a[v-1].push_back({u-1, true});
            deg[u-1]++; deg[v-1]++;
        }
        int flag = 0, start = -1;
        for(int i=0; i<50; i++){
            if(deg[i] % 2){
                flag = 1; break;
            }
            else if(deg[i] && start == -1){
                start = i;
            }
        }
        cout << "Case #" << cas++ << "\n";
        if(flag) {
            cout << "some beads may be lost\n";
        }
        else{
            euler_tour(start, cycle.begin());
            for(auto el:cycle){
                cout << el.first+1 << " " << el.second+1 << "\n";
            }
        }
    }
    return 0;
}