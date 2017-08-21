#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;
		if(b>a || (a+b)%2 == 1) cout << "impossible" << endl;
		else{
			cout << ((a+b)/2) << " " << ((a-b)/2) << endl;
		}
	}
}