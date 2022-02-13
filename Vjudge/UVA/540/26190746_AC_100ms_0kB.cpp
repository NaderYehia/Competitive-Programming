#include <bits/stdc++.h>

using namespace std;

const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k,q;
string s;


int main(){
    //freopen("myfile.txt","w",stdout);
    int tc=0;
    while(~scanf("%d",&t)&t){
        printf("Scenario #%d\n",++tc);
        map<int,int>mp;
        int tmp=0;
        for(int i=0;i<t;++i){
            scanf("%d",&n);
            for(int j=0,k;j<n;++j){
                scanf("%d",&k);
                mp[k]=tmp;
            }
            tmp++;
        }
        queue<int> q;
        queue<int> arr[t];
        while(getline(cin,s)&&s!="STOP"){
            if(s=="DEQUEUE"){
                printf("%d\n",arr[q.front()].front());
                arr[q.front()].pop();
                if(arr[q.front()].empty())
                    q.pop();
            }
            else if(s[0]=='E'){
                int tm;
                stringstream ss(s);
                ss>>s;
                ss>>tm;
                if(arr[mp[tm]].size()){
                    arr[mp[tm]].push(tm);
                }
                else{
                    arr[mp[tm]].push(tm);
                    q.push(mp[tm]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
