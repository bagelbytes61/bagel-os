#include <string.h>

void* memmove(void* destination, const void* source, size_t num) {
    if (destination < source) {
        while (num--) {
            for (size_t i = 0; i < num; ++i) {
                ((unsigned char*)destination)[i] = ((const unsigned char*)source)[i];
            }
        }
    }
    else {
        for (size_t i = num; i > 0; --i) {
            ((unsigned char*)destination)[i - 1] = ((const unsigned char*)source)[i - 1];
        }
    }

    return destination;
}