#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n;
unordered_map <string, int> special, target, source;
int used[12];

inline void init(int n){
    string start; for(int i=0; i<n; i++) start += (char)('1' + i);
    queue <string> q; q.push(start);
    target[start] = 0;
    string current, t1, t2, t3;
    int distance;
    while(!q.empty()){
        current = q.front(); q.pop();
        distance = target[current];
        if(distance == 2) break;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                t1 = current.substr(i, j-i+1);
                t2 = current;
                t2.erase(i, j-i+1);
                for(int k=0; k<t2.size(); k++){
                    t3 = t2;
                    t3.insert(k, t1);
                    if(target.find(t3) == target.end()){
                        //cout << t3 << " " << distance + 1 << "\n";
                        target[t3] = distance + 1;
                        q.push(t3);
                    }
                }
            }
        }
    }
}

int solve(const string &b){
    if(!used[n]){
        used[n] = 1; init(n);
    }
    if(target.find(b) != target.end()) return target[b];
    queue <string> q; q.push(b);
    source[b] = 0;
    string current, t1, t2, t3;
    int distance;
    while(!q.empty()){
        current = q.front(); q.pop();
        distance = source[current];
        if(distance == 2) break;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                t1 = current.substr(i, j-i+1);
                t2 = current;
                t2.erase(i, j-i+1);
                for(int k=0; k<t2.size(); k++){
                    t3 = t2;
                    t3.insert(k, t1);
                    if(source.find(t3) == source.end()){
                        source[t3] = distance + 1;
                        if(target.find(t3) != target.end()){
                            return (target[t3] + source[t3]);
                        }
                        q.push(t3);
                    }
                }
            }
        }
    }
    return 5;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    memset(used, 0, sizeof used);
    int cas = 1;
    while(cin >> n, n){
        source.clear();
        char last;
        string b;
        for(int i=0; i<n; i++){
            cin >> last; b += last;
        }
        int ans = solve(b);
        cout << "Case " << cas++ << ": " << ans << "\n";
    }
    return 0;
}