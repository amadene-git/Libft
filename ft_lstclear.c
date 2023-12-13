#include "libft.h"

void    ft_lstclear_rec(t_list *lst, void (*del)(void*))
{
    if (lst == NULL || del == NULL)
        return;
    if (lst->next)
        ft_lstclear_rec(lst->next, del);
    del(lst->content);
    free(lst);
}


void    ft_lstclear(t_list **lst, void (*del)(void*))
{
    ft_lstclear_rec(*lst, del);
    *lst = NULL;
}