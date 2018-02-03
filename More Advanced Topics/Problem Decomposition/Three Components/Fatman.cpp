#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
#define EPS 1e-6
#define inf 1e9

int n, m, k;
ii a[205];

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

bool solve(double mid){
    MyUnionFind satvik(k+2);
    for(int i=0; i<k; i++){
        if(a[i].second < mid){
            satvik.unionSet(i, k);
        }
        if(m - a[i].second < mid){
            satvik.unionSet(i, k+1);
        }
        for(int j=i+1; j<k; j++){
            if(a[j].first > a[i].first + mid) break;
            if(hypot(a[i].first - a[j].first, a[i].second - a[j].second) < mid) {
                satvik.unionSet(i, j);
            }
            if(satvik.isSameSet(k, k+1)) return true;
        }
    }
    return satvik.isSameSet(k, k+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    cout << fixed << setprecision(4);
    int cas = 1;
    while(tc--){
        cin >> n >> m >> k;
        for(int i=0; i<k; i++){
            cin >> a[i].first >> a[i].second;
        }
        sort(a, a+k);
        double lo=0, mid, hi=m, ans = 0;
        while(hi - lo > EPS){
            mid = lo + (hi - lo)/2;
            if(solve(mid)){
                hi = mid;
            }
            else{
                lo = mid;
                ans = max(ans, mid);
            }
        }
        cout << "Maximum size in test case " << cas++ << " is " << ans << ".\n";
    }
    return 0;
}
