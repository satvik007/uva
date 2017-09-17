#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

int n, m, ans, sum, k;
vi a;

void bs(){
    int lo = *max_element(a.begin(), a.end());
    int hi = INT_MAX;
    int mid;
    while(lo < hi){
        mid = lo + (hi-lo)/2;
        sum = 0;
        k = 1;
        for(int i=0; i<n; i++){
            if(sum + a[i] <= mid){
                sum += a[i];
            }
            else{
                sum = a[i];
                k++;
            }
        }
        //cout << k << endl;
        if(k > m) lo = mid+1;
        else hi = mid;
    }
    ans = lo;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(cin >> n >> m){
        a.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];
        bs();
        cout << ans << "\n";
    }
    return 0;
}
