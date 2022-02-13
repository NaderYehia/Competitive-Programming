#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;

int n,q;
int arr[N];
int seg[4*N];

void build(int si=0,int ss=0,int se=n-1){
    if(ss==se){
        seg[si]=(arr[ss]>0?1:arr[ss]==0?0:-1);
        return;
    }
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    build(lf,ss,md);
    build(rt,md+1,se);
    seg[si]=seg[lf]*seg[rt];
}

void update(int qi,int qv,int si=0,int ss=0,int se=n-1){
    if(ss>qi||se<qi) return;
    if(ss==se){
        seg[si]=(qv>0?1:qv==0?0:-1);
        return;
    }
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    update(qi,qv,lf,ss,md);
    update(qi,qv,rt,md+1,se);
    seg[si]=seg[lf]*seg[rt];
}

int query(int qs,int qe,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return 1;
    if(ss>=qs&&se<=qe) return seg[si];
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    return query(qs,qe,lf,ss,md)*query(qs,qe,rt,md+1,se);
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    while(~scanf("%d%d",&n,&q)){
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);

        build();

        while(q--){
            char ch;
            int x,y;
            scanf(" %c%d%d",&ch,&x,&y);
            if(ch=='C'){
                --x;
                update(x,y);
            }
            else{
                --x,--y;
                int ans=query(x,y);
                printf("%c",ans==0?'0':ans==1?'+':'-');
            }
        }
        printf("\n");
    }

    return 0;
}
