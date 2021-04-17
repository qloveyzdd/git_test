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

void add_string(const char *in_data, simple_c_string *array_c)
{
    assert(array_c);
    int index = array_c->size;
    array_c->size++;
    array_c->data = realloc(array_c->data, array_c->size * sizeof(str_node));
    strcpy(array_c->data[index].data, in_data);
}

void printf_string(simple_c_string *array_c)
{
    assert(array_c);
    for (int i = 0; i < array_c->size; i++)
    {
        printf("%s \r\n", array_c->data[i].data);
    }
}

char *get_string(int in_index, simple_c_string *array_c)
{
    return array_c->data[in_index].data;
}

void dismantling_string(const char *in_data, const char *str_sub, simple_c_string *array_c)
{
    char buf[260] = {0};
    strcpy(buf,in_data);
    init_string(array_c);
    char *p = strtok(buf, str_sub);
    while (p != NULL)
    {
        add_string(p, array_c);
        p = strtok(NULL, str_sub);
    }
}

