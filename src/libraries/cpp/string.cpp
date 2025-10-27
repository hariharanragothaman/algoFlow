#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Hello, world!" << "\n"; // "Hello world!" is a C-style string literal.

    /*
     * While C-style string literals are fine to use, C-style string variables behave oddly, are hard to work with
     * In modern C++ best to avoid C-style strings
     *
     * We have std:string and std:string_view (They are clas types)
     */

    string name{}; // empty string
    string name2{"Alex"}; // Initialize name with string literal "Alex"

    name2 = "John Smith"; // change name2 to -> John

    /*
     *
     *
     * initialized with the string "Alex", which contains five characters (four explicit characters and a null-terminator).
     * We then set name to a larger string, and then a smaller string.
     * std::string has no problem handling this!
     * You can even store really long strings in a std::string.
     *
     * If std::string doesn’t have enough memory to store a string, it will request additional memory (at runtime)
     * using a form of memory allocation known as dynamic memory allocation.
     * This ability to acquire additional memory is part of what makes std::string so flexible, but also comparatively slow.
     */

    string myID{"45"};
    cout << "Name is: " << name2 << endl;

    /* Note constraints when using with string with spaces
     * It turns out that when using operator>> to extract a string from std::cin,
     * operator>> only returns characters up to the first whitespace it encounters.
     */

    string tmp{};
    getline(cin >> ws, name); // read a full line of text into name

    /*
     * ws, here is an input manipulator, tells std::cin to ignore, leading whitespaces before extraction
     */

    /*
     * Initializing a std::string is expensive
     * Whenever a std::string is initialized, a copy of the string used to initialize it is made.
     * Making copies of strings is expensive, so care should be taken to minimize the number of copies made.
     */

    /*
     * Do not pass std::string by value
     * When a std::string is passed to a function by value,
     * the std::string function parameter must be instantiated and initialized with the argument.
     * This results in an expensive copy.
     *
     * Now, when function returns a value, it makes a copy to the caller?
     * Does that mean you cannot return a string?
     * We can if it's a local variable, returned from another functino call, temporary variable.
     *
     * string also support move semantics, which allows an object that will be destroyed at the end
     * of the function to be returned without making a copy.
     *
     * std::string can also be referenced by const reference. - which is another way to avoid making a copy()
     * ~ Here string_view will be helpful.
     *
     */

    string tmp2 = "goo\n"s; // literal for strings using namespace std::literals.
    cout << tmp2;

    return 0;

}
