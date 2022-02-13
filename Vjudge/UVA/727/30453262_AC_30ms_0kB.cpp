#include <bits/stdc++.h>

using namespace std;

const int N=5e5+10;

int prec(char c){
    if(c=='(') return 0;
    if(c=='+'||c=='-') return 1;
    return 2;
}

int main(){

    int t,tc=0;
    scanf("%d\n\n",&t);
    while(t--){
        if(tc++) puts("");
        string infix;
        stack<char> ops;
        string s;
        while(getline(cin,s)&&s.length()>0){
            char c=s[0];
            if(c>='0'&&c<='9'){
                infix+=c;
            }
            else if(c=='('){
                ops.push(c);
            }
            else if(c==')'){
                while(ops.top()!='(')
                    infix+=ops.top(),ops.pop();
                ops.pop();
            }
            else{
                while(!ops.empty()&&prec(ops.top())>=prec(c))
                    infix+=ops.top(),ops.pop();
                ops.push(c);
            }
        }
        while(!ops.empty()) infix+=ops.top(),ops.pop();
        printf("%s\n",infix.c_str());
    }

    return 0;
}
