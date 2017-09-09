#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

const int N = 100005;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] * t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] * t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
    int res = 1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res *= t[l++];
        if (r&1) res *= t[--r];
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int m;
    int u, v;
    int temp;
    char type;
    while(cin >> n >> m){
        for(int i=0; i<n; i++){
            cin >> temp;
            t[i+n] = sgn(temp);
        }
        build();
        string ans;
        for(int i=0; i<m; i++){
            cin >> type >> u >> v;
            if(type == 'C'){
                modify(u-1, sgn(v));
            } 
            else{
                switch(query(u-1, v)){
                    case 1: ans += '+'; break;
                    case -1: ans += '-'; break;
                    case 0: ans += '0'; break;
                    default: break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
