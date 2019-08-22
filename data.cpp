#include "data.hpp"
using namespace MyData;
Data::Data(initializer_list<int> a)
{
    for (int i : a)
    {
        _list.push_back(i);
    }
}
