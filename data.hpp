#include <initializer_list>
#include <list>

using namespace std;

namespace MyData
{
class Data
{
private:
public:
    Data(initializer_list<int> a);
    list<int> _list;
};
} // namespace MyData
