#include <iostream>
using namespace std;

double que[1001];
int n;
int up[1001];
int down[1001];

int main(){
    cin>>n;
    for (int i = 1; i <= n; ++i)
    {
     	cin>>que[i];
     	up[i] = 1;
     	down[i] = 1;

    }
     

    for (int i = 2; i <= n; ++i)
    {
    	for (int j = 1; j < i; ++j)
    	{
    		if(que[i]>que[j]){
    			if(up[j]>=up[i]){
    				up[i] = up[j]+1;
    			}
    		}
    	}
    }

     for (int i = n-1; i > 0; --i)
    {
    	for (int j = n; j >i ; --j)
    	{
    		if(que[i]>que[j]){
    			if(down[j]>=down[i]){
    				down[i] = down[j]+1;
    			}
    		}
    	}
    }

     int tmp = 0;
    for (int i = 1; i < n; ++i)
    {
    	for (int j = i+1; j<=n; ++j)
    	{
    		if(up[i] + down[j] > tmp)  
                 tmp = up[i] + down[j];	
    	}
    }

    cout<<n-tmp<<endl;

    
    




	return 0;
}