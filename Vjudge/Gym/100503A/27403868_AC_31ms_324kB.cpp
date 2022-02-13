#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=2e7+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m;
char s[300][300];
bool vis[300][300];
char inst[505];

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d\n",&n,&m);
    for(int i=1;i<2*n;i+=2){
        for(int j=1;j<2*m;j+=2){
            char ch;
            scanf("%c",&ch);
            if(ch>='0'&&ch<='9'){
                s[i][j]=ch;
            }
            else {
                scanf("%c",&ch);
                s[i][j]=ch;
            }
        }
    }
    scanf("%s",inst);
    int curR=0,curC=0; char to='e';
    int ans=0;
    memset(vis,0,sizeof vis);
    for(int i=0;inst[i];++i){
        if(inst[i]=='M'){
            if(to=='e'){
                ++curC;
                if(curR-1>0){
                    int x=s[curR-1][curC]-'0';
                    if(!vis[curR-1][curC])
                        ans+=x,vis[curR-1][curC]=1;
                    else
                        ans+=x/2;
                }
                if(curR+1<2*n){
                    int x=s[curR+1][curC]-'0';
                    if(!vis[curR+1][curC])
                        ans+=x,vis[curR+1][curC]=1;
                    else
                        ans+=x/2;
                }
                ++curC;
            }
            else if(to=='w'){
                --curC;
                if(curR-1>0){
                    int x=s[curR-1][curC]-'0';
                    if(!vis[curR-1][curC])
                        ans+=x,vis[curR-1][curC]=1;
                    else
                        ans+=x/2;
                }
                if(curR+1<2*n){
                    int x=s[curR+1][curC]-'0';
                    if(!vis[curR+1][curC])
                        ans+=x,vis[curR+1][curC]=1;
                    else
                        ans+=x/2;
                }
                --curC;
            }
            else if(to=='s'){
                ++curR;
                if(curC-1>0){
                    int x=s[curR][curC-1]-'0';
                    if(!vis[curR][curC-1])
                        ans+=x,vis[curR][curC-1]=1;
                    else
                        ans+=x/2;
                }
                if(curC+1<2*m){
                    int x=s[curR][curC+1]-'0';
                    if(!vis[curR][curC+1])
                        ans+=x,vis[curR][curC+1]=1;
                    else
                        ans+=x/2;
                }
                ++curR;
            }
            else if(to=='n'){
                --curR;
                if(curC-1>0){
                    int x=s[curR][curC-1]-'0';
                    if(!vis[curR][curC-1])
                        ans+=x,vis[curR][curC-1]=1;
                    else
                        ans+=x/2;
                }
                if(curC+1<2*m){
                    int x=s[curR][curC+1]-'0';
                    if(!vis[curR][curC+1])
                        ans+=x,vis[curR][curC+1]=1;
                    else
                        ans+=x/2;
                }
                --curR;
            }
        }
        else if(inst[i]=='L'){
            if(to=='s')
                to='e';
            else if(to=='w')
                to='s';
            else if(to=='n')
                to='w';
            else if(to=='e')
                to='n';
        }
        else if(inst[i]=='R'){
            if(to=='e')
                to='s';
            else if(to=='s')
                to='w';
            else if(to=='w')
                to='n';
            else if(to=='n')
                to='e';
        }
    }
    printf("%d",ans);
    return 0;
}
