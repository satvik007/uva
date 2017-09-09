#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;

class Data{
public:
    string name;
    int l, h;
};

bool satvik(Data a, Data b){
    return a.h < b.h;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    int d, q, temp;
    Data tem;
    vector <Data> a;
    while(t--){
        cin >> d;
        a.resize(d);
        for(int i=0; i<d; i++){
            cin >> a[i].name >> a[i].l >> a[i].h;
        }
        sort(a.begin(), a.end(), satvik);
        //for(auto el:a) cout << el.l << " "; cout << endl;
        cin >> q;
        int counter = 0;
        int ind = 0;
        for(int j=0; j<q; j++){
            cin >> temp;
            counter = 0;
            for(int i = 0; i<d; i++){
            	if(a[i].l <= temp && a[i].h>= temp){
            		counter++;
            		ind = i;
            		if(counter > 1) break;
				}
			}
            if(counter == 1){
                cout << a[ind].name << "\n";
            }
            else cout << "UNDETERMINED\n";
        }
        if(t!=0) cout << "\n";
    }
}
