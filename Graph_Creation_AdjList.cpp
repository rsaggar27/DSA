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

};

int main()
{
    vector <int> adj[4];
    GRAPH obj;

    obj.addEdge(0,1,adj);
    obj.addEdge(1,2,adj);
    obj.addEdge(1,3,adj);
    obj.addEdge(3,0,adj);
    obj.addEdge(0,2,adj);

    obj.show(adj,4);
}