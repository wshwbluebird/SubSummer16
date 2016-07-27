#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char dic[11001][20];
int cnt;

void read_dic(){
	while(scanf("%s%*c",dic[cnt])){
		if(dic[cnt][0]=='#')
			break;
		cnt++;
	}
}

bool isSame(char *str){
	for (int i = 0; i < cnt; ++i)
	{
		if(strcmp(str,dic[i])==0)  return true;
	}
	return false;
}

void replace (char *str){
	printf("%s:", str);
	int ld, ls = strlen(str);
    int arr[20];

	for (int i = 0; i < cnt; ++i)
	{    
		ld = strlen(dic[i]);
		if(ls == ld){ //长度相同
           int diff = 0;
           for (int j = 0; j < ld; ++j)
                if(dic[i][j]!= str[j]) diff++;
           if(diff==1)printf(" %s",dic[i]);
		}else if(ls == ld + 1){  //删除后可得到 字典
            int a,b;
            a=0;
            b=0;
            int flag = 0;
            while(a!=ld){
            	if(str[b]!=dic[i][a]) {  flag++ ; a--;}
            	a++;b++;
            	if(flag>1) break;
            }

            if(flag==0||flag==1) printf(" %s",dic[i]);

		}else if(ls == ld - 1){
			int a,b;
            a=0;
            b=0;
            int flag = 0;
            while(a!=ls){
            	if(str[a]!=dic[i][b]) { flag++ ; a--;}
            	a++;b++;
            	if(flag>1) break;
            }

            if(flag==0||flag==1) printf(" %s",dic[i]);
		}

	}
}
int main(){
    read_dic();  
    //cout<<endl;
    char str[20];  
    while(scanf("%s%*c",str),str[0]!='#')  
    {  
        if(isSame(str))  
        printf("%s is correct\n",str);  
        else  
        {  
           replace(str);  
           printf("\n");  
        }  
    }  



	return 0;
}