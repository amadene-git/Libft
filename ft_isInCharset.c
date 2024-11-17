#include <libft.h>

int ft_isInCharset(char c, const char *charset) {
    while (*charset) {
        if (*charset == c)
            return (1);
        ++charset;
    }
    return (0);
}