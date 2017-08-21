#include <bits/stdc++.h>
using namespace std;

inline void func(vector <string> &a, ostream &cout){
	int n = a.size();
	vector <string> b(n);
	for(int i=0; i<n; i++){
		for(int j=0; j<a[i].size(); j++) if(a[i][j] != ' ') b[i] += a[i][j];
		sort(b[i].begin(), b[i].end());
	}
	//for(int i=0; i<n; i++) cout << b[i] << endl;	
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(b[i] == b[j]){
				cout << a[i] << " = " << a[j] << endl;
			}
		}
	}
	return;
}
int main(){
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	cin.ignore(); cin.ignore();
	while(t--){
		vector <string> a;
		string line;
		int index = 0;
		while(1){
			getline(cin, line);
			if(line.empty()) break;
			a.push_back(line);
			index++;
		}
		sort(a.begin(), a.end());
		func(a, cout);
		if(t != 0) cout << '\n';
	}
	return 0;
}