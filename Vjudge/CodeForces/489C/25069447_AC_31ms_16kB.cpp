#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int t,s,m;
int ans[105];
int mn[105];

int main() {
    scanf("%d%d",&m,&s);
    if(((!s)&&m&&m!=1)||(m*9<s)){
        printf("-1 -1");
        return 0;
    }
    for(int i=1;i<=m;++i){
        ans[i]=min(9,s);
        s-=min(9,s);
    }
    for(int i=1;i<=m;++i)
        mn[i]=ans[i];
    if(mn[m]==0){
        for(int i=m;i>0;--i){
            if(mn[i]!=0){
                --mn[i];
                ++mn[m];
                break;
            }
        }
    }
    for(int i=m;i>0;--i)
        cout<<mn[i];
    cout<<" ";
    for(int i=1;i<=m;++i)
        cout<<ans[i];
    return 0;
}
