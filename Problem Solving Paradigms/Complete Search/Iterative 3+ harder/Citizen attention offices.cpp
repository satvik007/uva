#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, u, v, w, size = 25, counter, n, min1;
    cin >> t;
    vi a(25);
    vi b(5);
    vi ans(5);
    while(t--){
        cin >> n;
        a.assign(25, 0);
        for(int i=0; i<n; i++){
            cin >> u >> v >> w;
            a[5*u + v] = w;
        }

        min1 = INT_MAX;
        for(int i=0; i<size-4; i++){ for(int j=i+1; j<size-3; j++){ for(int r=j+1; r<size-2; r++){ for(int m=r+1; m<size-1; m++){ for(int p=m+1; p<size; p++){
                            counter = 0;
                            for(int s = 0; s<25; s++){
                                if(a[s]){
                                    b[0] = abs(i/5-s/5) + abs(i%5 - s%5);
                                    b[1] = abs(j/5-s/5) + abs(j%5 - s%5);
                                    b[2] = abs(r/5-s/5) + abs(r%5 - s%5);
                                    b[3] = abs(m/5-s/5) + abs(m%5 - s%5);
                                    b[4] = abs(p/5-s/5) + abs(p%5 - s%5);
                                    counter += a[s] * (*min_element(b.begin(), b.end()));
                                }
                            }
                            if(counter < min1){
                                //cout << counter << endl;
                                min1 = counter;
                                ans[0] = i; ans[1] = j; ans[2] = r; ans[3] = m; ans[4] = p;
                            }
                        }}}}}
        cout << ans[0];
        for(int i=1; i<5; i++) cout << " " << ans[i]; cout << "\n";
    }
    return 0;
}
