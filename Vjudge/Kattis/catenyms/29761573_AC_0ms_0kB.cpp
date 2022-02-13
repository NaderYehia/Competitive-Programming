#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=1e9+7,OO=0x3f3f3f3f;
const double eps=1e-6;

int n;
int head[26],nxt[N],to[N],vis[N],vid,ne,res[N],sz,len[N],I[N],deg[26];
char str[N][21];

void init(){
    memset(head,-1,sizeof head);
    memset(deg,0,sizeof deg);
    ne=0;
    sz=0;
    ++vid;
}

void addEdge(int u,int v){
    to[ne]=v;
    nxt[ne]=head[u];
    head[u]=ne++;
}

void addBiEdge(int u,int v){
    addEdge(u,v);
    addEdge(v,u);
}

void euler(int u){
    for(int &e=head[u];~e;){
        int x=e;
        e=nxt[e];
        int v=to[x];
        euler(v);
        res[sz++]=x;
    }
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int t;
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d",&n);
        int st='z'-'a';
        for(int i=0;i<n;++i){
            scanf("%s",str[i]);
            len[i]=strlen(str[i])-1;
            I[i]=i;
            st=min(st,str[i][0]-'a');
        }
        sort(I,I+n,[](int i,int j){
             return strcmp(str[i],str[j])>0;
             });
        for(int i=0;i<n;++i){
            int j=I[i];
            deg[str[j][0]-'a']++,deg[str[j][len[j]]-'a']--;
            addEdge(str[j][0]-'a',str[j][len[j]]-'a');
        }
        int ok=1,cnt=0;
        for(int i=0;i<26;++i){
            switch(deg[i]){
                case 0:break;
                case 1:
                    if(cnt++) ok=0;
                    st=i;
                    break;
                case -1:break;
                default:
                    ok=0;
                    break;
            }
        }
        euler(st);
        ok&=(sz==n);
        if(ok){
            for(int i=sz-1;~i;--i)
                printf("%s%c",str[I[res[i]]],".\n"[!i]);
        }
        else{
            puts("***");
        }
    }

    return 0;
}
