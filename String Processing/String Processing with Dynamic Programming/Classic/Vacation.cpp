#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf (int)1e6

int b[105][105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    string u, v;
    int cas = 1;
	while(cin.peek() != '#'){
		getline(cin, u); getline(cin, v);
		memset(b, 0, sizeof b);
		int n = u.size(), m = v.size();
		for(int i=1; i <= n; i++){
			for(int j=1; j <= m; j++){
				b[i][j] = max(b[i-1][j-1] + (u[i-1] == v[j-1] ? 1 : -inf), max(b[i-1][j], b[i][j-1]));
			}
		}
        int ans = b[n][m];
        cout << "Case #" << cas++ << ": you can visit at most " << ans << " cities.\n";
	}
	return 0;
}