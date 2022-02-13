#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e3+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,k;
int mem[N][N];
string mem2[N][N];
string s;
string ans;

int solve(int i,int j){
    if(i>j) return 0;
    if(i==j) return 1;
    int &ret=mem[i][j];
    if(~ret) return ret;
    if(s[i]==s[j]) return 2+solve(i+1,j-1);
    int op1=solve(i+1,j);
    int op2=solve(i,j-1);
    return ret=max(op1,op2);
}

string dfs(int i=0,int j=s.length()-1){
    if(mem2[i][j]!="###") return mem2[i][j];
    if(i>j) return "";
    if(i==j){
        string as="";
        as+=s[i];
        return as;
    }
    int ret=solve(i,j);
    if(s[i]==s[j]){
        return s[i]+dfs(i+1,j-1);
    }
    int op1=solve(i+1,j);
    int op2=solve(i,j-1);
    if(op1==op2){
        return mem2[i][j]=min(dfs(i+1,j),dfs(i,j-1));
    }
    else{
        if(ret==op1){
            return dfs(i+1,j);
        }
        else if(ret==op2){
            return dfs(i,j-1);
        }
    }
}

int main(){
    //freopen("myfile.txt","w",stdout);
    while(getline(cin,s)){
        memset(mem,-1,sizeof mem);
        int sol=solve(0,s.length()-1);
        for(int i=0;i<s.length();++i)
            for(int j=0;j<s.length();++j)
                mem2[i][j]="###";
        ans=dfs();
        int len=ans.length();
        if(sol&1){
            for(int i=0;i<len;++i)
                printf("%c",ans[i]);
            for(int i=len-2;i>-1;--i)
                printf("%c",ans[i]);
            printf("\n");
        }
        else{
            for(int i=0;i<len;++i)
                printf("%c",ans[i]);
            for(int i=len-1;i>-1;--i)
                printf("%c",ans[i]);
            printf("\n");
        }
    }
    return 0;
}
