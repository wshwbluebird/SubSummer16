#include <iostream>
#include <string.h>
using namespace std;

int N;
int net[25][25];
int divide[25];
int ans = 0;

void dfs(int cur , int value){
	divide[cur] = 1;
	int tempv =value;
	for (int i = 0; i < N; ++i)
	{
		if(divide[i]) tempv -= net[cur][i];
		else  tempv += net[cur][i];
	}
	if(tempv>ans) ans = tempv;
   	if(tempv>value){
   		for (int i = cur+1; i < N; ++i)
   		{
   			dfs(i,tempv);
   		}
   	}
   	divide[cur]= 0;


}

int main(){
   cin>>N;
   memset(divide,0,sizeof(divide));
   for (int i = 0; i < N; ++i)
   {
   		for (int j = 0; j < N; ++j)
   		{
   			cin>>net[i][j];
   		}
   }
   dfs(0,0);
   cout<<ans<<endl;


	return 0;
}