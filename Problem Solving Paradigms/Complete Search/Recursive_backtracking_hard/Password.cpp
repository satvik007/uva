#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

vector <string> a(6), b(6), ans;
unordered_set <string> map1;

int k;

void solve1(string temp){
    if(temp.size() == 5) {
        map1.insert(temp); return;
    }
    for(int i=0; i<6; i++){
        solve1(temp + a[i][temp.size()]);
    }
}
void solve2(string temp){
    if(temp.size() == 5){
        if(map1.find(temp) != map1.end()) ans.push_back(temp), map1.erase(temp);
        return;
    }
    for(int i=0; i<6; i++){
        solve2(temp + b[i][temp.size()]);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        cin >> k;
        for (int i = 0; i < 6; i++) cin >> a[i];
        for (int j = 0; j < 6; j++) cin >> b[j];
        string temp;
        map1.clear();
        ans.clear();
        solve1(temp); solve2(temp);

        sort(ans.begin(), ans.end());
        auto it = unique(ans.begin(), ans.end());
        ans.resize(it- ans.begin());
        //for(auto el:ans) cout << el << endl;
        if(k > ans.size()) cout << "NO\n";
        else cout << ans[k-1] << "\n";
    }
    return 0;
}