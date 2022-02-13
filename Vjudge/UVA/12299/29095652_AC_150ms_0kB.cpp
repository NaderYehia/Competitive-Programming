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
    int md=ss+(se-ss)/2,rt=si*2+1,lf=rt++;
    build(lf,ss,md);
    build(rt,md+1,se);
    seg[si]=min(seg[lf],seg[rt]);
}

int query(int qs,int qe,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return OO;
    if(ss>=qs&se<=qe) return seg[si];
    int md=ss+(se-ss)/2,rt=si*2+1,lf=rt++;
    return min(query(qs,qe,lf,ss,md),query(qs,qe,rt,md+1,se));
}

void update(int qi,int qv,int si=0,int ss=0,int se=n-1){
    if(ss>qi||se<qi) return;
    if(ss==se){
        seg[si]=qv;
        return;
    }
    int md=ss+(se-ss)/2,rt=si*2+1,lf=rt++;
    update(qi,qv,lf,ss,md);
    update(qi,qv,rt,md+1,se);
    seg[si]=min(seg[lf],seg[rt]);
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);

    build();

    while(q--){
        char s[35];
        scanf("%s",s);
        if(s[0]=='q'){
            vector<int> ind;
            for(int i=6;s[i];++i){
                int cur=s[i]-'0';
                i++;
                while(s[i]>='0'&&s[i]<='9'){
                    cur=cur*10+s[i]-'0';
                    ++i;
                }
                ind.push_back(cur-1);
            }
            printf("%d\n",query(ind[0],ind[1]));
        }
        else{
            vector<int> ind;
            for(int i=6;s[i];++i){
                int cur=s[i]-'0';
                i++;
                while(s[i]>='0'&&s[i]<='9'){
                    cur=cur*10+s[i]-'0';
                    ++i;
                }
                ind.push_back(cur-1);
            }
            vector<int> val;
            for(int i=0;i<ind.size();++i)
                val.push_back(query(ind[i],ind[i]));

            int len=ind.size();
            for(int i=len-1;i>-1;--i){
                update(ind[i],val[(i+1)%len]);
            }
        }
    }

    return 0;
}
