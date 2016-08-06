#include <iostream>
#include <string.h>
using namespace std;
//区间化的思想
int n;
int num[101];
int price[101];
int sum[101];//表示 前i种 珍珠 总共有多少个
int dp[101];

int main()
{
	int cases;
	cin>>cases;
	while(cases--){
		 memset(sum,0,sizeof(sum));
		 memset(dp,0,sizeof(dp));
         cin>>n;
         for (int i = 1; i <= n; ++i)
         {
         	cin>>num[i]>>price[i];
         	sum[i] = sum[i-1]+num[i];
         	dp[i] = dp[i-1] + (num[i]+10) * price[i];
         }

         for (int i = 2; i <= n ; ++i)
         {
         	for (int j = 0; j < i; ++j)
         	{
         		int temp = (sum[i]-sum[j]+10) * price[i] + dp[j];
         		if(temp < dp[i]) dp[i] = temp;
         	}
         }
         cout<<dp[n]<<endl;




	}
	return 0;
}