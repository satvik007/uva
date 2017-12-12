#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n >> k){
        int cigar = n, waste = n, temp;
        while(waste >= k){
            cigar += waste/k;
            temp = waste;
            waste -= (waste/k)*k;
            waste += temp / k;
        }
        cout << cigar << "\n";
    }
    return 0;
}