#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;
typedef pair<int, int> ii;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	list <char> a;
	while(cin.peek() != EOF){
		string line;
		getline(cin, line, '\n');
		//cout << line << endl;
		a.clear();
		auto index = a.begin();
		for(int i=0; i<line.size(); i++){
			if(line[i] == '[') index = a.begin();
			else if(line[i] == ']') index = a.end();
			else{
				index = a.insert(index, line[i]);
				index++;
			}
		}
		string ans;
		for(auto iter = a.begin(); iter != a.end(); iter++){
			if((*iter) >= 'a' && (*iter) <= 'z' || (*iter) == '_' || (*iter)>='A' && (*iter)<='Z')
			ans += (*iter);
		}
		cout << ans << '\n';
	}
	return 0;
}
