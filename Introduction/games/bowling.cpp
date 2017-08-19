#include <bits/stdc++.h>
using namespace std;

int func(vector <char> &move, int index){
	if(move[index] == 'X') return 10;
	else if(move[index] == '/') return (10 - move[index-1] + '0');
	else return (move[index] - '0');
}
int main(){
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	string line;
	while(1){
		getline(cin, line);
		if(line == "Game Over") break;
		int index = 0;
		vector <char> move;
		while(index < line.size()){
			move.push_back(line[index]);
			index += 2;
		}
		int k = 0;
		int counter = 0;
		//   1 0 1 / 2 2 X 3 3 X 1 / 3 / X 1 2
		for(int i=0; k<10; i+=1, k+=1){
			if(move[i] == 'X'){
				counter += 10;
				counter += func(move, i+1);
				counter += func(move, i+2);
			}
			else{
				counter += func(move, i);
				counter += func(move, i+1);
				if(move[i+1] == '/') counter += func(move, i+2);
				i++;
			}
		}
		cout << counter << endl;
	}
}