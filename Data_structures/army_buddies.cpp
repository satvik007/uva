#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream cin("in.txt");
	ofstream cout("out.txt");
	int s, b;
	while(cin >> s >> b, s||b){
		vi left(s);
		vi right(s);
		vector <int> status(s);
		fill(status.begin(), status.end(), true);
		for(int i=0; i<s; i++) left[i] = i-1;
		for(int i=0; i<s; i++) right[i] = i+1;
		int u, v;
		for(int j=0; j<b; j++){
			cin >> u >> v;
			u--; v--;
			for(int j=u; j<=v; j++){
				status[j] = false;
				right[j] = v+1;
				left[j] = u-1;
			}
			int x = u, y = v;
			while(y>=0 && status[y] != true) y = left[y];
			while(x<s && status[x] != true) x = right[x]; 
			if(y<0) cout << "* ";
			else cout << (y+1) << " ";
			if(x>=s) cout << "*\n";
			else cout << (x+1) << "\n";
			int index1 = y, index2 = x;
			x = u; y = v; 
			int temp;
			while(y>=0 && status[y] != true){
				temp = left[y];
				left[y] = index1;
				y = temp;
			}
			while(x<s && status[x] != true){
				temp = right[x]; 
				right[x] = index2;
				x = temp;
			} 
		} 
		cout << "-\n";
	}
}
