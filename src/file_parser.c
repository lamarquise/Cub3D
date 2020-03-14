



	// All the stuff before the map can be in any order ...





#include "cub3d.h"

	// how do i want to store file contents??? as a **str ???
	// directly in the map struct ???

	// how do i store the actual map ????
	// linked list ???	seems good to me...


// OK here's what i want:
	// parse file into a linked list, each line is an elem
	// check each elem/line storing in the map struct and makeing sure valid
		// and not redundant...
	// hold onto lines of cart and put them in seperate pointer ?
	// test them for correct walls and stuff...


int		ft_expected_size(char **tab, int e)
{
	int		i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		++i;
	return (i == e ? 1 : 0);
}

int		ft_retrieve_file_contents(int fd, t_nlist **f_lines)
{
	int		ret;
	char	*s;
	char	*line;

	s = ft_strnew(1);	// s needs to be inited, i wonder if i can make that
	line = NULL;		// not the case, cuz i didn't remember...
	while ((ret = gnl(&line, &s, 42, fd)) > 0)
	{
		if (!ft_nlstadd_back(f_lines, ft_nlstnew(ft_strdup(line), 0)))
			return (0);	// also free shit, like everything	// scott_free ??
//		free(line);
		ft_scott_free(&line);	// worth it ???
	}
	return (1);
}



int		ft_parse_file(int fd, t_map *file)
{
	static char	*rets[] = {"R", "NO", "SO", "WE", "EA", "S", "F", "C"};
	int			pos;
	size_t		l;

	t_nlist		*f_lines;
	size_t		i;
	char		**tab;
	char		**colors;

//	printf("porse file test 1\n");

	i = 0;
	l = 0;
	pos = 0;
	tab = NULL;
	colors = NULL;
	f_lines = NULL;
	
	ft_retrieve_file_contents(fd, &f_lines);

	// now need to check the lines, make sure they're good
	// for now assume they good.

	// tab size after split:
	// 3, 2, 2, 2, 2, 0, 2, 2, 2, 0, map

//	printf("porse file test 2\n");


	// could use a bol insead of else ret every time ... ?

	tab = ft_split(ft_read_nlst_n(f_lines, l++), " ");
	if (!ft_expected_size(tab, 3))
		return (-1);	// and free shit like the tab
	if (ft_strcmp(tab[0], rets[pos++]) == 0)	// Resolution
	{
		// somehow check that tab[1] and [2] are only numbers, and pos
		file->res_x = ft_atoi(tab[1]);
		file->res_y = ft_atoi(tab[2]);
	}
	else
		return (-2);		// better way of doing this i think...
	ft_free_strtab(tab);	// make sure this shit actually works...
//	tab = NULL;
//	printf("tab[0]: |%s|, line: |%s|\n",tab[0],ft_read_nlst_n(f_lines, l));

	tab = ft_split(ft_read_nlst_n(f_lines, l++), " ");
	if (!ft_expected_size(tab, 2))
		return (-3);
	if (ft_strcmp(tab[0], rets[pos++]) == 0)	// North texture
	{
		file->no_tex = ft_strdup(tab[1]);	// or somtin loike dat
	}
	else
		return (-4);
	ft_free_strtab(tab);

	tab = ft_split(ft_read_nlst_n(f_lines, l++), " ");
	if (!ft_expected_size(tab, 2))
		return (-5);
	if (ft_strcmp(tab[0], rets[pos++]) == 0)	// South texture
	{
		file->so_tex = ft_strdup(tab[1]);
	}
	else
		return (-6);
	ft_free_strtab(tab);

	tab = ft_split(ft_read_nlst_n(f_lines, l++), " ");
	if (!ft_expected_size(tab, 2))
		return (-7);
	if (ft_strcmp(tab[0], rets[pos++]) == 0)	// West texture
	{
		file->we_tex = ft_strdup(tab[1]);
	}
	else
		return (-8);
	ft_free_strtab(tab);

	tab = ft_split(ft_read_nlst_n(f_lines, l++), " ");
	if (!ft_expected_size(tab, 2))
		return (-9);
	if (ft_strcmp(tab[0], rets[pos++]) == 0)	// East texture
	{
		file->ea_tex = ft_strdup(tab[1]);
	}
	else
		return (-10);
	ft_free_strtab(tab);

	// some tab thing about empty line...
	++l;	// good enough for now ???

	tab = ft_split(ft_read_nlst_n(f_lines, l++), " ");
	if (!ft_expected_size(tab, 2))
		return (-11);
	if (ft_strcmp(tab[0], rets[pos++]) == 0)	// Sprite texture
	{
		file->sprit_tex = ft_strdup(tab[1]);
	}
	else
		return (-12);
	ft_free_strtab(tab);

//	printf("before floor\n");

	tab = ft_split(ft_read_nlst_n(f_lines, l++), " ");
	if (!ft_expected_size(tab, 2))
		return (-13);
	if (ft_strcmp(tab[0], rets[pos++]) == 0)	// Floor color
	{
		colors = ft_split(tab[1], ",");
		file->f_r = ft_atoi(colors[0]);
		file->f_g = ft_atoi(colors[1]);
		file->f_b = ft_atoi(colors[2]);
		ft_free_strtab(colors);
	}
	else
		return (-14);
	ft_free_strtab(tab);

	tab = ft_split(ft_read_nlst_n(f_lines, l++), " ");
	if (!ft_expected_size(tab, 2))
		return (-15);
	if (ft_strcmp(tab[0], rets[pos++]) == 0)	// Cealing color
	{
		colors = ft_split(tab[1], ",");
		file->c_r = ft_atoi(colors[0]);
		file->c_g = ft_atoi(colors[1]);
		file->c_b = ft_atoi(colors[2]);
		ft_free_strtab(colors);
	}
	else
		return (-16);
	ft_free_strtab(tab);


//	printf("porse file test 3 end of pre map\n");
	

	++l;

	// empty line
	
	// 10 lines for pre map, empty lines included
	// so while l-- nlstdel_one_n(0) ??? then left with map...

//	printf("l: %zu\n", l);

	while (l-- > 0)		// I mean it should work...
	{
		ft_nlstdel_n_one(&f_lines, 0);
	}

//	printf("the map:\n");
	
//	ft_print_nlst(f_lines);

	// then map... f_lines is just map....


//	printf("are we here yet?\n");
	
	t_floorplan *level;
	int		wid;
	int		hei;
	int		n;
	int		c;
	t_nlist	*tmp;

	if (!(level = (t_floorplan*)malloc(sizeof(t_floorplan))))
		return (-17);	// free shit too...	if create vars in prev fun, can
					// just ret and free in parent func

	wid = 0;
	hei = 0;
	n = 0;
	tmp = f_lines;

	while (tmp)
	{
		c = 0;
		while (((char*)tmp->content)[c])
		{
			if ((n = ft_findchar("NSEW", ((char*)tmp->content)[c])) != -1)
			{
				file->player->s_dir = ((char*)tmp->content)[c];
				file->player->x = c;
				file->player->y = hei;
//				((char*)tmp->content)[c] = '0';
			}
			++c;
		}
		if (c > wid)
			wid = c;
//		if ((n = ft_strlen((char*)tmp->content)) > wid)
//			wid = n;
		++hei;
		tmp = tmp->next;
	}
	level->x_boxes = wid;
	level->y_boxes = hei;
	level->floor = f_lines;

	printf("wid: %d, hei: %d\n", wid, hei);

//	printf("the map\n");

//	ft_print_nlst(f_lines);


	file->level = level;


//	printf("porse file post map and end\n");


	// need to gather x and y coords for person, 


	// start by adding spaces...


	// now floor plan has been made
	// check to make sure surounded by 1's
	// no idea how to do that ????

	return (1);
}







