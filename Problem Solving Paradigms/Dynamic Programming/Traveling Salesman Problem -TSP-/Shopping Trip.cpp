#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf 1000000000

int n, m, p, best;
int dist[60][60], temp[60], shop[60], price[60], dp[13][1<<13];
int final;

int tsp(int index, int bitmask){
	if(dp[index][bitmask] != -inf) return dp[index][bitmask];
	int max1 = -dist[shop[index]][0];
	for(int i=0; i<p; i++){
		if(!(bitmask & (1<<i))){
			max1 = max(max1, price[i]-dist[shop[index]][shop[i]]+tsp(i, bitmask|(1<<i)));
		}
	}
	dp[index][bitmask] = max1;
    return max1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t;
	cin >> t;
	cout << fixed << setprecision(2);
	while(t--){
		int x, y;
		char null;
		cin >> n >> m;
		for(int i=0; i<=n; i++){
			for(int j=0; j<=n; j++) dist[i][j] = inf;
			dist[i][i] = 0;
		}
		int u, v;
		double w;
		for(int i=0; i<m; i++){
			cin >> u >> v >> x >> null >> y;
			dist[u][v] = min(dist[u][v], (int)(x*100+y));
			dist[v][u] = dist[u][v];
		}
		for(int k=0; k<=n; k++)
			for(int i=0; i<=n; i++)
				for(int j=0; j<=n; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		cin >> p;
		memset(temp, 0, sizeof(temp));
		for(int i=0; i<p; i++){
			cin >> u >> x >> null >> y;
			temp[u] += (int)(x*100+y);
		}
		int k = 0;
		for(int i=0; i<=n; i++){
			if(temp[i]){
				price[k] = temp[i]; shop[k] = i; k++;
			}
		}
		p = k;
		best = 0;
		final = (1<<p)-1;
		for(int i=0; i<=p; i++)
			for(int j=0; j<=final; j++)
				dp[i][j] = -inf;
		for(int i=0; i<p; i++){
			best = max(best, price[i] - dist[shop[i]][0] + tsp(i, 1<<i));
		}
		if(best == 0) cout << "Don't leave the house\n";
		else cout << "Daniel can save $" << (best/100.0) << "\n";
	}
}
