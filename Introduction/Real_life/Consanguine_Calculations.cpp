#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream cin("in.txt");
	ofstream cout("out.txt");
	string a, b, c;
	int cas = 1;
	while(cin >> a >> b >> c){
		//cout << a << " " << b << " " << c << endl;
		if(a == "E") break;
		cout << "Case " << cas << ": ";
		if(a == "?"){
			string det = b.substr(b.size()-1)+c.substr(c.size()-1);
			int sign = 0;
			if(det == "-+") sign = 1;
			string current = b.substr(0, b.size()-1) + c.substr(0, c.size()-1);
			if(current == "AA" || current == "BB" || current == "ABA" || current == "ABB"){
				if(sign == 1) cout << "{O+, AB+, B+, A+} ";
				else cout << "{O-, O+, AB-, AB+, B-, B+, A-, A+} ";
			}
			else if(current == "AB"|| current == "AAB"|| current == "OB"){
				if(sign == 1) cout << "{AB+, B+} ";
				else cout << "{AB-, AB+, B-, B+} ";
			}
			else if(current == "AO" || current == "BO" || current == "OO"){
				if(sign == 1) cout << "{O+, B+, A+} ";
				else cout << "{O-, O+, B-, B+, A-, A+} ";
			}
			else if(current == "BA" || current == "BAB" || current == "OA"){
				if(sign == 1) cout << "{AB+, A+} ";
				else cout << "{AB-, AB+, A-, A+} ";
			}
			else if(current == "ABAB") {
				if(sign == 1) cout << "{AB+, B+, A+} ";
				else cout << "{AB-, AB+, B-, B+, A-, A+} ";
			}
			else if(current == "ABO" || current == "OAB") {
				if(sign == 1) cout << "IMPOSSIBLE ";
				else cout << "IMPOSSIBLE ";
			}
			cout << b << " " << c << '\n'; 
		}
		if(b == "?"){
			string det = a.substr(a.size()-1)+c.substr(c.size()-1);
			int sign = 0;
			if(det == "-+") sign = 1;
			string current = a.substr(0, a.size()-1) + c.substr(0, c.size()-1);
			cout << a << " ";
			if(current == "AA" || current == "BB" || current == "ABA" || current == "ABB"){
				if(sign == 1) cout << "{O+, AB+, B+, A+} ";
				else cout << "{O-, O+, AB-, AB+, B-, B+, A-, A+} ";
			}
			else if(current == "AB"|| current == "AAB"|| current == "OB"){
				if(sign == 1) cout << "{AB+, B+} ";
				else cout << "{AB-, AB+, B-, B+} ";
			}
			else if(current == "AO" || current == "BO" || current == "OO"){
				if(sign == 1) cout << "{O+, B+, A+} ";
				else cout << "{O-, O+, B-, B+, A-, A+} ";
			}
			else if(current == "BA" || current == "BAB" || current == "OA"){
				if(sign == 1) cout << "{AB+, A+} ";
				else cout << "{AB-, AB+, A-, A+} ";
			}
			else if(current == "ABAB") {
				if(sign == 1) cout << "{AB+, B+, A+} ";
				else cout << "{AB-, AB+, B-, B+, A-, A+} ";
			}
			else if(current == "ABO" || current == "OAB") {
				if(sign == 1) cout << "IMPOSSIBLE ";
				else cout << "IMPOSSIBLE ";
			}
			cout << c << '\n'; 
		}
		else if(c == "?"){
			cout << a << " " << b << " ";
			string current;
			string det = a.substr(a.size()-1)+b.substr(b.size()-1);
			int sign = 0;
			if(det == "--") sign = 1;
			current = a.substr(0, a.size()-1) + b.substr(0, b.size()-1);
			if(current == "AO" || current == "OA" || current == "AA"){
				if(sign == 1) cout << "{O-, A-}\n";
				else cout << "{O-, O+, A-, A+}\n";
			}
			else if(current == "AAB" || current == "ABA" || current == "BAB" || current == "ABB" || current == "ABAB"){
				if(sign == 1) cout << "{AB-, B-, A-}\n";
				else cout << "{AB-, AB+, B-, B+, A-, A+}\n";
			}
			else if(current == "AB" || current == "BA"){
				if(sign == 1) cout << "{O-, AB-, B-, A-}\n";
				else cout << "{O-, O+, AB-, AB+, B-, B+, A-, A+}\n";
			}
			else if(current == "BO" || current == "BB" || current == "OB"){
				if(sign == 1) cout << "{O-, B-}\n";
				else cout << "{O-, O+, B-, B+}\n";
			}
			else if(current == "ABO" || current == "OAB") {
				if(sign == 1) cout << "{B-, A-}\n";
				else cout << "{B-, B+, A-, A+}\n";
			} 
			else if(current == "OO"){
				if(sign == 1) cout << "O-\n";
				else cout << "{O-, O+}\n";
			}
		}
		cas++;
	}
	return 0;
}
