#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

int numDiffPF[1000005], M[1000005], mu[1000005], squareFree[1000005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    memset(squareFree, 1, sizeof squareFree);
    memset(numDiffPF, 0, sizeof numDiffPF);
    M[1] = 1; mu[1] = 1;
    for (int i = 2; i < 1000001; i++){
        if (numDiffPF[i] == 0){
            for (int j = i; j < 1000001; j += i){
                numDiffPF[j]++;
                if(i*i > 0 && j % (i*i) == 0) squareFree[j] = 0;
            }
        }
        if(squareFree[i]) {
            if(numDiffPF[i] % 2) mu[i] = -1;
            else mu[i] = 1;
        }else{
            mu[i] = 0;
        }
        M[i] = M[i-1] + mu[i];
    }
    int n;
    int a[10000]; int j = 0;
    while(cin >> n, n){
        a[j] = n; j++;
    }
    for(int i=0; i<j; i++){
        cout << setw(8) << a[i] << setw(8) << mu[a[i]] << setw(8) << M[a[i]] << "\n";
    }
    return 0;
}