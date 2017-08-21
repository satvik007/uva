#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

void func(vector <string> &a, string begin, string end, ostream &cout){
	if(begin == end){
		cout << begin << endl;
		return;
	}
	int index = 0;
	for(int i=0; i<begin.size(); i++){
		if(begin[i] != end[i]){
			index = i;
			break;
		}
	}
	cout << begin << "-" << end.substr(index) << endl;
}	

int main(){
	ios_base::sync_with_stdio(false);
	ifstream cin("in.txt");
	ofstream cout("out.txt");
	int n;
	int cas = 1;
	while(cin >> n, n){
		vector <string> a(n);
		for(int i=0; i<n; i++) cin >> a[i];
		vector <ll> b(n);
		for(int i=0; i<n; i++) b[i] = stoll(a[i]);
		string begin = a[0];
		string end = a[0];
		cout << "Case " << cas << ":" << endl;
		for(int j = 1; j<n; j++){
			if(b[j] - b[j-1] == 1){
				end = a[j];
			}
			else{
				func(a, begin, end, cout);
				begin = a[j];
				end = a[j];
			}
		}
		func(a, begin, end, cout);
		cas++;
		cout << endl;
	}
}