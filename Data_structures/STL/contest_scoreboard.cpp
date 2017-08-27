#include <bits/stdc++.h>
using namespace std;

class Data{
public:
	int id;
	int solved;
	vector <int> penalty;
	int final;
};

bool satvik(Data a, Data b){
	if(a.solved > b.solved) return true;
	else if(a.solved == b.solved) {
		if(a.final < b.final) return true;
		else if(a.final == b.final){
			if(a.id < b.id) return true;
		}
	}
	return false;
} 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int t;
	cin >> t; cin.ignore();
	for(int cas = 1; cas <= t; cas++){
		if(cas != 1) cout << "\n";
		cin.ignore();
		int a, b, c;
		char letter;
		vector <Data> players(101);
		vector <vector <bool>> status(101, vector <bool> (10));
		vector <bool> sub(101);
		fill(sub.begin(), sub.end(), false);
		for(int i=0; i<101; i++){
			players[i].id = i;
			players[i].solved = 0;
			players[i].final = 0;
			players[i].penalty.resize(10);
			for(int j=0; j<10; j++){
				status[i][j] = false;
				players[i].penalty[j] = 0;
			} 
		} 
		while(cin.peek()!='\n' && cin.peek()!=EOF){
			cin >> a >> b >> c;
			cin >> letter; cin.ignore();
			//cout << a << " " << b << " " << c << " " << letter << endl;
			sub[a] = true;
			if(letter == 'C' && status[a][b] == false){
				players[a].penalty[b] += c;
				players[a].solved++;
				status[a][b] = true;
			}
			else if(letter == 'I' && status[a][b] == false){
				players[a].penalty[b] += 20;
			}
		}
		for(int i=0; i<101; i++){
			for(int j=0; j<10; j++){
				if(status[i][j]){
					players[i].final += players[i].penalty[j];
				}
			}
		}
		sort(players.begin(), players.end(), satvik);
		for(int i=0; i<101; i++){
			if(sub[players[i].id]){
				cout << players[i].id << " " << players[i].solved << " " << players[i].final << "\n";
			}
		}
	}
	return 0;
}
