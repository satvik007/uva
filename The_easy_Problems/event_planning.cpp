#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

int main(){
	//ifstream cin("in.txt");
	//ofstream cout ("out.txt");
	int n, b, h, w;
	while(cin >> n >> b >> h >> w){
		int min1 = INT_MAX;
		int price;
		for(int i=0; i<h; i++){
			cin >> price;
			int current;
			for(int i=0; i<w; i++){
				cin >> current;
				if(current >= n && price*n <= b){
					if(price*n < min1) min1 = price*n; 
				}
			}
		}
		if(min1 != INT_MAX) cout << min1 << endl;
		else cout << "stay home" << endl;
	}
}
