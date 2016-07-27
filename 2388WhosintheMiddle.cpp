#include <iostream>
#include <algorithm>
using namespace std;

int n;
int milk[10001];
int main(){
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
    	cin>>milk[i];
    }

    sort(milk,milk+n);
    cout<<milk[n/2]<<endl;


	return 0;
}