#include<bits/stdc++.h>

using namespace std;

int n,x,w,y,z;
int a[5000];
int b[5000];
int c[5000];
int d[5000];
vector<int> sum1,sum2;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d%d%d",&x,&w,&y,&z);
        a[i]=x;
        b[i]=w;
        c[i]=y;
        d[i]=z;
    }
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            sum1.push_back(a[i]+b[j]);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            sum2.push_back(c[i]+d[j]);
    sort(sum2.begin(),sum2.end());
    long long cnt=0;
    for(int i=0;i<sum1.size();++i)
        if(binary_search(sum2.begin(),sum2.end(),-sum1[i]))
            cnt+=upper_bound(sum2.begin(),sum2.end(),-sum1[i])-lower_bound(sum2.begin(),sum2.end(),-sum1[i]);
    printf("%lld",cnt);
    return 0;
}
