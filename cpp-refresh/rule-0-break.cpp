//
// Created by hariharanragothaman on 4/20/25.
//
#include <cstring>

class Buffer
{
    size_t  len {};
    char* bytes {}; // raw resources

public:
    Buffer(size_t n): len(n), bytes{new char[n]} {}

    // Destructor
    ~Buffer() {delete[] bytes;}


};
