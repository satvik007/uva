#include <bits/stdc++.h>
#define MAX_BOLTS 500
#define MAX_NUTS 500

int nuts,bolts;
int fits[MAX_BOLTS][MAX_NUTS];
int match[MAX_BOLTS];

void read_input_data(void){
    int n,b;
    scanf("%d%d",&bolts,&nuts);
    for(b=0;b<bolts;b++){
        for(n=0;n<nuts;n++){
            scanf("%d",&fits[b][n]);
        }
    }
}

int nut_used[MAX_NUTS];
int bestmatched;

int augment(int u){
    if(nut_used[u]) return 0;
    nut_used[u] = 1;
    for(int v = 0; v<nuts; v++){
        if(fits[u][v] > 0 && (match[v] == -1 || augment(match[v]))){
            match[v] = u;
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cases,caseno;
    scanf("%d",&cases);
    for(caseno=1;caseno<=cases;caseno++){
        read_input_data();
        bestmatched = 0;
        memset(match, -1, sizeof match);
        for(int i=0; i<bolts; i++){
            memset(nut_used, 0, sizeof nut_used);
            bestmatched += augment(i);
        }
        printf("Case %d: ",caseno);
        printf("a maximum of %d nuts and bolts ",bestmatched);
        printf("can be fitted together\n");
    }
    return 0;
}


