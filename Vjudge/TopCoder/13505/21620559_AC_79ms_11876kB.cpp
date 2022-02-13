#include<bits/stdc++.h>
using namespace std;

class GreaterGameDiv2{
	public:
		int calc(vector<int> snuke,vector<int> sothe){
			int i,ans=0;
			for(i=0;i<snuke.size();++i)
				if(snuke[i]>sothe[i])
					++ans;
			
			return ans;
		}
};

