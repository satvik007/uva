#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream cin("in.txt");
	ofstream cout("out.txt");
	int n, m;
	while(cin >> n >> m, n||m){
		vector <string> a(n);
		vector <string> b(m);
		for(int i=0; i<n; i++) cin >> a[i];
		for(int i=0; i<m; i++) cin >> b[i];
		vi counter(4);
		fill(counter.begin(), counter.end(), 0);
		vi flag(4);
		for(int row = 0; row<n-m; row++){
			for(int col=0; col<n-m; col++){
				fill(flag.begin(), flag.end(), 0);
				for(int i=0; i<m; i++){
					for(int j=0; j<m; j++){
						if(a[row+i][col+j] != b[i][j]) flag[0] = 1;
						if(a[row+i][col+j] != b[i][m-1-j]) flag[1] = 1;
						if(a[row+i][col+j] != b[m-1-i][m-1-j]) flag[2] = 1;
						if(a[row+i][col+j] != b[i][j]) flag[3] = 1;
					}	
				}
				for(int i=0; i<4; i++){
					if(flag[i] == 0) counter[i]++;
				}
				//if(flag[0] == 0) counter[0]++;
			}
		}
		for(int i=0; i<4; i++) cout << counter[i] << " "; cout << endl;
		
	}
	return 0;
}
