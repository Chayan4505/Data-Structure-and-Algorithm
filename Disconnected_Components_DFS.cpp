#include<iostream>
#include<queue>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int>* l;
  public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }  

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }


    void DFS_helper( int u, vector<bool> &vis){
        vis[u] = true;
        cout<< u <<" ";

        list<int> neighbours = l[u];
        for(int v: neighbours){
            if (!vis[v])
            {
                DFS_helper(v, vis);
            }
            
        }
    }

    void DFS(){
        vector<bool> vis(7, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                DFS_helper(i, vis);
                cout<<endl;
            }
        }      
        cout<<endl;
    }
};

int main(){
    Graph graph(10);

    graph.addEdge(1,6);
    graph.addEdge(6,4);
    graph.addEdge(4,3);
    graph.addEdge(4,9);
    graph.addEdge(3,7);
    graph.addEdge(3,8);
    graph.addEdge(0,2);
    graph.addEdge(2,5);

    graph.DFS();

    return 0;
}