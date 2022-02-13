#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=1e3+7,OO=0x3f3f3f3f;




int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n,h;
    scanf("%d%d",&n,&h);
    vector<int> freq(h+5,0);
    for(int i=0;i<n;++i){
        int x;
        scanf("%d",&x);
        if(i&1){
            freq[h-x+1]++;
            freq[h+1]--;
        }
        else{
            freq[1]++;
            freq[x+1]--;
        }
    }

    for(int i=1;i<=h;++i)
        freq[i]+=freq[i-1];

    int mn=OO,cnt=0;

    for(int i=1;i<=h;++i){
        if(freq[i]<mn){
            mn=freq[i];
            cnt=1;
        }
        else if(freq[i]==mn){
            ++cnt;
        }
    }

    printf("%d %d\n",mn,cnt);

    return 0;
}
