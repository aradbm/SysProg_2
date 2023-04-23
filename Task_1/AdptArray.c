#include <stdio.h>
#include <stdlib.h>
#include "AdptArray.h"
typedef struct AdptArray_
{
    int size;
    PElement *element_array; // The array of elements
    COPY_FUNC copy;
    DEL_FUNC delete;
    PRINT_FUNC print;
} AdptArray, *PAdptArray;

PAdptArray CreateAdptArray(COPY_FUNC c_fun, DEL_FUNC d_func, PRINT_FUNC p_func)
{
    PAdptArray arr = (PAdptArray)malloc(sizeof(AdptArray));
    if (arr == NULL)
    {
        return NULL;
    }
    arr->size = 0;
    arr->element_array = NULL;
    arr->copy = c_fun;
    arr->delete = d_func;
    arr->print = p_func;
    return arr;
}
void DeleteAdptArray(PAdptArray p_arr)
{
    if (p_arr == NULL)
        return;
    for (size_t i = 0; i < p_arr->size; i++)
    {
        if (p_arr->element_array[i] != NULL)
        {
            p_arr->delete (p_arr->element_array[i]);
        }
    }
    free(p_arr->element_array);
    free(p_arr);
}
Result SetAdptArrayAt(PAdptArray p_arr, int index, PElement elem)
{
    if (index < 0)
        return FAIL;

    if (p_arr == NULL) // check we get a array
        return FAIL;
    int newsize = p_arr->size;
    if (p_arr->size <= index) // when index is bigger than arr size
    {
        newsize = index + 1;
        // first we need to increase the size of the array:
        PElement *new_arr = (PElement *)calloc(newsize, sizeof(PElement));
        if (new_arr == NULL)
            return FAIL;
        for (size_t i = 0; i < p_arr->size; i++)
        {
            if (p_arr->element_array[i] != NULL)
                new_arr[i] = (p_arr->element_array[i]);
        }
        free(p_arr->element_array);
        p_arr->element_array = new_arr;
    }
    if (p_arr->element_array[index] != NULL)
        p_arr->delete (p_arr->element_array[index]);
    p_arr->element_array[index] = p_arr->copy(elem);
    p_arr->size = newsize;
    return SUCCESS;
}
PElement GetAdptArrayAt(PAdptArray p_arr, int index)
{
    if (p_arr == NULL)
        return NULL;
    if (p_arr->size < index)
        return NULL;
    if (p_arr->element_array[index] == NULL)
        return NULL;
    return p_arr->copy(p_arr->element_array[index]);
}
int GetAdptArraySize(PAdptArray p_arr)
{
    if (p_arr == NULL)
    {
        return -1;
    }
    else
        return p_arr->size;
}
void PrintDB(PAdptArray p_arr)
{
    if (p_arr != NULL)
        for (size_t i = 0; i < p_arr->size; i++)
        {
            if (p_arr->element_array[i] != NULL)
                p_arr->print(p_arr->element_array[i]);
        }
}