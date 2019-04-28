#include <stdio.h>
#include <stdlib.h>

__attribute__((__noreturn__))
void abort(void) {
    #if defined(__is_libk)
    // TODO: Add proper kernel panic
    printf("%s\n", "kernel: panic: abort()");
    #else
    // TODO: Abnormally terminate the process as if by SIGABRT
    printf("%s\n", "abort()");
    #endif

    while(1) { }
    __builtin_unreachable();
}