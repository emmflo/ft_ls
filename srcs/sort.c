#include "ft_ls.h"

int		ft_lstlen(t_list *list)
{
	int	i;

	i = 0;
	while (list != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
}

t_list	*ft_merge(t_list *a, t_list *b, int cmp(void *, void *))
{
	t_list	*r;
	t_list	*result;

	result = NULL;
	while (a != NULL && b != NULL)
	{
		if (cmp(a->content, b->content) <= 0)
		{
			if (result == NULL)
			{
				result = a;
				r = result;
			}
			else
			{
				result->next = a;
				result = result->next;
			}
			a = a->next;
		}
		else
		{
			if (result == NULL)
			{
				result = b;
				r = result;
			}
			else
			{
				result->next = b;
				result = result->next;
			}
			b = b->next;
		}
	}
	if (a != NULL)
		result->next = a;
	else if (b != NULL)
		result->next = b;
	return (r);
}

t_list	*ft_merge_sort(t_list *list, int cmp(void *, void *))
{
	t_list	*left;
	t_list	*right;
	t_list	*ptr;
	int		i;
	int		len;

	if (list == NULL || list->next == NULL)
		return (list);
	i = 0;
	ptr = list;
	len = ft_lstlen(list);
	while (i < (len / 2) - 1)
	{
		ptr = ptr->next;
		i++;
	}
	right = ptr->next;
	ptr->next = NULL;
	left = list;
	left = ft_merge_sort(left, cmp);
	right = ft_merge_sort(right, cmp);
	return (ft_merge(left, right, cmp));
}
