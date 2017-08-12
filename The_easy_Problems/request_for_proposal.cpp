#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

class Data{
public:
	string name;
	double price;
	int req;
};

bool pred(Data a, Data b){
	if(a.req < b.req) return true;
	else if(a.req == b.req && a.price > b.price) return true;
	return false;
}
int main(){
	//ifstream cin("in.txt");
	//ofstream cout ("out.txt");
	int n, p;
	int cas = 1;
	while(cin >> n >> p, n||p){
		if(cas != 1) cout << endl;
		vector <string> a(n);
		cin.ignore();
		for(int i=0; i<n; i++){
			getline(cin, a[i]);
		}
		vector <Data> b(p);
		for(int i = 0; i<p; i++){
			getline(cin, b[i].name);
			cin >> b[i].price >> b[i].req;
			string null;
			cin.ignore();
			for(int j=0; j<b[i].req; j++){
				getline(cin, null);
			}
		}
		cout << "RFP #" << cas << endl;
		int index = max_element(b.begin(), b.end(), pred) - b.begin();
		cout << b[index].name << endl;
		cas++;
	}
	return 0;
}
