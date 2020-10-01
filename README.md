
# Cub3D

Cub3D is a full and self contained program, it is set up to work on MacOS
only at the moment.


The Makefile recompiles the libmlx and the libft as needed.

Currently using the non dynamic version of the mlx because the dynamic
version fucked things up for an unknown reason.


Have a list of the libft functions used in this project

error msg
strnew
nlist stuff
findchar


Wall Textures:
North is different colored stone wall
South is mossy gray stone wall
West is grey stone bricks
East is red bricks




Explain the structures, like what contains what...

### Structures used in this project

#### T Imge
Stores a void pointer to the img, an int pointer to the img data, an int for each
the width, height and last pixel of the image.

#### T Wind
Stores a void pointer to the window, an int for the width and the height, and a
string for the name.

#### T Lmlx
Stores a void pointer, an in for the bpp, s l and endian, all variables necessary
to store when using the mlx library.
Instance exists in T Game, is initialized when Jeu is initialized by ft init mlx
which is called by init game, which is called in main.

#### T Player
Stores a double for each the player x and y coordinates, and for the player x and
y direction vector, a char for the starting direction (N,S,E,W), an int for the
life. Ultimately there will be a good bit more in here I expect.

#### T Sprite
Empty for now, eventually will store everything necessary to make the sprites NPCs.

#### T Input
Stores the information passed by the level file given as an argument. An in for the
x and y resolutions, strings for the north, south, east and west texture paths. A
string for the sprite path (eventually multiple i think). An in for the floor and
ceiling colors (already converted from rgb). T Imge's for the n,s,e,w and sprite
tesxtures.
I may ultimately use an indexed linked list for the sprite textures.
The instance of input i use is called file, it is created in main, initialized to
null by ft init input called in main, and stored in Jeu in main. It is populated
by the file parser.

#### T Settings
Stores the in game settings, things the player can modify (or not?). An int
acting as a bool, 0 or 1 is the minimap to be displayed. Could store all in a
single int and do bitwise operations...

#### T Texture
Stores a void pointer to the path and another to the img (not the imge tho...?).
I'm not sure i use this structure at any point...

#### T Game
The largest structure, contains everything necessary to run the game.
Stores a T Input file, a table of strings floor, an int for the x and y boxes as
well as the last box. A T Lmlx mlx, a T Wind win, a T Imge minimap and fpv (also hud
but getting rid of that one i think...). An int bol (bitwise shit to make sure the
argument file is complete), a T nList tex list for the textures (again, do i use this?),
a T Player me, a T Settings set, a double plane x and y (for raycasting i think).
The instance of T Game I use is called Jeu. Jeu is created in main, it is initialized
to mostly null by ft init game called in main. It is populated pgrogressively before
the game engine function is called in main.


### Source Files

#### Main
Handles the arguments and opening files, then delegates first to initialization,
then parsing, then finally the game engine (which does window management within it).


#### Parse Files
Highest level parsing file, handles the .cub files

#### Parse Lines
Handles the parsing for individual lines, called from Parse Files.



#### Creat MLX Entities
Handles the allocation and correct assignment of variables for mlx windows,
images, all that stuff


#### Math
Handles changing coordinate systems to be pixel rather than grid position, rgb shit...


#### Quit
Handles quiting the MLX windows and freeing all that shit.
Also have it manage other free shit ?


#### Game Engine
Ok so this handles the creation and recreation of the images that will appear on the
window, it also puts them there.
This includes the minimap and the fpv (first person view)
It also deals with the MLX looping

So far we have a general function, ft game engine, that does all the mlx loop stuff,
and calls for the generation of new FPV and minimap images to be added to the window.

##### Ft Prime Engine
The init function for all the game engine stuff, it is called from
the main (i think that will make it more efficient? not called each mlx loop, but i
have no idea how the mlx loop actually works anymore so...).

##### Ft Generate FPV
Calls the raycasting to populate the img and then puts it in the window.
I think that's the right stuff for it to do...

##### Ft Generate Minimap
Calls a as of yet nonexistent function to populate the minimap img and puts it in
the window. Called after FPV so is ontop of FVP, I hope.



#### Raycasting

##### Ft Draw Pix To Img
Generic draw pixel function.
Takes a pointer to an Imge, an int for the position to be drawn to, and an int for
the color. Checks if the img is good, and if the position is in the img.
Returns 1 on success and 0 on failure.

Doesn't actually use Ft Pixel Put from MLX, easier to write straight to img data.

##### Ft Draw Col To Img
Generic draw column of pixels to an image.
Takes a pointer to an Imge, an in for the starting and ending rows, and for the
column and the color.
Checks if the column can be drawn and if img is good. Loops though ft draw pix to img
calculating new positions based on the width of the img and the chosen column.
Returns 1 on success and 0 on failure.

##### Ft Raycasting

##### Ft Draw Pix To Imge
Given an image, a 1D position and a color will produce a pixel.

##### Ft Draw Col To Imge
Given an image, a start and end y, an x and a color will a produce a column of pixels.

#####


#### Game Engine.c

##### Ft Game Engine
Starts the game runing process by calling the draw to screen functions and containing
the mlx and hooks loops.

##### Ft Draw Images
Calls the correct and relevant functions to draw the right images depending on player
settings (like is the minimap on). Seperate from Ft Game Engine so can be called from
redraw function.

##### Ft Prime Engine
Called before Ft Game Engine in main, inits settings for the game engine given the
now parsed and valid input file. Also creates all the mlx assets, the window and
images given the input file parameters as well as generates the minimap image, so
none of these get needlessly repeated.

##### Ft Generate FPV
Calls the raycasting functions to create the First Person View image which it then
places in the window.

##### Ft Generate Minimap
Creates the minimap background image (without a player) that will be used through
out the level. Completely fills the image with an opace tint free color, then adds
the map grid sized to fit any map to any resolution, and centers it.

##### Ft Generate Player
Creates populates an image the size of the minimap grid, filled entirely with
seethrough colorless pixels except in the exact location of the player at any point
in time.
Eventually will also have a sweeping Field Of View in yellow to indicate what the
player can see.

##### Ft Display Minimap
Adds the minimap image to the window then calls Ft Generate Player and adds that
image to the window.
Display Minimap is only called if the player requests the minimap to be displayed
meaning no computations, save the initial creation ones, are done once the game is
in progress, which is more efficient.




#### Minimap.c
These functions exist to help create the minimap.

##### Ft Sizing Minimap Imge
Calculates the size of the minimap grid depending on the resolution and the map
proportions.

##### Ft Draw Box
Draws a single filled in squar of pixels at a specified location in an image. The
location is specified with a 1D system not a 2D coordinate system, this fits right
into the way pixels are addressed by the images.

##### Ft Fill Imge
Fills every pixel of an imge with a specified color, by iterating through the
img data table.

##### Ft Draw Grid
Not Generic.
Based on the layout of the map, draws a box for each, of different color depending
on the contents of the cell. Takes the top left position of the minimap grid in the
imge as a parameter, starts there.

##### Ft Draw Crosshair
Not Currently in use, but could prove useful

##### Ft Draw P (player) Box
Defunct for now, might use later to scale the player square for minimap display.


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




