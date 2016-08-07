#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

vector<int> bow[355];
vector<int> dp[355];
int n;

int main()
{
	cin>>n;
	for (int i = n; i >= 1; i--)
	{
		for (int j = 1; j <= n-i+1; ++j)
		{
			int temp;
			cin>>temp;
			bow[i].push_back(temp);
			dp[i].push_back(0);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < bow[i].size(); ++j)
		{
			if(i==1)  dp[i][j] = bow[i][j];
			else dp[i][j] = max(dp[i-1][j],dp[i-1][j+1]) + bow[i][j];
		}
	}
	
	cout<<dp[n][0]<<endl;
	return 0;
}