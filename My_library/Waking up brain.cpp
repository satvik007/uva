#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

map <char, int> map1;

class UnionFind {
public:
    vi p, rank;
    explicit UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i) {
        while(i != p[i]) p[i] = p[p[i]], i = p[i];
        return i;
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, m;
    string wake;
    string temp;
    while(cin >> n >> m){
        cin >> wake;
        int k = 0;
        UnionFind a(n);
        map1.clear();
        for(int i=0; i<m; i++){
            cin >> temp;
            if(map1.find(temp[0]) == map1.end()) map1[temp[0]] = k++;
            if(map1.find(temp[1]) == map1.end()) map1[temp[1]] = k++;
            a.unionSet(map1[temp[0]], map1[temp[1]]);
        }
        vi b;
        b.push_back(map1[wake[0]]); b.push_back(map1[wake[1]]);
        b.push_back(map1[wake[2]]);
        int flag = 1;
        int time = 0;
        while(flag == 1){
            time++;
            flag = 0;
            for(int i=0; i<n; i++){
                vi status(n);
                status.assign(n, 0);
                if(find(b.begin(), b.end(), i) == b.end())
                    for(int j=0; j<b.size(); j++){
                        if(a.p[i] == b[j] || a.p[b[j]] == i) status[i]++;
                    }
                if(status[i] >= 3) b.push_back(i), flag = 1;
            }
        }
        if(b.size() == n) cout << "WAKE UP IN, " << time << ", YEARS\n";
        else cout << "THIS BRAIN NEVER WAKES UP\n";
    }
    return 0;
}
