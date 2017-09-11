#include <bits/stdc++.h>
#define epsilon 1e-9
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, u, v, w, size = 25, counter, index, n;
    vector <vi> a(5, vi(5));
    vi c;
    cin >> t;
    while(t--){
        cin >> n;
        c.clear();
        for(int i=0; i<5; i++){
        	a[i].assign(5, 0);
		}
        for(int i=0; i<n; i++){
            cin >> u >> v >> w;
            a[u][v] = w;
        }
        for(int i=0; i<size-4; i++){
        	for(int j=0; j<size-3; j++){
        		for(int r=0; r<size-2; r++){
        			for(int m=0; m<size-1; m++){
        				for(int p=0; p<size; p++){
        					counter = 0;
        					for(int x = 0; x<5; x++){
        						for(int y=0; y<5; y++){
        							counter += a[x][y]*((abs(x-i/5)+abs(y-i%5)) + (abs(x-j/5)+abs(y-j%5)) + (abs(x-r/5)+abs(y-r%5))+(abs(x-m/5)+abs(y-m%5))+(abs(x-p/5)+abs(y-p%5)));
								}
							}
							c.push_back(counter);
						}
					}
				}
			}
		}
		sort(c.begin(), c.end());
		auto it = unique (c.begin(), c.end());
		c.resize(it - c.begin());
        cout << c[0];
        for(int i=1; i<5; i++) cout << " " << c[i];
		cout << "\n";
    }
    return 0;
}
