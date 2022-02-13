#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e5+5,M=2e6+7,OO=0x3f3f3f3f;

char s[N];
int n,q;

struct node{
    int arr[26];
};

node operator+(const node &lf,const node &rt){
    node ret;
    for(int i=0;i<26;++i)
        ret.arr[i]=lf.arr[i]+rt.arr[i];
    return ret;
}

void init(node &cur){
    memset(cur.arr,0,sizeof cur.arr);
}
node seg[4*N];

void build(int si=0,int ss=0,int se=n-1){
    init(seg[si]);
    if(ss==se){
        seg[si].arr[s[ss]-'a']=1;
        return;
    }
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    build(lf,ss,md);
    build(rt,md+1,se);
    seg[si]=seg[lf]+seg[rt];
}
node identity;
node query(int qs,int qe,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return identity;
    if(ss>=qs&&se<=qe) return seg[si];
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    return query(qs,qe,lf,ss,md)+query(qs,qe,rt,md+1,se);
}

void update(int qi,char c,int si=0,int ss=0,int se=n-1){
    if(ss>qi||se<qi) return;
    if(ss==se){
        init(seg[si]);
        seg[si].arr[c-'a']=1;
        return;
    }
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    update(qi,c,lf,ss,md);
    update(qi,c,rt,md+1,se);
    seg[si]=seg[lf]+seg[rt];
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    scanf("%s",s);
    scanf("%d",&q);
    n=strlen(s);

    build();

    while(q--){
        int op;
        scanf("%d",&op);
        if(op==2){
            int l,r;
            scanf("%d%d",&l,&r);
            --l,--r;
            node ans=query(l,r);
            int cnt=0;
            for(int i=0;i<26;++i)
                cnt+=(ans.arr[i]>0);
            printf("%d\n",cnt);
        }
        else{
            int id;char c;
            scanf("%d %c",&id,&c);
            --id;
            update(id,c);
        }
    }



    return 0;
}
