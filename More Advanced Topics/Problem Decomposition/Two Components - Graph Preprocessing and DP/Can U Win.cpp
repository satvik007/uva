#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, ll> ii;
typedef pair <int, ii> iii;

#define inf (int)1e9

int k;
vector <string> a(8);
map <ii, int> dp, visited;
ll mask2;
int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool solve(ll mask1, int pos){
    dp.clear(); visited.clear();
    queue <pair<int, ii>> pq; pq.push({0, {pos, mask1}});
    visited[{pos, mask1}] = 1;
    int ans = 0;
    pair <int, ii> current;
    while(!pq.empty()){
        current = pq.front(); pq.pop();
        if(current.first > k || current.first > 60)
            break;
        if(current.second.second == 0)
            return true;
        for(int k=0; k<8; k++){
            int tx = current.second.first / 8 + dr[k];
            int ty = current.second.first % 8 + dc[k];
            if(tx >= 0 && ty >= 0 && tx < 8 && ty < 8 && !(mask2 & (1LL << (8*tx+ty))) &&
            !visited.count({8*tx + ty, current.second.second & ~(1LL << (8*tx + ty))})){
                visited[{8*tx + ty, current.second.second & ~(1LL << (8*tx + ty))}] = 1;
                pq.push({current.first + 1, {8*tx + ty, current.second.second & ~(1LL << (8*tx + ty))}});
            }
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--){
        cin >> k;
        for(int i=0; i<8; i++)
            cin >> a[i];
        ll mask1 = 0; mask2 = 0;
        int pos = 0;
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(a[i][j] == 'k') pos = 8 * i + j;
                else if(a[i][j] == 'P') mask1 |= (1LL<<(8*i+j));
                else if(a[i][j] != '.') mask2 |= (1LL<<(8*i+j));
            }
        }
        if(solve(mask1, pos))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}