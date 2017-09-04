#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair<int, int> ii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    while(cin >> n, n){
	    priority_queue <ll, vector <ll> , greater <ll>> a;
        ll temp;
        for(int i=0; i<n; i++){
        	cin >> temp; a.push(temp);
		}
		ll counter = 0;
		while(a.size()>1){
			ll x = a.top(); a.pop();
			ll y = a.top(); a.pop();
			counter += x+y;
			a.push(x+y);
		}
		cout << counter << "\n";
    }
    return 0;
}
