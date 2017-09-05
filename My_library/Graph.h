#ifndef GRAPH_H
#define GRAPH_H
#define <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
//memset(memo, -1, sizeof memo); // initialize DP memoization table with -1
//memset(arr, 0, sizeof arr);



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
#endif
