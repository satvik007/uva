#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ifstream cin("in.txt");
	ofstream cout("out.txt");
	vector <int> a;
	ll n;
	while(cin >> n){
		a.push_back(n);
		nth_element(a.begin(), a.begin()+a.size()/2, a.end());
		if(a.size()%2){
			cout << a[a.size()/2] << endl;
		}
		else{
			int current = a[a.size()/2];
			nth_element(a.begin(), a.begin() + a.size()/2 - 1, a.end());
			int curr = a[a.size()/2 - 1];
			cout << ((current + curr)/2) << endl;
		}
	}
}