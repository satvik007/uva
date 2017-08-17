#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
// ‘r’, ‘k’, ‘Q’, ‘K’
int main(){
	//ifstream cin ("in.txt");
	//ofstream cout ("out.txt");
	int t;
	cin >> t;
	while(t--){
		char piece;
		int m, n;
		cin >> piece >> m >> n;
		if(piece == 'r') cout << min(m, n) << endl;
		else if(piece == 'k'){
			cout << ((m*n+1)/2) << endl;
		}
		else if(piece == 'Q'){
			cout << min(m, n) << endl;
		}
		else if(piece == 'K'){
			cout << (((m+1)/2) * ((n+1)/2)) << endl;
		}
	}
}
