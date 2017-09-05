#include <bits/stdc++.h>

using namespace std;
typedef vector <int> vi;

class SegmentTree{
private: vi A, st;
public:
    int n;
    SegmentTree(const vi &_A){
        A = _A; n = A.size();
        st.assign(4*n, 0);
        build(1, 0, n-1);
    }
    int left(int p) {return (p<<1);}
    int right(int p) {return ((p<<1)+1);}
    int build(int p, int L, int R){
        if(L==R) return st[p] = A[L];
        return st[p] = max(build(left(p), L, (L+R)/2), build(right(p), (L+R)/2+1, R));
    }
    int rmq(int p, int L, int R, int i, int j) {
        if (i > R || j < L) return -1;
        if (L >= i && R <= j) return st[p];
        return max(rmq(left(p), L, (L+R)/2, i, j), rmq(right(p), (L+R)/2+1, R, i, j));
    }
    int rmq(int i, int j){return rmq(1, 0, n-1, i, j);}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, q;
    int u, v;
    while(cin >> n, n){
        cin >> q;
        vi a(n);
        vi start(n);
        vi count(n);
        for(int i=0; i<n; i++) cin >> a[i];
        int last = 0;
        int counter = 0;
        for(int i=0; i<n; i++){
            if(a[i] != a[last]){
                int j = i;
                while(j>=0 && j!= last-1){
                    count[j--] = counter;
                }
                last = i;
                counter = 1;
            }
            else counter++;
            start[i] = last;
        }
        int j = n-1;
        while(j!=0 && j!= last-1){
            count[j--] = counter;
        }
        //for(auto el:a) cout << el << " "; cout << endl;
        //for(auto el:start) cout << el << " "; cout << endl;
        //for(auto el:count) cout << el << " "; cout << endl;
        SegmentTree seg(count);
        for(int i=0; i<q; i++){
            cin >> u >> v;
            u--; v--;
            if(a[u] == a[v]) cout << (v-u+1) << "\n";
            else{
                int k = start[u] + count[u];
                int cnt1 = k - u;
                int cnt2 = v - start[v]+1;
                int cnt3 = seg.rmq(k, start[v]-1);
                cout << max((int)max(cnt1, cnt2), cnt3) << "\n";
            }
        }
    }
}
