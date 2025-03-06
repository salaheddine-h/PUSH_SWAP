#include "libft.h"

t_list  *ft_lstnew(int value)
{
  t_list  *result;

  result = (t_list *)malloc(sizeof(t_list));
  if(!result)
    return(NULL);
  result->value = value;
  result->next = NULL;
  return(result);
}
