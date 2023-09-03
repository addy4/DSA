#ifndef disk_hpp
#define disk_hpp

#include "page.hpp"

class DiskStorage
{
public:
    static int ctr;
    static DiskStorage *dso;
    DiskStorage();
    vector<PageData> storage;
    void addPage(PageData pg);
    void showPages();
    PageData getPageFile(int id);
    static DiskStorage *getDisk();
};

#endif