# Questions

## What's `stdint.h`?

int8_t
int16_t
int32_t
uint8_t
uint16_t
uint32_t

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

To avoid portability issues. Across different systems, int, double, etc may have different sizes, but uint8_t, etc
have standard sizes and standard operation. the 8 says to give exactly 8 bits, and the u vs no u says whether it is
unsigned or signed, allow for consistent behavior.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?


byte = 8 bits = 1 byte
dword = 32 bits = 4 bytes
long = 32 bits = 4 bytes
word = 16 bits = 2 bytes

typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;
typedef uint16_t WORD;

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

42 4D

## What's the difference between `bfSize` and `biSize`?

bfSize is the file size, whereas biSize is the image size
bfSize = 54 + biSize (54 = header info info)

## What does it mean if `biHeight` is negative?

it means the image is stored top to bottom instead of the normal bottom to top

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

It fails to open the file

## Why is the third argument to `fread` always `1` in our code?

Because we are providing sizeof(content we want), and we only want to manipulate one of each each time.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

fseek places the pointer at a certain offset from your designated point. For example,
fseek(ptr, 7, SEEK_CUR) will place you 7 from the current position

## What is `SEEK_CUR`?

The current pointer position

## Whodunit?

It was professor plum with the candlestick in the library
