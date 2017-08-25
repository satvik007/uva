
#include <bits/stdc++.h>
using namespace std;

vector <vector <string> > rep(27, vector <string> (5));
string test1 = 
".***.. ****.. .****. ****.. *****. *****. .****. *...*. *****.\
 *...*. *...*. *...*. *...*. *..... *..... *..... *...*. ..*...\
 *****. ****.. *..... *...*. ***... ***... *..**. *****. ..*...\
 *...*. *...*. *..... *...*. *..... *..... *...*. *...*. ..*...\
 *...*. ****.. .****. ****.. *****. *..... .***.. *...*. *****.\
 ..***. *...*. *..... *...*. *...*. .***.. ****.. .***.. ****..\
 ...*.. *..*.. *..... **.**. **..*. *...*. *...*. *...*. *...*.\
 ...*.. ***... *..... *.*.*. *.*.*. *...*. ****.. *...*. ****..\
 *..*.. *..*.. *..... *...*. *..**. *...*. *..... *..**. *..*..\
 .**... *...*. *****. *...*. *...*. .***.. *..... .****. *...*.\
 .****. *****. *...*. *...*. *...*. *...*. *...*. *****. ......\
 *..... *.*.*. *...*. *...*. *...*. .*.*.. .*.*.. ...*.. ......\
 .***.. ..*... *...*. .*.*.. *.*.*. ..*... ..*... ..*... ......\
 ....*. ..*... *...*. .*.*.. **.**. .*.*.. ..*... .*.... ......\
 ****.. .***.. .***.. ..*... *...*. *...*. ..*... *****. ......";
stringstream test(test1);
vector <string> a(60);

void print(ostream &cout){
	for(int i=0; i<60; i++){
		for(int j=0; j<60; j++) cout << a[i][j];
		cout << endl;
	} 
	cout << endl;
	for(int i=0; i<60; i++) cout << "-";
	cout << endl << endl;
	return;
}

int read(string line, ostream &cout){
	stringstream current(line);
	string ord;
	current >> ord;
	if(ord == ".EOP") return 0;	
	string size, message;
	int row, col;
	current >> size;
	current >> row;
	if(ord == ".P"){
		current >> col;
		col--;
	} 
	
	current.ignore(); current.ignore();
	getline(current, message, '|');
	
	if(ord == ".L") col = 0;
	else if(ord == ".R"){
		if(size == "C1") col = 60 - message.size();
		else col = 60 - 6*message.size();
	}
	else if(ord == ".C"){
		if(size == "C1") col = 30-(int)message.size()/2;
		else col = 30 - 6*(int)message.size()/2;
	}
	row--;
	if(size == "C1" && row <60 && row >= 0){
		for(int i=0; i<message.size() && i + col < 60; i++){
			if(col+i >= 0 && col+i < 60){
				if(message[i] == ' ') continue;
				a[row][col+i] = message[i];
			}
		}
	}
	else if(size == "C5"){
		for(int i=0; i<message.size(); i++){
			if(message[i] != ' '){
				for(int k = 0; k <5; k++){
					for(int m=0; m<6; m++){
						if(row+k<60 && col+m<60 && row + k >= 0 && col+m >= 0){
							if(rep[message[i]-'A'][k][m] == '.');
							else{
								a[row+k][col+m] = rep[message[i]-'A'][k][m];
							}
						}
					}
				}
			}
			col += 6;
		}
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	for(int t = 0; t<3; t++) for(int i=0; i<5; i++) for(int j=0; j<9; j++)
		test >> rep[9*t + j][i];
	for(int i=0; i<60; i++) a[i].resize(60);
	string line;
	while(cin.peek() != EOF){
		for(int i=0; i<60; i++) for(int j=0; j<60; j++) a[i][j] = '.';
		int status = 1;
		while(status){
			getline(cin, line);
			status = read(line, cout);
		}
		print(cout);
	}
	return 0;
}
