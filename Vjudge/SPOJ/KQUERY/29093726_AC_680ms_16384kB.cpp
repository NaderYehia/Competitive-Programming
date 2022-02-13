#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;


int arr[N];
vector<int> seg[4*N];

int n;
void build(int si=0,int ss=0,int se=n-1){
    if(ss==se){
        seg[si].push_back(arr[ss]);
        return;
    }
    int md=ss+(se-ss)/2,rt=si*2+1,lf=rt++;
    build(lf,ss,md);
    build(rt,md+1,se);
    merge(seg[lf].begin(),seg[lf].end(),seg[rt].begin(),seg[rt].end(),inserter(seg[si],seg[si].begin()));
}

int query(int qs,int qe,int qv,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return 0;
    if(ss>=qs&&se<=qe) return int(seg[si].end()-upper_bound(seg[si].begin(),seg[si].end(),qv));
    int md=ss+(se-ss)/2,rt=si*2+1,lf=rt++;
    return query(qs,qe,qv,lf,ss,md)+query(qs,qe,qv,rt,md+1,se);
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);

    build();
    int q;
    scanf("%d",&q);
    while(q--){
        int l,r,v;
        scanf("%d%d%d",&l,&r,&v);
        --l,--r;
        printf("%d\n",query(l,r,v));
    }

    return 0;
}
