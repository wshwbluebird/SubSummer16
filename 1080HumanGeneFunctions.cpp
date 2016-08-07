#include <iostream>
#include <string.h>

using namespace std;
int kv[][5]={
	{5,-1,-2,-1,-3},
	{-1,5,-3,-2,-4},
	{-2,-3,5,-2,-2},
	{-1,-2,-2,5,-1},
	{-3,-4,-2,-1,-2147483648}
};
int fun(char t){
	if(t=='A') return 0;
	if(t=='C') return 1;
	if(t=='G') return 2;
	if(t=='T') return 3;
	else return 4;

}

int len1,len2;
char l1[101];
char l2[101];
int dp[101][101];

int main(){
     int cases;
     cin>>cases;
     while(cases--){
     	cin>>len1;
     	getchar();
     	for (int i = 1; i <= len1; ++i)
     	{
     		l1[i] = getchar();
     	}
     	getchar();
 
     	cin>>len2;
     	getchar();
     	for (int i = 1; i <= len2; ++i)
     	{
     		l2[i] = getchar();
     	}
     	getchar();
     	

        memset(dp,0,sizeof(dp));
        dp[0][0]  =0 ;

        for (int i = 1; i <= len2; ++i)
        {       
        	dp[0][i] = dp[0][i-1] + kv[4][fun(l2[i])];
        }

        for (int i = 1; i <= len1; ++i)
        {
        	dp[i][0] = dp[i-1][0] +kv[fun(l1[i])][4];
        }
     	
     	for (int i = 1; i <= len1; ++i)
     	{
     		for (int j = 1; j <= len2; ++j)
     		{
     			int temp1 = dp[i-1][j-1]+ kv[fun(l1[i])][fun(l2[j])];
     			int temp2 = dp[i][j-1] + kv[4][fun(l2[j])];
     			int temp3 = dp[i-1][j] + kv[fun(l1[i])][4];
     			dp[i][j] = max(temp1,max(temp2,temp3));
     		}
     	}


     	cout<<dp[len1][len2]<<endl;
     }



	return 0;
}