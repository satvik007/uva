#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

vector <ll> a;

bool comp(ll x, ll y) {
    if(x > 0 && y > 0){
        if(x <= y) return true;
        return false;
    }
    if(x > 0) return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    ll p=1, q=1, r=1, s=1;
    for(int i=0; i<33; i++){
        q = 1;
        for(int j=0; j<22; j++){
            r = 1;
            for(int k=0; k<15; k++){
                s = 1;
                for(int l=0; l<13; l++){
                    a.push_back(p*q*r*s);
                    s *= 7;
                }
                r *= 5;
            }
            q *= 3;
        }
        p *= 2;
    }
    sort(a.begin(), a.end(), comp);
    while(cin >> n, n){
        cout << "The " << n;
        if(n%10 == 1 && n%100 != 11)
            cout << ("st");
        else if(n%10 == 2 && n%100 != 12)
            cout << ("nd");
        else if(n%10 == 3 && n%100 != 13)
            cout << ("rd");
        else
            cout << ("th");
        cout << " humble number is " << a[n-1] << ".\n";

    }
    return 0;
}
