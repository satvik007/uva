#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
    int a,b,count = 0;
    char s,c[1000];
    while(scanf("%d%c%d=%s",&a,&s,&b,c) == 4){
        if(s == '+'){
            if(a + b == atoi(c))
                count++;
        }
        else if(s == '-'){
            if(a - b == atoi(c))
                count++;
        }
    }
    cout << count << endl;
    return 0;
}