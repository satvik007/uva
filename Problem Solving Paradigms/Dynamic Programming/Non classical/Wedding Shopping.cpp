#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int g, money, k, TC, M, C;
    int price[25][25]; 
    bool reachable[25][210];
    cin >> TC;
    while (TC--) {
        cin >> M >> C;
        for (g = 0; g < C; g++) {
            cin >> price[g][0];
            for (money = 1; money <= price[g][0]; money++)
                cin >> price[g][money];
    	}
    memset(reachable, false, sizeof reachable); 
    for (g = 1; g <= price[0][0]; g++) 
    	if (M - price[0][g] >= 0) // to prevent array index out of bound
    		reachable[0][M - price[0][g]] = true; // using first garment g = 0
    for (g = 1; g < C; g++) // for each remaining garment
        for (money = 0; money < M; money++) if (reachable[g-1][money])
            for (k = 1; k <= price[g][0]; k++) if (money - price[g][k] >= 0)
                reachable[g][money - price[g][k]] = true; // also reachable now
        for (money = 0; money <= M && !reachable[C - 1][money]; money++);
    if (money == M + 1) cout << "no solution\n"; // last row has no on bit
    else cout << (M - money) << "\n";
    }
    return 0;
}
