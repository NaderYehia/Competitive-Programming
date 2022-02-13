#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5;
int t,n,c;
string s;
long long mem[N][7];

long long solve(int i,int cnt){
    if(i==s.length()){
        if(cnt==0)
            return 1;
        return 0;
    }
    if(mem[i][cnt]!=-1) return mem[i][cnt];
    long long ret=solve(i+1,cnt);
    if(cnt==3){
        if(s[i]=='o')
            ret+=solve(i+1,cnt-1);
    }
    else if(cnt==5||cnt==2){
        if(i+1<s.length()&&s[i]=='v'&&s[i+1]=='v')
            ret+=solve(i+2,cnt-2);
    }
    return mem[i][cnt]=ret;
}

int main() {
    cin>>s;
    memset(mem,-1,sizeof mem);
    printf("%lld",solve(0,5));
    return 0;
}
