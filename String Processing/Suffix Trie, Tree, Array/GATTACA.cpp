#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define maxn 1000010

char T[maxn];
int n, c[maxn];
int SA[maxn], RA[maxn], tempRA[maxn], tempSA[maxn];
int LCP[maxn], PLCP[maxn], Phi[maxn];

void countingSort(int k){
    int i, sum, maxi = max(n, 300);
    memset(c, 0, sizeof c);
    for(i=0; i<n; i++) c[i+k<n ? RA[i+k] : 0]++;
    for(i=sum=0; i<maxi; i++) {
        int t = c[i]; c[i] = sum; sum += t;
    }
    for(i=0; i<n; i++) tempSA[c[SA[i]+k<n ? RA[SA[i]+k] : 0]++] = SA[i];
    for(i=0; i<n; i++) SA[i] = tempSA[i];
}
void constructSA(){
    int i, k, r;
    for(i=0; i<n; i++) SA[i] = i, RA[i] = T[i];
    for(k=1; k<n; k<<=1){
        countingSort(k); countingSort(0);
        tempRA[SA[0]]=r=0;
        for(i=1; i<n; i++) tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        for(i=0; i<n; i++) RA[i] = tempRA[i];
        if(RA[SA[n-1]] == n-1) break;
    }
}
void calculateLCP(){
    int i, L;
    Phi[SA[0]] = -1;
    for(i=1; i<n; i++) Phi[SA[i]] = SA[i-1];
    for(i=L=0; i<n; i++){
        if(Phi[i] == -1){ PLCP[i] = 0; continue;}
        while(T[i+L] != '.' && T[i+L] == T[Phi[i]+L]) L++;
        PLCP[i] = L;
        L = max(L-1,0);
    }
    for(i=0; i<n; i++) LCP[i] = PLCP[SA[i]];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--){
        cin >> T; n = strlen(T);
        T[n++] = '$'; T[n] = '\0';
        constructSA();
        calculateLCP();
        int max1=0;
        for(int i=0; i<n; i++){
            if(LCP[i] > LCP[max1]) max1 = i;
        }
        if(max1 == 0) cout << "No repetitions found!\n";
        else{
            int size = 0;
            char P[maxn];
            for(; SA[max1-1]+size < n && SA[max1]+size < n && T[SA[max1-1]+size] == T[SA[max1]+size]; size++) P[size] = T[SA[max1-1]+size];
            int counter = 0; P[size] = '\0';
            int k = max1 - 1;
            while(k<n && strstr(T+SA[k], P) == T+SA[k]){
                k++, counter++;
            }
            cout << P << " " << counter << endl;
        }
    }
    return 0;
}