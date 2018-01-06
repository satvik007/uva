#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define MAX_N 101010

char T[MAX_N];
int RA[MAX_N], tempRA[MAX_N], SA[MAX_N], tempSA[MAX_N], c[MAX_N];
int Phi[MAX_N], PLCP[MAX_N], LCP[MAX_N], n;

const int nr_max = 100;
int nr, lengths[nr_max], counters[nr_max];
int Owners[MAX_N];

void countingSort(int k) {
    int i, sum, maxi = max(300, n);   // up to 255 ASCII chars or length of n
    memset(c, 0, sizeof c);                          // clear frequency table
    for (i = 0; i < n; i++)       // count the frequency of each integer rank
        c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++) {
        int t = c[i]; c[i] = sum; sum += t;
    }
    for (i = 0; i < n; i++)          // shuffle the suffix array if necessary
        tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    for (i = 0; i < n; i++)                     // update the suffix array SA
        SA[i] = tempSA[i];
}
void constructSA() {         // this version can go up to 100000 characters
    int i, k, r;
    for (i = 0; i < n; i++) RA[i] = T[i];                 // initial rankings
    for (i = 0; i < n; i++) SA[i] = i;     // initial SA: {0, 1, 2, ..., n-1}
    for (k = 1; k < n; k <<= 1) {       // repeat sorting process log n times
        countingSort(k);  // actually radix sort: sort based on the second item
        countingSort(0);          // then (stable) sort based on the first item
        tempRA[SA[0]] = r = 0;             // re-ranking; start from rank r = 0
        for (i = 1; i < n; i++)                    // compare adjacent suffixes
            tempRA[SA[i]] = // if same pair => same rank r; otherwise, increase r
                    (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        for (i = 0; i < n; i++)                     // update the rank array RA
            RA[i] = tempRA[i];
        if (RA[SA[n-1]] == n-1) break;               // nice optimization trick
    }
}
void computeLCP() {
    int i, L;
    Phi[SA[0]] = -1;                                         // default value
    for (i = 1; i < n; i++)                            // compute Phi in O(n)
        Phi[SA[i]] = SA[i-1];    // remember which suffix is behind this suffix
    for (i = L = 0; i < n; i++) {             // compute Permuted LCP in O(n)
        if (Phi[i] == -1) { PLCP[i] = 0; continue; }            // special case
        while (T[i + L] != '.' && T[i + L] == T[Phi[i] + L]) L++; // L increased max n times
        PLCP[i] = L;
        L = max(L-1, 0);                             // L decreased max n times
    }
    for (i = 0; i < n; i++)                            // compute LCP in O(n)
        LCP[i] = PLCP[SA[i]];   // put the permuted LCP to the correct position
}
int owner(int idx) {
    for (int i = 0, length = lengths[i] + 1; ; i++, length += lengths[i] + 1) {
        if (idx < length - 1) return i;
        else if (idx == length - 1) return -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    bool printed = false;
    while (cin >> nr, nr) {
        if (printed) cout << "\n"; printed = true;
        if (nr == 1) {
            cin >> T; cout << (T) << "\n"; continue;
        }
        n = 0;
        for (int i = 0; i < nr; i++) {
            cin >> T + n;
            lengths[i] = (int)strlen(T + n);
            n += lengths[i];
            T[n++] = '.';
        }
        T[n] = '\0';
        constructSA();
        computeLCP();
        for(int i=0; i<n; i++) cout << T + SA[i] << " " << LCP[i] << endl;
        for (int i = 0; i < n; i++) Owners[i] = owner(SA[i]);
        int lcs_length = 0;
        memset(counters, 0, sizeof(counters));
        for (int i = nr, j = nr, total = 0; j < n; ) {
            if (total <= nr / 2) {
                if (!counters[Owners[j++]]++)
                    ++total;
            }
            if (total > nr / 2) {
                lcs_length = max(lcs_length, LCP[min_element(LCP + i + 1, LCP + j) - LCP]);
                if (!--counters[Owners[i++]])
                    --total;
            }
        }
        if (!lcs_length) {
            cout << ("?\n"); continue;
        }
        int psa = -1;
        memset(counters, 0, sizeof(counters));
        for (int i = nr, j = nr, total = 0; j < n; ) {
            if (total <= nr / 2) {
                if (!counters[Owners[j++]]++)
                    ++total;
            }
            if (total > nr / 2) {
                int k = (int)(min_element(LCP + i + 1, LCP + j) - LCP);
                if (LCP[k] == lcs_length &&
                    (psa == -1 || strncmp(T + psa, T + SA[k], lcs_length))) {
                    psa = SA[k];
                    char c = T[psa + lcs_length];
                    T[psa + lcs_length] = '\0';
                    cout << (T + psa) << "\n";
                    T[psa + lcs_length] = c;
                }
                if (!--counters[Owners[i++]])
                    --total;
            }
        }
    }
    return 0;
}