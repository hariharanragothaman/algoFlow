#include "../../../debug.h"
/*
 *  File streams used for reading and writing have to set the file position pointer after the contents change.
 *
 *  std::ifstream and std::wifstream   -    File stream for the input of data of type char and wchar_t.
 *  std::ofstream and std::wofstream   -    File stream for the output of data of type char and wchar_t.
 *  std::fstream and std::wfstream     -    File stream for the input and output of data of type char and wchar_t.
 *  std::filebuf and std::wfilebuf     -    Data buffer of type char and wchar_t.
 *
 *  Flags enable us to set the opening mode of a file stream.
 *  FLAGS
 *
 *  std::ios::in        -   Opens the file stream for reading (default for std::ifstream and std::wifstream).
 *  std::ios::out       -   Opens the file stream for writing (default for std::ofstream and std::wofstream).
 *  std::ios::app       -   Appends the character to the end of the file stream.
 *  std::ios::ate       -   Sets the initial position of the file position pointer at the end of the file stream.
 *  std::ios::trunc     -   Deletes the original file.
 *  std::ios::binary    -   Suppresses the interpretation of an escape sequence in the file stream.
 *
 */


int main()
{
    ifstream fin("data.input");
    ofstream out ("data.output");
    out << fin.rdbuf();
    return 0;
}
