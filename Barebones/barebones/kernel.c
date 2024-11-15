#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#if defined(__linux__)
    #error "This code must be compiled with a cross-compiler"
#endif

#if !defined(__i386__)
    #error "This code must be compiled with an x86-elf compiler"
#endif

enum vga_color {
    VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg){
    return fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color){
    return (uint16_t) uc | (uint16_t) color << 8;
}

size_t strlen(const char* str){
    size_t len = 0;
    while(str[len]){
        len++;
    }
    return len;
}

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

void terminal_initialize(void){
    terminal_row = 0;
    terminal_column = 0;
    terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    terminal_buffer = (uint16_t*) 0xB8000;
    for(size_t y = 0; y < VGA_HEIGHT; y++){
        for(size_t x = 0; x < VGA_WIDTH; x++){
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = vga_entry(' ', terminal_color);
        }
    }
}

void terminal_setcolor(uint8_t color){
    terminal_color = color;
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y){
    const size_t index = y * VGA_WIDTH + x;
    terminal_buffer[index] = vga_entry(c, color);
}

void terminal_shift_down(){
    
}

void terminal_putchar(char c){
    
    if(c == '\n'){
        terminal_row++;
        terminal_column = 0;
        return;
    }

    terminal_putentryat(c, terminal_color, terminal_column, terminal_row);

    if(++terminal_column == VGA_WIDTH){
        terminal_column = 0;
        if(++terminal_row == VGA_HEIGHT){
            terminal_row = 0;
        }
    }
    
}

void terminal_write(const char* data, size_t size){
    for(size_t i = 0; i < size; i++){
        terminal_putchar(data[i]);
    }
}

void terminal_writestring(const char* data){
    terminal_write(data, strlen(data));
}

void kernel_main(void){
    terminal_initialize();
    terminal_writestring("Hello, kernel World!\n");
    terminal_writestring(
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.\n");
    terminal_writestring("This is a new line.\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n");
    terminal_writestring("This is a new line.\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n");
    terminal_writestring("This is a new line.\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n");github
    
}