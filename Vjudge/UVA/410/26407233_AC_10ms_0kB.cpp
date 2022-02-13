#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k,q,c,s;
vector<int> ans[15];
int arr[15];

int main(){
    //freopen("myfile.txt","w",stdout);
    int tc=1;
    while(~scanf("%d%d",&c,&s)){
        for(int i=0;i<15;++i)
            ans[i].clear();
        double avg=0,imb=0;
        for(int i=0;i<s;++i)
            scanf("%d",arr+i),avg+=arr[i];
        avg/=c;
        for(int i=s;i<2*c;++i)
            arr[i]=0;
        sort(arr,arr+2*c);
        for(int i=0;i<c;++i){
            imb+=abs(avg-(arr[i]+arr[2*c-1-i]));
            if(arr[i]!=0)
                ans[i].push_back(arr[i]);
            if(arr[2*c-1-i]!=0)
                ans[i].push_back(arr[2*c-1-i]);
        }
        printf("Set #%d\n",tc++);
        int pr=0;
        for(int i=0;i<c;++i){
            printf(" %d:",pr++);
            for(int j=0;j<ans[i].size();++j){
                printf(" %d",ans[i][j]);
            }
            printf("\n");
        }
        printf("IMBALANCE = %.5f\n\n",imb);
    }
    return 0;
}
