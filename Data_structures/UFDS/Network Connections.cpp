#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

class MyUnionFind { // OOP style
private: vi p, rank; // remember: vi is vector<int>
public:
    explicit MyUnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i) {
        int start = i, temp;
        while(i != p[i]) p[i] = p[p[i]], i = p[i];
        while(start != p[start]){
           temp = p[start];
            p[start] = i;
            start = temp;
        }
        return i;
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) { // if from different set
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    size_t n;
    while(t--){
        cin >> n;
        cin.ignore();
        char current;
        int u, v;
        MyUnionFind a(n+1);
        int c1 = 0, c2 = 0;
        while(cin.peek() != '\n' && cin.peek() != EOF){
            cin >> current >> u >> v; cin.ignore();
            //cout << current << " " << u << " " <<  v << endl;
            if(current == 'c') a.unionSet(u, v);
            else {
                if(a.isSameSet(u, v)) c1++;
                else c2++;
            }
        }
        cout << c1 << "," << c2 << "\n";    
        if(t!=0) cout << "\n";
    }
    return 0;
}
