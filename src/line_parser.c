/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:57:12 by ericlazo          #+#    #+#             */
/*   Updated: 2020/10/05 16:42:53 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


	// Is there a more efficient way of doing strcmp...
	// Check freeing, especially in error conditions.


#include "cub3d.h"

int     ft_expected_size(char **tab, int e)
{
	int		i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		++i;
	return (i == e ? 1 : 0);
}

int		ft_parse_res(char **tab, t_input *file)
{
	int		x;
	int		y;

	if (!ft_expected_size(tab, 3))
		return (ft_error_msg("res wrong tab size\n", 0));
	if (file->res.x > 0 || file->res.y > 0)
		return (ft_error_msg("res already inited\n", 0));
	x = ft_atoi(tab[1]);	
	y = ft_atoi(tab[2]);
	if (x <= 0 || y <= 0)	// i think cor conditions...
		return (ft_error_msg("res inputes negative\n", 0));
	file->res.x = x;
	file->res.y = y;
	return (1);
}

int		ft_parse_path(char **tab, char **path)
{
	if (!ft_expected_size(tab, 2))
		return (ft_error_msg("path wrong tab size\n", 0));
	if (*path)
		return (ft_error_msg("already a path\n", 0));
	if (!ft_check_str_end(tab[1], ".xpm"))
		return (ft_error_msg("not an .xpm file\n", 0));
	if (!(*path = ft_strdup(tab[1])))
		return (ft_error_msg("path dup failed\n", 0));
	return (1);
}

int		ft_parse_colors(char **tab, int *color)
{
	char	**nums;
	int		r;
	int		g;
	int		b;

	if (!ft_expected_size(tab, 2))
		return (ft_error_msg("floor or celing wrong tab size\n", 0));
	nums = ft_split(tab[1], ",");
	if (!ft_expected_size(nums, 3))
		return (ft_error_msg("color wrong tab size\n", 0));
	if (*color >= 0)
		return (ft_error_msg("already colors\n", 0));
	if (!ft_str_isdigit(nums[0]) || !ft_str_isdigit(nums[1]) \
		|| !ft_str_isdigit(nums[2]))
		return (ft_error_msg("color in file isn't a number\n", 0));
	r = ft_atoi(nums[0]);
	g = ft_atoi(nums[1]);
	b = ft_atoi(nums[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (ft_error_msg("color inputs not btw 0 and 255 inclusive\n", 0));
	*color = ft_rgb_to_int(r, g, b, 0);
	ft_free_strtab(nums);
	return (1);
}

	// can i get rid of ternairs ?

	// i hope my !(*bol ...) works...

int		ft_parse_line(t_input *file, char *line, int *bol)
{
	char	**tab;
	int		ret;

	if (!line)	// or file or bol ???
		return (ft_error_msg("no line\n", 0));
	ret = 0;
	tab = ft_split(line, " ");	// secure ???
	if (!(*bol & RES) && ft_strcmp(tab[0], "R") == 0)
		ret = (ft_parse_res(tab, file) > 0 ? 1 : 0);
	else if (!(*bol & PNO) && ft_strcmp(tab[0], "NO") == 0)
		ret = (ft_parse_path(tab, &file->no_path) > 0 ? 2 : 0);
	else if (!(*bol & PSO) && ft_strcmp(tab[0], "SO") == 0)
		ret = (ft_parse_path(tab, &file->so_path) > 0 ? 3 : 0);
	else if (!(*bol & PWE) && ft_strcmp(tab[0], "WE") == 0)
		ret = (ft_parse_path(tab, &file->we_path) > 0 ? 4 : 0);
	else if (!(*bol & PEA) && ft_strcmp(tab[0], "EA") == 0)
		ret = (ft_parse_path(tab, &file->ea_path) > 0 ? 5 : 0);
	else if (!(*bol & PS1) && ft_strcmp(tab[0], "S") == 0)
		ret = (ft_parse_path(tab, &file->sprite_path) > 0 ? 6 : 0);
	else if (!(*bol & CFL) && ft_strcmp(tab[0], "F") == 0)
		ret = (ft_parse_colors(tab, &file->f) > 0 ? 7 : 0);
	else if (!(*bol & CCE) && ft_strcmp(tab[0], "C") == 0)
		ret = (ft_parse_colors(tab, &file->c) > 0 ? 8 : 0);
	ft_free_strtab(tab);
	*bol |= (1 << ret);
//	printf("parse line ret: %d\n", ret);
	return (ret);
}
