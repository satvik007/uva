#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m, k;
vi a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n >> m >> k, n||m||k){
        a.resize(n+m);
        for(int i=0; i<n; i++) a[i] = 1;
        for(int j=n; j<n+m; j++) a[j] = 2;
        int size = n + m;
        bool flag = true;
        int last = 1;
        int current = -1;
        //for(auto el:a) cout << el << " "; cout << endl;
        while(true){
            if(flag){
                if(size == 1) break;
                flag = false;
                current = (current + k) % size;
                last = a[current];
                a.erase(a.begin()+current);
                //cout << 1 << " " << current << " - ";
                size--; current--;
                //for(auto el:a) cout << el << " "; cout << endl;
            }else{
                flag = true;
                current = (k + current) % size;
                if(last == a[current]){
                    a[current] = 1;
                }else
                    a[current] = 2;
                //cout << 2 << " " << current << " - ";
                //for(auto el:a) cout << el << " "; cout << endl;
            }
        }
        if(a[0] == 1){
            cout << "Gared\n";
        }else cout << "Keka\n";
    }
    return 0;
}