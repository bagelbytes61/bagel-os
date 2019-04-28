#include <stdio.h>

#include "kernel/tty.h"

void kernel_main(void) {
    tty_initialize();

    printf("%s", "Hello, from BagelOS!\n");
}