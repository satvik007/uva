#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int numDiffPF[1000005];
    memset(numDiffPF, 0, sizeof numDiffPF);
    for (int i = 2; i < 1000001; i++)
        if (numDiffPF[i] == 0)
            for (int j = i; j < 1000001; j += i)
                numDiffPF[j]++;
    int n;
    while(cin >> n, n){
        cout << n << " : " << numDiffPF[n] << "\n";
    }
    return 0;
}