#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

string a;
vi kmp;

int kmpPreprocess(){
    kmp.resize(a.size());
    int i = 0, j = -1; kmp[0] = -1;
    while(i < a.size()){
        while(j >= 0 && a[i] != a[j]) j = kmp[j];
        i++; j++;
        kmp[i] = j;
    }
    return j;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> a, a != "."){
        int t = kmpPreprocess();
        int n = a.size();
        if(n % (n - t) == 0) cout << (n / (n - t)) << endl;
        else cout << "1\n";
    }
    return 0;
}