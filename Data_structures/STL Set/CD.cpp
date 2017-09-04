#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, m;
    while(cin >> n >> m, n||m){
        vector <int> jack(n);
        int temp;
        for(int i=0; i<n; i++) cin >> jack[i];
        sort(jack.begin(), jack.end());
        int counter = 0;
        for(int i=0; i<m; i++){
            cin >> temp;
            if(binary_search(jack.begin(), jack.end(), temp)) counter++;
        }
        cout << counter << "\n";
    }
    return 0;
}
