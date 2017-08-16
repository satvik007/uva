#include <bits/stdc++.h>
using namespace std;

int main(){
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int m, n;
	while(cin >> m >> n, m||n){
		int a = min(m, n);
		int b = max(m, n);
		if(a == 0) cout << "0 knights may be placed on a " << m << " row " << n << " column board." << endl;
		if(a == 1) cout << b << " knights may be placed on a " << m << " row " << n << " column board."<< endl;
		else if(a == 2){
			if(b%4 == 1) cout << (b+1) << " knights may be placed on a " << m << " row " << n << " column board."<< endl;
			else cout << ((b+2)/4*4) << " knights may be placed on a " << m << " row " << n << " column board."<< endl;
		}
		//else if(a == 3){
		//	if(b%4 == 1) cout << (b+1) << " knights may be placed on a " << m << " row " << n << " column board."<< endl;
		//	else cout << ((b+2)/4*4) << " knights may be placed on a " << m << " row " << n << " column board."<< endl;
		//}
		else cout << ((m*n+1)/2) << " knights may be placed on a " << m << " row " << n << " column board."<< endl;
	}
}