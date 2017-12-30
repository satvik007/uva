#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef unordered_map <string, int> msi;

msi map1, map2;
vector <string> a(4);
int visited[6][6], used[120];

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int points(int size){
    if(size == 3 || size == 4) return 1;
    else if(size == 5) return 2;
    else if(size == 6) return 3;
    else if(size == 7) return 5;
    else if(size >= 8) return 11;
    else cerr << "How did this happen?\n";
}

int explore(int x, int y, string word){
    if(x < 0 || x >= 4 || y < 0 || y >= 4 || visited[x][y]) return 0;
    word += a[x][y];
    if(map2.find(word) == map2.end()) return 0;
    visited[x][y] = 1;
    int val = 0;
    if(map1.find(word) != map1.end() && !used[map1[word]]) {
        //cout << word << endl;
        used[map1[word]] = 1; val += points((int)word.size());
    }
    for(int k=0; k<8; k++){
        val += explore(x + dr[k], y + dc[k], word);
    }
    visited[x][y] = 0;
    return val;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc, q, cas = 1;
    string u;
    cin >> tc;
    while(tc--){
        map1.clear(); map2.clear(); memset(used, 0, sizeof used);
        for(int i=0; i<4; i++) cin >> a[i];
        cin >> q;
        while(q--){
            cin >> u;
            map1[u] = q;
            string temp;
            for(int i=0; i<u.size(); i++){
                temp += u[i];
                map2[temp] = 1;
            }
        }
        int counter = 0;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                memset(visited, 0, sizeof visited);
                counter += explore(i, j, "");
            }
        }
        cout << "Score for Boggle game #" << cas++ << ": " << counter << "\n";
    }
    return 0;
}