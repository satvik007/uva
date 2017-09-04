#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int t;
	cin >> t;
	int n, greenSize, blueSize;
	while(t--){
		cin >> n >> greenSize >> blueSize;
		int temp;
		multiset <int, greater <int> > a;
		multiset <int, greater <int> > b;
		for(int i=0; i<greenSize; i++){
			cin >> temp;
			a.insert(temp);
		}
		for(int i=0; i<blueSize; i++){
			cin >> temp;
			b.insert(temp);
		}
		while(!a.empty() && !b.empty()){
			int size = min(a.size(), b.size());
			size = min(size, n);
			vi x(size), y(size);
			for(int i=0; i<size; i++){
				x[i] = (*a.begin()); a.erase(a.begin());
				y[i] = (*b.begin()); b.erase(b.begin());
				if(x[i]>y[i]) {
					x[i] -= y[i]; y[i] = 0;
				}
				else{
					y[i] -= x[i]; x[i] = 0;
				}
			}
			//for(auto el:x) cout << el << " "; cout << endl;
			//for(auto el:y) cout << el << " "; cout << endl;
			for(int i=0; i<size; i++){
				if(x[i] > 0) a.insert(x[i]);
				if(y[i] > 0) b.insert(y[i]);
			}
			//for(auto el:a) cout << el << " "; cout << endl;
			//for(auto el:b) cout << el << " "; cout << endl;
		}
		if(a.empty()){
			if(b.empty()) cout << "green and blue died\n";
			else {
				cout << "blue wins\n";
				for(auto el: b) cout << el << "\n";
			}
		}
		else {
			cout << "green wins\n";
			for(auto el: a) cout << el << "\n";
		}
		if(t!=0) cout << "\n";
	}
	return 0;
}
