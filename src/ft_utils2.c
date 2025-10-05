/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:01:53 by dmontana          #+#    #+#             */
/*   Updated: 2025/09/28 17:01:59 by dmontana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// This function checks the index of a number
// 	 in the stack.
int	ft_find_index(t_stack *a, int nbr)
{
	int		i;

	i = 0;
	while (a->nbr != nbr)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}

// This function finds the correct place of the number in stack_b.
// In other words, it check what index number nbr_push will get 
// after it is being pushed to the stack_b.

// if (nbr_push > stack_b->nbr && nbr_push < ft_stack_last(stack_b)->nbr)
//    i = 0;
// Se nbr_push è maggiore del primo elemento di stack_b e minore dell’ultimo elemento di stack_b, allora lo posso inserire in cima, cioè all’indice 0
// Sembra controintuitivo, ma ricorda che devo sortare cose che non sono ruotate necessariamente correttamente, ma che hanno i numeri ordinati circolarmente

// else if (nbr_push > ft_max(stack_b) || nbr_push < ft_min(stack_b))
//    i = ft_find_index(stack_b, ft_max(stack_b));
// Se nbr_push è più grande del massimo o più piccolo del minimo di stack_b, allora:
// Non può essere inserito “in mezzo” a nessuna coppia di nodi
// Va dopo il massimo, che è il punto di rotazione naturale

// else
// Se nbr_push non è fuori dai limiti, cerchi la coppia di nodi tra cui può essere inserito:
// Continui a scorrere finche non trovi: stack_b->nbr > nbr_push && tmp->nbr < nbr_push
// Cioè: nbr_push è tra due nodi decrescenti
// Il ciclo si ferma e i ti dice quante rotazioni servono per portare nbr_push nella posizione giusta.
int	ft_find_place_b(t_stack *stack_b, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push > stack_b->nbr && nbr_push < ft_stack_last(stack_b)->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_b) || nbr_push < ft_min(stack_b))
		i = ft_find_index(stack_b, ft_max(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->nbr < nbr_push || tmp->nbr > nbr_push)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

// This function finds the correct place of the number in stack_a.
// In other words, it check what index number nbr_push will get 
// after it is being pushed to the stack_a.

// This function finds the correct place of the number in stack_a.
// In other words, it checks what index number nbr_push will get 
// after it is being pushed to stack_a.

// if (nbr_push < stack_a->nbr && nbr_push > ft_stack_last(stack_a)->nbr)
//     i = 0;
// Se nbr_push è minore del primo elemento di stack_a e maggiore dell’ultimo,
// allora lo posso inserire in cima, cioè all’indice 0.
// Sembra controintuitivo, ma ricorda che lo stack può essere ruotato,
// quindi i numeri sono ordinati circolarmente e la testa non è necessariamente il minimo.

// else if (nbr_push > ft_max(stack_a) || nbr_push < ft_min(stack_a))
//     i = ft_find_index(stack_a, ft_min(stack_a));
// Se nbr_push è più grande del massimo o più piccolo del minimo di stack_a, allora:
// Non può essere inserito “in mezzo” a nessuna coppia di nodi
// Va prima del minimo, che è il punto di rotazione naturale per uno stack ordinato in senso crescente.

// else
// Se nbr_push non è fuori dai limiti, cerchi la coppia di nodi tra cui può essere inserito:
// Continui a scorrere finché non trovi: stack_a->nbr < nbr_push && tmp->nbr > nbr_push
// Cioè: nbr_push è tra due nodi crescenti
// Il ciclo si ferma e i ti dice quante rotazioni servono per portare nbr_push nella posizione giusta.
int ft_find_place_a(t_stack *stack_a, int nbr_push)
{
    int     i;
    t_stack *tmp;

    i = 1;
    if (nbr_push < stack_a->nbr && nbr_push > ft_stack_last(stack_a)->nbr)
        i = 0;
    else if (nbr_push > ft_max(stack
int	ft_find_place_a(t_stack *stack_a, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push < stack_a->nbr && nbr_push > ft_stack_last(stack_a)->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_a) || nbr_push < ft_min(stack_a))
		i = ft_find_index(stack_a, ft_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->nbr > nbr_push || tmp->nbr < nbr_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
