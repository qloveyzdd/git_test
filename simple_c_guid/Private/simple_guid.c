#include "..\Public\simple_guid.h"
#include <combaseapi.h>
#include "..\..\simple_c_string_algorithm\simple_c_string_algorithm.h"

int hex_digit(char c)
{
    int ret = 0;
    if (c > '0' && c <= '9')
    {
        ret = c - '0';
    }
    else if (c > 'A' && c <= 'F')
    {
        ret = c + 10 - 'A';
    }
    else if (c > 'a' && c <= 'f')
    {
        ret = c + 10 - 'a';
    }

    return ret;
}

unsigned int hex_number(char *buf)
{
    unsigned int ret = 0;

    while (*buf)
    {
        ret *= 16;
        ret += hex_digit(*buf++);
    }

    return ret;
}

void normalization_guid(simple_c_guid *c_guid)
{
    c_guid->a = 0;
    c_guid->b = 0;
    c_guid->c = 0;
    c_guid->d = 0;
}

bool create_guid(simple_c_guid *c_guid)
{
    normalization_guid(c_guid);
    if ((CoCreateGuid((GUID *)c_guid)) == S_OK)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void guid_to_string(char *buf, const simple_c_guid *c_guid)
{
    get_printf_s(buf, "%08X%08X%08X%08X", c_guid->a, c_guid->b, c_guid->c, c_guid->d);
}

void string_to_guid(simple_c_guid *c_guid, const char *buf)
{
    char byte_buf[260] = {0};
    c_guid->a = hex_number(string_mid(byte_buf, buf, 0, 8));
    c_guid->b = hex_number(string_mid(byte_buf, buf, 8, 8));
    c_guid->c = hex_number(string_mid(byte_buf, buf, 16, 8));
    c_guid->d = hex_number(string_mid(byte_buf, buf, 24, 8));
}