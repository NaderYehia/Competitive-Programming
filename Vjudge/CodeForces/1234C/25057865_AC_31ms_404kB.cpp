#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int q,n,c;
char arr[2][N];


int main() {
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        scanf("%s",arr[0]);
        scanf("%s",arr[1]);
        bool up=0;
        int i;
        for(i=0;i<n;++i){
            if(arr[up][i]=='1'||arr[up][i]=='2'){
                continue;
            }
            else{
                if(arr[up^1][i]=='3'||arr[up^1][i]=='4'||arr[up^1][i]=='5'||arr[up^1][i]=='6'){
                    up^=1;
                    continue;
                }
                break;
            }
        }
        if(i==n&&up)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
