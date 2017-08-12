#include <bits/stdc++.h>
using namespace std;

int main(){
	//ifstream cin("in.txt");
	//ofstream cout ("out.txt");
	map <char, int> map1;
	map1['N'] = 0; map1['S'] = 2; map1['L'] = 3; map1['O'] = 1;
	int n, m, s;
	while(cin >> n >> m>> s, n){
		vector <string> a(n);
		for(int i=0; i<n; i++) cin >> a[i];
		vector <vector <int>> status(n , vector <int> (m));
		int cx, cy;
		for(int i=0; i<n; i++) for(int j=0; j<m; j++){
			if(a[i][j]>='A' && a[i][j] <= 'Z') cx = i, cy = j;
			if(a[i][j] == '*') status[i][j] = 1;
			else status[i][j] = 0;
		}
		string q;
		cin >> q;
		int counter = 0;
		int direction = map1[a[cx][cy]];
		for(int j=0; j<s; j++){
			if(q[j] == 'D') direction = (direction - 1 + 4)%4;
			else if(q[j] == 'E') direction = (direction+1)%4;
			else {
				if(direction == 0){
					if(cx == 0 || a[cx-1][cy] == '#');
					else cx--;
				} 
				else if(direction == 1){
					if(cy == 0 || a[cx][cy-1] == '#');
					else cy--;
				} 
				else if(direction == 2){
					if(cx == n-1 || a[cx+1][cy] == '#');
					else cx++;
				} 
				else{
					if(cy == m-1 || a[cx][cy+1] == '#');
					else cy++;
				} 
			}
			if(status[cx][cy] == 1) {
				counter++;
				status[cx][cy] = 0;
			}
		}
		cout << counter << endl;

	}
}