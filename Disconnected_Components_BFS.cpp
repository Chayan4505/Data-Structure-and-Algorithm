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

    
    void BFS_Helper(int st, vector<bool> &vis){             // T.C = O(V + E)  
        queue<int> q;
        
        q.push(st);
        vis[st] = true;

        while (q.size() > 0)
        {
            int u = q.front(); // curr vertex
            q.pop();
            cout<< u << " ";

            list<int> neighbours = l[u];
            for(int V : neighbours) {
                if(!vis[V]){
                    vis[V] = true;
                    q.push(V);
                }
            }
        }
    }

    void BFS(){
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                BFS_Helper(i, vis);
                cout<<endl;
            }
        }
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

    graph.BFS();

    return 0;
}