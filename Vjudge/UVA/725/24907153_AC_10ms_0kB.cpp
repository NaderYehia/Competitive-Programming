#include<bits/stdc++.h>

using namespace std;

const int N=2e3+5;
int t,n,m;
bool found;

int main() {
    while(~scanf("%d",&n),n){
        if(t)
           printf("\n");
        ++t;
        found=0;
        for(int i=1234;i<=98765/n;++i){
            int j=i*n;
            int tmp1=i,tmp2=j;
            int vis[15];
            memset(vis,0,sizeof vis);
            if(tmp1<10000) ++vis[0];
            if(tmp2<10000) ++vis[0];
            while(tmp1){
                ++vis[tmp1%10];
                tmp1/=10;
            }
            while(tmp2){
                ++vis[tmp2%10];
                tmp2/=10;
            }
            bool bazet=0;
            for(int i=0;i<10;++i){
                if(vis[i]!=1)
                    bazet=1;
            }
            if(!bazet)
                printf("%.5d / %.5d = %d\n",j,i,n),found=1;
        }
        if(!found)
            printf("There are no solutions for %d.\n",n);
    }

    return 0;
}
