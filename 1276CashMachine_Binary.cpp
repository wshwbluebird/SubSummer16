#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

bool f[100005]; //前n 份请求  在cash 为xx时的最大可送达面额
int items[110];
int cnt;
int N;
int cash;



int main(){

    while(scanf("%d%d",&cash,&N)){
    	memset(f,0,sizeof(f));
        //memset(items,0,sizeof(items));
    	cnt = 1;
    	int x,y;
    	for (int i = 1; i <= N; ++i)
    	{
    		scanf("%d%d", &x, &y);
    		int k = 1;
    		while(x>0){
    			 if(x>=k) items[cnt++] = k*y, x = x - k, k = k<<1;
			     else {
				 items[cnt++] = x*y; break;
				}
    		}
    	}
        f[0] = 1;
    	for (int i = 1; i < cnt; ++i)
    	{
    		for (int j = cash; j >=items[i]; j--)
    		{
    			f[j] = f[j]||f[j-items[i]];
    			//if(f[j]) cout<<j<<endl;
    		}
    	}
        int i;

    	for (i = cash; i!=0; i--)
			if (f[i]) break;
		printf("%d\n",i);
        //cout<<f[cash]<<endl;
       
    }
    
	return 0;
}




// #include <string.h>
// #include <stdio.h>
// #include <iostream>
// int s,n,max, a[111],x,y,z, i,k, j,v[100005];
// int main() {
// 	while (scanf("%d", &s) != EOF)
// 	{
// 		memset(v, 0, sizeof(v)); v[0] = 1; z = 1;
// 		scanf("%d",&n);
// 		for (i = 1; i <= n; i++)
// 		{
// 			scanf("%d%d", &x, &y);
// 			k = 1;
// 			while (x>0)
// 			{if(x>=k) a[z++] = k*y, x = x - k, k = k<<1;
// 			else {
// 				a[z++] = x*y; break;
// 	}}}
// 		for (i = 1; i < z; i++)
// 			for (j = s; j >=a[i]; j--){
// 				v[j] = v[j]||v[j-a[i]];
// 				//if(v[j]) cout<<j<<endl;
// 			}

// 		for (i = s; i!=0; i--)
// 			if (v[i]) break;
// 		printf("%d\n",i);
// 	}
// 	return  0;
// }
