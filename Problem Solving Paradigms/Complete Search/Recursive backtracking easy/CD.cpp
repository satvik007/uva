#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

vi a;
int max1, n, counter, k;
int ans;
unsigned int countSetBits(int n)
{
    unsigned int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    return count;
}
void jeffDean(int u, int mask){
    if(abs(u-k) < max1 ) max1 = abs(u-k), ans = mask;
    for(int i=0; i<n; i++){
        if(!(mask & (1<<i))) jeffDean(u+a[i], mask|(1<<i));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> k >> n){
        a.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];
        max1 = INT_MAX;
        jeffDean(0, 0);
        cout << countSetBits(ans) << "\n";
    }
    return 0;
}
