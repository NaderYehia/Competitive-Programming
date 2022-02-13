#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e2+10,M=2e4+7,OO=0x3f3f3f3f;

int n;
int mem[10][N];

int solve(int standing,int cur){
    if(cur>=n) return cur-n;
    int &ret=mem[standing][cur];
    if(~ret) return ret;
    ret=n-cur;
    if(standing==0){
        ret=min(ret,solve(0,cur*10));
    }
    else if(standing==1){
        for(int i=0;i<10;++i)
            ret=min(ret,solve(i,cur*10+i));
    }
    else if(standing==2){
        for(int i=0;i<10;i+=3)
            ret=min(ret,solve(i,cur*10+i));
        for(int i=2;i<9;i+=3)
            ret=min(ret,solve(i,cur*10+i));
    }
    else if(standing==3){
        for(int i=3;i<10;i+=3)
            ret=min(ret,solve(i,cur*10+i));
    }
    else if(standing==4){
        for(int i=4;i<10;++i)
            ret=min(ret,solve(i,cur*10+i));
        ret=min(ret,solve(0,cur*10));
    }
    else if(standing==5){
        for(int i=6;i<10;i+=3)
            ret=min(ret,solve(i,cur*10+i));
        for(int i=5;i<10;i+=3)
            ret=min(ret,solve(i,cur*10+i));
        ret=min(ret,solve(0,cur*10));
    }
    else if(standing==6){
        for(int i=6;i<10;i+=3)
            ret=min(ret,solve(i,cur*10+i));
    }
    else if(standing==7){
        for(int i=7;i<10;++i)
            ret=min(ret,solve(i,cur*10+i));
        ret=min(ret,solve(0,cur*10));
    }
    else if(standing==8){
        for(int i=8;i<10;++i)
            ret=min(ret,solve(i,cur*10+i));
        ret=min(ret,solve(0,cur*10));
    }
    else{
        ret=min(ret,solve(9,cur*10+9));
    }
    return ret;
}

void dfs(int standing,int cur){
    if(cur>=n) return;
    int ret=solve(standing,cur);
    if(ret==n-cur) return;
    if(standing==0){
        printf("0");
        dfs(0,cur*10);
    }
    else if(standing==1){
        for(int i=0;i<10;++i){
            if(ret==solve(i,cur*10+i)){
                printf("%d",i);
                dfs(i,cur*10+i);
                return;
            }
        }
    }
    else if(standing==2){
        for(int i=0;i<10;i+=3){
            if(ret==solve(i,cur*10+i)){
                printf("%d",i);
                dfs(i,cur*10+i);
                return;
            }
        }
        for(int i=2;i<9;i+=3){
            if(ret==solve(i,cur*10+i)){
                printf("%d",i);
                dfs(i,cur*10+i);
                return;
            }
        }
    }
    else if(standing==3){
        for(int i=3;i<10;i+=3){
            if(ret==solve(i,cur*10+i)){
                printf("%d",i);
                dfs(i,cur*10+i);
                return;
            }
        }
    }
    else if(standing==4){
        for(int i=4;i<10;++i){
            if(ret==solve(i,cur*10+i)){
                printf("%d",i);
                dfs(i,cur*10+i);
                return;
            }
        }
        printf("0");
        dfs(0,cur*10);
    }
    else if(standing==5){
        for(int i=6;i<10;i+=3){
            if(ret==solve(i,cur*10+i)){
                printf("%d",i);
                dfs(i,cur*10+i);
                return;
            }
        }
        for(int i=5;i<10;i+=3){
            if(ret==solve(i,cur*10+i)){
                printf("%d",i);
                dfs(i,cur*10+i);
                return;
            }
        }
        printf("0");
        dfs(0,cur*10);
    }
    else if(standing==6){
        for(int i=6;i<10;i+=3){
            if(ret==solve(i,cur*10+i)){
                printf("%d",i);
                dfs(i,cur*10+i);
                return;
            }
        }
    }
    else if(standing==7){
        for(int i=7;i<10;++i){
            if(ret==solve(i,cur*10+i)){
                printf("%d",i);
                dfs(i,cur*10+i);
                return;
            }
        }
        printf("0");
        dfs(0,cur*10);
    }
    else if(standing==8){
        for(int i=8;i<10;++i){
            if(ret==solve(i,cur*10+i)){
                printf("%d",i);
                dfs(i,cur*10+i);
                return;
            }
        }
        printf("0");
        dfs(0,cur*10);
    }
    else{
        printf("9");
        dfs(9,cur*10+9);
    }
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(mem,-1,sizeof mem);
        dfs(1,0);
        puts("");
    }


    return 0;
}
