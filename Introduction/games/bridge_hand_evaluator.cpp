#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

void print(vector <vi> &status, ostream &cout){
	for(int i=0; i<status.size(); i++){
		for(int j=0; j<status[0].size(); j++){
			cout << status[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void printv(vi &a){
	for(int i=0; i<a.size(); i++) cout << a[i] << " "; cout << endl;
}
int main(){
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int n = 13;
	vector <string> a(13);
	stringstream line;
	while(cin.peek()!= EOF){
		for(int i=0; i<n; i++) cin >> a[i]; cin.ignore();
		//for(int i=0; i<n; i++) cout << a[i] << " "; cout << endl;
		vector <vi> status(4, vi(13));
		for(int i=0; i<4; i++) for(int j=0; j<13; j++) status[i][j] = 0;
		int cx;
		int cy;
		int final1 = 0;
		int final2 = 0;
		for(int i=0; i<n; i++){
			if(a[i][0] == 'A') cx = 0, final1 += 4;
			else if(a[i][0] >='2' && a[i][0] <='9') cx = a[i][0]-'1';
			else if(a[i][0] == 'T') cx = 9;
			else if(a[i][0] == 'J') cx = 10, final1 += 1;
			else if(a[i][0] == 'Q') cx = 11, final1 += 2;
			else if(a[i][0] == 'K') cx = 12, final1 += 3;
			if(a[i][1] == 'S') cy = 0;
			else if(a[i][1] == 'H') cy = 1;
			else if(a[i][1] == 'D') cy = 2;
			else if(a[i][1] == 'C') cy = 3;
			status[cy][cx]++;
		}
		final2 = final1;
		//print(status, cout);
		vi stop(4);
		fill(stop.begin(), stop.end(), 0);
		vi check(4);
		fill(check.begin(), check.end(), 1);
		vi suits(4);
		fill(suits.begin(), suits.end(), 0);
		for(int i=0; i<4; i++){
			int counter = 0;
			for(int j=0; j<13; j++) counter += status[i][j];
			suits[i] = counter;
			if(counter == 2) final2 += 1;
			if(counter == 1 || counter == 0) final2 += 2;
			if(status[i][0] > 0) stop[i] = 1;
			if(status[i][10] > 0){
				if(counter <4) final1-=1, final2-=1;
			}
			if(status[i][11] > 0){
				if(counter <3) final1-=1, final2-=1;
				else stop[i] = 1;	
			}
			if(status[i][12] > 0){
				if(counter < 2) final1-=1, final2-=1;
				else stop[i] = 1;
			}
		}
		//cout << final1 << " " << final2 << endl;
		//printv(stop);
		if(final2 < 14){
			cout << "PASS" << endl;
		}
		else if(final1 >= 16 && check == stop){
			cout << "BID NO-TRUMP" << endl;
		}
		else{
			int index = max_element(suits.begin(), suits.end()) - suits.begin();
			if(index == 0) cout << "BID S" << endl;
			else if(index == 1) cout << "BID H" << endl;
			else if(index == 2) cout << "BID D" << endl;
			else if(index == 3) cout << "BID C" << endl;
		}

	}
}
