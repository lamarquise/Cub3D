

	// Is there a more efficient way of doing strcmp...
	// Check freeing, especially in error conditions.



#include "cub3d.h"


int		ft_parse_res(char **tab, t_input *file)
{
	int		x;
	int		y;

	if (!ft_expected_size(tab, 3))
		return (ft_error_msg("res wrong tab size\n"));

//	printf("file->res_x: %d\n", file->res_x);
	if (file->res_x > 0 || file->res_y > 0)
		return (ft_error_msg("res already inited\n"));
	x = ft_atoi(tab[1]);	
	y = ft_atoi(tab[2]);
	if (x <= 0 || y <= 0)	// i think cor conditions...
		return (ft_error_msg("res inputes negative\n"));
	file->res_x = x;
	file->res_y = y;
	return (1);
}

int		ft_parse_path(char **tab, char *path)
{
	if (!ft_expected_size(tab, 2))
		return (ft_error_msg("path wrong tab size\n"));
	if (path)
		return (ft_error_msg("already a path\n"));
	
	// can I check the path here ???
	// should i go directly from a path to an image or whatever???

	// for now:	
	if (!(path = ft_strdup(tab[1])))
		return (ft_error_msg("path dup failed\n"));
	return (1);
}

int		ft_parse_colors(char **tab, t_color *color)
{
	char	**nums;
	int		r;
	int		g;
	int		b;

	if (!ft_expected_size(tab, 2))
		return (ft_error_msg("floor or celing wrong tab size\n"));
	nums = ft_split(tab[1], ",");
	if (!ft_expected_size(nums, 3))
		return (ft_error_msg("color wrong tab size\n"));

	// all colores must be btw 0 and 255

	if (color->r > 0 || color->g > 0 || color->b > 0)
		return (ft_error_msg("already colors\n"));
	r = ft_atoi(nums[0]);
	g = ft_atoi(nums[0]);
	b = ft_atoi(nums[0]);
	if (r < 1 || g < 1 || b < 1)
		return (ft_error_msg("color inputs negative\n"));
	color->r = r;
	color->g = g;
	color->b = b;
	ft_free_strtab(nums);
	return (1);
}

int		ft_parse_line(t_input *file, char *line)
{
	char	**tab;
	int		ret;

	if (!line)
		return (ft_error_msg("no line\n"));
//		return (0);
	ret = 0;
	tab = ft_split(line, " ");
	if (ft_strcmp(tab[0], "R") == 0)		// more efficient than 100 cmps ?
		ret = ft_parse_res(tab, file);		// not sure what...
	else if (ft_strcmp(tab[0], "NO") == 0)
		ret = ft_parse_path(tab, file->no_tex);
	else if (ft_strcmp(tab[0], "SO") == 0)
		ret = ft_parse_path(tab, file->so_tex);
	else if (ft_strcmp(tab[0], "WE") == 0)
		ret = ft_parse_path(tab, file->we_tex);
	else if (ft_strcmp(tab[0], "EA") == 0)
		ret = ft_parse_path(tab, file->ea_tex);
	else if (ft_strcmp(tab[0], "S") == 0)
		ret = ft_parse_path(tab, file->sprite_tex);
	else if (ft_strcmp(tab[0], "F") == 0)
		ret = ft_parse_colors(tab, file->f);
	else if (ft_strcmp(tab[0], "C") == 0)
		ret = ft_parse_colors(tab, file->c);
	ft_free_strtab(tab);
//	printf("parse line ret: %d\n", ret);
	return (ret);
}
