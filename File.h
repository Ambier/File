#ifndef FILE_H
#define FILE_H

#include <string>
#include <iostream>

#include <ctime>
#include <cstdio>
#include <cstdlib>

#include "sys/types.h"
#include "sys/stat.h"

class File
{
    public:

        //construct function
        File();

        File(const std::string& filename);

        /**
        *@brief get the size of the file
        */
        size_t size();
        void size(size_t& fileSize);

        /**
        *@brief get the last modified time of the file
        */
        time_t mtime();
        void mtime(time_t& modifyTime);
        std::string mtime(const std::string& mtimeFormat);
        /**
        *@brief get the create time of the file
        */
        time_t ctime();
        void ctime(time_t& createTime);
        std::string ctime(const std::string& ctimeFormat);
        //destruct function
        virtual ~File();
    protected:
    private:
        struct stat fileStatus;
};

#endif // FILE_H

