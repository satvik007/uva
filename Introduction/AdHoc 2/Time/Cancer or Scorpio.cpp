#include <bits/stdc++.h>
using namespace std;

void print(int d, int m){
	if(m == 1 && d>=21 || m==2 && d<=19) cout << "aquarius" << endl;
	if(m == 2 && d>=20 || m==3 && d<=20) cout << "pisces" << endl;
	if(m == 3 && d>=21 || m==4 && d<=20) cout << "aries" << endl;
	if(m == 4 && d>=21 || m==5 && d<=21) cout << "taurus" << endl;
	if(m == 5 && d>=22 || m==6 && d<=21) cout << "gemini" << endl;
	if(m == 6 && d>=22 || m==7 && d<=22) cout << "cancer" << endl;
	if(m == 7 && d>=23 || m==8 && d<=21) cout << "leo" << endl;
	if(m == 8 && d>=22 || m==9 && d<=23) cout << "virgo" << endl;
	if(m == 9 && d>=24 || m==10 && d<=23) cout << "libra" << endl;
	if(m == 10 && d>=24 || m==11 && d<=22) cout << "scorpio" << endl;
	if(m == 11 && d>=23 || m==12 && d<=22) cout << "sagittarius" << endl;
	if(m == 12 && d>=23 || m==1 && d<=20) cout << "capricorn" << endl;
}
int main(){
	int n;
	cin >> n;
	for(int cas = 1; cas <= n; cas++){
		string a;
		cin >> a;
		string mm = a.substr(0, 2);
		string dd = a.substr(2, 2);
		string yyyy = a.substr(4, 4);
		int d = stoi(dd);
		int m = stoi(mm);
		int y = stoi (yyyy);
		tm current;
		current.tm_mday = 280 + d;
		current.tm_mon = m - 1;
		current.tm_year = y - 1900;
		mktime(&current);
		cout << cas << setfill('0') << " "<< setw(2) << (current.tm_mon+1) << "/" << setw(2) << (current.tm_mday) << "/" << setw(4) << (current.tm_year+1900) << " ";
		print(current.tm_mday, current.tm_mon+1);
	}
}
=======
#include <bits/stdc++.h>
using namespace std;

void print(int d, int m, ostream &cout){
	if(m == 1 && d>=21 || m==2 && d<=19) cout << "aquarius" << endl;
	if(m == 2 && d>=20 || m==3 && d<=20) cout << "pisces" << endl;
	if(m == 3 && d>=21 || m==4 && d<=20) cout << "aries" << endl;
	if(m == 4 && d>=21 || m==5 && d<=21) cout << "taurus" << endl;
	if(m == 5 && d>=22 || m==6 && d<=21) cout << "gemini" << endl;
	if(m == 6 && d>=22 || m==7 && d<=22) cout << "cancer" << endl;
	if(m == 7 && d>=23 || m==8 && d<=21) cout << "leo" << endl;
	if(m == 8 && d>=22 || m==9 && d<=23) cout << "virgo" << endl;
	if(m == 9 && d>=24 || m==10 && d<=23) cout << "libra" << endl;
	if(m == 10 && d>=24 || m==11 && d<=22) cout << "scorpio" << endl;
	if(m == 11 && d>=23 || m==12 && d<=22) cout << "sagittarius" << endl;
	if(m == 12 && d>=23 || m==1 && d<=20) cout << "capricorn" << endl;
}
int main(){
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int n;
	cin >> n;

	for(int cas = 1; cas <= n; cas++){
		string a;
		cin >> a;
		string mm = a.substr(0, 2);
		string dd = a.substr(2, 2);
		string yy = a.substr(4, 4);
		int d = stoi(dd);
		int m = stoi(mm);
		int y = stoi(yy);
		tm current;
		mktime(&current);
		current.tm_mday = 280 + d;
		current.tm_mon = m - 1;
		current.tm_year = y - 1900;
		mktime(&current);
		d = current.tm_mday;
		m = current.tm_mon;
		y = current.tm_year;
		cout << cas << setfill('0') << " "<< setw(2) << (m+1) << "/" << setw(2) << d << "/" << setw(4) <<(y+1900) << " ";
		print(current.tm_mday, current.tm_mon+1, cout);
	}
}
