#include <bits/stdc++.h>

using namespace std;

const int N=8e3+5,OO=0x3f3f3f3f;
int t,n,k;
int grid[200][200];

bool ok(){
    for(int i=0;i<n;++i){
        int cnt=0;
        for(int j=0;j<n;++j){
            if(grid[i][j])
                ++cnt;
        }
        if(cnt&1)
            return false;
    }
    for(int i=0;i<n;++i){
        int cnt=0;
        for(int j=0;j<n;++j){
            if(grid[j][i])
                ++cnt;
        }
        if(cnt&1)
            return false;
    }
    return true;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    while(~scanf("%d",&n),n){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                scanf("%d",grid[i]+j);
            }
        }
        if(ok()){
            printf("OK\n");
            continue;
        }
        bool found=0;
        for(int i=0;i<n&&!found;++i){
            for(int j=0;j<n&&!found;++j){
                grid[i][j]=abs(1-grid[i][j]);
                if(ok()){
                    found=1;
                    printf("Change bit (%d,%d)\n",i+1,j+1);
                }
                grid[i][j]=abs(1-grid[i][j]);
            }
        }
        if(!found)
            printf("Corrupt\n");
    }
    return 0;
}
