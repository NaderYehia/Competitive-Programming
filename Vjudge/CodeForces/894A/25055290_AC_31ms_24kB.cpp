#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int t,n,c;
string s;
int mem[105][4];

int solve(int i,int cnt){
    if(i==s.length()){
        if(cnt==0)
            return 1;
        return 0;
    }
    if(mem[i][cnt]!=-1) return mem[i][cnt];
    int ret=solve(i+1,cnt);
    if(cnt==3&&s[i]=='Q'){
        ret+=solve(i+1,cnt-1);
    }
    else if(cnt==2&&s[i]=='A'){
        ret+=solve(i+1,cnt-1);
    }
    else if(cnt==1&&s[i]=='Q'){
        ret+=solve(i+1,cnt-1);
    }
    return mem[i][cnt]=ret;
}

int main() {
    cin>>s;
    memset(mem,-1,sizeof mem);
    printf("%d",solve(0,3));
    return 0;
}
