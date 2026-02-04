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

    
    void BFS(){             // T.C = O(V + E)  
        queue<int> q;
        vector<bool> vis(V, false);
        q.push(0);
        vis[0] = true;

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
        cout<<endl;
    }
};

int main(){
    Graph graph(7);

    graph.addEdge(0,1);    
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);
    graph.addEdge(5,6);

    graph.BFS();

    return 0;
}