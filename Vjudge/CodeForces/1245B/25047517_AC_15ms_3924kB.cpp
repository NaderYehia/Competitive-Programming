#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5;
int t,n,a,b,c,cnt;
int arr[N];
char s[200];
char st[200];

int main() {
    scanf("%d",&t);
    while(t--){
        int cnt=0;
        scanf("%d%d%d%d",&n,&a,&b,&c);
        scanf("%s",s);
        for(int i=0;i<n;++i)
            st[i]='.';
        for(int i=0;i<n;++i){
            if(s[i]=='S'&&a){
                st[i]='R';
                --a;
                ++cnt;
            }
            else if(s[i]=='R'&&b){
                st[i]='P';
                --b;
                ++cnt;
            }
            else if(s[i]=='P'&&c){
                st[i]='S';
                --c;
                ++cnt;
            }
        }
        if(cnt<n/2+(n&1)){
            printf("NO\n");
            continue;
        }
        for(int i=0;i<n;++i){
            if(st[i]=='.'){
                if(a){
                    st[i]='R';
                    --a;
                }
                else if(b){
                    st[i]='P';
                    --b;
                }
                else if(c){
                    st[i]='S';
                    --c;
                }
            }
        }
        printf("YES\n");
        st[n]='\0';
        printf("%s\n",st);
    }
    return 0;
}
