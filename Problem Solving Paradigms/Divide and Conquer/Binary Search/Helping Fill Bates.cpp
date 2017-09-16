#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string a;
    cin >> a;
    int n = a.size();
    vector <vi> status(128);
    for(int i=0; i<n; i++){
        status[a[i]].push_back(i);
    }
    int q;
    cin >> q;
    string b;
    auto it = status['a'].begin();
    int current = 0;
    int flag = 0;
    int start, end;
    while(q--){
        cin >> b;
        flag = 0;
        current = -1;
        for(auto el:b){
            it = upper_bound(status[el].begin(), status[el].end(), current);
            if(it == status[el].end()){
                flag = 1; break;
            }
            if(current == -1) start = *it;
            current = *it;
            //cout << current << " ";
        }
        if(flag) cout << "Not matched\n";
        else{
            cout << "Matched " << start << " " << current << "\n";
        }

    }
    return 0;
}
