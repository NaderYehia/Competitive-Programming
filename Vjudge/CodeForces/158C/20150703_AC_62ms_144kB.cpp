#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<string>cmd;
	int t;
	scanf("%d",&t);
	char a[5];
	char c[201];
	while(t--){
		scanf("%s",&a);
		if(a[0]=='p'){
			printf("/");
			for(int i=0;i<cmd.size();++i){
				cout<<cmd[i]<<"/";
			}
			printf("\n");
		}
		else if(a[0]=='c'){
			scanf("%s",&c);
if(c[0]=='/')
cmd.clear();
				char *token=strtok(c, "/");
				while(token!=NULL){
				if(token[0]=='.')
					cmd.pop_back();
				else
					cmd.push_back(token);
				token=strtok(NULL,"/");
				}
	}
}
}