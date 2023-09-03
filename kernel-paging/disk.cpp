#include </Users/PremBhatia1/stdc.h>
#define PAGES 10
#include "disk.hpp"

int DiskStorage::ctr = 0;
DiskStorage *DiskStorage::dso = nullptr;

using namespace std;

DiskStorage::DiskStorage()
{
    ctr++;
    cout << "#Instances: " << ctr << endl;
}

void DiskStorage::addPage(PageData pg)
{
    //cout << "Pushing!" << endl;
    storage.push_back(pg);
}

PageData DiskStorage::getPageFile(int id)
{
    PageData pg_target;
    for (auto pgi : storage)
    {
        if (pgi.identifier == id)
        {
            pg_target = pgi;
        }
    }
    return pg_target;
}

void DiskStorage::showPages()
{
    for (auto p : storage)
    {
        cout << p.identifier << ": ";
        p.getData();
    }
}

DiskStorage *DiskStorage::getDisk()
{
    //cout << "check" << endl;
    if (dso == nullptr)
    {
        dso = new DiskStorage();
    }
    //cout << "checked" << endl;
    return dso;
}