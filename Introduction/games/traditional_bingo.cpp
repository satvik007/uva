#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > a(5, vector <int> (5));
vector <vector <bool> > status(5, vector <bool> (5));
vector <int> calls(75);

bool bingo(){
	int flag3 = 0;
	int flag4 = 0;
	for(int i=0; i<5; i++){
		if(status[i][i] == false) flag3 = 1;
		if(status[i][4-i] == false) flag4 = 1;
		int flag1 = 0;
		int flag2 = 0;
		for(int j=0; j<5; j++){
			if(status[i][j] == false) flag1 = 1;
			if(status[j][i] == false) flag2 = 1;
		}
		if(flag1 == 0) return true;
		if(flag2 == 0) return true;
	}
	if(flag3 == 0) return true;
	if(flag4 == 0) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int t;
	cin >> t;
	a[2][2] = 0;
	while(t--){
		map <int, pair<int, int>> map1;
		for(int i=0; i<5; i++) for(int j=0; j<5; j++) status[i][j] = false;
		for(int i=0; i<5; i++) for(int j=0; j<5; j++) if(!(i == 2 && j == 2)){
			cin >> a[i][j];
			map1[a[i][j]] = {i, j};
		} 
		for(int i=0; i<75; i++) cin >> calls[i];
		int counter = 0;
		status[2][2] = true;
		for(int i=0; i<75; i++){
			counter = i;
			if(map1.find(calls[i]) != map1.end()){
				status[map1[calls[i]].first][map1[calls[i]].second] = true;
				if(bingo() == true) break;
			}
		}
		cout << "BINGO after " << (counter + 1) << " numbers announced" << '\n';
	}
}