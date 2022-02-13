#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tc=1;
    scanf("%d",&t);
    while(t--){
        string s;
        cin>>s;
        int len=s.length();
        if(s[len-2]=='c'&&s[len-1]=='h'){
            s+='e';
            s+='s';
            cout<<s<<endl;
            continue;
        }
        if(s[len-2]=='f'&&s[len-1]=='e'){
            s.pop_back();s.pop_back();
            s+='v';
            s+='e';
            s+='s';
            cout<<s<<endl;
            continue;
        }
        if(s[len-1]=='x'||s[len-1]=='s'||s[len-1]=='o'){
            s+='e';
            s+='s';
            cout<<s<<endl;
            continue;
        }
        if(s[len-1]=='f'){
            s.pop_back();
            s+='v';
            s+='e';
            s+='s';
            cout<<s<<endl;
            continue;
        }
        if(s[len-1]=='y'){
            s.pop_back();
            s+='i';
            s+='e';
            s+='s';
            cout<<s<<endl;
            continue;
        }
        s+='s';
        cout<<s<<endl;
    }
    return 0;
}
