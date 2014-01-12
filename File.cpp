#include "File.h"

File::File()
{
    //ctor
}

File::File(const std::string& filename)
{
    int ret = stat(filename.c_str(),&fileStatus);

    if(ret<0)
    {
        std::cerr<<"read the file status error"<<std::endl;

        exit(-1);
    }
}

size_t File::size()
{
    return fileStatus.st_size;
}

void File::size(size_t& fileSize)
{
    fileSize = fileStatus.st_size;
}


time_t File::mtime()
{
    return fileStatus.st_mtime;
}

void File::mtime(time_t& modifyTime)
{
    modifyTime = fileStatus.st_mtime;
}

std::string File::mtime(const std::string& mtimeFormat)
{
    struct tm* timeInfo;

    timeInfo = localtime(&fileStatus.st_mtime);

    char fmtTimeBuffer[100];

    strftime(fmtTimeBuffer,100,mtimeFormat.c_str(),timeInfo);
    fmtTimeBuffer[100] =0;

    return fmtTimeBuffer;
}

time_t File::ctime()
{
    return fileStatus.st_ctime;
}

void File::ctime(time_t& createTime)
{
    createTime = fileStatus.st_ctime;
}

std::string File::ctime(const std::string& ctimeFormat)
{
    struct tm* timeInfo;

    timeInfo = localtime(&fileStatus.st_ctime);

    char fmtTimeBuffer[100];

    strftime(fmtTimeBuffer,100,ctimeFormat.c_str(),timeInfo);
    fmtTimeBuffer[100] =0;

    return fmtTimeBuffer;
}

File::~File()
{
    //dtor
}

