#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *elem = NULL;
    t_list  *begin = NULL;
    
    if (lst == NULL || f == NULL || del == NULL)
        return (NULL);
    
    begin = ft_lstnew(f(lst->content));
    if (begin == NULL)
    {
        ft_lstclear(&begin, del);
        return (NULL);
    }
    lst = lst->next;
    elem = begin;
    while (lst)
    {
        elem->next = ft_lstnew(f(lst->content));
        if (elem->next == NULL)
        {
            ft_lstclear(&begin, del);
            return (NULL);
        }
        lst = lst->next;
        elem = elem->next;
    }
    return (begin);
}