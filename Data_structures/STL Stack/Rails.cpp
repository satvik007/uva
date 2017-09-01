#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;
typedef pair<int, int> ii;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int n;
	while(cin >> n, n){
		vector <int> a(n);
		while(1){
			cin >> a[0];
			if(a[0] == 0) break;
			for(int i=1; i<n; i++) cin >> a[i];
			//for(int i=0; i<)
			int k = 1;
			stack <int> b;
			int index = 0;
			while(k != n+1){
				b.push(k);
				while(!b.empty() && b.top() == a[index]){
					b.pop();
					index++;
				}
				k++;
			}
			cout << ((b.empty())?"Yes\n":"No\n");
		}
		cout << "\n";
	}

	return 0;
}
