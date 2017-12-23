#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

class Data{
public:
    string name;
    int order, val;
    Data() {}
    Data(int v, string n) : val(v), name(n) {}
};

bool comp(Data x, Data y){
    if(x.val < y.val) return true;
    if(x.val == y.val){
        for(int i=0; i<min(x.name.size(), y.name.size()); i++){
            if(tolower(x.name[i]) < tolower(y.name[i])) return true;
            else if(tolower(x.name[i]) > tolower(y.name[i])) return false;
        }
        if(x.name.size() == y.name.size()) return (x.order <= y.order);
        else return x.name.size() < y.name.size();
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    vector <Data> a;
    while(cin >> n){
        a.resize(n);
        int m; string u, v;
        int tim;
        for(int i=0; i<n; i++){
            tim = 0;
            cin >> u >> v >> m >> v; tim += 60000 * m;
            cin >> m >> v; tim += 1000 * m;
            cin >> m >> v; tim += m;
            Data curr; curr.val = tim; curr.name = u; curr.order = i;
            a[i] = curr;
        }
        sort(a.begin(), a.end(), comp);
        int row = 1, counter = 2;
        for(int i=0; i<n; i++){
            if(counter == 2){
                cout << "Row " << row << "\n"; row++;
                counter = 0;
            }
            cout << a[i].name << "\n";
            counter++;
        }
        cout << "\n";
    }
    return 0;
}