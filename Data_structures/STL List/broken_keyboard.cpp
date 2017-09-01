#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream cin("in.txt");
	ofstream cout("out.txt");
	string line;
	while(cin.peek() != EOF){
		getline(cin, line);
		string ans;
		int index = 0;
		vector <pair<int, int>> a;
		for(int i=0; i<line.size(); i++){
			if(line[i] == '[') a.push_back({i, true});
			if(line[i] == ']') a.push_back({i, false});
		}
		
		
	}
	return 0;
}
