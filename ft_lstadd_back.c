#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *elem;
    
    if (lst == NULL || new == NULL)
        return;
    if (*lst == NULL)
    {
        *lst = new;
        return;
    }
    elem = *lst;
    while (elem->next != NULL)
        elem = elem->next;
    elem->next = new;
}