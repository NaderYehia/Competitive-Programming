#include<bits/stdc++.h>

using namespace std;

int n;
string a,b;
vector<int> arr[30];

int main(){
    scanf("%d",&n);
    while(n--){
        for(int i=0;i<26;++i)
            arr[i].clear();
        cin>>a>>b;
        for(int i=0;a[i];++i)
            arr[a[i]-'a'].push_back(i);
        int inw=-1,att=1;
        bool failed=0;
        for(int i=0;b[i];++i){
            if(upper_bound(arr[b[i]-'a'].begin(),arr[b[i]-'a'].end(),inw)!=arr[b[i]-'a'].end()){
                inw=*upper_bound(arr[b[i]-'a'].begin(),arr[b[i]-'a'].end(),inw);
            }
            else if(upper_bound(arr[b[i]-'a'].begin(),arr[b[i]-'a'].end(),-1)!=arr[b[i]-'a'].end()){
                inw=*upper_bound(arr[b[i]-'a'].begin(),arr[b[i]-'a'].end(),-1),++att;
            }
            else {
                failed=1;
                break;
            }
        }
        if(failed)
            printf("-1\n");
        else
            printf("%d\n",att);
    }
    return 0;
}
