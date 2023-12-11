#include <iostream> 
#include <vector>

using namespace std;

void addSol(vector<vector<int> >&board,vector<vector<int> >&ans, int n)
{
	vector<int> temp;

	for(int i=0;i<n;i++)
	{
          for (int j = 0; j < n; j++) 
		  {
            cout<<board[i][j];
          }
          cout<<endl;
    }
    cout<<endl;
    
}

bool isSafe(int row,int col,vector<vector<int> >&board,vector<vector<int> >&ans, int n)
{
	int x=row;
	int y=col;

	//hum column m toh khud hee place kr rhe hain ki like humare code m aisa hee hai ki
	//hum ek col m sirf ek hee QUEEN("1") place kr rhe hain aur saath hee col badal dete hain
	//toh hum sirf **ROW CHECK** krenge voh bhi sirf piche ko kyuki aage toh abhi khaali hai
	while(y>=0)
	{
		if(board[x][y]==1)
		return false;

		y--;
	}
	//**UPPER RIGHT DIAGNOL CHECK**
	//aage-vale(LEFT) check krne ka fayda nahi hai
	//kyuki aage toh abhi khaali hai
	 x=row;
	 y=col;

	while(x>=0&&y>=0)
	{
		if(board[x][y]==1)
		return false;
		x--;
		y--;
	}
	//**BOTTOM RIGHT DIAGNOL CHECK**
	 x=row;
	 y=col;

	while(x<n&&y>=0)
	{
		if(board[x][y]==1)
		return false;
		x++;
		y--;
	}

	return true;
}

void queenPlacer(int col,vector<vector<int> >&board,vector<vector<int> >&ans, int n)
{
	//base condition
	if(col==n)
	{
		addSol(board,ans,n);
		return;
	}
	//abb baari hai function ki

	for(int row=0;row<n;row++)
	{
		if(isSafe(row,col,board,ans,n))
		{
			board[row][col]=1;					//ek '1' rkha
			queenPlacer(col+1,board,ans,n);		//aur col change

		//for back-tracking

			board[row][col]=0;
		}
	}
}

vector<vector<int> > nQueens(int n)
{
	vector<vector<int> >board(n,vector<int>(n,0));
	vector<vector<int> >ans(n,vector<int>(n,0));

	queenPlacer(0,board,ans,n);
	return ans;
}

int main()
{
 int n=4;
 
 nQueens(n);
 
}