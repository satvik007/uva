#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("in.txt");
    //ofstream cout("out.txt");
    int t;
    cin >> t;
    while(t--) {
        int n, time, m;
        cin >> n >> time >> m;
        queue <int> left;
        queue <int> right;
        vi lef;
        vi rig;
        for(int i=0; i<m; ++i){
            int val;
            string temp;
            cin >> val >> temp;
            if(temp == "left") left.push(val), lef.push_back(i);
            else right.push(val), rig.push_back(i);
        }
        int status = -1;
        int curr = 0;
        int k1 = 0;
        int k2 = 0;
        vi ans(m);
        while(!left.empty() || !right.empty()){
            int flag = 0;
            int size = 0;
            if(status == -1){
                while(!left.empty() && curr >= left.front() && size < n){
                    size++;
                    left.pop();
                    ans[lef[k1++]] = curr+time;
                    flag = 1;
                }
                if(flag){
                	status = 1; curr += time;
				} 
            }else {
                while(!right.empty() && curr >= right.front() && size < n){
                    size++;
                    right.pop();
                    ans[rig[k2++]] = curr + time;
                    flag = 1;
                }
                if(flag){
                	status = -1; curr += time;
				} 
            }
            if(flag == 0){
            	if(status == -1){
            		if(left.empty() || !right.empty() && left.front() > right.front()){
            			status = 1;
            			if(right.front()<= curr) curr += time;
            			else curr = right.front()+time;
					} 
            		else curr = left.front();
				}
				else {
					if(right.empty() || !left.empty() && left.front() < right.front()){
						status = -1;
						if(left.front()<= curr) curr += time;
            			else curr = left.front()+time;
					} 
            		else curr = right.front();
				}
			}
        }
        for(int i=0; i<ans.size(); ++i){
        	cout << ans[i] << "\n";
		}
		if(t!=0)cout << "\n";
    }
    return 0;
}
