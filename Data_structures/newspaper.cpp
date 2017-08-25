#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream cin("in.txt");
	ofstream cout("out.txt");
	int t;
	cin >> t;
	vector <int> a(128);
	while(t--){
		int n;
		cin >> n;
		fill(a.begin(), a.end(), -2);
		char current;
		for(int i=0; i<n; i++) {
			cin >> current;
			cin >> a[(int)current];
		}
		cin >> n;
		string line;
		cin.ignore();
		int counter = 0;
		for(int i=0; i<n; i++){
			getline(cin, line);
			for(int j=0; j<line.size(); j++){
				if(a[(int)line[j]] != -2) counter += a[(int)line[j]];
			}
		}
		cout << fixed << setprecision(2) << (counter/100.0) << "$\n";
	}
	return 0;
}
