#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	ll n;
	while(cin >> n, n){
		bitset <32> a(n);
		int flag = 0;
		ll b=0, c=0;
		for(int i=0; i<32; i++){
			if(a[i] == 1){
				if(flag == 0){
					b ^= (1<<i);
					flag = 1;
				}
				else {
					c ^= (1 << i);
					flag = 0;
				}
			}
		}
		cout << b << " " << c << "\n";
		
	}
	return 0;
}
