#include <bits/stdc++.h>
#define epsilon 1e-9
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, c1, c2;
    vi a;
    a.push_back(50);
    a.push_back(0);
    for(int i=1; i<=20; i++){
        a.push_back(i);
        a.push_back(2*i);
        a.push_back(3*i);
    }
    sort(a.begin(), a.end());
    auto it = unique(a.begin(), a.end());
    a.resize(it - a.begin());
    vi temp(3);
    unordered_set <vi> set1;
    //for(auto el : a) cout << el << " "; cout << endl;
    while(cin >> n, n>0){
    	set1.clear();
        int counter = 0;
        for(int i=0; i<a.size(); i++){
            for(int j=0; j<a.size(); j++){
                for(int k=0; k<a.size(); k++){
                    if(a[i]+a[j]+a[k] == n){
                        counter++;
                        temp[0] = i; temp[1] = j; temp[2] = k;
                        sort(temp.begin(), temp.end());
                        set1.insert(temp);
                    }
                }
            }
        }
        if(counter == 0){
        	cout << "THE SCORE OF " << n << 
			" CANNOT BE MADE WITH THREE DARTS.\n";
		}else{
			cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << 
			" IS " << set1.size() << ".\n";
        	cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << 
			" IS " << counter << ".\n";
		} 
        for(int i=0; i<70; i++) cout << "*"; cout << "\n";
    }
    cout << "END OF OUTPUT\n";
    return 0;
}
