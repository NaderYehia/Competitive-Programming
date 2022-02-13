#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e6+5,M=2<<30,OO=0x3f3f3f3f;
int t,n,m,k;
string s;
char ch;

int main(){
    //freopen("myfile.txt","w",stdout);
    while(~scanf("%c",&ch)){
        if(ch=='0'||ch=='1'||ch=='#')
            s+=ch,++n;
        if(ch!='#')
            while(~scanf("%c",&ch)){
                if(ch=='0'||ch=='1'||ch=='#')
                    s+=ch,++n;
                if(ch=='#') break;
            }
        if(!n) continue;
        //cout<<s<<endl;
        int exp=1,sum=0;
        for(int i=s.length()-2;i>-1;--i){
            if(s[i]=='1'){
                sum=(sum%131071+exp%131071)%131071;
            }
            exp=(exp*2)%131071;
        }
        puts(sum%131071==0?"YES":"NO");
        s="",n=0;
    }
    return 0;
}
