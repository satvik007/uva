#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <vector <bool>> water;
vector <vector <int >> counter;
vector <vector <bool>> status;
int r, c, m, n, w, flag;

void stack1(int cx, int cy){
	status[cx][cy] = true;
	if(m != 0 && m != n && n!=0){
		if(cx - n >= 0 && cy + m < r && water[cx - n][cy + m] != true){
			counter[cx][cy]++;
			if(status[cx-n][cy+m] == false){
				stack1(cx-n, cy+m);
			}
		}
		if(cx - m >= 0 && cy + n < r && water[cx - m][cy + n] != true){
			counter[cx][cy]++;
			if(status[cx-m][cy+n] == false){
				stack1(cx-m, cy+n);
			}
		}
		if(cx + n < c && cy + m < r && water[cx + n][cy + m] != true){
			counter[cx][cy]++;
			if(status[cx+n][cy+m] == false){
				stack1(cx+n, cy+m);
			}
		}
		if(cx + m < c && cy + n < r && water[cx + m][cy + n] != true){
			counter[cx][cy]++;
			if(status[cx+m][cy+n] == false){
				stack1(cx+m, cy+n);
			}
		}
		if(cx + n < c && cy - m >= 0 && water[cx + n][cy - m] != true){
			counter[cx][cy]++;
			if(status[cx+n][cy-m] == false){
				stack1(cx+n, cy-m);
			}
		} 
		if(cx + m < c && cy - n >= 0 && water[cx + m][cy - n] != true){
			counter[cx][cy]++;
			if(status[cx+m][cy-n] == false){
				stack1(cx+m, cy-n);
			}
		} 
		if(cx - n >= 0 && cy - m >= 0 && water[cx - n][cy - m] != true){
			counter[cx][cy]++;
			if(status[cx-n][cy-m] == false){
				stack1(cx-n, cy-m);
			}
		} 
		if(cx - m >= 0 && cy - n >= 0 && water[cx - m][cy - n] != true){
			counter[cx][cy]++;
			if(status[cx-m][cy-n] == false){
				stack1(cx-m, cy-n);
			}
		} 
	}
	else {
		if(cx - n >= 0 && cy + m < r && water[cx - n][cy + m] != true){
			counter[cx][cy]++;
			if(status[cx-n][cy+m] == false){
				stack1(cx-n, cy+m);
			}
		}
		if(cx + n < c && cy - m >= 0 && water[cx + n][cy - m] != true){
			counter[cx][cy]++;
			if(status[cx+n][cy-m] == false){
				stack1(cx+n, cy-m);
			}
		}
		if(cx + m < c && cy + n < r && water[cx + m][cy + n] != true){
			counter[cx][cy]++;
			if(status[cx+m][cy+n] == false){
				stack1(cx+m, cy+n);
			}
		}
		if(cx - m >= 0 && cy - n >= 0 && water[cx - m][cy - n] != true){
			counter[cx][cy]++;
			if(status[cx-m][cy-n] == false){
				stack1(cx-m, cy-n);
			}
		}
	}	
	return;
}

int main(){
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int t;
	cin >> t;
	for(int cas = 1; cas<=t; cas++){
		cin >> r >> c >> m >> n;
		cin >> w;
		int u, v;
		water.clear(); water.resize(c, vector <bool> (r));
		for(int i=0; i<c; i++) for(int j=0; j<r; j++) water[i][j] = false;
		for(int i = 0; i<w; i++) {
			cin >> u >> v;
			water[v][u] = true;
		}
		counter.clear(); counter.resize(c, vector <int> (r));
		for(int i=0; i<c; i++) for(int j=0; j<r; j++) counter[i][j] = 0;
		status.clear(); status.resize(c, vector <bool> (r));
		for(int i=0; i<c; i++) for(int j=0; j<r; j++) status[i][j] = false;
		flag = 0;
		if(m == 0 || n == 0 || m == n) flag = 1;
		stack1(0, 0);
		int count1 = 0;
		int count2 = 0;

		for(int i=0; i<c; i++){
			for(int j=0; j<r; j++){
				if(counter[i][j]%2==0 && counter[i][j] != 0) count1++;
				else if(counter[i][j]%2) count2++;
			}
		}
		if(counter[0][0] == 0) count1++;
		cout << "Case "<< cas << ": " << count1 << " " << count2 << endl;
	}
}