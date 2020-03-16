


Cub3D is a full and self contained program, it is set up to work on MacOS
only at the moment.


The Makefile recompiles the libmlx and the libft as needed.

Currently using the non dynamic version of the mlx because the dynamic
version fucked things up for an unknown reason.


Main.c:

Basic structure initialization,
does a few checks, is the file .cub terminated...
calls the file parser,
then the master game manager function
then terminates.


File Parser:

Reads the file with gnl
The first lines are checked and info converted and stored in t input struct
once all necessary info is stored, the remaining (the map) are stored in
a linked list, the dimetions are found, the map is checked, player start pos
and the likes are store in jeu var.



We rely very hevily on the libft, many new functions were added, like those
working on an nlist type structure.


Keyhooks.c

Directly lifted from Fractol and IMG creator, very little has changed.




