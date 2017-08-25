#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int t;
	cin >> t;
	//players, snakes, and dice rolls
	int a, b, c;
	while(t--){
		cin >> a >> b >> c;
		vi pos(a);
		fill(pos.begin(), pos.end(), 1);
		vi snakes(105);
		fill(snakes.begin(), snakes.end(), -1);
		int u, v;
		for(int i=0; i<b; i++) {
			cin >> u >> v;
			snakes[u] = v;
		}
		vi dice(c);
		for(int i=0; i<c; i++) cin >> dice[i];
		for(int i=0; i<c; i++){
			pos[i%a] += dice[i];
			if(snakes[pos[i%a]] != -1) pos[i%a] = snakes[pos[i%a]];
			if(pos[i%a] >= 100) {
				pos[i%a] = 100;
				break;
			}
		}
		for(int i=0; i<a; i++){
			cout << "Position of player " << (i+1) << " is " << pos[i] << ".\n";
		}
	}
}
