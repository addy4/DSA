#include </Users/PremBhatia1/stdc.h>

using namespace std;

void topologicalSort(int src, vector<vector<int>> graph, stack<int> &courses, vector<bool> &visited, vector<bool> &discovered, bool &cycle)
{
    if (visited[src] == true)
    {
        return;
    }

    visited[src] = true;
    discovered[src] = true;
    cout << "Iterating.. " << src << endl;
    for (auto x : graph[src])
    {
        cout << ". . . reached " << x << endl;

        if (discovered[x] == true)
        {
            cout << "cycle found" << endl;
            cycle = true;
            return;
        }

        if (visited[x] == false)
        {
            topologicalSort(x, graph, courses, visited, discovered, cycle);
        }
    }
    discovered[src] = false;
    cout << "PUSHING " << src << endl;
    courses.push(src);
    return;
}

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> x;
        vector<vector<int>> graph(numCourses);
        bool cycle = false;

        for (auto pre : prerequisites)
        {
            graph[pre[1]].push_back(pre[0]);
        }

        /*
        for (int i = 0; i < graph.size(); i++)
        {
            cout << "At: " << i << endl;
            for (int j = 0; j < graph[i].size(); j++)
            {
                cout << " - " << graph[i][j];
            }
            cout << endl;
        }
        */

        stack<int> courses;
        vector<bool> visited(numCourses, false);
        vector<bool> discovered(numCourses, false);

        for (int i = 0; i < numCourses; i++)
        {
            topologicalSort(i, graph, courses, visited, discovered, cycle);
        }

        if (cycle == true)
        {
            return {};
        }

        while (courses.empty() == false)
        {
            x.push_back(courses.top());
            courses.pop();
        }

        return x;
    }
};

int main(int argc, char const *argv[])
{
    Solution *sln = new Solution();

    int numCourses = 2;
    //vector<vector<int>> pre{{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<vector<int>> pre{{1, 0}, {0, 1}};

    vector<int> ans;
    ans = sln->findOrder(numCourses, pre);

    cout << "done" << endl;

    for (auto it : ans)
    {
        cout << it << endl;
    }

    return 0;
}
