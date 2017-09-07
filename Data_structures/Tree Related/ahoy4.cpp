#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

class Node{
public:
    int value, len=1;
    char utype =-1;
};

class SegmentTree{
public:
    vector <Node> tree;
    vi a;
    int n;
    static const int maxn = 1024010;
    int left(int p){return (p<<1);}
    int right(int p){return ((p<<1)|1);}
    explicit SegmentTree(vi &_A){
        a = _A;
        n = a.size();
        tree.resize(4*maxn);
        build(1, 0, n-1);
    }
    void build (int p, int L, int R){
        tree[p].len = R-L+1;
        if(L == R) tree[p].value = a[L];
        else{
            build(left(p), L, (L+R)/2);
            build(right(p), (L+R)/2+1, R);
            tree[p].value = tree[left(p)].value + tree[right(p)].value;
        }
    }
    int query(int p, int L, int R, int i, int j){
        change(p);
        if(L>j || R<i) return 0;
        if(L>=i && R<=j) return tree[p].value;
        int p1 = query(left(p), L, (L+R)/2, i, j);
        int p2 = query(right(p), (L+R)/2+1, R, i, j);
        tree[p].value = tree[left(p)].value + tree[right(p)].value;
        return p1 + p2;
    }
    int query(int i, int j){return query(1, 0, n-1, i, j);}
    void modify(int i, int j, char type){modify(1, 0, n-1, i, j, type);}
    void modify(int p, int L, int R, int i, int j, char type){
        if(L >= i && R <= j) set_utype(p, type);
        change(p);
        if(L>=i && R <= j) return;
        if(L>j || R<i) return;
        modify(left(p), L, (L+R)/2, i, j, type);
        modify(right(p), (L+R)/2+1, R, i, j, type);
        tree[p].value = tree[left(p)].value + tree[right(p)].value;
    }
    void set_utype(int p, char type){
        if(type == 'I'){
            switch(tree[p].utype){
                case 'F': tree[p].utype = 'E'; break;
                case 'E': tree[p].utype = 'F'; break;
                case 'I': tree[p].utype = -1; break;
                case -1: tree[p].utype = 'I'; break;
                default : break;
            }
        }
        else tree[p].utype = type;
    }
    void change(int p){
        switch(tree[p].utype){
            case 'F': tree[p].value = tree[p].len; break;
            case 'E': tree[p].value = 0; break;
            case 'I': tree[p].value = tree[p].len - tree[p].value; break;
            default: return;
        }
        set_utype(left(p), tree[p].utype);
        set_utype(right(p), tree[p].utype);
        tree[p].utype = -1;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int cases;
    cin >> cases;
    size_t m, u, v;
    string line;
    for(int cas = 1; cas <= cases; cas++){
        string b;
        cout << "Case " << cas << ":\n";
        int k = 1;
        cin >> m;
        while(m--){
            cin >> u >> line;
            while(u--) b += line;
        }
        vi a(b.size());
        for(int i=0; i<a.size(); i++) a[i] = b[i]-'0';
        SegmentTree seg(a);
        cin >> m;
        char type;
        while(m--){
            cin >> type >> u >> v;
            if(type == 'S') cout << "Q" << (k++) << ": " << seg.query(u, v) << "\n";
            else seg.modify(u, v, type);
        }
    }
}
