#include<iostream>
#include<vector>

using namespace std;

class GRAPH
{
    public:

    void addEdge(int src,int dst,vector<int>adj[])
    {
        adj[src].push_back(dst); //creation of the adjacentency list
    }

    void show(vector<int>adj[],int size)
    {
        for(int r=0;r<size;r++)
        {
            cout<<r<<":";

            for(auto ch:adj[r])
            {
                cout<<ch<<" ";
            }
            cout<<endl;
        }
    }

    void DFS(int src,vector<int>adj[],vector<bool>&visited, int &size)
    {
       // cout<<src<<" ";
       size++;

        visited[src]=true;
        

        for(auto ch:adj[src])
        {
         //   cout<<"ch is:"<<ch;
            if(visited[ch]==false)
            {
                DFS(ch,adj,visited,size);
            }
        }

    }

    pair<int,int> countIsland(vector <int> adj[],vector<bool> &visited,int siz)// count island and returns the size of max island
    {
        int Island_count=0;
        int size;
        int mxSize=0;

        for(int v=0;v<siz;v++)
        {
            size=0;

            if(!visited[v])
            {
                DFS(v,adj,visited,size);
                Island_count++;

            }
             mxSize=max(mxSize,size);

        }

        return(Island_count,mxSize);

    } 

};

int main()
{
    vector <int> adj[6];
    vector<bool>visited(6,false);
    GRAPH obj;

    obj.addEdge(0,1,adj);
    obj.addEdge(1,2,adj);
    obj.addEdge(1,3,adj);
    obj.addEdge(3,0,adj);
    obj.addEdge(2,5,adj);
    obj.addEdge(4,5,adj);

   // obj.show(adj,4);
    
    
    cout<<"Reachable Elements in the Graph:"<<endl;
    //obj.DFS(0,adj,visited,size);
    

}
