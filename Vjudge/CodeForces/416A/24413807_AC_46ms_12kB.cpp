#include<bits/stdc++.h>

using namespace std;

const int N=5e5+5,OO=2000000000;
int n,t,x,from=-OO,to=OO;
string s;
char ch;
bool sm,gr;

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        cin>>s>>x>>ch;
        if(ch=='Y'){
            if(s[0]=='>'){
                if(s.length()==2){
                    from=max(from,x);
                } else if(s.length()==1){
                    from=max(from,x+1);
                }
            } else if(s[0]=='<'){
                if(s.length()==2){
                    to=min(to,x);
                } else if(s.length()==1){
                    to=min(to,x-1);
                }
            }
        } else if(ch=='N'){
            if(s[0]=='>'){
                if(s.length()==2){
                    to=min(to,x-1);
                } else if(s.length()==1){
                    to=min(to,x);
                }
            } else if(s[0]=='<'){
                if(s.length()==2){
                    from=max(from,x+1);
                } else if(s.length()==1){
                    from=max(from,x);
                }
            }
        }
    }
    if(from>to)
        printf("Impossible");
    else
        printf("%d",from);
	return 0;
}
