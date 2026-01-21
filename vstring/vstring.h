#ifndef VSTRING_H
#define VSTRING_H
#include <stdbool.h>

/*This an incomplete type so you can't store it in an array instead use array of pointers*/

typedef struct vstring
{
    int max_len;
    int len;
    char str[];
} vstring;

/*****************************************************************
*  vstring_construct: allocates n number of bytes to a vstring   *
*               type and return true if successful otherwise     *
*               returns false                                    *
*                                                                *  
******************************************************************/

bool vstring_construct(vstring **vs, int n);

/*****************************************************************
*  vstring_resize: resizes the string to n number of bytes       *
*               returns true if successful otherwise returns     *
*               false                                            *
******************************************************************/

bool vstring_resize(vstring **vs, int n);

/*****************************************************************
*  vstring_free: frees the memory occupied the vstring           *
******************************************************************/

void vstring_free(vstring **vs);

/*****************************************************************
*  vstring_store_string: Function used to store a null terminated*
*                string in a vstring                             *
******************************************************************/

bool vstring_store_string(vstring **vs, char *a);

/*****************************************************************
*  vstring_print: prints the string into std out without a       *
*              a new line after                                  *
******************************************************************/

void vstring_print(vstring *vs);

/*****************************************************************
*  vstring_print: prints the string into std out without a       *
*              a new line                                        *
******************************************************************/

void vstring_println(vstring *vs);

/*****************************************************************
*  vstring_print: prints the string into std out without a       *
*              a new line                                        *
******************************************************************/

void vstring_println(vstring *vs);

/*****************************************************************
* vstring_copy: Takes double pointers to destination vstring and *
*          pointer to source vstring.                            *
*          copies the content of second vstring to first. if the *
*          first vstring doesn't have enough memory it will be   *
*          reallocated.                                          *
******************************************************************/
int vstring_copy(vstring **vs1, const vstring *vs2);

/*****************************************************************
* vstring_cat: Takes double pointers to destination vstring and  *
*          pointer to source vstring.                            *
*          copies the content of second vstring and appends to   *
*          the first one.                                        *
******************************************************************/
int vstring_cat(vstring **vs1, const vstring *vs2);

/*****************************************************************
* vstring_cmp: Compares two strings and return -1 if the first   *
*          string is lexicographically before the second strign  *
******************************************************************/
int vstring_cmp(const vstring *v1, const vstring *v2);

/*****************************************************************
* append_char: Take a double pointer to a vstring and character  *
*        appends the character to the end of the vstring         *
******************************************************************/
int vstring_append_char(vstring **v1, const char c);

/*****************************************************************
* vstring_make_empty: empties the string   Note: doesn't free    *
*              the memory                                        *
******************************************************************/
void vstring_make_empty(vstring *v1);


#endif