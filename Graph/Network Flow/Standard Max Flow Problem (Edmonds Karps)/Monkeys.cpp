#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 2;
const int MAXM = 5 + 2;
const int MAXVAB = 5e4 + 4;

int n, m;
struct Monkey{
    int id;
    int v, a, b;
    Monkey(){}
    Monkey(int _d, int _v, int _a, int _b): id(_d), v(_v), a(_a), b(_b){}
    bool operator < (const Monkey &oth) const{
        if( b != oth.b ) return b > oth.b;
        return v < oth.v;
    }
} monk[ MAXN ];

bool cmpl(const Monkey &x, const Monkey &y){
    return x.a < y.a;
}

typedef pair< int, int > pii;
vector< pii > take[ MAXN ];

bool solve(){
    sort( monk, monk + n, cmpl );
    priority_queue< Monkey > pq;
    int k = 0;
    for(int i = 0; i <= 50000; ++i){
        while( k < n && monk[ k ].a <= i ) pq.push( monk[ k++ ] );
        int space = m;
        vector< Monkey > vec;
        while( space > 0 && !pq.empty() ){
            Monkey tmp = pq.top(); pq.pop();
            if( tmp.b < i ) return false;
            --tmp.v;
            --space;
            if( take[ tmp.id ].empty() || 
                take[ tmp.id ].back().first + take[ tmp.id ].back().second != i )
                    take[ tmp.id ].push_back( pii( i, 1 ) );
            else
                ++take[ tmp.id ].back().second;
            if( tmp.v > 0 ) vec.push_back( tmp );
        }
        for(int i = 0; i < vec.size(); ++i)
            pq.push( vec[ i ] );
    }
    if( k == n && pq.empty() ) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int kase = 0;
    while(cin >> n >> m){
        for(int i = 0; i < n; ++i){
            int v, a, b; cin >> v >> a >> b;
            monk[ i ] = Monkey( i, v, a, --b );
            take[ i ].clear();
        }
        cout << "Case " << (++kase) << ": ";
        if( solve() ){
            cout << "Yes\n";
            for(int i = 0; i < n; ++i){
                cout << take[ i ].size();
                for(int j = 0; j < take[ i ].size(); ++j){
                    cout << " (" << take[ i ][ j ].first << "," << 
                            (take[ i ][ j ].first + take[ i ][ j ].second) << ")";
                }
                cout << "\n";
            }
        } else{
            cout << "No\n";
        }
    }
    return 0;
}