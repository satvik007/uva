#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

vector <int> a;

class node{
public:
	int value, len;
	char op;
};

class SegmentTree{
private: vi A;
	vector <node> st;
	int n;
public:
    int left(int p) {return (p << 1);}
    int right(int p) {return ((p << 1)|1);}
	explicit SegmentTree(){
		n = a.size();
		st.resize(4*n);	
        build(1, 0, n-1);
	}
    int build(int p, int L, int R){
        st[p].len = R-L+1;
        st[p].op = -1;
        if(L == R) return st[p].value = a[L];
        else return st[p].value = build(left(p), L, (L+R)/2) + build(right(p), (L+R)/2, R); 
    }
    int rmq(int p, int L, int R, int i, int j){
        apply_update(p, i, j);
        if(j<L || i>R) return 0;
        if(i<=L && j>=R) return st[p].value;
        return rmq(left(p), L, (L+R)/2, i, j) + rmq(right(p), (R+L)/2+1, R, i, j);
    }
    int rmq(int i, int j){
        return rmq(1, 0, n-1, i, j);
    }
    void update(int p, int L, int R, int u, int v, char wish){
        if(j<L || i>R) return;
        if(i<=L && j>=R) return;
        update(left(p)
    }
    void update(int i, int j, char wish){return update(1, 0, n-1, i, j, wish);}
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
            u--; v--;
            if(wish == 'S') cout << "Q" << (k++) << " " << seg.rmq(u, v) << "\n";
            else update(u, v, wish);   
        }
    }
}
