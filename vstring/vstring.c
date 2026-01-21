#include "vstring.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


/*************************************************************************************** */

bool vstring_construct(vstring **vs, int n) //allocate string 
{
    vstring *vstr = malloc(sizeof(vstring) + n);
    if(vstr == NULL)
    {
        printf("--- vstring allocation failed ---");
        return false;
    }
    vstr->len = 0;
    vstr->max_len = n;
    *vs = vstr;
    return true;
}
/*************************************************************************************** */

bool vstring_resize(vstring **vs, int n)
{
    int old_len = (*vs)->len;
    vstring *tmp = realloc(*vs, sizeof(vstring) + n);
    if(tmp != NULL)
    {
        tmp->len = old_len;
        tmp->max_len = n;
        *vs = tmp;
        return true;
    }
    printf("--- vstring reallocation failed ---");
    return false;
}
/*************************************************************************************** */

void vstring_free(vstring **vs)
{
    free(*vs);
    *vs = NULL;
}
/*************************************************************************************** */

bool vstring_store_string(vstring **vs, char *a) //store a null terminated string in vstring
{
    if(*vs == NULL)
    {
        if(!vstring_construct(vs, strlen(a)))
            return 0;
    }
    else if((*vs)->max_len < strlen(a))
    {
        if(!vstring_resize(vs, strlen(a)))
            return 0;
    }

    for(int i = 0; a[i] != '\0'; i++)
    {
        (*vs)->str[i] = a[i];
    }
    (*vs)->len = strlen(a);
    return 1;
}
/*************************************************************************************** */

void vstring_print(vstring *vs)
{
    for(int i = 0; i < vs->len; i++)
    {
        putchar(vs->str[i]);
    }
}
/*************************************************************************************** */

void vstring_println(vstring *vs)
{
    for(int i = 0; i < vs->len; i++)
    {
        putchar(vs->str[i]);
    }
    putchar('\n');
}
/*************************************************************************************** */

int vstring_copy(vstring **vs1, const vstring *vs2)
{
    if(vs2 == NULL)
        return 0;
    if(vs1 == NULL)
    {
        if(!vstring_construct(vs1, vs2->len))
        {
            return 0;
        }
    }
    else if((*vs1)->max_len < vs2->len)
    {
        if(!vstring_resize(vs1, vs2->len))
            return 0;
    }
    memcpy(*vs1, vs2, sizeof(vstring) + vs2->len);
    return 1;
}

/***************************************************************** */

int vstring_cat(vstring **vs1, const vstring *vs2)
{
    if(vs2 == NULL)
    {
        return 0;
    }
    if(*vs1 == NULL)
    {
        if(!vstring_construct(vs1, vs2->len))
        {
            printf("--- Failed to copy ---\n");
            return 0;
        }
    }
    else if((*vs1)->len + vs2->len > (*vs1)->max_len)
    {
        if(!vstring_resize(vs1, (*vs1)->len + vs2->len))
        {
            printf("--- Failed to copy ---\n");
            return 0;
        }
    }

    memcpy((char *) *vs1 + sizeof(vstring) + (*vs1)->len, (char *) vs2 + sizeof(vstring), vs2->len);
    (*vs1)->len = (*vs1)->len + vs2->len; 
    return 1;
}

/************************************************************** */

int vstring_cmp(const vstring *v1, const vstring *v2)
{
    int min = 0, i = 0;

    min = (v1->len < v2->len) ? v1->len : v2->len;

    for(i = 0; i < min; i++)
    {
        if(v1->str[i] != v2->str[i])
            return (unsigned char)v1->str[i] - (unsigned char)v2->str[i];
    }

    return (v2->len < v1->len) - (v1->len < v2->len);
}

/*************************************************************** */

int vstring_append_char(vstring **v, const char c)
{
    if(v == NULL)
    {
        if(!vstring_construct(v, 10))
        {
            printf("--- Failed to copy ---\n");
            return 0;
        }
    }
    else if((*v)->len + 1 > (*v)->max_len)
    {
        if(!vstring_resize(v, 2 * (*v)->max_len))
        {
            printf("--- Failed to copy ---\n");
            return 0;
        }
    }
    (*v)->str[(*v)->len] = c;
    (*v)->len++;
    return 1; 
}

/******************************************************* */
void vstring_make_empty(vstring *v1)
{
    v1->len = 0;
}
