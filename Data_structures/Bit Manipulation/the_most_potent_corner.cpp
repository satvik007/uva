#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int n;
	while(cin >> n){
		int size = (int)pow(2, n);
		vector <int> a(size);
		for(int i=0; i<size; i++) cin >> a[i];
		vector <int> b(size);
		fill(b.begin(), b.end(), 0);
		for(int i=0; i<size; i++){
			for(int j=0; j<n; j++){
				b[i] += a[i^(1<<j)];
			}
		}
		int max1 = 0;
		for(int i=0; i<size; i++){
			for(int j=0; j<n; j++){
				if(max1 < b[i] + b[i^ (1<<j)]) max1 = b[i]+b[i^(1<<j)];
			}
		}
		cout << max1 << endl;
	}
	return 0;
}
