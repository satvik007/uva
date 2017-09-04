#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair<int, int> ii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    int u, v;
    while(cin >> n){
        stack <int> s;
        queue <int> q;
        priority_queue <int> pq;
        int flag1 = 0, flag2 = 0, flag3 = 0;
        for(int i=0; i<n; i++){
            cin >> u >> v;
            if(u==1){
                s.push(v);
                q.push(v);
                pq.push(v);
            }
            else {
            	if(s.empty()){
            		flag1 = 1;flag2 = 1; flag3 = 1;
            		continue;
				}
                if(s.top() != v) flag1 = 1;
                s.pop();
                if(q.front() != v) flag2 = 1;
                q.pop();
                if(pq.top() != v) flag3 = 1;
                pq.pop();
            }
        }
        if(!flag1 && flag2 && flag3) cout << "stack\n";
        else if(flag1 && !flag2 && flag3) cout << "queue\n";
        else if(flag1 && flag2 && !flag3) cout << "priority queue\n";
        else if(flag1 && flag2 && flag3) cout << "impossible\n";
        else cout << "not sure\n";
    }
    return 0;
}
