#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

int possible[9][9][10];
int sudo[9][9];



void input(int x,int y,int z){
	for (int i = 0; i < 9; ++i)
	{
		possible[x][i][z]++;
		possible[i][y][z]++;
	}

	int row = x/3;
	int col = y/3;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			possible[3*row+i][3*col+j][z]++;
		}
	}
}

void deput(int x,int y,int z){
	for (int i = 0; i < 9; ++i)
	{
		possible[x][i][z]--;
		possible[i][y][z]--;
	}

	int row = x/3;
	int col = y/3;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			possible[3*row+i][3*col+j][z]--;
		}
	}
}


bool check(int x,int y,int z){
	for (int i = 0; i < 9; ++i)
	{
		if(sudo[x][i]==z||sudo[i][y]==z)  return false;
	}

	int row = x/3;
	int col = y/3;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if(sudo[3*row+i][3*col+j]==z) return false;
		}
	}
	return true;
}

int dfs(int cur){
	//cout<<"cur: "<<cur<<endl;
	if(cur==81)  return 1;
	int x = cur/9;
	int y = cur%9;
	if(sudo[x][y]!=0) return dfs(cur+1);
	for (int i = 1; i < 10; ++i)
	{
		if(!possible[x][y][i] && check(x,y,i)){
            input(x,y,i);
            //cout<<x<<" : "<<y<< "  >>> "<<i<<endl;
            sudo[x][y] = i;
            if(dfs(cur+1)) return 1;
            deput(x,y,i);
            sudo[x][y] = 0;
		}
	}
	return 0;
}

int main()
{   int cases;
    cin>>cases;
    getchar();
    while(cases--){
    	memset(possible,0,sizeof(possible));
        for (int i = 0; i < 9; ++i)
        {
        	for (int j = 0; j < 9; ++j)
        	{
        		char tt = getchar();
        		sudo[i][j]=tt-'0';
        		// /cout<<sudo[i][j]<<endl;
        		if(sudo[i][j]!=0)
        		input(i,j,sudo[i][j]);
        	    //cout<<i<<" : "<<j<<"   dsf: "<<possible[0][1][4]<<endl;
        	}
        	getchar();
        }
        //cout<<"dsf: "<<possible[0][1][4]<<endl;
        dfs(0);
        //cout<<endl;
       for (int i = 0; i < 9; ++i)
        {
        	for (int j = 0; j < 9; ++j)
        	{
        		cout<<sudo[i][j];
        		
        	}
        	cout<<endl;
        }

    }
	
	return 0;
}