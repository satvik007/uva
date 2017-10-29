#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef complex <double> point;
typedef pair<int, int> ii;
typedef pair<double, ii> dii;
int k, n;
vector <point> data;
vector <dii> a;

class UFDS {
private:
    vector<int> p, rank, setSizes;
    int numSets;
public:
    UFDS(int N) {
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
        setSizes.assign(N, 1);
    }
    int findSet(int i) {
        while(p[i] != i) p[i] = p[p[i]], i = p[i];
        return i;
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) {
                setSizes[findSet(x)] += setSizes[findSet(y)];
                p[y] = x;
            } else {
                setSizes[findSet(y)] += setSizes[findSet(x)];
                p[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;
            }
            numSets--;
        }
    }
    int setSize(int i) {
        return setSizes[findSet(i)];
    }
    int numDisjointSets() {
        return numSets;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, u, v;
    cin >> t;
    cout << fixed << setprecision(2);
    while(t--){
        cin >> k >> n;
        a.clear();
        data.clear(); data.resize(n);
        for(int i=0; i<n; i++){
            cin >> u >> v;
            data[i].real(u); data[i].imag(v);
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                a.push_back(make_pair(abs(data[i]-data[j]),ii(i,j)));
            }
        }
        UFDS seg(n);
        sort(a.begin(), a.end());
        int size = n*(n-1)/2;
        double ans=-1;
        for(int i=0; i<size && seg.numDisjointSets() > k; i++){
            dii front = a[i];
            if(!seg.isSameSet(front.second.first, front.second.second)){
                ans = front.first;
                seg.unionSet(front.second.first, front.second.second);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
