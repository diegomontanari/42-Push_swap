/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node_to_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:58:53 by dmontana          #+#    #+#             */
/*   Updated: 2025/09/28 16:58:55 by dmontana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// stack è una linked stack.
// If stack is empy, new nodes becomes the head.
// If not empty, ft_stack_last adds a node at the back of the stack.

// t_stack **stack punta all'indirizzo della testa della lista 
// (cioè la variabile head)
//    -> permette di modificare la testa della lista 
// (es: aggiungere il primo nodo).
// t_stack *stack invece punta al primo nodo (head), quindi permette di 
// scorrere la lista.
//    -> non puntando a un indirizzo, è una copia e non permette di modificare
//       la variabile head originale.
//    -> tuttavia, tramite *stack puoi modificare ogni nodo e i 
//       collegamenti tra i nodi.

void	ft_add_node_to_back(t_stack **stack, t_stack *node_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = node_new;
	else
		(ft_stack_last(*stack))->next = node_new;
}
