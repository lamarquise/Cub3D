# Design Docs for the Libft


Update, sepreate into 2 categories, the funcs i made, complex med and simple
and the regular ones...



Makefile will need a rework eventually.


In total there are: 92 Functions.

The Libft is divided into two groups of functions, those that are extremely useful
and found commonly throughout my projects, and those that are far less common.

This Design Doc mimics the tree structure of the libft file, each function appears
here where it would in the actual file. Folowing the name of each function is a
short description of what it does and then a more technical description of how it
accomplishes that.

Rework split ?
Consider adding a list of just the names of all the functions, one for both groups

Any left in Cub3D ?


## Essencial Functions
39

### Complex Functions
4
##### StrJoin ✅
Joins 2 strings together into a larger string.
Takes 2 strings s1 and s2. Allocates memory for a new string, fills it,
returns a string or null if error.

##### FStrJoin ✅
Free Join, joins 2 strings together into a larger string, but makes sure
to free them both, error or not, can handle empty strings.
Takes 2 pointers to strings s1 and s2. Allocates memory for a new string,
uses fstrlen to count length of strings, fills the new string and frees
the old ones, returns a string or null if error.

##### Split ✅
Divides a string into 'words' spliting then using a set of char.
Takes 2 strings s and set. The number of words s can be divided into
according to set is counted and a pointer to strings is allocated with
that many slots. Then the length of each word is counted and allocated
to the next available slot in the table of strings, the slot is then
filled. Returns a table of strings or null if error.

##### GNL
Reads and returns one line of a file at a time.
Takes 2 pointers to strings l and s, and 2 ints b size and fd.
Returns 1 on line successfully returned, -1 if error and 0 if nothing
left to be read. (I think... Should test)



### Linked List Functions
13

#### T List Functions
T List Structure has a void pointer called content and a pointer to
the next link
##### LstNew
Creates a new T List containing argument passed.
Takes a void pointer to content, allocates a T List, inits it's
variables and returns the T List.

##### LstAdd Front
Adds a new T List to the begining of a T List linked list.
Takes a pointer to the pointer to the first elem of the T List linked
list, and the new T List elem, prepends the elem. Returns void.

##### LstAdd Back
Adds a new T List to the end of a T List linked list.
Takes a pointer to the pointer to the first elem of the T List linked
list, and the new T List elem, appends the elem. Returns void.

##### LstDelOne
Applies a Delete function to a single element of a T List linked list.
Takes a pointer to the element to be deleted, and a pointer to the del
function. Applies the del function, frees the pointer to the elem.
Returns void.

##### LstClear
Deletes an entire T List linked list.
Takes a pointer to the linked list, and a pointer to the del function.
Applies the del function to every element of the list and frees them,
finally frees the pointer to the linked list. Returns void.

##### LstIter
Applies a function to every element of a T List linked list.
Takes a pointer to the first elem of the T List linked list, and a
pointer to the function to be applied. Applies the function. Returns void.

##### LstLast
Iterates through a T List linked list until the last element is reached,
this element is returned.
Takes a pointer to the first elem of the list. Returns T List.

##### LstMap
Iterates through a T List linked list applying a function to the conents
and creating a new parallel linked list with the results.
Takes a pointer to the origional T List linked list, a pointer to the
function to be applied, and a pointer to a del function. For each elem of
the origional list a new corresponding elem is allocated and assigned the
results of the passed function, should that function fail, the del func
is applied instead. This function is recursive, the return is the new
T List elem that has been created in a particular iteration, until the
list is exhausted at which point it returns NULL.

##### LstSize
Counts the size of a T List linked list.
Takes a pointer to the first elem of a T List linked list, iterates
through it while counting, returns the result as an int.

##### Print Elem
Prints the conents of a T List elem.
Takes an pointer to a T List elem, prints with putstr and appends with
a \n. Returns void.

##### LstPrint
Prints the contents of all the elems of a T List linked list.
Takes a pointer to the first elem of a T List linked list, iterates
through while applying the Print Elem (as seen above) function.
Returns void.

##### LstGen
Creates a T List linked list out of a string and seperator character.
Easily used in conjunction with argv and argc, great for testing.
Takes a string and a char. Creates a table of strings from these
arguments using the Split function, then turns these strings into
T List elems with LstNew and links them together with LstAdd Front.
Returns a pointer to the new T List linked list's first element.

##### LstRev
Reverses the order of the elems of a T List linked list.
Takes a pointer to a T List linked list, iterates through the list
swaping elems around in such a way that none are lost. Returns void.


### Medium Functions
12

##### Memalloc ✅
Actually very useful. Quite similar to malloc only after allocating a given amount
of memory it fills it with \0s.
Takes a size t size. Malloces then fills, returns a void pointer to the allocated
memory space.

##### StrDup
Makes a copy of a string, handles the allocation.
Takes a string s1. Counts its size, allocates that much memory and fills it with
s1. Returns the new string or null if failure.

##### FStrDup ✅
Makes a copy of a string, handles the allocation.
Takes a string str. Unlike strdup, fstrdup makes sure str exists. Counts size of
str, allocates that much memory and fills it with str. Returns the new string or
null if failure or str does not exist.

##### NStrDup
Makes a copy of a string, handles the allocation.
Takes a pointer to a string cp, and a string og. Very similar to fstrdup but sends
an int back to confirm success or failure, used in those rare occations when the
string you want to copy could be null but that would not be a failure. Allocates
the memory for cp and fills it from og. Returns 1 if og is null, 0 if cp is null
or malloc failure, and 1 if normal success.

##### Free StrTab ✅
Frees a table of strings, the likes you might end up with from using split.
Takes a pointer to a string tab. Applies scott free to each string in the
table. Returns 0 if error or 1 if success.

##### Print StrTab ✅
Prints a table of strings, the likes you might end up with from using split.
Takes a pointer to a string tab. Prints each string folowed by a \n. Returns
1 if success or 0 if failure.

##### Fill With ✅
Creates a string of a specified length and fills it with a specified char.
Takes a char this and a size t len. Memallocs a string of size len, fills
it with this, returns the string or null if error.

##### Atoi ✅
Turns an string into an int.
Takes a string, ignores prefix whitespaces, understands + or - sign,
iterates through the digits adding their value to an int which is
multiplied by a factor of ten each time. Returns an int. Has the same
querks as the original atoi.

##### Latoi ✅
Turns a string into a long and counts the number of char necessary to
display that int.
Takes a string and a pointer to a long. The long will hold the final
result of the string to long translation. The return is an int which
represents the length of the number and sign (if relevant). Other
than these particularities it's algorythm is identical to that of the
regular atoi.

##### Itoa ✅
Turns an int into a string, the opposit of atoi.
Takes an int. The length necessary to hold the int is calculated
(including sign), a string of that size is allocated and then filled
back to front, cuting off the last digit of the int on each iteration.
Returns the string containing the number.

##### PosItoa ✅
Nearly identical to Itoa, except it only handle positive numbers in
order to handle the largest possible number, an unsigned long long.
Takes an unsigned long long, returns a string. The algorythm is nearly
identical to that of Itoa.

##### SubStr ✅
Copies the contents of a string from a given start point for a given
length.
Takes a string s, an unsigned int start and a size t len. A string of
len + 1 is allocated, it is filled with the contents of s starting from
start and for len char or until s is exhausted. Returns the new string
or null if error.



### Simple Functions
10
##### StrCmp ✅
Finds the first difference between 2 strings.
Takes 2 strings s1 and s2. Iterates through them simulatiously. Returns the ascii
difference between the first differing char or 0 if none found.

##### PutStr ✅
Writes a string to display.
Takes a string, writes 1 char at a time. Returns void.

##### PutNbr ✅
Writes an int to display.
Takes an int. recursively goes through the number dividing by
10 each time, printing the last digit (which ends up first cuz recursive).
Returns void.

##### Bzero ✅
Fills a designated memory slot with a specified number of \0s.
Takes a void pointer s and a size t n. Fills s with n \0s. Returns void.

##### FindChar ✅
Finds the position of the first instance of a char in a string.
Takes a string str and a char c. Iterates through str until c is found.
Returns the index of c or -1 if none is found.

##### Scott Free ✅
Clears the contents of a string from memory as well as the string variable
itself.
Takes a pointer to a string str and an int ret. If str exists, first use
bzero to clear the contents, carful to use fstrlen not strlen for the size
of str to be extra safe. Second we free str and set it to null. Finally we
return ret regardless of if str exists.

##### StrLen
Counts the length of a string.
Takes a string s. Iterates through it keeping count, returns a size t
represening the length.

##### FStrLen ✅
Counts the lenght of a string.
Takes a string s. Unlike the normal strlen, fstrlen checks if s exists
before attempting to iterate. Returns an int, the length or 0 even if null
is passed.

##### NStrLen
Counts the lenght of a string, and returns a given int if error.
Takes a string s and an int ret. Unlike the normal strlen, nstrlen checks
if s exists before attempting to iterate. Returns an int, the length or ret
if s is null.

##### Error Msg
Displays an error message and returns a specified int.
Takes a string str and an int ret. Putstr str, returns ret regardless of if
str was printed.



## Other Functions
53

#### Mem Functions
8

##### Calloc
Allocates a memory slot able to accomodate variables of different bit
sizes.
Takes 2 size ts count and size. Allocates a variable of count x size
bits, initiallizes all bits to 0. Returns a void pointer to the new
variable or null if error.

##### MemCpy
Copies n bytes of memory from a source to a destination variable.
Takes 2 void pointers and a size t. Does not allocate any memory itself.
Iterates through the source n times. Returns a void pointer to the destination.

##### MemCCpy
Copies n bytes of memory from a source to a destination variable but stops if
happens across a sepecified char..
Takes 2 void pointers, a size t and an int representing an ascii char. Does not
allocate any memory itself. Iterates through the source n times or until the
source is equal to the designated char.. Returns a void pointer to the position of
the designated char in the destination if one was coped, else returns null.

##### MemChr
Looks for a specified char in a string up to n bytes.
Takes a void pointer s, an int c for the char, and a size t n for the number of bytes.
Itertes through s at most n times looking for c. If c is found in s, a pointer to
that exact position is returned, else returns null.

##### MemCmp
Compares the contents of 2 void pointers returning the difference, positive or
negative.
Takes 2 void pointers s1 and s2, and a size t n. Iterates through s1 and s2 up to
n times, if a difference is found between the values of s1 and s2 at corresponding
indexes, the difference of their ascii values is returned, else returns 0.

##### MemSet
Actually could be useful. Sets a defined number of bytes of a variable to be a
specified value.
Takes a void pointer b, an int c defining the char to be used to set, and a size t
len indicating how many bytes. Iterates through b len times setting all its bytes
to the value of c. Returns a void pointer to b.

##### MemMove
Copes the memory from one variable to an other, respecting order.
Takes 2 void pointers dst and src, and a size t len. Iterates through src copying
len bytes to dst either from left to right or right to left depending on the
relative positions of src and dst. Returns dst, or null in the event of an error.

##### MemDel
Frees a chunk of memory.
Takes a void pointer to a pointer. Frees what is at the given address and sets it
to null, returns void.



#### Str Functions
23

##### StrStr
Finds the first occurence of a string in another string.
Takes 2 strings, haystack and needle. Iterates through haystack until all chars
of needle are found in a row. Returns a pointer to the begining of needle string
in haystack, or null if full needle not found.

##### StrNStr
Finds the first occurence within a given number of char of a string in another
string.
Takes 2 strings, haystack and needle, and a size t len. Iterates through haystack
until all chars of needle are found in a row, or len is reached. Returns a pointer
to the begining of needle string in haystack, or null if full needle not found.

##### StrCpy
Copies an entire string into another area of preallocated memory.
Takes 2 strings dst and src. Iterates fully through src cpying its contents into
dst, does not check if dst has enough space. Returns pointer to begining of dst.

##### StrNCpy
Copies a given amount of a string into another area of preallocated memory.
Takes 2 strings dst and src, and a size t len. Iterates through src until len
bytes have been reached or until the end of src cpying its contents into dst,
does not check if dst has enough space. Returns pointer to begining of dst.

##### StrLCpy
Copies a given amount of a string into another area of preallocated memory.
Takes 2 strings dst and src, and a size t dstsize. Iterates through src until
dstsize bytes have been reached or until the end of src cpying its contents
into dst, does not check if dst has enough space. Returns the number of bytes
copied into dst.

##### StrCat
Conactinates 2 strings (appends one to the other).
Takes 2 strings s1 and s2. Copies s2 to the end of s1, returns a pointer to
the begining of s1.

##### StrNCat
Conactinates a given number of bytes from one string to another (appends one
to the other).
Takes 2 strings s1 and s2, and a size t n. Copies n bytes of s2 to the end of
s1, returns a pointer to the begining of s1.

##### StrLCat
Conactinates a given number of bytes from one string to another if the destination
has enough room (appends one to the other).
Takes 2 strings dst and src, and a size t size. Copies size bytes of src to the
end of dst if dst can hold all of src. Returns the size of dst if success, or the
size of src if failure, or the size if it is negative.

##### StrChr
Finds the first instance of a char in a string.
Takes a string s and an int c. Iterates through s until c is found. Returns a
pointer to the position of c in s or null if none is found.

##### StrRChr
Finds the last instance of a char in a string.
Takes a string s and an int c. Iterates through s until c is found, starting from
the end. Returns a pointer to the position of c in s or null if none is found.

##### StrNCmp
Finds the first difference between 2 strings withing a given number of bytes.
Takes 2 strings s1 and s2, and a size t n. Iterates through them simulatiously
until n. Returns the ascii difference between the first differing char or 0 if
none found.

##### CStrJoin
Char Join, joins a char to a string and frees the string.
Takes a char c and a pointer to a string s2. Allocates memory for a new
string, uses fstrlen to count length of string, fills the new string and
frees the old one, returns a string or null if error.

##### StrTrim
Removes a specified set of chars from the begining and end of a string.
It trims the fat from the start and the end.
Takes 2 strings s1 and set (set is never checked...). Counts the lenght
of the string without the char set at the begining or end, allocates
that much memory and fills it. Returns the new string or null if error.

##### StrNew
Creates a new string filled with \0s.
Takes a size t size. Allocates a string of len size + 1, fills it with
\0s, returns the new string or null if error.

##### StrIter
Applies a function to each char of a string.
Takes a string s and a pointer to a function f. Iterates through s applying
f each time. Returns void.

##### StrIterI
Applies a function, that takes into account index, to each char of a string.
Takes a string s and a pointer to a function f. Iterates through s applying
f each time, but f takes the index of each char as a parameter. Returns void.

##### StrMap
Creates a new string by applying a function to each char of a string.
Takes a string s and a pointer to a function f. Allocates a new string the
the size of s, iterates through s applying f each time, the result is stored
in the new string. Returns a new string or null if error.

##### StrMapI
Creates a new string by applying a function, that takes into account index,
to each char of a string.
Takes a string s and a pointer to a function f. Allocates a new string the
the size of s, iterates through s applying f each time, but f takes the index
as a parameter, the result is stored in the new string. Returns a new string
or null if error.

##### StrEqu
Similar to strcmp, compares the contents of 2 strings at corresponding indexes.
Takes 2 strings s1 and s2, compares their contents much like strcmp, but
returns 1 if identical or 0 different.

##### StrNEqu
Similar to strcmp, compares the contents of 2 strings at corresponding indexes
up to a given number of chars.
Takes 2 strings s1 and s2, and a size t n. Compares their contents much like
strncmp, until n is reached. Returns 1 if identical or 0 different.

##### StrSwap
Swaps the addresses of 2 strings.
Takes 2 pointers to strings s1 and s2. S1 becomes s2, s2 becomes s1.
Returns void.

##### StrDel
Deletes a string variable from memory.
Takes a pointer to a string. Frees the contents of that string and sets
its address to null, returns void.

##### StrClr
Clears the contents of a string from memory.
Takes a string s. All the memory slots of s (until a \0) are set to \0.
Returns void.



#### Is Check Functions
9

##### IsAlpha
Checks if a char is an ascii letter.
Takes an int. Returns 1 if it is, 0 otherwise.

##### IsDigit
Checks if a char is an ascii number.
Takes an int. Returns 1 if it is, 0 otherwise.

##### StrIsDigit
Checks if all the char of a string are ascii digits.
Takes a string str, iterates through it. Returns 0 if no str or not digits
and 1 if all are digits.

##### IsAlNum
Checks if a char is an ascii letter or number.
Takes an int. Returns 1 if it is, 0 otherwise.

##### IsSpace
Checks if a char is an ascii space, 9 to 13 and 32.
Takes an int. Returns 1 if it is, 0 otherwise.

##### IsPrint
Checks if a char is an ascii printable character, between 32 and 126 inclusive.
Takes an int. Returns 1 if it is, 0 otherwise.

##### IsAscii
Checks if a char is an ascii character, between 0 and 127 inclusive.
Takes an int. Returns 1 if it is, 0 otherwise.

##### ToUpper
Makes lower case ascii letters into their corresponding uppercase letter.
Takes an int representing the ascii value, subtracts 32 if value represents
a lowercase letter, returns that int, modified or not.

##### ToLower
Makes uppercase ascii letters into their corresponding lowercase letter.
Takes an int representing the ascii value, adds 32 if value represents
an uppercase letter, returns that int, modified or not.


#### Put Functions
7

##### PutChar
Writes a single char to display.
Takes a char. Returns void.

##### PutEndl
Writes a string to display followed by a \n.
Takes a string, writes one char at a time. Returns void.

##### PutCharFD
Writes a single char to a specified output, could be 1 (display) could be
a random file.
Takes a char and an int for the fd. Returns void.

##### PutStrFD
Writes a string to a specified output, could be 1 (display) could be
a random file.
Takes a string and an int for the fd, writes one char at a time.
Returns void.

##### PutNbrFD
Writes an int to a specified output, could be 1 (display) could be
a random file.
Takes an int for the number and an int for the fd. recursively goes
through the number dividing by 10 each time, printing the last digit
(which ends up first cuz recursive). Returns void.

##### PutEndlFD
Writes a string followed by a \n to a specified output, could be 1 (display)
could be a random file.
Takes a string and an int for the fd, writes one char at a time. Returns void.

##### PutNbrNl
Writes a int to display followed by a \n (New Line).
Takes an int, returns void.




#### nList Functions
6
Serious rework needed on these ?
T NList Structures contain an int indicating the index, a void pointer
for the contents, and a pointer to the next element of the linked list.

##### nLstNew
Creates a new T NList elem.
Takes a void pointer to content and an int for the index. A T NList
elem is allocated and initiallized with the parameters passed. Returns
the new elem.

##### nLstAdd Front
Prepends a new T NList elem to a T NList linked list.
Takes a pointer to a T NList linked list and a pointer to a T NList
elem. The new elem is attached at the start of the linked list or
becomes the linked list if none existed. Returns 1 if success 0
otherwise.

##### nLstAdd Back
Appends a new T NList elem to a T NList linked list.
Takes a pointer to a T NList linked list and a pointer to a T NList
elem. The linked list is iterated upon until the end it reached at
which point the new elem is attached. Returns 1 if success 0 otherwise.

##### nLstDel All
Iterates through a T NList linked list freeing the all contents and the
elems themselves.
Takes a pointer to a T NList linked list, iterates through it. Returns
1 if success or nothing to be done, 0 otherwize.

##### nLstDel n One		// Not yet approved for use, untested
Deletes a single element of a T NList linked list as designated by its
index number.
Will fill in the algorythm once it is tested.

##### Read nLst n		// also untested
Returns the content of a particular element of a T NList linked list
as designated by its index number.
Will fill in the algorythm once it is tested.



