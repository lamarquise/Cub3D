

	// May need to double secure some things, make sure free if fails


#include "cub3d.h"


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

	// read file, parses pre map lines, takes map and puts it in a list
int		ft_get_file_contents(int fd, t_input *file, t_nlist **floor)
{
	int		i;
	int		ret;
	char	*s;		// if gnl fail does s get free'd ???
	char	*line;

	i = 0;
	s = ft_strnew(1);	// s needs to be inited, i wonder if i can make that
	line = NULL;		// not the case, cuz i didn't remember...
	while ((ret = gnl(&line, &s, 42, fd)) > 0)
	{
		if (ft_strlen(line) > 0)
		{
			if (i < 8)
			{
				if (!(ft_parse_line(file, line)))
					return (ft_error_msg("parse line failed\n"));
				++i;
			}
			else if (!ft_nlstadd_back(floor, ft_nlstnew(ft_strdup(line), 0)))
				return (0);	// also free shit, like everything
		}
		ft_scott_free(&line);	// worth it ???
	}
//	ft_print_nlst(*floor);
	return (1);
}

int		ft_check_map(t_game *jeu, t_nlist *floor)
{
	int			c;
	int			wid;
	int			hei;
	t_nlist		*tmp;

	if (!jeu)
		return (ft_error_msg("no floor or jeu\n"));		// do this everywhere ?????
	wid = 0;
	hei = 0;
	tmp = floor;

//	ft_print_nlst(floor);

	while (tmp)
	{
		c = 0;
		while (((char*)tmp->content)[c])
		{		// more efficeint way of doing this ????
			if ((ft_findchar("012 ", ((char*)tmp->content)[c])) == -1)
			{
				if ((ft_findchar("NSEW", ((char*)tmp->content)[c])) != -1)
				{
					jeu->me->s_dir = ((char*)tmp->content)[c];
					jeu->me->x = c; //* 10 + 5;
					jeu->me->y = hei; //* 10 + 5;	// cor cuz middle of box ?
					((char*)tmp->content)[c] = '0';
				}
				else
					return (-2);
			}
			++c;
		}
		if (c > wid)
			wid = c;
		++hei;
		tmp = tmp->next;
	}
//	printf("wid: %d, hei: %d\n", wid, hei);
	jeu->x_boxes = wid;
	jeu->y_boxes = hei;
	jeu->floor = floor;
	return (1);
}

								// send both jeu and file ???
int		ft_parse_file(int fd, t_game *jeu)
{
	t_nlist		*floor;
	t_player	*me;


	int		ret;	// tmp

	ret = 0;

	// free if error to be set up...

	floor = NULL;
	if (!(ft_get_file_contents(fd, jeu->file, &floor)))
		return (ft_error_msg("file reader failed\n"));
	if (!(me = malloc(sizeof(t_player))))
		return (0);
//	ft_print_nlst(floor);
	me->life = 100;
	jeu->me = me;	
	jeu->floor = floor;
	if ((ret = ft_check_map(jeu, floor)) < 1)
	{
		printf("map ret: %d\n", ret);
		return (ft_error_msg("map failed check\n"));
	}
	return (1);
}



	// check to make sure surounded by 1's
	// no idea how to do that ????

	// first and last line only spaces and 1s
	// mid lines start and end with 1s
	// if:
/*
	111 111	// if space in first line, check spot under and next to underfor 1
	1011101
	1111111

	11111
	10001
	1X001	// does this one
	 1001
	1X001	// and this one need to be 1s ????
	10001
	11111

	// space must be surrounded by spaces or 1s...


*/




