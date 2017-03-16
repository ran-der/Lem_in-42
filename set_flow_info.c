
#include "lem_in.h"

int				sum_plist(t_path *plist)
{
	int			ret;
	t_path		*tmp;
	
	tmp = plist;
	ret = 0;
	while (tmp != NULL)
	{
		ret += (tmp->len - 2);
		tmp = tmp->next;
	}
	return (ret);
}

void			set_flow_info(t_map *map, t_path *plist)
{
	int			turns;
	t_path		*tmp;
	
	turns = (sum_plist(plist) + map->n) / plist_len(plist);
	tmp = plist;
	while (tmp != NULL)
	{
		tmp->pass = turns - (tmp->len - 2);
		tmp = tmp->next;
	}
}
