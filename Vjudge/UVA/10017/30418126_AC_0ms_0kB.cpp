#include <bits/stdc++.h>

using namespace std;

int n,m;

vector<int> arr[5];


void go_print(){
    printf("A=>");
    if(arr[0].size()) printf("  ");
    for(int i=0;i<arr[0].size();++i)
        printf(" %d",arr[0][i]);
    printf("\n");

    printf("B=>");
    if(arr[2].size()) printf("  ");
    for(int i=0;i<arr[2].size();++i)
        printf(" %d",arr[2][i]);
    printf("\n");


    printf("C=>");
    if(arr[1].size()) printf("  ");
    for(int i=0;i<arr[1].size();++i)
        printf(" %d",arr[1][i]);
    printf("\n\n");

}

void MoveTower(int desk,int src,int dest,int spare){
    if(desk==0||m<=0) return;

    MoveTower(desk-1,src,spare,dest);
    if(m<=0) return;
    arr[dest].push_back(arr[src].back());
    arr[src].pop_back();
    go_print();
    m--;
    MoveTower(desk-1,spare,dest,src);
}

int main(){

    int tc=1;
    while(~scanf("%d%d",&n,&m),n||m){
        printf("Problem #%d\n\n",tc++);
        for(int i=0;i<3;++i)
            arr[i].clear();
        for(int i=n;i>0;--i)
            arr[0].push_back(i);

        go_print();
        MoveTower(n,0,1,2);
    }

    return 0;
}
