#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

void printA(vector <string> &a, ostream &cout){
	for(int i=0; i<a.size(); i++){
		cout << a[i] << endl;
	}
	cout << endl;
}

void findDirection(vector <string> &a, int cx, int cy, int &dir);
void print(vector <vi> &status, ostream &cout){
	int n = status.size();
	int m = status[0].size();
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << status[i][j] << " "; 
		} 
		cout << endl;
	} 
	cout << endl;
}

void moveForward(vector <string> &a, int &cx, int &cy, int &dir){
	int n = a.size();
	int m = a[0].size();
	if(dir == 0){
		if(cy == m-1 || a[cx][cy+1] == '1') findDirection(a, cx, cy, dir);
	}
	else if(dir == 1){
		if(cx == 0 || a[cx-1][cy] == '1') findDirection(a, cx, cy, dir);
	}
	else if(dir == 2){
		if(cy == 0 || a[cx][cy-1] == '1') findDirection(a, cx, cy, dir);
	}
	else{
		if(cx == n-1 || a[cx+1][cy] == '1') findDirection(a, cx, cy, dir);
	}
	if(dir == 0) cy++;
	else if(dir == 1) cx--;
	else if(dir == 2) cy--;
	else cx++;
	return;
}

void findDirection(vector <string> &a, int cx, int cy, int &dir){
	int n = a.size();
	int m = a[0].size();
	if(dir == 0){
		// wall on the right
		if(cx == n-1 || a[cx+1][cy] == '1'){
			if(cy == m-1 || a[cx][cy+1] == '1')
				dir = 1;
		}
		else{
			dir = 3;
		}
	}
	else if(dir == 1){
		// wall on the right
		if(cy == m-1 || a[cx][cy+1] == '1'){
			// wall in front
			if(cx == 0 || a[cx-1][cy] == '1')
				dir = 2;
		}
		else{
			dir = 0;
		}
	}
	else if(dir == 2){
		if(cx == 0 || a[cx-1][cy] == '1'){
			if(cy == 0 || a[cx][cy-1] == '1')
				dir = 3;
		}
		else{
			dir = 1;
		}
	}
	else if(dir == 3){
		if(cy == 0 || a[cx][cy-1] == '1'){
			if(cx == n-1 || a[cx+1][cy] == '1')
				dir = 0;
		}
		else{
			dir = 2;
		}
	}
	return;
}

int main(){
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int n, m;
	while(cin >> n>> m, n||m){
		vector <string> a(n);
		for(int i=0; i<n; i++) cin >> a[i];
		int cx = n-1;
		int cy = 0;
		int dir = 0;
		int flag = 0;
		vector <vi> status(n, vector <int> (m));
		for(int i=0; i<n; i++) for(int j=0; j<m; j++) status[i][j] = 0;
		
		while((cx != n-1 || cy!= 0) || flag == 0){
			//cout << cx << " " << cy << endl;
			flag = 1;
			status[cx][cy]++;
			findDirection(a, cx, cy, dir);
			moveForward(a, cx, cy, dir);
			/*a[cx][cy] = 'c';
			printA(a, cout);
			a[cx][cy] = '0';*/
		}
		//print(status, cout);
		vi counter(5);
		fill(counter.begin(), counter.end(), 0);
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(a[i][j] == '0') counter[status[i][j]]++;
			}
		}
		for(int i=0; i<5; i++) cout << setw(3) << counter[i];
		cout<< endl;
	}
	return 0;
}
