#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

string line;
vi a, b, c;

void flip(int m){
    reverse(a.begin(), a.begin()+m+1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin.peek() != EOF){
        getline(cin, line);
        stringstream sin(line);
        int u; a.clear();
        while(sin >> u) a.push_back(u);
        auto n = (int)a.size();
        b = a;
        for(int i=0; i<n; i++){
            if(i) cout << " " << a[i];
            else cout << a[i];
        }
        cout << "\n";
        sort(b.begin(), b.end());
        while(!is_sorted(a.begin(), a.end())){
            int k, ind;
            for(int i=n-1; i>=0; i--){
                if(a[i] != b[i]){
                    k = i; break;
                }
            }
            int max1 = -1;
            for(int i=0; i<k; i++){
                if(a[i] > max1) {
                    max1 = a[i];
                    ind = i;
                }
            }
            if(ind == 0){
                cout << n - k << " ";
                flip(k);
            }else{
                cout << n - ind << " " << n - k << " ";
                flip(ind); flip(k);
            }
        }
        cout << "0\n";
    }
    return 0;
}