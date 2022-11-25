#include "bits/stdc++.h"
#include "../../../debug.h"
using namespace std;

/*
 *  A stream is an infinite data stream on which we can push or pull data.
 *  String streams and file streams enable strings and files to interact with the stream directly.
 *  String streams need the header <sstream>.
 *  They are not connected to an input or output stream and store their data in a string.
 */

template < class T >
T StringTo ( const std::string& source )
{
    std::istringstream iss(source);
    T ret;
    iss >> ret;
    return ret;
}

template< class T >
std::string ToString(const T& n)
{
    std::ostringstream tmp ;
    tmp << n;
    return tmp.str();
}


int main()
{
    /* Write data to a stream */
    stringstream os1;
    os1 << "New String";
    os1.str("Another New String");


    /* Read data from a string stream */
    stringstream os2;
    string str;
    os2 >> str;
    str = os2.str();

    // Clear a string stream
    stringstream os3;
    os3.str("");

    /*
     *  Stringstreams are often used for type-safe conversions between string and numeric values
     */
    std::cout << std::endl;

    std::cout << "5 = "  << std::string("5") << std::endl;
    std::cout << "5 = " <<  StringTo<int>("5") << std::endl;
    std::cout << "5 + 6 = " << StringTo<int>("5") + 6 << std::endl;

    std::string erg(ToString(StringTo<int> ("5") + 6 ) );
    std::cout << "5 + 6 = " << erg  << std::endl;

    std::cout << "5e10: " << std::fixed << StringTo<double>("5e10")  << std::endl;

    std::cout << std::endl;
    return 0;
}
