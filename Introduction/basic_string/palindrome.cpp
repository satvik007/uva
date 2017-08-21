#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin("in.txt");
	ofstream cout("out.txt");
	string a;
	vector <int> val(128);
	fill(val.begin(), val.end(), -1);
	val['A'] = 'A';
	val['E'] = '3';
	val['H'] = 'H';
	val['I'] = 'I';
	val['J'] = 'L';
	val['L'] = 'J';
	val['M'] = 'M';
	val['O'] = 'O';
	val['S'] = '2';
	val['T'] = 'T';
	val['U'] = 'U';
	val['V'] = 'V';
	val['W'] = 'W';
	val['X'] = 'X';
	val['Y'] = 'Y';
	val['Z'] = '5';
	val['1'] = '1';
	val['2'] = 'S';
	val['3'] = 'E';
	val['5'] = 'Z';
	val['8'] = '8';
	while(cin >> a){
		int flag1 = 0;
		int flag2 = 0;
		int n = a.size();
		for(int i=0; i<=n/2; i++) if(a[i] != a[n-1-i]) flag1 = 1;
		for(int i=0; i<=n/2; i++) if(val[a[i]] != a[n-1-i]) flag2 = 1;
		if(flag1 == 0 && flag2 == 0) cout << a << " -- is a mirrored palindrome.\n";
		else if(flag1 == 1 && flag2 == 0) cout << a << " -- is a mirrored string.\n";
		else if(flag1 == 0 && flag2 == 1) cout << a << " -- is a regular palindrome.\n";
		else cout << a << " -- is not a palindrome.\n";
		cout << endl;
	}
}