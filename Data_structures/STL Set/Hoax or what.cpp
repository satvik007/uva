#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    while(cin >> n, n){
        //vector <vi> a(n);
        multiset <int> bill;
        int size;
        int temp;
        ll counter = 0;
        for(int i=0; i<n; i++){
            cin >> size;
            //a[i].resize(size);
            for(int j=0; j<size; j++){
                cin >> temp; bill.insert(temp);
            }
            counter += *(--bill.end()) - *bill.begin();
            bill.erase(bill.begin());
            bill.erase(--(bill.end()));
        }
        cout << counter << "\n";
    }
    return 0;
}
