#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

string a;
vi b;

void kmpPreprocess(){
    b.resize(a.size());
    int i=0, j=-1; b[0] = -1;
    while(i < a.size()){
        while(j >= 0 && a[a.size()-i-1] != a[a.size()-j-1]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}
int kmpSearch(){
    int i=0, j=0;
    while(i < a.size()){
        while(j >= 0 && a[i] != a[a.size()-j-1]) j = b[j];
        i++; j++;
    }
    return j;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> a){
        kmpPreprocess();
        int t = kmpSearch();
        string b = a.substr(0, a.size() - t);
        reverse(b.begin(), b.end());
        cout << a << b << endl;
    }

    return 0;
}