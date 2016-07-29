#include <iostream>
#include <string.h>
using namespace std;

int m, t, n ;
double p[1005][35];//表示 第i队  做对第 j 题的概率
double f[1005][35][35];//表示  第i队 在 前 j 题中 当且仅当 做对 m题的概率
double s[1005][35]; //表示 第i队 共做出1到j题的 概率

void dp(){
    //cin>>m>>t>>n;
    double p1 = 1.0,p2 = 1.0;
    memset(p,0,sizeof(p));
    memset(s,0,sizeof(s));
    memset(f,0,sizeof(f));
    f[0][0][0] = 1.0;
    int i;
    for ( i = 1; i <= t; ++i)
    {   
    	f[i][0][0] = 1.0;
    	for (int j = 1; j <= m; ++j)
    	{
    		cin>>p[i][j];
    		f[i][j][0] = f[i][j-1][0] * (1.0 - p[i][j]); 
    		//cout<<"f: "<<"i: "<<i<<" j: "<<j<<" 0    : "<<f[i][j][0]<<endl;
    	}
        
        for (int j = 1; j <= m; ++j)
        {
        	for (int k = 1; k <= j; ++k)
        	{
        		f[i][j][k] = f[i][j-1][k-1] * p[i][j] + f[i][j-1][k] *(1.0-p[i][j]);
        		//cout<<"f: "<<"i: "<<i<<" j: "<<j<<" k: "<<k<<"     :  "<<f[i][j][k]<<endl;
        	}
        }

        for (int k = 1; k <= m; ++k)
        {
        	s[i][k] = s[i][k-1] + f[i][m][k];
        }
        p1 *= s[i][m];
        p2 *= s[i][n-1]; 

    }

     //cout<<i<<endl;
     //cout<<"p1: "<<p1<<endl;
     //cout<<"p2: "<<p2<<endl;
     printf("%.3f\n", p1-p2);


}

int main()
{
	while(cin>>m>>t>>n){
		if(!m&&!t&&!n) break;
        else dp();
        //cout<<"end"<<endl; 
	}
	return 0;
}