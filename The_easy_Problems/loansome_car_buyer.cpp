#include <bits/stdc++.h>
using namespace std;

class Data{
public:
	int month;
	double dep;
};

int main(){
	ifstream cin("in.txt");
	ofstream cout("out.txt");
	double downp;
	double amount;
	int months;
	int k;
	while(cin >> months >> downp >> amount >> k, (months > 0)){
		//cout << months << " " << downp << " " << amount << " " << k << endl;
		vector <Data> a(k);
		for(int i=0; i<k; i++){
			cin >> a[i].month >> a[i].dep;
		}
		int m=1;
		int index = 1;
		double car = downp + amount;
		double current = a[0].dep;
		double monthly = amount/months;
		car -= car*current;
		while(amount >= car){
			if(index <k && a[index].month == m){
				current = a[index].dep;
				index++;
			}
			amount -= monthly;
			car -= car*current;
			m++;
		}

		cout << (m-1) << endl;
	}
	
	
}