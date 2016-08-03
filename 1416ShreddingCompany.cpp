#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

int source ,aim;
int ans,flag,maxn;
int con[6];
int rec[6];


void dfs(int cur , int val, int len){
	int sum = 0;
	for (int i = 0; i < cur; ++i)
	 {
	 	sum += con[i];
	 } 

	 if(sum + val == ans){
	 	flag = 1;
	 }else if(sum + val > ans  && sum + val <= aim){
	 	flag = 0;
	 	ans = sum + val;
        for (int i = 0; i < cur; ++i)  rec[i] = con[i];
        	rec[cur] = val;
            maxn = cur+1;
            //if(maxn==1 && ans == aim) return;
	 }
	 if(len==1) return ;
	 int div= 10;
	 int w = 1;
	 while(w!=len){
         int a = val/div;
         int b = val%div;
         con[cur] = a;
         dfs(cur+1,b,w);
         div = div * 10;
         w++;
	 }


}
int main()
{   
	while(cin>>aim>>source){
		if(source==0&&aim==0) break;
		memset(rec,0,sizeof(rec));
		flag  = 0;
		ans = 0;
        int sum1 = 0;
        int temp = source;
        int l = 0;
        while(temp!=0){
        	sum1+= temp%10;
        	temp = temp/10;
        	l++;
        }
        if(sum1 > aim){
        	printf("error\n");
        	continue;
        }

        dfs(0,source,l);
        if(flag) printf("rejected\n");
        else {
        	cout<<ans<<" ";
        	for (int i = 0; i < maxn; ++i)
        	{
        		cout<<rec[i]<<" ";
        	}
        	cout<<endl;
        }
	}

	
	return 0;
}