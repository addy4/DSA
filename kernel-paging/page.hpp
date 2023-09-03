#ifndef page_hpp
#define page_hpp

using namespace std;

    class PageData
{
private:
    string ct;

public:
    string content;
    int identifier;

    PageData();
    PageData(int id, string data);

    void getData();
};

#endif