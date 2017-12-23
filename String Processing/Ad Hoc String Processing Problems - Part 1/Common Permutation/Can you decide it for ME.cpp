#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <limits>
#include <sstream>
#include <string>
#include <regex>
#define iter(a,b,c,d) for(a = b; a < c; a+=d)
#define ited(a,b,c,d) for(a = b; a > c; a-=d)
#define li long int
#define uli unsigned li
#define ll long li
#define ull unsigned ll
#define si(a) scanf("%d",&a)
#define sli(a) scanf("%ld",&a)
#define sll(a) scanf("%lld",&a)
#define slu(a) scanf("%llu",&a)
#define sf(a) scanf("%f",&a)
#define slf(a) scanf("%lf",&a)
#define PI 3.1415926
using namespace std;
int main()
{
    /*freopen("1in.txt", "r", stdin);
    freopen("1out.txt", "w", stdout);*/
    char str[100];
    int n; si(n);
    regex r("(\\?+)(M)(\\?+)(E)(\\?+)");
    int i;
    cin.ignore(100,'\n');
    while(n--)
    {
        gets(str);
        if(regex_match(str,r))
        {
            int l = strlen(str);
            int m = find(str,str+l,'M') - str;
            int e = (find(str,str+l,'E') - str) - m - 1;
            int en = l - (e + m + 2);
            //cout << m << " " << e << " " << en << endl;
            if(m+e == en) puts("theorem");
            else puts("no-theorem");
        }
        else puts("no-theorem");
    }
    return 0;
}