#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e4+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,w,n,d[50],v[50];
char grid[20][20];

bool valid(int r,int c){
    return r>-1&&c>-1&&r<n&&c<n;
}

void solve(){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(grid[i][j]=='.'){
                for(char ch='A';ch<='Z';++ch){
                    if((valid(i-1,j)&&grid[i-1][j]==ch)||(valid(i+1,j)&&grid[i+1][j]==ch)||(valid(i,j+1)&&grid[i][j+1]==ch)||(valid(i,j-1)&&grid[i][j-1]==ch)){
                        continue;
                    }
                    grid[i][j]=ch;
                    break;
                }
            }
        }
    }
}

int main(){
    //freopen("myfile.txt","w",stdout);
    int tc=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%s",grid+i);
        solve();
        printf("Case %d:\n",tc++);
        for(int i=0;i<n;++i)
            printf("%s\n",grid[i]);
    }
    return 0;
}
