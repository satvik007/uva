#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

#define maxn 1024010

int n;
int a[maxn];
int tree[4 * maxn], lazy[4 * maxn];
map <char, int> map1;

class SegmentTree {
public:
    SegmentTree() {
        memset(lazy, 0, sizeof lazy);
        build(1, 0, n-1);
    }
    int build(int p, int l, int r) {
        if(l == r) return tree[p] = a[l];
        return tree[p] = build(left(p), l, (l+r)/2) + build(right(p), (l+r)/2+1, r);
    }
    int query(int p, int l, int r, int i, int j) {
        slide(p, l, r);
        if (r < i || l > j) return 0;
        if (l >= i && r <= j) return tree[p];
        return query(left(p), l, (l + r) / 2, i, j) + query(right(p), (l + r) / 2 + 1, r, i, j);
    }
    int update(int p, int l, int r, int i, int j, int change) {
        slide(p, l, r);
        if(l > j || r < i) return tree[p];
        if(l >= i && r <= j) {
            lazy[p] = change;
            slide(p, l, r);
            return tree[p];
        }
        return tree[p] = update(left(p), l, (l+r)/2, i, j, change) + update(right(p), (l+r)/2+1, r, i, j, change);
    }
    void slide(int p, int l, int r) {
        switch(lazy[p]) {
            case 0: break;
            case 1: tree[p] = (r - l + 1); break;
            case 2: tree[p] = 0; break;
            case 3: tree[p] = (r - l + 1) - tree[p]; break;
        }
        if(l == r) {
            a[l] = tree[p];
        } else {
            force(left(p), l, (l+r)/2, lazy[p]);
            force(right(p), (l+r)/2+1, r, lazy[p]);
        }
        lazy[p] = 0;
    }
    void force(int p, int l, int r, int change) {
        if(change == 0);
        else if(change == 1) lazy[p] = 1;
        else if(change == 2) lazy[p] = 2;
        else if(change == 3) lazy[p] = 3 - lazy[p];
    }
    void clear(int p, int l, int r) {
        slide(p, l, r);
        if(l != r) {
            clear(left(p), l, (l+r)/2);
            clear(right(p), (l+r)/2+1, r);
        }
    }
    int left(int p) {return (p << 1);}
    int right(int p) {return (p << 1 | 1);}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    map1['F'] = 1;
    map1['E'] = 2;
    map1['I'] = 3;

    int tc;
    cin >> tc;

    int cas = 1;

    while(tc--) {
        cout << "Case " << cas++ << ":\n";
        int m;
        cin >> m;
        string s;
        while(m--) {
            int u; string v;
            cin >> u >> v;
            while(u--) s += v;
        }
        n = (int)s.size();
        for(int i=0; i<n; i++) {
            a[i] = s[i] - '0';
        }

        int q;
        cin >> q;

        int u, v;
        char type;
        int qnum = 1;

        SegmentTree cur;

        while(q--) {
            cin >> type >> u >> v;
            if(type == 'S') {
                cout << "Q" << qnum++ << ": " << cur.query(1, 0, n-1, u, v) << "\n";
            } else {
                cur.update(1, 0, n-1, u, v, map1[type]);
            }
        }
    }

    return 0;
}
