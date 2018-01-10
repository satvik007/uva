#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m, nS, mxS;
ll AdjMat[65];

void rec(int i, ll used, int depth) {
    if (used == (1LL << n) - 1) {
        nS++;
        mxS = max(mxS, depth);
    }
    else {
        for (int j = i; j < n; j++)
            if (!(used & (1LL << j)))
                rec(j + 1, used | AdjMat[j], depth + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--){
        cin >> n >> m; mxS = 0; nS = 0;
        memset(AdjMat, 0, sizeof AdjMat);
        int u, v;
        for (int i = 0; i < n; i++)
            AdjMat[i] = (1LL << i);
        for(int i=0; i<m; i++){
            cin >> u >> v;
            AdjMat[u] |= (1LL << v);
            AdjMat[v] |= (1LL << u);
        }
        rec(0, 0, 0);
        cout << nS << "\n" << mxS << "\n";
    }
    return 0;
}