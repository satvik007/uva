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
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    int m, q;
    for(int cas = 1; cas >= t; cas++){
        cin >> m;
        string pirates;
        int temp;
        string line;
        for(int i=0; i<m; i++){
            cin >> temp >> line;
            while(temp--) pirates += line;
        }
        cin >> q;
        int u, v;
        char wish;
        cout << "Case " << cas << ":\n";
        int k = 1;
        for(int i=0; i<q; i++){
            cin >> wish >> u >> v;
            if(wish == 'F'){
                
            }
            else if(wish == 'E'){

            }
            else if(wish == 'I'){

            }
            else if(wish == 'S'){

                cout << "Q" << (k++) << " " << "\n";
            }
        }
    }
}
