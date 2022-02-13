#include<bits/stdc++.h>

using namespace std;

const int N=2e3+5;
int t,n,m;
int arr[16];

int main() {
    scanf("%d",&t);
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        bool found=0;
        for(int i=-100;i<=100;++i){
            for(int j=-100;j<=100;++j){
                for(int k=-100;k<100;++k){
                    if(i!=j&&i!=k&&j!=k&&i+j+k==a&&i*j*k==b&&i*i+j*j+k*k==c&&!found)
                        printf("%d %d %d\n",i,j,k),found=1;
                }
            }
        }
        if(!found)
            printf("No solution.\n");
    }

    return 0;
}
