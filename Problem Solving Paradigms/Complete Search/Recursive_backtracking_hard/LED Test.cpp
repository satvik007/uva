#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

int t, n, flag, solve;
vector <string> a;
vector <string> segment(10);
vi led(7);
void check(int val, int u){
    for(int i=0; i<7; i++){
        if(led[i] == 0 && a[val][i] == '1') flag = 0;
        if(segment[u][i] == '0' && a[val][i] == '1') flag = 0;
        if(segment[u][i] == '1' && a[val][i] == '0') led[i] = 0;
    }
    //for(auto el:a[val]) cout << el << " "; cout << endl;
    //for(auto el:segment[u]) cout << el << " "; cout << endl;
    //for(auto el:led) cout << el << " "; cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    segment[0] = "1111110";
    segment[1] = "0110000";
    segment[2] = "1101101";
    segment[3] = "1111001";
    segment[4] = "0110011";
    segment[5] = "1011011";
    segment[6] = "1011111";
    segment[7] = "1110000";
    segment[8] = "1111111";
    segment[9] = "1111011";
    
    while(cin >> n, n){
    	a.clear();
    	a.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) for(int j=0; j<a[i].size(); j++)
        	a[i][j] = (a[i][j] == 'Y' ? '1' : '0');
		//for(auto row:a) for(auto el:row) el = (el == 'Y' ? '1' : '0');
        solve = 0;
        for(int num = 9; num >=n-1; num--){
            led.assign(7, 1);
            flag = 1;
            for(int i=0; i<n; i++){
                check(i, num-i);
            }
            if(flag){
            	//cout << num << endl;
                solve = 1; break;
            }
        }
        cout << (solve ? "MATCH\n": "MISMATCH\n");
    }
    return 0;
}