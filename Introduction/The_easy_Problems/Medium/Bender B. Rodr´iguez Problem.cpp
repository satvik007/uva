#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

int main(){
	//ifstream cin("in.txt");
	//ofstream cout ("out.txt");
	int len;
	while(cin >> len, len){
		vector <string> a(len-1);
		for(int i=0; i<len-1; i++) cin >> a[i];
		int current = 1;
		for(int i=0; i<len-1; i++){
			if(a[i] == "No");
			else if(abs(current) == 1){
				if(a[i] == "+y") current *= 2;
				if(a[i] == "-y") current *= -2;
				if(a[i] == "+z") current *= 3;
				if(a[i] == "-z") current *= -3;
			}
			else if(abs(current) == 2){
				if(a[i] == "+z");
				if(a[i] == "-z");
				if(a[i] == "+y") current = (current/2)*-1;
				if(a[i] == "-y") current = (current/2)*1;
			}
			else if(abs(current) == 3){
				if(a[i] == "+z") current = (current/3)*-1;
				if(a[i] == "-z") current = (current/3)*1;
				if(a[i] == "+y") ;
				if(a[i] == "-y") ;
			}	
		}
		switch(current){
			case -1: cout << "-x" << endl; break;
			case 1: cout << "+x" << endl; break;
			case -2: cout << "-y" << endl; break;
			case 2: cout << "+y" << endl; break;
			case -3: cout << "-z" << endl; break;
			case 3: cout << "+z" << endl; break;
		}
	}
	return 0;
}
