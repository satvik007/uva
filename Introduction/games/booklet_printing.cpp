#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int n;
	while(cin >> n, n){
		cout << "Printing order for " << n << " pages:\n";
		if(n%4 == 0){
			for(int i=0; i<n/4; i++){
				cout << "Sheet " << (i+1) << ", front: " << (n-i*2)  << ", " << (i*2+1) << '\n';
				cout << "Sheet " << (i+1) << ", back : " << (i*2+2) << ", " << (n-1-i*2) << '\n';
			}
		}
		else if(n%4 == 1){
			cout << "Sheet " << (1) << ", front: "  << "Blank, " << (1) << '\n';
			if(n>1){
				cout << "Sheet " << (1) << ", back : " << (2) << ", Blank" << '\n';
				cout << "Sheet " << (2) << ", front: " << "Blank,"  << " " << (3) << '\n';
				cout << "Sheet " << (2) << ", back : " << (4) << ", " << (n) << '\n';
			}
			for(int i=2; i<=n/4; i++){
				cout << "Sheet " << (i+1) << ", front: " << (n - i*2+3 )  << ", " << (i*2+1) << '\n';
				cout << "Sheet " << (i+1) << ", back : " << (i*2+2) << ", " << (n - i*2-1+ 3) << '\n';
			}
		}
		else if(n%4 == 2){
			cout << "Sheet " << (1) << ", front: "  << "Blank, " << (1) << '\n';
			cout << "Sheet " << (1) << ", back : " << (2) << ", Blank" << '\n';
			for(int i=1; i<=n/4; i++){
				cout << "Sheet " << (i+1) << ", front: " << (n - i*2+2)  << ", " << (i*2+1) << '\n';
				cout << "Sheet " << (i+1) << ", back : " << (i*2+2) << ", " << (n - i*2-1+2) << '\n';
			}
		}
		else{
			cout << "Sheet " << (1) << ", front: "  << "Blank, " << (1) << '\n';
			cout << "Sheet " << (1) << ", back : " << (2) << ", " << (n) << '\n';
			for(int i=1; i<=n/4; i++){
				cout << "Sheet " << (i+1) << ", front: " << (n - i*2+1)  << ", " << (i*2+1) << '\n';
				cout << "Sheet " << (i+1) << ", back : " << (i*2+2) << ", " << (n - i*2) << '\n';
			}
		}

		
	}
	return 0;
}