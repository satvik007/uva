#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, m, k;
	vi a, b;
	vector <double> c, d;
	while(cin >> n, n){
		cin >> m;
		a.resize(n); b.resize(m);
		for(int i=0; i<n; i++) cin >> a[i];
		for(int j=0; j<m; j++) cin >> b[j];
		c.resize(n*m);
		k = 0;
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				c[k++] = b[i]*1.0/a[j];
			}
		}
		sort(c.begin(), c.end());
		d.resize(n*m-1);
		for(int i=1; i<m*n; i++){
			d[i-1] = c[i]/c[i-1];
		}
		cout << fixed << setprecision(2) << *max_element(d.begin(), d.end()) << "\n";
	}
}
