/*

-- Topological sort
    - DFS
    - Mark time at which completely visited
    - (visited means all adjacent vertices covered)
    - Print vertices in
    - Decreasing order of time
    - (used linear sort for sorting in decreasing order)
-- Toplogical Sort 

 */

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include </Users/PremBhatia1/stdc.h>

using namespace std;

class Node
{
public:
    int val;
    int finishtime;

    Node(int val)
    {
        this->val = val;
    }
};

void addEdge(vector<Node *> adjList[], int u, int v, Node *unode, Node *vnode)
{
    adjList[u].push_back(vnode);
    //adjList[v].push_back(unode);
}

void createGraph(vector<Node *> adjList[], Node *node_list[])
{
    int V = 6;

    node_list[0] = new Node(0);
    node_list[1] = new Node(1);
    node_list[2] = new Node(2);
    node_list[3] = new Node(3);
    node_list[4] = new Node(4);
    node_list[5] = new Node(5);

    addEdge(adjList, 0, 1, node_list[0], node_list[1]);
    addEdge(adjList, 1, 2, node_list[1], node_list[2]);
    addEdge(adjList, 2, 3, node_list[2], node_list[3]);
    addEdge(adjList, 2, 4, node_list[2], node_list[4]);
    addEdge(adjList, 3, 5, node_list[3], node_list[5]);

    /* 
    addEdge(adjList, 2, 3, node_list[2], node_list[3]);
    addEdge(adjList, 3, 1, node_list[3], node_list[1]);
    addEdge(adjList, 5, 2, node_list[5], node_list[2]);
    addEdge(adjList, 5, 0, node_list[5], node_list[0]);
    addEdge(adjList, 4, 0, node_list[4], node_list[0]);
    addEdge(adjList, 4, 1, node_list[4], node_list[1]);
    */
}

void dfs(vector<Node *> adjList[], int start, int visited[], int *time, Node *start_node, int linsort[])
{
    if (visited[start] == 1)
    {
        return;
    }

    visited[start] = 1;
    (*time)++;

    for (auto x : adjList[start])
    {
        if (visited[x->val] == 0)
        {
            dfs(adjList, x->val, visited, time, x, linsort);
        }
    }

    (*time)++;
    start_node->finishtime = *time;
    linsort[start_node->finishtime] = start;
    cout << start << " visited completely at time " << start_node->finishtime << endl;
}

int main(int argc, char const *argv[])
{
    cout << "starting topological sort....." << endl;

    int V = 6;
    vector<Node *> adjList[V];
    Node *node_list[V];
    int time = 0;
    int visited[V];
    int linsort[V * V];

    createGraph(adjList, node_list);

    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < V * V; i++)
    {
        linsort[i] = -1;
    }

    for (int s = 0; s < V; s++)
    {
        dfs(adjList, s, visited, &time, node_list[s], linsort);
    }

    cout << "\n -- Sorted --" << endl;

    for (int j = (V * V - 1); j > -1; j--)
    {
        if (linsort[j] != -1)
        {
            cout << "Node " << linsort[j] << endl;
        }
    }

    return 0;
}
