#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

int binary_gcd(int u, int v){
  int shl = 0;
  while ( u && v && u!=v ) {
    bool eu = !(u & 1);
    bool ev = !(v & 1);

    if ( eu && ev ) {
      ++shl;
      u >>= 1;
      v >>= 1;
    }
    else if ( eu && !ev ) u >>= 1;
    else if ( !eu && ev ) v >>= 1;
    else if ( u>=v ) u = (u-v)>>1;
    else {
      int tmp = u;
      u = (v-u)>>1;
      v = tmp;
    }
  }
  return !u? v<<shl : u<<shl;
}

int main(){
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int n;
	int cas = 1;
	while(cin >> n, n){
		vi a(n);
		for(int i=0; i<n; i++) cin >> a[i];
		int counter = 0;
		for(int i=0; i<n; i++) counter += a[i];
		cout << "Case " << cas << ":" << endl;
		if(counter >= 0){
			int div = binary_gcd(counter, n);
			counter /= div;
			n /= div;
			int quo = counter/n;
			int rem = counter%n;
			string rems = to_string(n);
			if(counter % n == 0) cout << (counter / n) << endl;
			else if(counter < n){
				cout << setw(rems.size()) << rem << endl;
				for(int i=0; i<rems.size(); i++) cout << "-"; cout << endl;
				cout << n << endl;
			}
			else{
				string quos = to_string(quo);
				cout << setw(quos.size() + rems.size()) << rem << endl;
				cout << quo;
				for(int i=0; i<rems.size(); i++) cout << "-"; cout << endl;
				cout << setw(quos.size()+rems.size()) << n << endl;
			}
		}
		else{
			counter = -counter;
			int div = binary_gcd(counter, n);
			counter /= div;
			n /= div;
			int quo = counter/n;
			int rem = counter%n;
			string rems = to_string(n);

			if(counter % n == 0) cout << "- " << (counter / n) << endl;
			else if(counter < n){
				cout << setw(rems.size()+2) << rem << endl;
				cout << "- "; for(int i=0; i<rems.size(); i++) cout << "-"; cout << endl;
				cout << "  " << n << endl;
			}
			else{
				string quos = to_string(quo);
				cout << setw(quos.size() + rems.size()+2) << rem << endl;
				cout << "- " << quo;
				for(int i=0; i<rems.size(); i++) cout << "-"; cout << endl;
				cout << setw(quos.size()+rems.size()+2) << n << endl;
			}
		}
		cas++;
	}
}