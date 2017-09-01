#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	string a;
	int cas = 1;
	
	while(cin >> a){
		if(a == "end") break;
		cout << "Case " << cas << ": ";
		vector <stack<char>> b(26);
		int counter = 1;
		for(int i=0; i<a.size(); i++){
			for(int j=0; j<26; j++){
				counter = max(counter, j+1);
				if(b[j].empty() || b[j].top() >= a[i]){
					b[j].push(a[i]);
					break;
				}
			}
		}
		cout << counter << "\n";
		
		cas++;
	}
}
