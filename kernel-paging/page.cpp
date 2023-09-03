#include </Users/PremBhatia1/stdc.h>
#include "page.hpp"

using namespace std;

PageData::PageData()
{
    // pass
}

PageData::PageData(int id, string data)
{
    this->identifier = id;
    this->content = data;
}

void PageData::getData()
{
    cout << this->content << endl;
}