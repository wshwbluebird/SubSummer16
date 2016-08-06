#include <iostream>
using namespace std;

int up[1005];
int q[1005];
int n;


int main(){
    cin>>n;
    for (int i = 1; i <= n; ++i)
    {
    	up[i] = 1;
    	cin>>q[i];
    }

    for (int i = 2; i <= n; ++i)
    {
    	for (int j = 1; j < i; ++j)
    	{
    		if(q[i]>q[j]){
    			if(up[j]>=up[i])  up[i] = up[j]+1;
    		}
    	}
    }
    int temp = 0;
    for (int i = 1; i <= n; ++i)
    {
    	if(temp<up[i])  temp = up[i];
    }
    cout<<temp<<endl;
	return 0;
}