#ifndef _KERNEL_TTY_H_
#define _KERNEL_TTY_H_

void tty_initialize(void);

void tty_write(const void* buf, size_t size);

void tty_putc(char c);

void tty_puts(const char* str);

#endif