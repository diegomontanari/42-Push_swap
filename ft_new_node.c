// I'm simply creating the node for the value
t_stack *ft_new_node(int value)
{
    t_list *new;

    new = malloc(sizeof(t_list));
    if (!new)
        ft_error();
    new->nbr = value;
    new->next = NULL;
    return (new);
}