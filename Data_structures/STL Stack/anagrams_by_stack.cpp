#include <bits/stdc++.h>
using namespace std;

string a, b;

void func(stack <char> c, int index, int k, string ans, ostream &cout){
	if(k == a.size() && index == b.size()){
		ans.pop_back(); 
		cout << ans << endl;
		return;
	}
	while(k < a.size() && (c.empty() || c.top() != b[index])){
		c.push(a[k++]);
		ans += "i ";
	} 
	if(k < a.size() && c.top() == b[index]){
		c.push(a[k]);
		func(c, index, k+1, ans+"i ", cout);
		c.pop();
	}
	if(!c.empty() && c.top() == b[index]){
		c.pop();
		func(c, index+1, k, ans + "o ", cout);
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	while(cin.peek() != EOF){
		cin >> a;
		cin >> b;
		cin.ignore();
		cout << "[\n";
		stack <char> c;
		string ans;
		func(c, 0, 0, ans, cout);
		cout << "]\n";
	}
	return 0;
}
