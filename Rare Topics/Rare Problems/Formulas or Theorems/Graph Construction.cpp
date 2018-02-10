#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, a[10010];
int b[10010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n, n){
        ll cnt = 0;
        a[0] = INT_MAX;
        for(int i=1; i<=n; i++){
            cin >> a[i], cnt += a[i];
        }
        sort(a+1, a+n+1, greater<int> ());
        b[n] = a[n];
        for(int i=n-1; i>=1; i--){
            b[i] = b[i+1] + a[i];
        }
        b[n+1] = 0;
        //for(int i=1; i<=n; i++) cout << a[i] << " "; cout << endl;
        //for(int i=1; i<=n; i++) cout << b[i] << " "; cout << endl;
        bool flag = true;
        if(a[n] < 0 || cnt % 2)
            flag = false;
        int last = 0, sum;
        for(int i=1; i<=n && flag; i++){
            last += a[i];
            int index = lower_bound(a+i+1, a+n+1, i, greater<int> ()) - a;
            sum = b[index] + (index - i - 1) * (i);
            if(last > (i)*(i-1) + sum)
                flag = false;
        }
        if(flag)
            cout << "Possible\n";
        else cout << "Not possible\n";

    }
    return 0;
}