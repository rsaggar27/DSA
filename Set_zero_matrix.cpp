#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) 
{
	int i,j;
	vector<pair<int,int>>pos;

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(matrix[i][j]==0)
			{
				pos.push_back({i,j});
			}
		}
	}

	for (int g=0;g<pos.size();g++)
	{
		for (int y=0;y<m;y++)
		{
			matrix[pos[g].first][y]=0;
		}
		for(int x=0;x<n;x++)
		{
			matrix[x][pos[g].second]=0;
		}
	}

	return matrix;
}

int main()
{
    vector<vector<int>> matrix;
    int n, m;
    cout<<"Enter the value of n and m:";
    cin>>n;
    cin>>m;

    for (int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<"enter the value at "<<i<<"X"<<j<<":";
            cin>>matrix[i][j];
        }
    }

    vector<vector<int>> resp=zeroMatrix(matrix,n,m);
}