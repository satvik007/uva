#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		cin.ignore();
		string a;
		int counter = 0;
		map<string, int> map1;
		while(cin.peek() != '\n' && cin.peek() != EOF){
			getline(cin, a);
			if(map1.find(a) == map1.end()) map1[a] = 1;
			else map1[a]++;
			counter++;
		}
		for(auto iter = map1.begin(); iter != map1.end(); ++iter){
			cout << (iter)->first << " " << setprecision(4) << fixed << ((100.0 *iter->second)/counter) << "\n";
		}
		if(t!=0)cout << "\n";
	}
	return 0;
}
