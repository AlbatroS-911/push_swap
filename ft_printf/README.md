*This project has been created as part of the 42 curriculum by tokrabem.*

# Ft_printf
## DESCRIPTION

***Ft_printf*** is a project within the 42 cursus recreating the behavior of the versatile function of C : **printf**. As a reminder, printf is the main function in C useful to display different information on the standard output like terminal. 

**The purpose:**

 - Have a custom function capable of displaying information on the standard output as the original one is not allowed to be used
 - Understand the real behavior of printf() function and copy it
 - Gain skills based on algorithms and code structure.
 - Share knowledge and insights thanks to peer-learning
 
 **Rules of implementation**
 - Do not implement the buffer management of the original printf()
 - The function must handle the following conversions : ***cspdiuxX%***
 - The function will compared against the original printf()
 - Create my own library using the command **ar**. Using the command **libtool** is not allowed.
 - The library **libftprintf.a** should be created in the root of the repository
 - The header must be named **ft_printf.h** and must contain the prototype of the ft_printf() function

**The function have to handle:**

 - %c Prints a single character.
 - %s Prints a string (as defined by the common C convention).
 - %p The void * pointer argument has to be printed in hexadecimal format.
 - % d Prints a decimal (base 10) number.
 -  %i Prints an integer in base 10.
 - %u Prints an unsigned decimal (base 10) number. 
 - %x Prints a number in hexadecimal (base 16) lowercase format. 
 -  %X Prints a number in hexadecimal (base 16) uppercase format. 
 - %% Prints a percent sign.

## INSTRUCTIONS

### Clone the repository
```git clone git@vogsphere.42antananarivo.mg:vogsphere/intra-uuid-ecfba0ff-b702-448b-8405-7981a763775b-7263287-tokrabem```

### Compilation
To compile the function, use the provided Makefile:
```bash

# Compile the function (creates libftprintf.a)
make

# Clean object files
make  clean

# Clean everything (object files + libftprintf.a)
make  fclean

# Recompile everything
make  re

```
### Execution
 - Include the project in your project
 ```#include "ft_printf.h"```
 - Compile your program alongside the library in ```bash``` using this command
 ```cc your_program.c libftprintf.a -o your_program```

## RESOURCES

### Official resources

 - Official documentation about printf() ```man printf``` that describes the behavior of the function.
 - Some articles and learning platform on the internet and obviously www.youtube.com for apprehending some new concepts thanks to tutorials.
 - Peer-learning system within 42 School based on exchanges, contribution and learning from projects.

### About AI

What I used it for?

 - Giving me an idea on how can I proceed and build the project from scratch.
 - Offset some information judged important but I didn't figure out in the articles or tutorials.
 - Asking few tips real quick, and not more.
 - Being an emotional support when tests did not work. 
 
 What I did not use it for?
 - Asking directly all the code that I didn't even understand.
 - Building the whole project that will be tricky for me
 - 
## CONTENT OF THE PROJECT
### Utils functions
 - ft_putchar_fd - Display a single character
 - ft_putstr_fd - Display a whole string
 - ft_strlen - Count the length of a string
 
### Conversion functions
 - ft_putnbr_base - Convert a number into any base
 - ft_print_add - Display the address into suitable format
 - ft_un_int - Display an unsigned number
 
### Main function
 ft_printf - Contain the logic as the original one

### Header 
ft_printf.h - Prototype all the functions and others headers useful for the project.

### Makefile
Makefile - Compile and run the function

## TECHNICAL DETAILS
 This function follows the rules and the Norm solicited by 42.\
 The function has been tested in several ways and didn't show any form of error

## Author
42 login : *tokrabem*\
For eventual questions or remarks, feel free to contact me within 42 network.
