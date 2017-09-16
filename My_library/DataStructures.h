#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

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

int main(){
	ios_base::sync_with_stdio(false);
	//cin.tie(nullptr);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int V;
	cin >> V;
	vector <vi> a(V, vi(V));
	for(int i=0; i<V; i++) for(int j=0; j<V; j++) cin >> a[i][j];
	int flag = 0;
	for (int k = 0; k < V; k++)
	{
		if(flag) break;
		// Pick all vertices as source one by one
		for (int i = 0; i < V; i++)
		{
			if(flag) break;
			// Pick all vertices as destination for the
			// above picked source
			for (int j = 0; j < V; j++)
			{
				if(flag) break;
				// If vertex k is on the shortest path from
				// i to j, then update the value of dist[i][j]
				if (a[i][k] + a[k][j] < a[i][j])
					flag = 1;
			}
		}
	}
	if(flag == 1) cout << "-1\n";
	else{
		vector <pair<int, pair<int, int>>> edge(n*n);
		int k = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				edge[k++] = {a[i][j], {i, j}};
			}
		}
		sort(edge.begin(), edge.end(), greater<int> ());
		UnionFind uf(n);
		uf.unionSet()
	}
	return 0;
}