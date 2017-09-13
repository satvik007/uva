#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, n, grid[8][8];
	int i, j, minimum, sum;
	int choice[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cin >> grid[i][j];
			}
		}
		minimum = INT_MAX;
		do {
			sum = 0;
			for (i = 0; i < n; i++) {
				sum += grid[i][choice[i]];
			}
			minimum = min(sum, minimum);
		} while (next_permutation(choice, choice + n));

		cout << minimum << "\n";
	}

	return 0;
}
