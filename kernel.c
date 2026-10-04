typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

#define VGA_MEMORY 0xB8000
#define VGA_WIDTH 80

volatile uint16_t* video_memory = (uint16_t*)VGA_MEMORY;

int position = 0;

void print_char(char character, uint8_t color)
{
    video_memory[position] = ((uint16_t)color << 8) | character;
    position++;
}

void print_string(char* text, uint8_t color)
{
    while (*text)
    { print_char(*text, color);
        text++;
    }
}

void kernel_main()
{
    print_string("Name: Zunaira Ansar", 0x0D);

    position = VGA_WIDTH;

    print_string("Roll No: 24011556-211", 0x09);

    while (1)
    {
    }
}
