#include "w1ce.h"

#ifdef _WIN32
    #include <conio.h>
    #include <Windows.h>
#endif

bool w1_isfile(const char* path)
{
    #ifdef _WIN32
        DWORD a = GetFileAttributes(path);
        return (a != INVALID_FILE_ATTRIBUTES) && !(a & FILE_ATTRIBUTE_DIRECTORY);
    #else
        #error w1_isfile is only implemented on win32
    #endif
}

bool w1_isdir(const char* path)
{
    #ifdef _WIN32
        DWORD a = GetFileAttributes(path);
        return (a != INVALID_FILE_ATTRIBUTES) && (a & FILE_ATTRIBUTE_DIRECTORY);
    #else
        #error w1_isdir is only implemented on win32
    #endif
}

unsigned int w1_abspath(const char* path, char* buf, unsigned int buf_length)
{
    #ifdef _WIN32
        return GetFullPathName(path, buf_length, buf, 0);
    #else
        #error w1_abspath is only implemented on win32
    #endif
}

int w1_getch()
{
    #ifdef _WIN32
        return _getch();
    #else
        #error w1_abspath is only implemented on win32
    #endif
}

