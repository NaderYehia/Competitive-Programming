#include <bits/stdc++.h>

using namespace std;

const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k,q;
char grid[N][N];
int r[N];
int c[N];

int main(){
    int tc=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%s",grid[i]);
        }
        scanf("%d\n",&q);
        int tmp=0;
        for(int i=0;i<n;++i)
            r[i]=i,c[i]=i;
        while(q--){
            string s;
            getline(cin,s);
            if(s=="dec"){
                --tmp;
            }
            else if(s=="inc"){
                ++tmp;
            }
            else if(s=="transpose"){
                for(int i=0;i<n;++i){
                    for(int j=i+1;j<n;++j){
                        swap(grid[i][j],grid[j][i]);
                    }
                }
            }
            else if(s[0]=='r'){
                for(int i=0;i<n;++i)
                    swap(grid[s[4]-'1'][i],grid[s[6]-'1'][i]);
            }
            else if(s[0]=='c'){
                for(int i=0;i<n;++i)
                    swap(grid[i][s[4]-'1'],grid[i][s[6]-'1']);
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                grid[i][j]='0'+((grid[i][j]-'0'+tmp+40)%10);
            }
        }
        printf("Case #%d\n",++tc);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                printf("%c",grid[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
