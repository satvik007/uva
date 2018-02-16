#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

#define maxn 100010

int treeFather[maxn];
int treeLevels[maxn];
ll treeLength[maxn];

int N, Q, u, v;

ll cost(int a1, int a2){
    int start = a1, target = a2;
    ll ans = 0;
    while(treeLevels[a1] > treeLevels[a2]){
        a1 = treeFather[a1];
    }
    while(treeLevels[a2] > treeLevels[a1]){
        a2 = treeFather[a2];
    }
    while(a1 != a2){
        a1 = treeFather[a1];
        a2 = treeFather[a2];
    }
    return treeLength[start] + treeLength[target] - treeLength[a1] - treeLength[a2];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> N, N){
        treeFather[0] = 0;
        treeLevels[0] = 0;
        treeLength[0] = 0;
        for(int i=1; i<N; i++){
            cin >> u >> v;
            treeFather[i] = u;
            treeLevels[i] = treeLevels[u] + 1;
            treeLength[i] = treeLength[u] + v;
        }
        cin >> Q;
        for(int i=0; i<Q; i++){
            cin >> u >> v;
            cout << cost(u, v);
            if(i < Q-1)
                cout << " ";
        }
        cout << "\n";
    }
    return 0;
}