#include <bits/stdc++.h>
using namespace std;

int main(){
    //ifstream cin("in.txt");
    //ofstream cout("out.txt");
    int n, m;
    int cas = 1;
    while (cin >> n >> m, n||m){
        //if(cas != 1) cout << endl;
        vector <string> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] == '.') a[i][j] = '0';
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] == '*'){
                    if(i-1>=0 && a[i-1][j] != '*') a[i-1][j]++;
                    if(i-1>=0 && j+1<m && a[i-1][j+1] != '*') a[i-1][j+1]++;
                    if(j+1<m && a[i][j+1] != '*') a[i][j+1]++;
                    if(i+1<n && j+1<m && a[i+1][j+1] != '*') a[i+1][j+1]++;
                    if(i+1<n && a[i+1][j] != '*') a[i+1][j]++;
                    if(i+1<n && j-1>=0 && a[i+1][j-1] != '*') a[i+1][j-1]++;
                    if(j-1>=0 && a[i][j-1] != '*') a[i][j-1]++;
                    if(i-1>=0 && j-1>=0 && a[i-1][j-1] != '*') a[i-1][j-1]++;
                }
            }
        }
        cout << "Field #" << cas << ":" << endl;
        for(int i=0; i<n; i++){
            cout << a[i] << endl;
        }
        cout << endl;
        cas++;
    }
    return 0;
}
