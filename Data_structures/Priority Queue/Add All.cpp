#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef pair<int, int> ii;

class satvik
{
public:
    bool operator() (ii a, ii b) {
        if(a.second < b.second) return true;
        if(a.second == b.second && a.first > b.first) return true;
        return false;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    return 0;
}
