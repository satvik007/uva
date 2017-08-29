#include <bits/stdc++.h>
using namespace std;

class Data{
public:
	int start;
	int end;
	int rep;
};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	vector <bool> status(1000001);
	int n, m;
	while(cin >> n >> m, n||m){
		vector <Data> a(n);
		vector <Data> b(m);
		fill(status.begin(), status.end(), false);
		for(int i=0; i<n; i++) cin >> a[i].start >> a[i].end;
		for(int i=0; i<m; i++) cin >> b[i].start >> b[i].end >> b[i].rep;
		int flag = 0;
		for(int i=0; i<n; i++){
			for(int j=a[i].start; j<a[i].end; j++){
				if(status[j] == true){
					flag = 1;
					break;
				}
				else status[j] = true;
			}
			if(flag == 1) break;
		}
		for(int i = 0; i<m; i++){
			int duration = b[i].end - b[i].start;
			for(int j=b[i].start; j<=1000000; j += b[i].rep){
				for(int k=j; k<j+duration && k < 1000001; k++){
					if(status[k] == true){
						flag = 1;
						break;
					}
					else status[k] = true;
				}
				if(flag == 1) break;
			}
			if(flag == 1) break;
		}
		if(flag == 0) cout << "NO CONFLICT\n";
		else cout << "CONFLICT\n";
	}
	
	return 0;
}
