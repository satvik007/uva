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

class UnionFind {
private: vi p, rank;
public:
	UnionFind(int N) { 
		rank.assign(N, 0);
		p.assign(N, 0); 
		for (int i = 0; i < N; i++) p[i] = i; 
	}
	int findSet(int i) { 
		return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
	}
	bool isSameSet(int i, int j) { 
		return findSet(i) == findSet(j); 
	}
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			// if from different set
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) p[y] = x;
			// rank keeps the tree short
			else {
				p[x] = y;
				if (rank[x] == rank[y]) rank[y]++; 
			}
		} 		
	} 
};


#endif