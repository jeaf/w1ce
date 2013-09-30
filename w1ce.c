#include "w1ce.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <conio.h>
    #include <Windows.h>
#else
    #include <sys/param.h>
    #include <sys/stat.h>
    #include <termios.h>
#endif

bool w1_isfile(const char* path)
{
    #ifdef _WIN32
        DWORD a = GetFileAttributes(path);
        return (a != INVALID_FILE_ATTRIBUTES) && !(a & FILE_ATTRIBUTE_DIRECTORY);
    #else
        struct stat sb;
        stat(path, &sb);
        return S_ISREG(sb.st_mode);
    #endif
}

bool w1_isdir(const char* path)
{
    #ifdef _WIN32
        DWORD a = GetFileAttributes(path);
        return (a != INVALID_FILE_ATTRIBUTES) && (a & FILE_ATTRIBUTE_DIRECTORY);
    #else
        struct stat sb;
        stat(path, &sb);
        return S_ISDIR(sb.st_mode);
    #endif
}

unsigned int w1_abspath(const char* path, char* buf, unsigned int buf_length)
{
    #ifdef _WIN32
        return GetFullPathName(path, buf_length, buf, 0);
    #else
        assert(buf_length >= PATH_MAX);
        realpath(path, buf);
        return 0;
    #endif
}

int w1_getch()
{
    #ifdef _WIN32
        return _getch();
    #else
        // from: http://stackoverflow.com/questions/7469139/what-is-equivalent-to-getch-getche-in-linux

        struct termios old;
        struct termios new;

        // initTermios
        tcgetattr(0, &old); /* grab old terminal i/o settings */
        new = old; /* make new settings same as old settings */
        new.c_lflag &= ~ICANON; /* disable buffered i/o */
        new.c_lflag &= ~ECHO; /* set echo mode */
        tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */

        // Read char
        int ch = getchar();

        // resetTermios and return val
        tcsetattr(0, TCSANOW, &old);
        return ch;
    #endif
}

