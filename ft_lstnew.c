#include "libft.h"

t_list	*ft_lstnew(void *content)
{
    t_list  *elem = NULL;

    elem = (t_list*)malloc(sizeof(t_list));
    if (elem == NULL)
        return (NULL);
    elem->content = content;
    elem->next = NULL;
    return (elem);
}