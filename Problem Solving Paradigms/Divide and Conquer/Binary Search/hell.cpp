#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
	int n;
	cin >> n;
	vi a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	cout << max(0, *max_element(a.begin(), a.end()) - 25) << endl;
}
