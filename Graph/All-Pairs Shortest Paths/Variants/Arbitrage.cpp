#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define e 1e-7

double d[25][25][25], x;
int n, path[25][25][25];

void floyd(){
    for(int l=1; l<n; l++){
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    x = d[i][k][l-1] * d[k][j][0];
                    if(d[i][j][l] < x){
                        d[i][j][l] = x;
                        path[i][j][l] = k;
                    }
                }
            }
        }
    }

    bool flag = false;
    stack <int> s;
    int temp;
    for(int l=1; l<n && !flag; l++){
        for(int i=0; i<n; i++){
            if(d[i][i][l] > 1.01){
                s.push(path[i][i][l]);
                for(int j=l-1; j>=0; j--) s.push(path[i][s.top()][j]);
                temp = s.top();
                while(!s.empty()){
                    cout << (s.top() + 1) << " "; s.pop();
                }
                cout << temp + 1;
                flag = true;
                break;
            }
        }
    }
    if(!flag) cout << "no arbitrage sequence exists";
    cout << "\n";

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n){
        memset(d, 0, sizeof d);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                path[i][j][0] = i;
                if(i == j){
                    path[i][j][0] = 1.0;
                }
                else {
                    cin >> d[i][j][0];
                }
            }
        }
        floyd();
    }
}