#include "../../../debug.h"
/*
 *
 *
 * The helper function std::make_unique was unlike its sibling std::make_shared forgotten in the C++11 standard.
 * So std::make_unique was added with the C++14 standard. std::make_unique enables it to create a std::unique_ptr in a single step:
 * std::unique_ptr<int> up = std::make_unique<int>(201
 */

class MyStruct
{
public:
    MyStruct():val(count)
    {
        cout << static_cast<void*>(this) << " Hello: " << val << endl;
        MyStruct::count++;
    }
    ~MyStruct(){
        cout << static_cast<void*>(this) << " Good Bye: " << val << endl;
        MyStruct::count--;
    }
private:
    int val;
    static int count;
};

int MyStruct::count= 0;

int main()
{
    {
        // generates a myUniqueArray with three `MyStructs`
        unique_ptr < MyStruct[] > myUniqueArray{new MyStruct[3]};
    }
    // 0x1200018 Hello: 0
    // 0x120001c Hello: 1
    // 0x1200020 Hello: 2
    // 0x1200020 GoodBye: 2
    // 0x120001c GoodBye: 1
    // 0x1200018 GoodBye: 0

    return 0;
}
