/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:59:49 by dmontana          #+#    #+#             */
/*   Updated: 2025/09/28 16:59:52 by dmontana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Frees all nodes of a stack and sets the pointer to NULL
**
** Parameters:
** lst: pointer to the stack pointer
**
** Behavior:
** - Checks if the pointer itself or the stack is NULL.
**   If yes, exits immediately, nothing to free.
** - Iterates over each node in the stack:
**   - Saves the pointer to the next node to not lose the rest of the stack.
**   - Frees the current node, deallocating its memory.
**   - Advances to the next node.
** - After freeing all nodes, sets the original pointer to NULL to:
**   - Prevent dangling pointer access.
**   - Improve safety and readability.
**
** Notes:
** - Setting the pointer to NULL is good practice because it signals
**   that the stack is empty and prevents accidental use of freed memory.
** - This function handles an empty stack or a NULL pointer safely.
*/
void	ft_free(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst || !*lst)
		return ;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}

	*lst = NULL;
}
