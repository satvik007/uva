#include <bits/stdc++.h>
using namespace std;

bool satvik(char a, char b){
	if(tolower(a) < tolower(b)) return true;
	else if(std::tolower(a) == std::tolower(b)){
		if(a<b) return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream cin("in.txt");
	ofstream cout("out.txt");
	int n;
	cin >> n;
	vector <string> a(n);
	for(int i=0; i<n; i++){
		 cin >> a[i];
		 sort(a[i].begin(), a[i].end(), satvik);
	}
	for(int i=0; i<n; i++){
		bool flag = true;
		int j=0;
		while(flag){
			cout << a[i] << '\n';
			flag = next_permutation(a[i].begin(), a[i].end(), satvik);
			j++;
			if(j>1000) break;
		}
	}
	return 0;
}