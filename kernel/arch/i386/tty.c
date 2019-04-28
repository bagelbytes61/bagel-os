#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "kernel/tty.h"

#include "vga.h"

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_MEMORY 0xb8000

static size_t tty_row, tty_column;
static uint8_t tty_color;
static uint16_t* tty_buffer;

static void tty_put_at(unsigned char c, uint8_t color, size_t x, size_t y) {
    tty_buffer[y * VGA_WIDTH + x] = vga_entry(c, color);
}

static void tty_put(unsigned char c, uint8_t color) {
    tty_put_at(c, color, tty_column, tty_row);

    if (++tty_column == VGA_WIDTH) {
        tty_column = 0u;
        if (++tty_row == VGA_HEIGHT) {
            tty_row = 0u;
        }
    }
}

void tty_initialize(void) {
    tty_row = tty_column = 0u;
    tty_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    tty_buffer = (uint16_t*)VGA_MEMORY;

    for (size_t y = 0u; y < VGA_HEIGHT; ++y) {
        for (size_t x = 0u; x < VGA_WIDTH; ++x) {
            tty_buffer[y * VGA_WIDTH +x] = vga_entry(' ', tty_color);
        }
    }
}

void tty_write(const void* buf, size_t size) {
    for (size_t i = 0u; i < size; ++i) {
        tty_put(((unsigned char*)buf)[i], tty_color);
    }
}

void tty_putc(char c) {
    tty_put(c, tty_color);
}

void tty_puts(const char* str) {
    tty_write(str, strlen(str));
}