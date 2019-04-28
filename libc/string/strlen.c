#include <string.h>

size_t strlen(const char* str) {
    const char* end = str;

    while (*end++);

    return end - str - 1;;
}