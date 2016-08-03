#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int f[11][100001]; //前n 份请求  在cash 为xx时的最大可送达面额
int n[11];
int d[11];
int N;
int cash;

int dp(int nk , int mount){
    
	if(f[nk][mount]!=-1)  return 0;
	if(nk==0 || mount==0)  return f[nk][mount] = 0;
	int sum = 0;
	for (int i = 0; i <= n[nk]; ++i)
	{  
		if(mount>=i*d[nk]){
			int temp = dp(nk-1,mount-i*d[nk]) + i*d[nk];
			if(temp  >sum) sum = temp;
		}
	}
	return f[nk][mount] = sum;
}

int main(){

    // while(scanf("%d%d",&cash,&N)){
    // 	memset(f,-1,sizeof(f));
    // 	memset(n,0,sizeof(n));
    // 	memset(d,0,sizeof(d));
    // 	for (int i = 1; i <= N; ++i)
    // 	{
    // 		scanf("%d%d", &n[i], &d[i]);
    // 	}
    //     cout<<dp(N,cash)<<endl;
       
    // }
    cout<<(7||4);
	return 0;
}