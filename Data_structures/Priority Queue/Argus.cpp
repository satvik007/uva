#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef pair<int, int> ii;

class satvik
{
public:
    bool operator() (ii a, ii b) {
        if(a.second > b.second) return true;
        if(a.second == b.second && a.first > b.first) return true;
        return false;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    priority_queue <ii, vector <ii> , satvik> a;
    vector <int> b(3001);
    string line;
    int n1, n2;
    while(cin >> line){
        if(line == "#") break;
        cin >> n1 >> n2;
        b[n1] = n2;
        ii temp = {n1, n2};
        a.push(temp);
    }
    int n;
    cin >> n;
    while(n--){
        cout << a.top().first << "\n";
        ii temp = a.top();
        a.pop();
        temp.second += b[temp.first];
        a.push(temp);
    }
    return 0;
}
