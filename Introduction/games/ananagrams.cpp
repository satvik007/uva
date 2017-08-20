#include <bits/stdc++.h>
using namespace std;

int main(){
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	vector <string> b;
	string word;
	while(cin >> word){ if(word == "#") break; b.push_back(word); }
	sort(b.begin(), b.end());
	vector <string> a(b);
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<a[i].size(); j++){
			if(a[i][j] <= 'Z') a[i][j] += -'A'+'a';
		}
	}
	//for(int i=0; i<a.size(); i++) cout << a[i] << endl;
	for(int i=0; i<a.size(); i++) sort(a[i].begin(), a[i].end());
	//for(int i=0; i<a.size(); i++) cout << a[i] << endl;
	vector <bool> status(a.size());
	fill(status.begin(), status.end(), true);
	map <string , int> map1;
	for(int i=0; i<a.size(); i++){
		if(map1.find(a[i]) != map1.end()){
			status[map1[a[i]]] = false;
			status[i] = false;
		}
		else map1[a[i]] = i;
	}
	for(int i=0; i<status.size(); i++) if(status[i] == true) cout << b[i] << endl;
	return 0;
}
