#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;
const int maxj = 7500;
int dp[21][2*maxj+1];//动态规划的状态： 前i 个砝码  在 平衡度 为 j 时 的方法个数
int C,G;
int c[21],g[21];

int findnum(int num , int balance){
	//cout<<num<<endl;
	if(dp[num][balance]!=-1)  return dp[num][balance];//记忆化递归
	else if(num==0) return dp[num][balance] = 0;
	int sum = 0;
    for (int i = 1; i <= C; ++i)
     {
     	
     	sum += findnum(num-1,balance-c[i]*g[num]);
     	
     } 
     return dp[num][balance] = sum; 
}

int main(){
	memset(dp,-1,sizeof(dp));
    dp[0][maxj] = 1;
    cin>>C>>G;
    for (int i = 1; i <= C; ++i)
    {
    	cin>>c[i];
    }
    for (int i = 1; i <= G; ++i)
    {
    	cin>>g[i];
    }
    cout<<findnum(G,maxj)<<endl;


	return 0;
}