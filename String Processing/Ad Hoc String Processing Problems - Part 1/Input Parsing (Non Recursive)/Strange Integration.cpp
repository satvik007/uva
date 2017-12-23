#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;
struct E {
    string lv, rv, op;
    E(string a, string b, string c):
        lv(a), op(b), rv(c) {}
    E():
        lv(""), op(""), rv("") {}
};
map<string, E> R;
string getLeft(string exp) {
    if(R.find(exp) == R.end())
        return "-1";
    return R[exp].op;
    int i, bracket = 0;
    for(i = exp.length()-1; i >= 0; i--) {
        if(exp[i] == ')')       bracket++;
        else if(exp[i] == '(')  bracket--;
        else {
            if(bracket == 0) {
                if(exp[i] == '*')
                    return "*";
                if(exp[i] == '+')
                    return "+";
            }
        }
    }
    return "-1";
}
string getRight(string exp) {
    if(R.find(exp) == R.end())
        return "-1";
    return R[exp].op;
    int i, bracket = 0;
    for(i = 0; i < exp.length(); i++) {
        if(exp[i] == ')')       bracket++;
        else if(exp[i] == '(')  bracket--;
        else {
            if(bracket == 0) {
                if(exp[i] == '*')
                    return "*";
                if(exp[i] == '+')
                    return "+";
            }
        }
    }
    return "-1";
}
string dfs(string nd) {
    E info = R[nd];
    string left, right;
    if(info.lv[0] < '0' || info.lv[0] > '9')
        left = dfs(info.lv);
    else
        left = info.lv;//integer
    if(info.rv[0] < '0' || info.rv[0] > '9')
        right = dfs(info.rv);
    else
        right = info.rv;//integer
    string l = getLeft(info.lv), r = getRight(info.rv);
    if(l == "-1" && r == "-1")
        return left + info.op + right;
    if(info.op == "+") {
        if(r == "-1" || r == "*")
            return left + "+" + right;
        return left + "+(" + right + ")";
    } else {
        if(l == "+" && (r == "+" || r == "*"))
            return "(" + left + ")*(" + right + ")";
        if(l == "+")
            return "(" + left + ")*" + right;
        if(r == "-1")
            return left + "*" + right;
        return left + "*(" + right + ")";
    }
}
int main() {
    int n, testcase, cases = 0;
    scanf("%d", &testcase);
    while(testcase--) {
        scanf("%d", &n);
        R.clear();
        char val[100], rv1[100], rv2[100], op[100];
        int i, j, k;
        for(i = 0; i < n; i++) {
            scanf("%s %*s %s %s %s", val, rv1, op, rv2);
            R[val] = E(rv1, op, rv2);
        }
        string ret = dfs(val);
        printf("Expression #%d: ", ++cases);
        cout << ret << endl;
    }
    return 0;
}