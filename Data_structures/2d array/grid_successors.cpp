#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

vector <vector <bool>> a(3, vector <bool> (3));

int func(){
	vector <vector <bool>> temp(a);
	a[0][0] = temp[1][0] ^ temp[0][1];
	a[2][2] = temp[2][1] ^ temp[1][2];
	a[0][2] = temp[1][2] ^ temp[0][1];
	a[2][0] = temp[1][0] ^ temp[2][1];
	a[0][1] = temp[0][0] ^ temp[0][2] ^ temp[1][1];
	a[1][0] = temp[0][0] ^ temp[2][0] ^ temp[1][1];
	a[2][1] = temp[2][0] ^ temp[2][2] ^ temp[1][1];
	a[1][2] = temp[0][2] ^ temp[2][2] ^ temp[1][1];
	a[1][1] = temp[1][2] ^ temp[1][0] ^ temp[0][1] ^ temp[2][1];
	if(a == temp) return 0;
	else return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int t;
	cin >> t;
	vector <string> b(3);
	while(t--){
		for(int i=0; i<3; i++) cin >> b[i];
		for(int i=0; i<3; i++) for(int j=0; j<3; j++) a[i][j] = b[i][j]-'0';
		int index = -1;
		while(func()){
			index++;
		} 
		cout << index << endl;
	}
	return 0;
}
