#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m, k, siz, max1, temp, counter;
vi a, b;
vector <vi> c;
vi ans;

void dfs(int u, vi towers){
    if(towers.size() == m){
        counter = 0;
        for(int i=0; i<m; i++){
            counter += a[towers[i]];
        }
        for(int i=0; i<k; i++){
        	int count=0;
        	for(int j=0; j<c[i].size(); j++){
        		for(int p=0; p<m; p++){
        			if(towers[p] == c[i][j]) count++;
				}	
			}
			if(count>1){
        		counter -= (count-1)*b[i];
			}
		}
		//cout << "working2.\n";
		//cout << counter << endl;
        if(counter > max1){
            max1 = counter;
            ans = towers;
        }
        return;
    }
    for(int i = u; i<n; i++){
        towers.push_back(i);
        //for(auto el:towers) cout << el << " "; cout << endl;
        dfs(i+1, towers);
        towers.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    while(cin >> n >> m, n||m){
    	cout << "Case Number  " << cas << "\n";
        a.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];
        cin >> k;
        c.resize(k);
        b.resize(k);
        vi towers;
        max1 = INT_MIN;
        for(int i=0; i<k; i++){
            cin >> siz;
            c[i].resize(siz);
            for(int j=0; j<siz; ++j){
                cin >> c[i][j];
                c[i][j]--;
            }
            cin >> b[i];
        }
        dfs(0, towers);
        cout << "Number of Customers: " << max1 << "\n";
        cout << "Locations recommended:";
        for(auto el:ans) cout << " " << el+1; cout << endl;
        cas++;
        cout << "\n";
    }
    return 0;
}
