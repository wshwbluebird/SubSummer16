#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
	int num;
	char sta[28][28];
	int channel[28];
	while(scanf("%d",&num)!=EOF&&num)
	{
		int result=1;
		for(int i=1;i<=num;i++)   channel[i]=1;
		char *p=&sta[0][1];
		gets(p);
		for(int i=1;i<=num;i++)
		{
			p=&sta[i][1];
			gets(p);
		//	puts(p);
		}
		for(int i=1;i<=num;i++)
		{
			int k;
			for(int j=3;sta[i][j]!='\0';j++)
			{
				k=sta[i][j]-'A'+1;
				if(k>i)
				channel[i]++;
			}
		}
		
		for(int i=1;i<=num;i++)
		{
		   if(result<channel[i])
		     result=channel[i];	
		}
		if(result==1)
		    printf("1 channel needed.\n");
		else
		    printf("%d channels needed.\n",result);
		
    }
}
