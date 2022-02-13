#include <bits/stdc++.h>

using namespace std;

const int N=1e6+5,OO=0x3f3f3f3f;
int t,n,m,k,q;
int arr[N];
string s;


int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        int cnt=0;
        bool on=1;
        scanf("%d%d",&n,&m);
        n=n*100;
        queue<int> left;
        queue<int> right;
        for(int i=0;i<m;++i){
            cin>>k>>s;
            if(s=="left"){
                left.push(k);
            }
            else{
                right.push(k);
            }
        }
        while(left.size()||right.size()){
            if(on){
                int tmp=n;
                while(left.size()&&tmp-left.front()>=0){
                    tmp-=left.front();
                    left.pop();
                }
                on=!on;
                ++cnt;
            }
            else{
                int tmp=n;
                while(right.size()&&tmp-right.front()>=0){
                    tmp-=right.front();
                    right.pop();
                }
                on=!on;
                ++cnt;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
