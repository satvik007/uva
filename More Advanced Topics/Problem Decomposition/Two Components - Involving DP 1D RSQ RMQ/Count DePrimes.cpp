#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

#define MAX_N 5000010
int numDiffPF[5000020];
bitset <6000000> bs;
vi primes;
vi imp;
void sieve(){
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i<5000010; i++) if(bs[i]){
		primes.push_back(i);
		for(ll j = i * i; j < 5000010; j += i) bs[j] = 0;
	}
}

int countPrimes(int n){
	int res = n;
	int cnt = 0;
	for(int i=0; primes[i] <= 3000 ; i++){
		if(numDiffPF[res] != -1){
			return numDiffPF[n] = cnt + numDiffPF[res];
		}
		if(res % primes[i] == 0){
			cnt += primes[i];
			while(res % primes[i] == 0) {
				res /= primes[i];
			}
		}
	}
	if(res != 1){
		return numDiffPF[n] = cnt + res;
	}
	return numDiffPF[n] = cnt;
}

void solve(){
	memset(numDiffPF, -1, sizeof numDiffPF);
	for(int i=2; i<MAX_N; i++){
		numDiffPF[i] = countPrimes(i);
	}
	for(int i=2; i<MAX_N; i++){
		if(numDiffPF[i] >= 0 && bs[numDiffPF[i]]) imp.push_back(i);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("in.txt", "r", stdin);
	freopen("out1.txt", "w", stdout);
	sieve();
	solve();
	//cout << imp.size() << endl;
	int u, v;
	while(cin >> u >> v){
		int ind1 = upper_bound(imp.begin(), imp.end(), u) - imp.begin();
		int ind2 = upper_bound(imp.begin(), imp.end(), v) - imp.begin();
		//cout << ind1 << " " << ind2 << "\n";
		int ans = ind2 - ind1 + (imp[ind1-1] == u ? 1 : 0);
		cout << ans << endl;
			
	}
	return 0;
}



