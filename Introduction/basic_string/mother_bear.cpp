#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin("in.txt");
	ofstream cout("out.txt");
	string a;
	while(1){
		getline(cin, a);
		if(a == "DONE") break;
		string b;
		for(int i=0; i<a.size(); i++){
			if(a[i]>='a' && a[i] <= 'z' || a[i]>='A' && a[i]<='Z'){
				b += a[i];
			}
		}
		int flag = 0;
		for(int i=0; i <= b.size()/2; i++) if(std::tolower(b[i]) != std::tolower(b[b.size()-i-1])) flag = 1;
		if(flag == 0) cout << "You won't be eaten!\n";
		else cout << "Uh oh..\n";
		//cout << b << endl;
	}
}