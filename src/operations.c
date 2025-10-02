/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:02:40 by dmontana          #+#    #+#             */
/*   Updated: 2025/09/28 17:02:42 by dmontana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// il primo if è sempre per verificare se la lista è vuota o ha un solo elemento
// se la lista è vuota o ha un solo elemento, non fa nulla (per evitare crash)

// ra (rotate a) : shift up all elements of stack a by 1. 
// The first element becomes the last one.

/*
	tmp = *a; // salva la testa della lista in temp
	*a = ft_stack_last(*a); porta il puntatore all'ultimo elemento della lista
	(*a)->next = tmp; imposta il next dell'ultimo elemento della lista a tmp 
	(che sarebbe la testa) (per un istante la lista è “circolare”, 
	ma solo momentaneamente durante la rotazione)

	Sintesi in parole
	tmp = old first node.
	*a = last node → collegato a tmp.
	*a = second node → nuovo primo.
	tmp->next = NULL → old first node diventa ultimo, lista non ciclica.
*/

// if (j == 0) // Questo j non centra nulla con quello di ft_process, vedrai

void	ft_ra(t_stack **a, int j)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = ft_stack_last(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "ra\n", 3);
}

// sa (swap a) : swap the first 2 elements at the top of stack a. 
// Do nothing if there is only one or no elements).

/*
	*a = (*a)->next; // Head diventa il secondo elemento
	tmp->next = (*a)->next; // il next del primo elemento diventa 
	il terzo elemento (intelligentissimo!)
	(*a)->next = tmp; // il secondo elemento diventa il primo elemento
*/
void	ft_sa(t_stack **a, int j)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (j == 0)
		write(1, "sa\n", 3);
}

// pa (push a) : take the first element at the top of b and 
// put it at the top of a. Do nothing if b is empty.

/*
	tmp = *a; a breve modificheremo la testa di a, 
	          ma ci serve quindi la salvo in tmp
	*a = *b; la testa di a diventa la testa di b
	*b = (*b)->next; la testa di b diventa il secondo elemento di b
	                 (creiamo "spazio" per la testa di a)
	(*a)->next = tmp; il next della testa di a diventa
	                  la testa di a (ovvero la nuova testa di a)
*/
void	ft_pa(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	if (j == 0)
		write(1, "pa\n", 3);
}

// rra (reverse rotate a) : shift down all elements of stack a by 1. 
// The last element becomes the first one.
void	ft_rra(t_stack **a, int j)
{
	t_stack	*tmp;
	int		i;

	if (!*a || !(*a)->next)
		return ;
	i = 0;
	tmp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 0)
		write(1, "rra\n", 4);
}

// ss : sa and sb at the same time.
void	ft_ss(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (j == 0)
		write(1, "ss\n", 3);
}
