//https://leetcode.com/problems/time-based-key-value-store/
//Modification - real problem : timestamp always increasing, here - timestamp not necesarilly increasing

#include </Users/PremBhatia1/stdc.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Valv
{
public:
    int timestamp;
    string val;

    Valv(int time, string val_string)
    {
        this->timestamp = time;
        this->val = val_string;
    }
};

class Compare
{
public:
    bool operator()(Valv *below, Valv *above)
    {
        if (below->timestamp < above->timestamp)
        {
            return true;
        }
        return false;
    }
};

class ValVect
{
public:
    priority_queue<Valv *, vector<Valv *>, Compare> pqds;

    void put(Valv *v)
    {
        pqds.push(v);
    }
};

class TimeMap
{
public:
    map<string, ValVect> ds;

    void set(string key, string val, int timestamp)
    {
        Valv *v = new Valv(timestamp, val);
        ds[key].put(v);
        return;
    }

    string get(string key, int timestamp)
    {
        priority_queue<Valv *, vector<Valv *>, Compare> pqelem;
        pqelem = ds[key].pqds;
        while (!pqelem.empty())
        {
            if (pqelem.top()->timestamp <= timestamp)
            {
                return pqelem.top()->val;
            }
            pqelem.pop();
        }
        return "";
    }

    void printAll()
    {
        for (auto it : ds)
        {
            cout << it.first << endl;
            priority_queue<Valv *, vector<Valv *>, Compare> elem;
            elem = it.second.pqds;
            while (!elem.empty())
            {
                cout << elem.top()->val << " " << elem.top()->timestamp << endl;
                elem.pop();
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    TimeMap *obj = new TimeMap();

    obj->set("A", "C", 100);
    obj->set("A", "B", 2);
    obj->set("D", "W", 23);
    obj->set("D", "Z", 24);
    cout << obj->get("A", 20) << endl;
    cout << obj->get("A", 100) << endl;
    cout << obj->get("D", 22) << endl;
    cout << obj->get("D", 25) << endl;

    obj->printAll();

    return 0;
}