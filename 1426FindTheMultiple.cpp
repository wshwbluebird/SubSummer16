#include <iostream>
using namespace std;
// 膜拜 源码大神！！！！！！！

int mod[524290];//网上抄到的 最小值 是 524282

int main(){
	int n;
    while(cin>>n){
    	if(!n) break;
        

        mod[1] = 1%n;
        int i;
    	for (i = 2; mod[i-1]!=0; ++i)
    	{
    		mod[i] = (mod[i/2] * 10 +i%2)%n; //十进制 只有 0 和 1
    		                                  //二进制 广搜！！！！！
    	}
    	i = i -1;
    	int point = 0;
    	while(i){
    		mod[point++] = i%2;
    		i = i/2;

    	}
    	while(point)  cout<<mod[--point];
    	cout<<endl;
    }

	return 0;
}