#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	while(1){
		vector <int> a;
		int temp;
		while(cin >> temp, temp){
			a.push_back(temp);
		}
		if(a.empty()) break;
		int n = a.size();
		int min1 = *min_element(a.begin(), a.end());
		int ans = -1;
		for(int i=min1+1; i<=3600*5; i++){
			int flag = 0;
			for(int j = 0; j<n; j++){
				if(i % a[j] < a[j]-5 && (i/a[j]) % 2 == 0);
				else{
					flag = 1;
					break;
				}
			}
			if(flag == 0){
				ans = i;
				break;
			}
		}
		if(ans == -1) cout << "Signals fail to synchronise in 5 hours\n";
		else{
			cout << setfill('0') << setw(2) << (ans/3600) << ":" << setw(2)
			<< ((ans%3600)/60) << ":" << setw(2) << (ans%60) << endl;
		}
	}
	return 0;
}