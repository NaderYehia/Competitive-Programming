#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5,M=1e9+7,OO=0x3f3f3f3f;

int n,m,k;
int arr[N][10];

int seg[4*N][10];

void build(int si=0,int ss=0,int se=n-1){
    if(ss==se){
        for(int i=0;i<m;++i)
            seg[si][i]=arr[ss][i];
        return;
    }
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    build(lf,ss,md);
    build(rt,md+1,se);
    for(int i=0;i<m;++i)
        seg[si][i]=max(seg[lf][i],seg[rt][i]);
}

vector<int> query(int qs,int qe,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return vector<int>(m,-OO);
    if(ss>=qs&&se<=qe){
        vector<int> ret;
        for(int i=0;i<m;++i)
            ret.push_back(seg[si][i]);
        return ret;
    }
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    vector<int> l=query(qs,qe,lf,ss,md);
    vector<int> r=query(qs,qe,rt,md+1,se);
    vector<int> ret;
    for(int i=0;i<m;++i)
        ret.push_back(max(l[i],r[i]));
    return ret;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            scanf("%d",arr[i]+j);

    build();

    int i=0,j=0,mxSeg=0;
    vector<int> ans(m,0);
    while(i<n&&j<n){
        if(i>j) j=i;
        vector<int> temp=query(i,j);
        if(accumulate(temp.begin(),temp.end(),0)>k){
            ++i;
            continue;
        }
        if(j-i+1>mxSeg){
            mxSeg=j-i+1;
            ans=temp;
        }
        ++j;
    }
    for(int i=0;i<m;++i)
        printf("%d ",ans[i]);

    return 0;
}
