#ifndef COMMON_H
#define COMMON_H

#include <X11/Xlib.h> 
#include <stdlib.h>
#include <stdio.h>

#define FALSE (0)
#define TRUE (!(FALSE))


#define LOG_FILE_PATH "/home/s/terminal.log"

void terminal_log(char* msg);

#define LOG(...) do{                \
    char buff[256];                 \
    sprintf(buff, __VA_ARGS__);     \
    terminal_log(buff);                   \
}while(0)

#define ASSERT(expr, ...) if(!expr) {LOG(__VA_ARGS__); goto fail;}

#define LENGTH(x) (sizeof(x) / sizeof(x[0]))

#endif