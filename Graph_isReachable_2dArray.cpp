#include <iostream>
#include <vector>

using namespace std;

class GRAPH
{
    public:

    void addEdge(int src, int dst,vector< vector<int> > &G)
    {
        G[src][dst]=1;  //creation of the undirected map using 2d array
        G[dst][src]=1;
    }

    void show(vector< vector<int> > &G)
    {
        int r;
        for(r=0;r<G.size();r++)
        {
            for(auto val:G[r])
            {
                cout<<val;
            }
            cout<<endl;
        }

    }
    
    bool isReachable(int src,int dst,vector<vector<int>> &G,vector<bool>&visited)
    { 
        cout<<src<<"=>";
        if(src==dst)
        return true;

        visited[src]=true;

        for(int c=0;c<G[src].size();c++)
        {
            if(visited[c]==false)
            {
            bool resp=isReachable(c,dst,G,visited);
            return resp;
            }
        }
        cout<<"********* NOT FOUND ***********";
        return false;
        
    }
};

int main()
{
    vector< vector<int> >G(4,vector<int>(4.0));  //creation of 2d array using vector

    GRAPH obj;
    vector<bool> visited(4,false);

    obj.addEdge(0,1,G);
    obj.addEdge(3,0,G);
    obj.addEdge(0,2,G);
    obj.addEdge(1,3,G);
    obj.addEdge(1,2,G);
   
   obj.show(G);

   bool resp= obj.isReachable(0,3,G,visited);

    cout<<endl<<"is reachable"<<resp;

}