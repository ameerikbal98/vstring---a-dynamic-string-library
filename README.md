** Made for strictly education purpose and may contain bugs **

VString: A Dynamic String Library for C

VString is a lightweight C library designed for handling dynamic, length-prefixed strings. By using a Flexible Array Member, it minimizes memory fragmentation and provides efficient string manipulation compared to standard null-terminated char* arrays.
Features

    Contiguous Memory: Metadata and string data are allocated in a single block.

    Length-Prefixed: O(1) time complexity for retrieving string length.

    Automatic Resizing: Functions like vstring_copy and vstring_cat handle memory reallocation automatically if the destination is too small.

    Safety: Built-in bounds checking using max_len and len properties.

Memory Structure

Because vstring uses a flexible array member, the total size of the struct is not fixed.

    max_len: The total capacity of the allocated buffer.

    len: The current number of characters stored.

    str[]: The actual character data (not strictly required to be null-terminated, though functions may add one for compatibility).

    Note: Since vstring is an incomplete type (variable size), you cannot declare an array of vstring objects directly. Instead, use an array of pointers: vstring *my_strings[10];.

API Reference
Initialization & Cleanup
Function	Description
vstring_construct(vs, n)	Allocates a new vstring with capacity n.
vstring_free(vs)	Frees the allocated memory and sets the pointer to NULL.
vstring_resize(vs, n)	Manually changes the capacity of the vstring.
String Operations
Function	Description
vstring_store_string(vs, char*)	Imports a standard C-string into a vstring.
vstring_copy(dest, src)	Copies src to dest. Reallocates dest if it is too small.
vstring_cat(dest, src)	Appends src to the end of dest.
vstring_append_char(vs, c)	Appends a single character to the vstring.
vstring_make_empty(vs)	Resets len to 0 without freeing memory.
Comparison & Output
Function	Description
vstring_cmp(v1, v2)	Lexicographical comparison (returns negative, zero, or positive).
vstring_print(vs)	Prints the string to stdout.
vstring_println(vs)	Prints the string followed by a newline.
Example Usage
C

#include "vstring.h"
#include <stdio.h>

int main() {
    vstring *my_str = NULL;

    // Allocate space for 20 characters
    if (vstring_construct(&my_str, 20)) {
        
        // Store a string
        vstring_store_string(&my_str, "Hello");
        
        // Append a character
        vstring_append_char(&my_str, '!');
        
        // Print it
        vstring_println(my_str); // Output: Hello!
        
        // Cleanup
        vstring_free(&my_str);
    }

    return 0;
}

Compilation

Include the header and compile with your implementation file:
Bash

gcc -o my_program main.c vstring.c
