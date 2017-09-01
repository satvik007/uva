#include <bits/stdc++.h>

using namespace std;
typedef vector <int> vi;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("in.txt");
    ofstream cout("out.txt");
    int t;
    cin >> t;
    while(t--){
        int n, s, q;
        cin >> n >> s >> q;
        vector <queue<int>> qa(n);
        stack <int> sa;
        ll counter = 0;
        for(int i=0; i<n; i++){
            int size;
            cin >> size;
            for(int j=0; j<size; j++){
                int temp;
                cin >> temp;
                counter++;
                qa[i].push(temp-1);
            }
        }
        int time = 0;
        while(counter > 0){
            for(int i=0; i<n; i++){
                while(!sa.empty() && (sa.top() == i || qa[i].size() < q)){
                    if(sa.top() == i) counter--;
                    else qa[i].push(sa.top());
                    sa.pop();
                    time += 1;
                }
                while(!qa[i].empty() && sa.size() < s){
                    time += 1;
                    sa.push(qa[i].front());
                    qa[i].pop();
                }
                if(counter == 0) break;
                time += 2;
            }
        }
        cout << time << "\n";
    }
    return 0;
}
