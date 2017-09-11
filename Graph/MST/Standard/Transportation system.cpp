#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;


class MyUnionFind { // OOP style
private: vi p, rank; // remember: vi is vector<int>
public:
    MyUnionFind(int N) {
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
        if (!isSameSet(i, j)) { // if from different set
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, k, u, v, cas = 1, states, num;
    double rails, roads;
    cin >> t;
    vector <complex<double>> a;
    vector< pair<double, ii>> EdgeList;
    while(t--){
        cout << "Case #" << cas << ": ";
        cas++;
        cin >> n >> k;
        a.resize(n);
        for(int i=0; i<n; i++){
            cin >> u >> v;
            a[i] = {u, v};
        }
        int size = n*(n-1)/2;
        EdgeList.resize(size);
        int m = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                EdgeList[m++] = {abs(a[i]-a[j]), {i, j}};
            }
        }
        sort(EdgeList.begin(), EdgeList.end());
        rails = 0; roads = 0; states = 1; num = 0;
        MyUnionFind UF(n); 
        for (int i = 0; i < size; i++) { 
            pair<double, ii> front = EdgeList[i];
            if (!UF.isSameSet(front.second.first, front.second.second)) {
				num++;
				if(front.first > k){
                    states++;
                    rails += front.first;
                }
                else roads+= front.first;
                //mst_cost += front.first;
                UF.unionSet(front.second.first, front.second.second); 
            }
            if(num == n-1) break;
        }
        cout << states << " " << (int)(roads+0.5) << " " << (int)(rails+0.5) << endl;

    }
}
