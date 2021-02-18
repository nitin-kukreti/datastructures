#include <iostream>
#include <iterator>
#include <list>
using namespace std;
class graph
{
private:
    int v;
    list<int> *l;

public:
    graph(int vertex)
    {
        v = vertex;
        l = new list<int>[vertex];
    }
    void edgeconnection(int x, int y)
    {
        if ((x >= 0) && (y>= 0)  && (x< v) && (y< v))
        {
            l[y].push_back(x);
            l[x].push_back(y);
        }
        else
        {
            cout << "enter proper vertex \n";
        }
    }
    void display() 
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << "--->>";
            for (auto j : l[i])
            {
                cout << " " << j;
            }
            cout << endl;
        }
    }
    void dfs_utils(int s, bool visited[])
    {
        visited[s] = true;
        cout << s << " ";
        list<int>::iterator i;
        for (i = l[s].begin(); i != l[s].end(); ++i)
        {
            if (!visited[*i])
                dfs_utils(*i, visited);
        }
    }

    void dfs(int s)
    {
        bool *visited = new bool[v];
        for (int i = 0; i < v; i++)
            visited[i] = false;

        // Call the recursive helper function
        // to print DFS traver
        cout << endl;
        dfs_utils(s, visited);
    }

    void bfs(int s)
    {
        int V = v;
        // Mark all the vertices as not visited
        bool *visited = new bool[V];

        for (int i = 0; i < V; i++)
            visited[i] = false;

        // Create a queue for BFS
        list<int> queue;

        // Mark the current node as visited and enqueue it
        visited[s] = true;
        queue.push_back(s);

        // 'i' will be used to get all adjacent
        // vertices of a vertex
        list<int>::iterator i;

        while (!queue.empty())
        {
            // Dequeue a vertex from queue and print it
            s = queue.front();
            cout << s << " ";
            queue.pop_front();

            // Get all adjacent vertices of the dequeued
            // vertex s. If a adjacent has not been visited,
            // then mark it visited and enqueue it
            for (i = l[s].begin(); i != l[s].end(); ++i)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
    }
};

int main()
{

    int v, ch;
    cout << "enter number of vertex in graph\n";
    cin >> v;
    graph g(v);
    while (true)
    {
        cout << "\nselect from bellow\n";
        cout << "1 make connection v1 to v2 enter vertex v1 and v2\n";
        cout << "2 for Breath Frist search of Graph\n";
        cout << "3 for  Depth First Search of Graph\n";
        cout << "4 for  adjancy list of Graph\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "enter vertex v1 and v2\n";
            int v1, v2;
            cin >> v1 >> v2;
            g.edgeconnection(v1, v2);
            break;
        case 2:
            cout<<"enter vertex for bfs\n";
            int vertexbfs;
            cin>>vertexbfs;
            cout<<"Breath Frist search : ";
            g.bfs(vertexbfs);
            break;

        case 3:
            cout<<"enter vertex for Dfs\n";
            int vertex;
            cin>>vertex;
            cout<<"Depth Frist search : ";
            g.dfs(vertex);
            break;
        case 4:
            cout<<"adjancy list\n";
            g.display();
            break;
        default:
            exit(1);
            break;
        }
    }

    return 0;
}
