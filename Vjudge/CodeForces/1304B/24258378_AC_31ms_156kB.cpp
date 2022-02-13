#include<bits/stdc++.h>
 
using namespace std;
 
int n,m;
string s;
string arr[105];
bool vis[105];
vector<int> v;
 
bool pal(string s){
    int i=0,j=s.length()-1;
    while(i<j){
        if(s[i]!=s[j])
            return 0;
        ++i,--j;
    }
    return true;
}
 
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    for(int i=0;i<n;++i){
        if(vis[i])
            continue;
        string s=arr[i];
        reverse(s.begin(),s.end());
        for(int j=0;j<n;++j){
            if(i==j)
                continue;
            if(!vis[j]&&s==arr[j])
                vis[i]=1,vis[j]=1,v.push_back(i),v.push_back(j);
        }
    }
    for(int i=0;i<n;++i){
        if(!vis[i]&&pal(arr[i])){
            v.push_back(i);
            break;
        }
    }
    printf("%d\n",v.size()*m);
    for(int i=0;i<v.size();i+=2)
        cout<<arr[v[i]];
    for(int i=(v.size()&1)?v.size()-2:v.size()-1;i>-1;i-=2)
        cout<<arr[v[i]];
    return 0;
}