#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	string a;
	while(cin >> a){
		if(a == "#") break;
		cout << (next_permutation(a.begin(), a.end()) ? a :"No Successor") << "\n";
	}
	return 0;
}