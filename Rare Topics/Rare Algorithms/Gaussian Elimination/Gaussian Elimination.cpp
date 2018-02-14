#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef vector <int> vi;
#define maxn 1510

ull a[maxn], out[10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--){
        for(int i=0; i<1500; i++)
            cin >> a[i];
        ull base = 1001;
        ull num = a[base-1];
        for(int i=0; i<7; i++){
            out[i] = num % base;
            num -= out[i];
            num /= base;
        }
        bool flag = true;
        for(int i=0; i<1500 && flag; i++){
            num = a[i];
            for(int j=0; j<7; j++){
                num -= out[j];
                if(num % (i+1) != 0){
                    flag = false;
                    break;
                }
                num /= (i+1);
            }
            if(num != 0){
                flag = false;
                break;
            }
        }
        if(flag){
            for(int i=0; i<7; i++){
                if(i) cout << " ";
                cout << out[i];
            }
            cout << "\n";
        }else{
            cout << "This is a smart sequence!\n";
        }
    }
    return 0;
}