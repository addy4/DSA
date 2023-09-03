#include </Users/PremBhatia1/stdc.h>
#define PAGES 10

using namespace std;

#include "cache.hpp"
#include "disk.hpp"

CacheLRU::CacheLRU(int csize)
{
    this->capacity = csize;
    addresses = (list<PageData>::iterator *)malloc(sizeof(list<PageData>::iterator) * (PAGES + 5));
    for (int i = 0; i < PAGES + 5; i++)
    {
        addresses[i] = cached.end();
    }
}

PageData CacheLRU::getPageFile(int id)
{
    list<PageData>::iterator it;
    PageData page;
    if (addresses[id] == cached.end())
    {
        cout << "MISS" << endl;
        if (cached.size() == capacity)
        {
            page = cached.back();
            cached.pop_back();
            addresses[page.identifier] = cached.end();
        }
        DiskStorage *dso = DiskStorage::getDisk();
        page = dso->getPageFile(id);
    }
    else
    {
        cout << "HIT" << endl;
        it = addresses[id];
        //cout << "HIT11" << endl;
        cached.erase(it);
        //cout << "HIT12" << endl;
        page = *it;
    }
    cached.push_front(page);
    addresses[id] = cached.begin();
    return cached.front();
}

void CacheLRU::CacheContent()
{
    cout << "In cache..." << endl;
    for (int i = 0; i < PAGES + 5; i++)
    {
        if (addresses[i] != cached.end())
        {
            cout << ". . . ." << addresses[i]->identifier << " in cache!" << endl;
        }
    }
}

CacheLRU *cso = new CacheLRU(4);