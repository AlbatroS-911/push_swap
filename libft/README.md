*This project has been created as part of the 42 curriculum by tokrabem*

# Libft
## Description
***Libft*** is a custom and reusable C library that  reimplements some functions included in standard C library, coupled with several functions related on these ones. This library is the first project of the 42 cursus that will be strongly useful for the future projects.

**Purpose:**
 - Recreate and reimplement essential C functions that have the same behaviour as the original ones without relying on standard library
 - Have a custom library for future 42 projects
 - Gain skills based on algorithms, string manipulation and memory management
 - Share knowledge and insights thank to peer-learning

The main content of ***Libft*** (all mandatory) are:

 - **Libc functions**: reimplemention of a set of functions from the libc
 - **Additional functions**: a set of functions that not included in libc 
 - **Linked list** : a set of functions about memory and string manipulation

## INSTRUCTIONS
 ### Clone the repository:

```c

git clone git@vogsphere.42antananarivo.mg:vogsphere/intra-uuid-aa7d6bae-45e9-4aac-839d-be3d05cec681-7234615-tokrabem

```
### Compilation

  

To compile the library, use the provided Makefile:
```bash

# Compile the library (creates libft.a)
make

# Clean object files
make  clean

# Clean everything (object files + libft.a)
make  fclean

# Recompile everything
make  re

```
### Execution
 - Include the library in your project
 ```#include "libft.h"```
 - Compile your program alongside the library in ```bash``` using this command
 ```cc your_program.c libft.a -o your_program```

## RESOURCES

### About official resources
 - Official documentation of the libc functions ```man <function>``` that describes the behavior of all the functions
 - Some articles and the best friend youtube.com who helped me a lot about learning something new
 - Peer-learning system of the 42 School based on exchanges, contribution and learning from projects

### About AI
What I used it for?

 - Explaining in easy way the behavior of some functions when official documentation was hard to understand
 - Giving idea and instruction on how should I approach the project especially on linked lists
 - Giving some aggressive tests in order to figure out where my function' s limits really is
 - Helping to find bugs that I was not expected to see and escape it

What I did not use it?
 - Giving me directly the code and algorithms on function implementations
 - Making all the tests and validate it for me
 - Optimize and correct my code


## Library Functions

  

### Part 1: Libc Functions

 #### Character Checks & Conversions
-  `ft_isalpha` - Check if character is alphabetic
-  `ft_isdigit` - Check if character is a digit
-  `ft_isalnum` - Check if character is alphanumeric
-  `ft_isascii` - Check if character is ASCII
-  `ft_isprint` - Check if character is printable
-  `ft_toupper` - Convert character to uppercase
-  `ft_tolower` - Convert character to lowercase

#### String Functions
-  `ft_strlen` - Calculate string length
-  `ft_strlcpy` - Copy string with size limit
-  `ft_strlcat` - Concatenate string with size limit
-  `ft_strchr` - Locate first occurrence of character
-  `ft_strrchr` - Locate last occurrence of character
-  `ft_strncmp` - Compare strings up to n characters
-  `ft_strnstr` - Locate substring in string
-  `ft_strdup` - Duplicate string

  

#### Memory Functions
-  `ft_memset` - Fill memory with constant byte
-  `ft_bzero` - Zero a byte string
-  `ft_memcpy` - Copy memory area
-  `ft_memmove` - Copy memory area (handles overlap)
-  `ft_memchr` - Scan memory for character
-  `ft_memcmp` - Compare memory areas
-  `ft_calloc` - Allocate and zero memory

#### Conversion Functions
-  `ft_atoi` - Convert string to integer

### Part 2: Additional Functions
#### String Manipulation
-  `ft_substr` - Extract substring from string
-  `ft_strjoin` - Concatenate two strings
-  `ft_strtrim` - Trim characters from string edges
-  `ft_split` - Split string by delimiter into array
-  `ft_strmapi` - Apply function to each character (with index)
-  `ft_striteri` - Iterate through string with function

#### Output Functions
-  `ft_putchar_fd` - Output character to file descriptor
-  `ft_putstr_fd` - Output string to file descriptor
-  `ft_putendl_fd` - Output string + newline to file descriptor
-  `ft_putnbr_fd` - Output integer to file descriptor

#### Conversion
-  `ft_itoa` - Convert integer to string

### Part 3: Linked Lists
#### List Structure
```c
typedef  struct s_list
{
void  *content;
struct s_list *next;
} t_list;

```
#### List Functions
-  `ft_lstnew` - Create new list element
-  `ft_lstadd_front` - Add element at beginning of list
-  `ft_lstsize` - Count elements in list
-  `ft_lstlast` - Get last element of list
-  `ft_lstadd_back` - Add element at end of list
-  `ft_lstdelone` - Delete single element
-  `ft_lstclear` - Delete and free entire list
-  `ft_lstiter` - Apply function to each element
-  `ft_lstmap` - Create new list by applying function to each element

## Technical Details
All the functions follow the rules and the Norme solicited  by 42.\
Each function has been tested in several ways and don't show any form of error expect the part 1 that reproduce the same behavior as the original one even it shows any error

## Author 
42 login : *tokrabem*\
For eventual questions or remarks, feel free to contact me within 42 network
