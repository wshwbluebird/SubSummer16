#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int n,k;
char chess[9][9];
int col[9];//哈西 表示 这一列是否搜索过
int ans = 0;

void dfs(int begin, int left){
	//cout<<"begin: "<<begin<<endl;
	for (int i = 0; i < n; ++i)
	{
		if(chess[begin][i]=='#'&& !col[i]){
			if(left==1) {ans++;}//cout<<"goof"<<endl;}
			else{
				col[i] = 1;
				for (int j = begin+1; j <= n-left+2; ++j)
				{
					dfs(j,left-1);
				}
				col[i]=0; 
			}
		}
	}
}


int main(){
	memset(col,0,sizeof(col));
	while(cin>>n>>k){
		if(n==-1&&k==-1){break;}
		ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%s",chess[i]);
		}

		for (int i = 1; i <= n-k+1; ++i)
		{
			dfs(i,k);
		}

		cout<<ans<<endl;
	}



	return 0;
}