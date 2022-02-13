#include <bits/stdc++.h>

using namespace std;

const int N=100000+10,inf=0x3f3f3f3f;

int dis[8][8];

bool valid(int r,int c){
    return r<8&&r>-1&&c<8&&c>-1;
}

int bfs(int srcR,int srcC,int destR,int destC){
    memset(dis,'?',sizeof dis);
    dis[srcR][srcC]=0;
    queue<pair<int,int> > q;
    q.push({srcR,srcC});

    while(q.size()){

        int r=q.front().first;
        int c=q.front().second;
        q.pop();

        for(int i=-1;i<2;i+=2){
            for(int j=-1;j<2;j+=2){
                for(int ii=1,jj=2,k=0;k<2;++k,swap(ii,jj)){
                    int di=ii*i,dj=jj*j;
                    if(valid(r+di,c+dj)&&dis[r+di][c+dj]>dis[r][c]+1){
                        dis[r+di][c+dj]=dis[r][c]+1;
                        q.push({r+di,c+dj});
                    }
                }
            }
        }

    }

    return dis[destR][destC];
}

int main()
{

    string s,t;
    while(cin>>s>>t){

        cout<<"To get from "<<s<<" to "<<t<<" takes "<<bfs(s[0]-'a',s[1]-'1',t[0]-'a',t[1]-'1')<<" knight moves.\n";
    }

    return 0;
}
