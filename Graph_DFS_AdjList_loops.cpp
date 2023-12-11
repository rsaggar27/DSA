#include<iostream>
#include<vector>
#include<stack>
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

void DFS(int src, vector<int>adj[])
{
    vector<bool>visited(4,false);
    stack<int>stk;

    stk.push(src);
    visited[src]=true;

    while(!stk.empty())
    {
        int ch= stk.top(); stk.pop();
        cout<<ch;
        for(auto nl:adj[ch])
        {
           if(visited[nl]==false)
           {
            stk.push(nl);
            visited[nl]=true;
           }
        }
    }
}


};

int main()
{
    vector <int> adj[4];
    vector<bool>visited(4,false);
    GRAPH obj;

    obj.addEdge(0,1,adj);
    obj.addEdge(1,2,adj);
    obj.addEdge(1,3,adj);
    obj.addEdge(3,0,adj);
    obj.addEdge(0,2,adj);

   // obj.show(adj,4);
    
    
    cout<<"reachale elements in the Graph with loops:"<<endl;
    obj.DFS(0,adj);
}
