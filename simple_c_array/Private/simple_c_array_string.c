#include "../Public/simple_c_array_string.h"

void init_string(simple_c_string *array_c)
{
    assert(array_c);
    array_c->size = 0;
    array_c->data = NULL;
    // memset(array_c->data, 0, 1);
}

void destroy_string(simple_c_string *array_c)
{
    assert(array_c);
    free(array_c->data);
}

void add_string(const char* in_data, simple_c_string *array_c)
{
    assert(array_c);
    int index = array_c->size;
    array_c->size += 1;
    array_c->data = realloc(array_c->data, array_c->size * sizeof(str_node));
    strcpy(array_c->data[index].data,in_data);
}

void printf_string(simple_c_string *array_c)
{
    assert(array_c);
    for (int i = 0; i < array_c->size; i++)
    {
        printf("%s \r\n", array_c->data[i].data);
    }
} 