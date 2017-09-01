#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream cin("in.txt");
	ofstream cout("out.txt");
	string a;
	int cas = 1;
	while(cin >> a){
		if(a == "end") break;
		cout << "Case " << cas << ": ";
		vector <int> status(26);
		fill(status.begin(), status.end(), -1);
		for(int i=a.size()-1; i>=0; i--){
			if(status[a[i]-'A'] == -1) status[a[i]-'A'] = i;
		}
		cas++;
	}
}
