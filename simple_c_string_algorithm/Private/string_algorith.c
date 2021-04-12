#include "../Public/string_algorith.h"
#include <stdarg.h>
//#define INDEX_NONE -1

void remove_char_start(char *str, const char sub_char)
{
    int len = strlen(str) + 1;

    for (int i = 0; i < len; i++)
    {
        if (str[i] == sub_char)
        {
            strcpy(&str[i], &str[i + 1]);
        }
    }
}

void remove_char_end(char *str, const char sub_char)
{
    int len = strlen(str) + 1;

    for (int i = len; i >= 0; i--)
    {
        if (str[i] == sub_char)
        {
            strcpy(&str[i], &str[i + 1]);
        }
    }
}

int find_string(char *str, const char *sub_str)
{
    int len = strlen(sub_str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == sub_str[0])
        {
            int j = 0;
            for (; sub_str[j] != "\0" && str[i + j] == sub_str[j]; j++)
                ;
            if (j == len)
            {
                return i;
            }
        }
    }

    return -1;
}

void remove_string_start(char *str, const char *sub_str)
{
    int index = find_string(str, sub_str);
    if (index != -1)
    {
        strcpy(&str[index], &str[index + strlen(sub_str)]);
    }
}

void replace_char_inline(char *str, const char sub_char_a, const char sub_char_b)
{
    int index = find_string(str, &sub_char_a);
    if (index != -1)
    {
        str[index] = sub_char_b;
        replace_char_inline(str, sub_char_a, sub_char_b);
    }
}

int get_printf(char *buf, char *format, ...)//va_arg的调取不可以低于int字节数，也不可以时浮点型
{
	int ret_num = 0;
	va_list param_list;
	va_start(param_list, format);

	for (int i = 0; *format != '\0'; i++)
	{
		if (*(format - 1) != '%')
		{
			buf[i] = *format;
		}
		else
		{
			i--;
			switch (*format)
			{
			case 'c':
			case 'C':
			{
				buf[i] = va_arg(param_list, int);
				break;
			}
			case 's':
			case 'S':
			{
				char* p = va_arg(param_list, char*);
				int len = strlen(p);
				ret_num += len;
				for (int j = 0; j < len; j++,i++)
				{
					buf[i] = p[j];
				}
				i--;
				break;
			}
			case 'i':
			case 'I':
			{
				char p[128] = {0};
				_itoa(va_arg(param_list, int), p, 10);
				int len = strlen(p);
				ret_num += len;
				for (int j = 0; j < len; j++,i++)
				{
					buf[i] = p[j];
				}
				i--;
				break;
			}
			default:
				break;
			}
		}
		format++;
	}

	return ret_num;
}