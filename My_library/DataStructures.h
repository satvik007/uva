#ifndef DATA_H
#define DATA_H
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

class MyUnionFind { // OOP style
private: vi p, rank; // remember: vi is vector<int>
public:
	UnionFind(int N) { 
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

class SegmentTree {
private: 
	vi st, A;
	int n;
	int left (int p) { return p << 1; }
	int right(int p) { return (p << 1) + 1; }
	void build(int p, int L, int R) {
		if (L == R)
		st[p] = L;
		else {
			build(left(p) , L , (L + R) / 2);
			build(right(p), (L + R) / 2 + 1, R );
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = (A[p1] <= A[p2]) ? p1 : p2;
		} 
	}
	int rmq(int p, int L, int R, int i, int j) {
		if (i > R || j < L) return -1;
		if (L >= i && R <= j) return st[p];
		int p1 = rmq(left(p) , L , (L+R) / 2, i, j);
		int p2 = rmq(right(p), (L+R) / 2 + 1, R , i, j);
		if (p1 == -1) return p2;
		if (p2 == -1) return p1;
		return (A[p1] <= A[p2]) ? p1 : p2;
	}
public:
	SegmentTree(const vi &_A) {
		A = _A; n = (int)A.size();
		st.assign(4 * n, 0);
		build(1, 0, n - 1);
	}
	int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
};

const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}
#define  LSOne(S) (S & (-S))
class FenwickTree {
private: vi ft;
public: 
	FenwickTree(int n) {
		ft.assign(n + 1, 0); 
	}
	int rsq(int b) { // returns RSQ(1, b)
		int sum = 0;
		for (; b; b -= LSOne(b)) sum += ft[b];
		return sum; 
	}
	int rsq(int a, int b) { // returns RSQ(a, b)
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); 
	}
	void adjust(int k, int v) { // note: n = ft.size() - 1
		for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; 
	}
};

#endif
