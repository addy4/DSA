#include </Users/PremBhatia1/stdc.h>

using namespace std;

class Edge
{
public:
    int start;
    int end;
    int weight;

    Edge(int s, int r, int w)
    {
        this->start = s;
        this->end = r;
        this->weight = w;
    }
};

bool cmp(Edge e1, Edge e2)
{
    return (e1.weight < e2.weight);
}

class Graph
{
public:
    vector<Edge> edges;
    vector<Edge> mst;
    int *parent;
    int *rank;

    Graph(int V)
    {
        parent = (int *)malloc(V * sizeof(int));
        rank = (int *)malloc(V * sizeof(int));
        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
            rank[i] = 0;
        }
    }

    int get_origin(int x)
    {
        if (parent[x] == -1)
        {
            return x;
        }
        return get_origin(parent[x]);
    }

    bool unite(int a_s, int b_e)
    {
        int a = get_origin(a_s);
        int b = get_origin(b_e);

        if (a == b)
        {
            return false;
        }
        parent[b] = a;
        /* 
        if (rank[a] > rank[b])
        {
            parent[b] = a;
            rank[a]++;
        }
        else if (rank[b] > rank[a])
        {
            parent[a] = b;
            rank[b]++;
        }
        else
        {
            parent[b] = a;
            rank[a]++;
        }
        */
        return true;
    }

    void add_edge(int p, int q, int wt)
    {
        Edge *e = new Edge(p, q, wt);
        edges.push_back(*e);
        return;
    }

    void generate_mst()
    {
        sort(edges.begin(), edges.end(), cmp);
        for (Edge ed : edges)
        {
            //cout << ed.start << " - " << ed.end << endl;
            if (unite(ed.start, ed.end))
            {
                mst.push_back(ed);
            }
            else
            {
                cout << "dont - " << ed.start << ",, " << ed.end << " - " << get_origin(ed.start) << ", " << get_origin(ed.end) << endl;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    cout << "KRUSKAL: " << endl;

    int V = 9;

    Graph *graph = new Graph(V);

    graph->add_edge(0, 1, 4);
    graph->add_edge(0, 7, 8);
    graph->add_edge(1, 2, 8);
    graph->add_edge(1, 7, 11);
    graph->add_edge(2, 3, 7);
    graph->add_edge(2, 8, 2);
    graph->add_edge(2, 5, 4);
    graph->add_edge(3, 4, 9);
    graph->add_edge(3, 5, 14);
    graph->add_edge(4, 5, 10);
    graph->add_edge(5, 6, 2);
    graph->add_edge(6, 7, 1);
    graph->add_edge(6, 8, 6);
    graph->add_edge(7, 8, 7);

    graph->generate_mst();
    for (Edge eds : graph->mst)
    {
        cout << eds.start << " - " << eds.end << endl;
    }

    //return 0;
}