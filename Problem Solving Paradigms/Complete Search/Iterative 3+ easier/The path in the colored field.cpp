#include <bits/stdc++.h>
#define epsilon 1e-9
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    vector <string> a;
    vector <pair<int, int>> one;
    vector <pair<int, int>> th;
    //vi dist;
    while(cin >> n){
    	one.clear();
    	th.clear();
        a.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];
        int counter = 0;
        int max1 = INT_MIN;
        int current = 0;
        int min1 = INT_MAX;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(a[i][j] == '1') one.push_back({i, j});
                if(a[i][j] == '3') th.push_back({i, j});
            }
        }
        for(int i=0; i<one.size(); i++){
        	min1 = INT_MAX;
        	//cout << one[i].first << " " << one[i].second << endl;
            for(int j=0; j<th.size(); j++){ 
                current = abs(one[i].first - th[j].first) + abs(one[i].second - th[j].second);
                if(current < min1) min1 = current;
            }
            if(min1 > max1) max1 = min1;
        }
        cout << max1 << "\n";
    }
    return 0;
}
