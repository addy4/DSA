#ifndef cache_hpp
#define cache_hpp

#include "page.hpp"

class CacheLRU
{
private:
    list<PageData> cached;
    int capacity;
    list<PageData>::iterator *addresses;

public:
    CacheLRU(int csize);
    PageData getPageFile(int id);
    void CacheContent();
};

#endif