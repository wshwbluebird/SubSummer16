#include <iostream>
#include <string>
#include <map>
using namespace std;

const int maxn = 100001;


int main(){
	map<string,string> translate;
    map<string,bool> appear;
    char eng[11],dic[11]; 
    char t;
    while( (t = getchar())!='\n'){
    	int i = 0;
        while(t!=' '){
            eng[i] = t;
            i++;
         	t= getchar();
         }
         eng[i] ='\0';

         cin>>dic;
         getchar();//完美  吃掉一个换行符号
         //getchar();
         
         translate[dic] = eng;
         appear[dic] = true;

    } 

    char str[11];
    while(cin>>str)
    {    

    	if(appear[str]) {
    		cout<<translate[str]<<endl;
    	}
    	else cout<<"eh"<<endl;
    }
    

	return 0;
}










