#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;

int n;
char s[N];

struct node{
    int pre,suf;
};

node operator+(const node &lf,const node &rt){
    node ret;

    int to_merge=min(lf.suf,rt.pre);
    ret.pre=lf.pre+rt.pre-to_merge;
    ret.suf=lf.suf+rt.suf-to_merge;

    return ret;
}

node seg[4*N];

void build(int si=0,int ss=0,int se=n-1){
    if(ss==se){
        seg[si].pre=(s[ss]==')');
        seg[si].suf=(s[ss]=='(');
        return;
    }
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    build(lf,ss,md);
    build(rt,md+1,se);
    seg[si]=seg[lf]+seg[rt];
}

void update(int qi,int si=0,int ss=0,int se=n-1){
    if(ss>qi||se<qi) return;
    if(ss==se){
        seg[si].pre=1-seg[si].pre;
        seg[si].suf=1-seg[si].suf;
        return;
    }
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    update(qi,lf,ss,md);
    update(qi,rt,md+1,se);
    seg[si]=seg[lf]+seg[rt];
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int tc=1;
    while(~scanf("%d",&n)){
        printf("Test %d:\n",tc++);
        scanf("%s",s);

        build();

        int q;
        scanf("%d",&q);
        while(q--){
            int k;
            scanf("%d",&k);
            if(k==0){
                printf((seg[0].pre==0&&seg[0].suf==0)?"YES\n":"NO\n");
            }
            else{
                --k;
                update(k);
            }
        }
    }

    return 0;
}
