#include "push_swap.h"
/*  ft_freestr.c                                                              */
/*                                                                            */
/*  Questa funzione libera un array di stringhe (char **), come quello         */
/*  restituito da ft_split.                                                    */
/*                                                                            */
/*  Perché serve:                                                             */
/*  - Quando si usa ft_split, viene allocato un array di puntatori a char,     */
/*    ciascuno dei quali punta a una stringa allocata dinamicamente.           */
/*  - Bisogna liberare ogni stringa e poi l'array stesso per evitare memory leak*/
/*                                                                            */
/*  Perché non si possono usare le funzioni della libft:                       */
/*  - Le funzioni come ft_lstclear, ft_lstdelone, ecc. sono pensate per        */
/*    strutture dati di tipo lista collegata (t_list), non per array di stringhe*/
/*  - Un array di stringhe non è una lista collegata, ma un semplice array     */
/*    terminato da NULL                                                        */

#include <stdlib.h>

void	ft_freestr(char **lst)
{
	int i = 0;
	if (!lst)
		return;
	while (lst[i])
	{
		free(lst[i]);
		i++;
	}
}
