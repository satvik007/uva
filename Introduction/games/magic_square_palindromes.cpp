#include <bits/stdc++.h>
using namespace std;

void print(vector <string> &a, ostream &cout){
	for(int i=0; i<a.size(); i++) cout << a[i] << endl;
	cout << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int t;
	cin >> t;
	cin.ignore();
	for(int cas = 1; cas <= t; cas++){
		string a;
		getline(cin, a);
		string b;
		for(int i=0; i<a.size(); i++) if(a[i] >= 'a' && a[i] <= 'z') b += a[i];
		//cout << b << endl;
		int len = b.size();
		int k = (int)pow(len, 0.5);
		int flag = 0;
		if(k*k != len) flag = 1;
		else {
			
			vector <string> data(k);
			for(int i=0; i<k; i++){
				data[i] = b.substr(i*k, k);
			}
			vector <string> cases(4);
			cases[0] = data[0];
			cases[3] = data[k-1];
			reverse(cases[3].begin(), cases[3].end());
			for(int i=0; i<k; i++){
				cases[2] += data[k-1-i][k-1];	
				cases[1] += data[i][0];
			}
			//print(data, cout);
			//print(cases, cout);
			for(int i=0; i<4; i++) if(cases[i] != cases[0]) flag = 1;
		}
		cout << "Case #" << cas << ":\n";
		if(flag == 0) cout << k << endl;
		else cout << "No magic :(" << endl;
	}
	return 0;
}