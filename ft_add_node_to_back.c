// list è una linked list.
// If list is empy, new nodes becomes the head.
// If not empty, ft_lstlast adds a node at the back of the list.

// t_list **list punta all'indirizzo della testa della lista (cioè la variabile head)
//    -> permette di modificare la testa della lista (es: aggiungere il primo nodo).
// t_list *list invece punta al primo nodo (head), quindi permette di scorrere la lista.
//    -> non puntando a un indirizzo, è una copia e non permette di modificare la variabile head originale.
//    -> tuttavia, tramite *list puoi modificare ogni nodo e i collegamenti tra i nodi.


void    ft_add_node_to_back(t_list **list, t_list *node_new)
{
	if (!list)
		return ;
	if (!*list)
		*list = node_new;
	else
		(ft_lstlast(*list))->next = node_new;
}