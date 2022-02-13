#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;

int n;
int arr[N];

int seg[4*N];

void build(int si=0,int ss=0,int se=n-1){
    if(ss==se){
        seg[si]=arr[ss];
        return;
    }
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    build(lf,ss,md);
    build(rt,md+1,se);
    seg[si]=min(seg[lf],seg[rt]);
}

int query(int qs,int qe,int qv,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return -1;
    if(seg[si]>=qv) return -1;
    if(ss==se) return ss;
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    int rg=query(qs,qe,qv,rt,md+1,se);
    if(~rg) return rg;
    return query(qs,qe,qv,lf,ss,md);
}


int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);

    build();

    for(int i=0;i<n;++i){
        int pos=query(i+1,n-1,arr[i]);
        printf("%d ",~pos?pos-i-1:pos);
    }

    return 0;
}
