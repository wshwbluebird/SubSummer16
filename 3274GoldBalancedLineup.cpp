#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

const int  maxn = 150000;
const int  maxk = 32;

int sum[maxn][maxk];
int c[maxn][maxk];
int head[maxn],nexte[maxn];
int n;
int k;
int ans = 0;

int hash(int i){
	int tem = 0;
	for (int j = 0; j < k; ++j)
	{
		if(c[i][j]<0)
		tem = tem - c[i][j];
	    else tem += c[i][j];
		tem = tem%maxn;
	}
	//cout<<temp<<endl;
	return tem ;
}

void search_insert(int i){
	int h = hash(i);
	//cout<<h<<endl;
	for (int e = head[h]; e != -1; e = nexte[e])
	{    
		int flag = 1;
		for (int j = 0; j < k; ++j)
	    {
		     if( c[e][j]!= c[i][j]){
                 flag = 0;
                 break;
		     }
	    }
	    if(flag){
	    	int p = i - e ;
	    	if(ans < p) ans = p;
	    }
	}
     
     nexte[i] = head[h];
     head[h] = i;
     //cout<<i<<endl;
     //return ;

}

int main()
{    
	cin>>n>>k;
	memset(sum, 0, sizeof(sum));
    memset(c, 0, sizeof(c));
    memset(head,-1,sizeof(head));
    //int temp;
    int temp;	
    search_insert(0);
	for (int i = 1; i <= n; ++i)
	{   
		 
		 scanf("%d", &temp);
		 //cout<<endl<<temp<<" :      ";
		for (int j = 0; j < k; ++j)
		{
			//cout<<"   tt: "<<tt<<endl;
			
		    sum[i][j] = sum[i-1][j]+(1& temp);	

			c[i][j] = sum[i][j] - sum[i][0];
			//cout<<c[i][j]<<"  ";
			temp>>=1;
		}
		 //cout<<endl;

		 search_insert(i);
	}
    
	cout<<ans<<endl;

	return 0;
}