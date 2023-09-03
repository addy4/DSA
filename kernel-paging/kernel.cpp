#include </Users/PremBhatia1/stdc.h>
#define PAGES 10

using namespace std;

#include "page.hpp"
#include "disk.hpp"
#include "cache.hpp"

//CacheLRU *cso = new CacheLRU(4);

int main(int argc, char const *argv[])
{
    PageData p1(1, "abcd");
    PageData p2(2, "ret");
    PageData p3(3, "oknw");
    PageData p4(4, "lknw");
    PageData p5(5, "knwt");
    PageData p6(6, "abcd");
    PageData p7(7, "retii");
    PageData p8(8, "kn");
    PageData p9(9, "kny");
    PageData p10(10, "kni");

    CacheLRU *cso = new CacheLRU(4);
    DiskStorage *dso = DiskStorage::getDisk();

    dso->addPage(p1);
    dso->addPage(p2);
    dso->addPage(p3);
    dso->addPage(p4);
    dso->addPage(p5);
    dso->addPage(p6);
    dso->addPage(p7);
    dso->addPage(p8);
    dso->addPage(p9);
    dso->addPage(p10);

    int refs[] = {1, 2, 3, 3, 1, 4, 2, 4, 5, 6, 7, 8, 1, 2, 7, 8, 5, 6, 6, 5, 6, 7, 8, 9, 10, 1, 2, 10, 10, 9, 1};

    for (int i = 0; i < sizeof(refs) / sizeof(refs[0]); i++)
    {
        PageData file = cso->getPageFile(refs[i]);
        file.getData();
        cso->CacheContent();
    }

    //Kernel::BootLoad();
    //Kernel::LoadProcesses();

    return 0;
}