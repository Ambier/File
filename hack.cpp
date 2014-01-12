#include <iostream>
#include <fstream>
#include <string>



#include "File.h"

int main(int argc,char* argv[])
{
    File file("./test.dat");

    std::cout<<file.size()<<std::endl;

    std::cout<<file.mtime("%Y-%m-%d %H:%M:%S")<<std::endl;

    return 0;
}
