#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

vi match, vis;
vector <vi> adjList;

int Aug(int l){
    if(vis[l])
        return 0;
    vis[l] = 1;
    for(int j=0; j<adjList[l].size(); j++){
        int r = adjList[l][j];
        if(match[r] == -1 || Aug(match[r])){
            match[r] = l;
            return 1;
        }
    }
    return 0;
}

int sx[505], sy[505], dx[505], dy[505], traveltime[505], times[505];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc, V, VLeft;
    int n;
    int h, m;
    cin >> tc;
    while(tc--){
        cin >> n;
        V = 2*n;
        VLeft = n;
        adjList.assign(V, vi());
        char null;
        for(int i=0; i<n; i++){
            cin >> h >> null >> m >> sx[i] >> sy[i] >> dx[i] >> dy[i];
            times[i] = h * 60 + m;
            traveltime[i] = abs(sx[i] - dx[i]) + abs(sy[i] - dy[i]);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int transtime = abs(dx[i] - sx[j]) + abs(dy[i] - sy[j]);
                if(times[j] > times[i] + traveltime[i] + transtime){
                    adjList[i].push_back(j+n);
                }
            }
        }
        int MCBM = 0;
        match.assign(V, -1);
        for(int l=0; l<VLeft; l++){
            vis.assign(VLeft, 0);
            MCBM += Aug(l);
        }
        cout << (n - MCBM) << "\n";
    }

    return 0;
}