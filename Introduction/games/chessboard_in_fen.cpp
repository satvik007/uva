#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

vector <string> piece;
vector <vector <int>> status;
int n = 8;
//int n;
int m = 8;

void rook(int row, int col){
	status[row][col] = true;
	for(int i=row+1; i<n; i++){
		if(piece[i][col] != '0') break;
		status[i][col] = true;
	}
	for(int i=row-1; i>=0; i--){
		if(piece[i][col] != '0') break;
		status[i][col] = true;
	}
	for(int i=col+1; i<m; i++){
		if(piece[row][i] != '0') break;
		status[row][i] = true;
	}
	for(int i=col-1; i>=0; i--){
		if(piece[row][i] != '0') break;
		status[row][i] = true;
	}
	return;
}
void knight(int row, int col){
	status[row][col] = true;
	if(row-2>=0 && col+1<m) status[row-2][col+1] = true;
	if(row-1>=0 && col+2<m) status[row-1][col+2] = true;
	if(row+1<n && col+2<m) status[row+1][col+2] = true;
	if(row+2<n && col+1<m) status[row+2][col+1] = true;
	if(row+2<n && col-1>=0) status[row+2][col-1] = true;
	if(row+1<n && col-2>=0) status[row+1][col-2] = true;
	if(row-1>=0 && col-2>=0) status[row-1][col-2] = true;
	if(row-2>=0 && col-1 >= 0) status[row-2][col-1] = true;
	return;
}
void king(int row, int col){
	status[row][col] = true;
	if(row-1>=0) status[row-1][col] = true;
	if(row-1>=0 && col+1<m) status[row-1][col+1] = true;
	if(col+1<m) status[row][col+1] = true;
	if(row+1<n && col+1<m) status[row+1][col+1] = true;
	if(row+1<n) status[row+1][col] = true;
	if(row+1<n && col-1>=0) status[row+1][col-1] = true;
	if(col-1>=0) status[row][col-1] = true;
	if(row-1>=0 && col-1>=0) status[row-1][col-1] = true;
	return;
}
void bishop(int row, int col){
	status[row][col] = true;
	for(int i=row+1; col-row+i<m && i<n; i++){
		if(piece[i][col-row+i] != '0') break;
		status[i][col-row+i] = true;
	}
	for(int i=row-1; col-row+i>=0 && i>=0; i--){
		if(piece[i][col-row+i] != '0') break;
		status[i][col-row+i] = true;
	}
	for(int i=row+1; col+row-i>=0 && i<n; i++){
		if(piece[i][col+row-i] != '0') break;
		status[i][col+row-i] = true;
	}
	for(int i=row-1; col+row-i<m && i>=0; i--){
		if(piece[i][col+row-i] != '0') break;
		status[i][col+row-i] = true;
	}
	return;
}
void queen(int row, int col){
	bishop(row, col);
	rook(row, col);
	return;
}
void pawn(int row, int col, int color){
	status[row][col] = true;
	if(color == 0){
		if(row+1<n && col-1>=0) status[row+1][col-1] = true;
		if(row+1<n && col+1<m) status[row+1][col+1] = true;
	}
	else {
		if(row-1>=0 && col+1<m) status[row-1][col+1] = true;
		if(row-1>=0 && col-1<m) status[row-1][col-1] = true;
	}
	return;
}

void printv(ostream &cout){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cout << piece[i][j];
		cout << endl;
	}
	cout << endl;
}
void print(ostream &cout){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cout << status[i][j];
		cout << endl;
	}
	cout << endl;
}
int main(){
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	string a;
	while(cin >> a){
		//n = count(a.begin(), a.end(), '/') + 1;
		//cout << n << endl;
		piece.resize(n);
		status.resize(n, vector <int> (m));
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				piece[i][j] = '0';
				status[i][j] = false;
			}
		}
		int index = 0;
		int k = 0;
		char current;
		while(index != a.size()){
			current = a[index];
			if(current >= '1' && current <= '8') k+=current-'0'-1;
			else if(current == '/') k--;
			else piece[k/8][k%8] = current;
			assert(k/8<n && k%8<m);
			k++;
			index++;
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				current = piece[i][j];
				if(current == '0');
				else if(tolower(current) == 'r') rook(i, j);
				else if(tolower(current) == 'n') knight(i, j);
				else if(tolower(current) == 'k') king(i, j);
				else if(tolower(current) == 'q') queen(i, j);
				else if(tolower(current) == 'b') bishop(i, j);
				else if(current == 'p') pawn(i, j, 0);
				else if(current == 'P') pawn(i, j, 1);
			}
		}
		//print(cout);
		//printv(cout);
		int counter = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(status[i][j] == false) counter++;
			}
		}
		cout << counter << endl;
	}
}
