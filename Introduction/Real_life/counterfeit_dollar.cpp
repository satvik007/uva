#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef vector <int> vi;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int t;
	cin >> t;
	while(t--){
		vector <string> a(9);
		for(int i=0; i<9; i++) cin >> a[i];
		if(a[2] == "down"){swap(a[0], a[1]); a[2] ="up";}
		if(a[5] == "down"){swap(a[3], a[4]); a[5] ="up";}
		if(a[8] == "down"){swap(a[6], a[7]); a[8] ="up";}
		vector <bool> status(12);
		fill(status.begin(), status.end(), false);
		for(int i=0; i<3; i++){
			for(int j=0; j<a[i*3].size(); j++) status[a[i*3][j]-'A'] = true;
			for(int j=0; j<a[i*3+1].size(); j++) status[a[i*3+1][j]-'A'] = true;
		}
		if(a[2] == "even"){
			for(int i=0; i<a[0].size(); i++) status[a[0][i]-'A'] = false;
			for(int i=0; i<a[1].size(); i++) status[a[1][i]-'A'] = false;
		} 
		if(a[5] == "even"){
			for(int i=0; i<a[3].size(); i++) status[a[3][i]-'A'] = false;
			for(int i=0; i<a[4].size(); i++) status[a[4][i]-'A'] = false;	
		} 
		if(a[8] == "even"){
			for(int i=0; i<a[6].size(); i++) status[a[6][i]-'A'] = false;
			for(int i=0; i<a[7].size(); i++) status[a[7][i]-'A'] = false;
		} 
		string ans1;
		string ans2;
		if(a[2] == "up") ans1 += a[0], ans2 += a[1];
		if(a[5] == "up") ans1 += a[3], ans2 += a[4];
		if(a[8] == "up") ans1 += a[6], ans2 += a[7];
		sort(ans1.begin(), ans1.end());
		sort(ans2.begin(), ans2.end());
		for(int i=0; i<ans1.size(); i++){
			if(ans2.find(ans1[i]) != string::npos) status[ans1[i]-'A'] = false;
			if(ans1.find(ans2[i]) != string::npos) status[ans2[i]-'A'] = false;
		}
		vector <int> counter1(12);
		vector <int> counter2(12);
		for(int i=0; i<ans1.size(); i++){
			if(status[ans1[i]-'A'] == true) counter1[ans1[i]-'A']++;
			if(status[ans2[i]-'A'] == true) counter2[ans2[i]-'A']++;
		} 
		int max1 = max_element(counter1.begin(), counter1.end()) - counter1.begin();
		int max2 = max_element(counter2.begin(), counter2.end()) - counter2.begin();
		if(counter1[max1] > counter2[max2]) {
			cout << (char)(max1+'A') << " is the counterfeit coin and it is heavy.\n";
		}	
		else {
			cout << (char)(max2+'A') << " is the counterfeit coin and it is light.\n";
		}
	}
	return 0;
}
