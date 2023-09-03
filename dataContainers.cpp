#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <iostream>

using namespace std;

class Check
{
public:
    int a;
    int b;
}

class Mapper
{
    // Variables
public:
    map<int, pair<int, int>> tweets;
    map<int, vector<int>> tw;

    // Methods
public:
    void insertMapAtIndex(int k, pair<int, int> pr)
    {
        tw[k].push_back(pr.first);
        tw[k].push_back(pr.second);
        tweets[k] = {pr.first, pr.second};
    }

    void getMapAtIndex(int k)
    {
        cout << tw[k][0] << " | " << tw[k][1] << endl;
        cout << tweets[k].first << ", " << tweets[k].second << endl;
    }

    void sizeOfMap()
    {
        cout << tweets.size() << endl;
    }

    void iterateMap()
    {

        for (auto it : tweets)
        {
            cout << it.first << ": { " << it.second.first << ", " << it.second.second << " }" << endl;
        }
        for (auto it : tw)
        {
            cout << it.first << ": " << endl;
            for (auto elem : it.second)
            {
                cout << elem << ", ";
            }
            cout << endl;
        }
    }
};

class UMap
{
    // Variables
public:
    unordered_map<int, vector<string>> umap;

    // Methods
public:
    void insertUMap(int k, string s)
    {
        umap[k].push_back(s);
        cout << umap[k][umap[k].size() - 1] << endl;
    }

    void iterateUMap()
    {

        for (auto it : umap)
        {
            cout << it.first << " : ";
            for (auto i : it.second)
            {
                cout << i << ", ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    Mapper *mp = new Mapper();
    mp->insertMapAtIndex(4, {1, 2});
    mp->insertMapAtIndex(1, {1, -1});
    mp->insertMapAtIndex(2, {3, 4});
    cout << " -------- " << endl;
    mp->getMapAtIndex(1);
    mp->sizeOfMap();
    mp->iterateMap();

    UMap *ump = new UMap();
    ump->insertUMap(8, "ab");
    ump->insertUMap(8, "cd");
    ump->insertUMap(3, "aa");
    ump->insertUMap(3, "rt");

    ump->iterateUMap();

    cout << " -------------- " << endl;

    //vector<vector<int>> vec2d(1);
    vector<vector<int>> vec2d;

    vec2d[0].push_back(1);

    cout << vec2d[0][0] << endl;

    Check *c = new Check();
    cout << c->b << c->a << endl;

    return 0;
}
