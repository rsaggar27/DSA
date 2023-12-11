#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > pascalTriangle(int N) 
{
    vector<vector<int> >Pascal_Triangle;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(i==j||j==0)
            Pascal_Triangle[i][j]=1;
            else
            Pascal_Triangle[i][j]=Pascal_Triangle[i-1][j-1]+Pascal_Triangle[i-1][j];
        }
    }
    return Pascal_Triangle;
}

int main()
{
    int N=3;
    
    vector<vector<int> >resp=pascalTriangle(N);

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<resp[i][j];
        }
    }
    
    
    
}