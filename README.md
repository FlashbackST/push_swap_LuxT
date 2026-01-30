# push_swap

*This project has been created as part of the 42 curriculum by <sthinnes> and <dgarot>.*

---

## Description

The project "ft_printf" requests the reconstruction of the function "printf" from Libc (C Library / Standard Library) without implementing the buffer management of the original "printf" function. The main objective of this project is to create our own version of the original function "printf" to understand the key concepts of this function as well as the advantages and disadvantages that come with this function.


### Brief Overview

**Makefile:**

A Makefile is a special file to create and compile specific files by using the 'make' build automation tool. In this project, the Makefile is used to create the object files (.o) of the different functions of the project "ft_printf" and to compile the library "libftprintf.a" of this project.

The Makefile of the project "ft_printf" contains this information:

```makefile
NAME	= libftprintf.a
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I.
SRCS	= ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunsignednbr.c \
          ft_atoi.c ft_puthex_lower.c ft_puthex_upper.c ft_putptr.c \
          ft_printf.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
```

*Obligatory to include in the Makefile for this project: The command 'cc' (command to invoke the C Compiler of the terminal), the Compilation Flags '-Wall', '-Wextra' and '-Werror' to compile the source files to the required output and the rules '$(NAME)', 'all', 'clean', 'fclean' and 're'.*

---

**ft_printf.h:**

A header file which contains all the function prototypes and all the include statements (necessary standard library headers) to compile the library "libftprintf.a" properly.

---

**All functions used in my project "ft_printf":**

1. **putchar:**

   Writes a single character to the output.

2. **putstr:**

   Writes a string to the output by printing each character one by one until it hits the end of the string.

3. **putnbr:**

   Writes an integer number (positive or negative) to the output.

4. **putunsignednbr:**

   Writes an unsigned integer (only positive numbers, including zero) to the output.

5. **atoi:**

   Converts a string to an integer.

6. **puthex_lower:**

   Writes a number in hexadecimal format to the output using lowercase letters (0-9 and a-f).

7. **puthex_upper:**

   Writes a number in hexadecimal format to the output using uppercase letters (0-9 and A-F).

8. **putptr:**

   Writes a memory address (pointer) in hexadecimal format to the output, usually with a "0x" prefix. Used to display where something is stored in memory.

9. **ft_printf:**

   The main function that recreates the original "printf" function. It reads a format string, identifies what type of data to print (%d, %s, %x, etc.), and calls the appropriate helper functions above to format and display the output.

---

## Instructions

### Compilation

To compile the library "libftprintf.a", use the provided Makefile by typing the following commands in your terminal:

- **`make`** - Create the object files (.o) of the functions and compiles the library "libftprintf.a"
- **`make clean`** - Remove the object files (.o) of the functions
- **`make fclean`** - Remove the object files (.o) of the functions and the library "libftprintf.a"
- **`make re`** - Recompiles everything from scratch

---

### Compilation Flags

The library "libftprintf.a" is compiled with the following flags:

- **`-Wall`** - Enable all warnings
- **`-Wextra`** - Enable extra warnings
- **`-Werror`** - Treat warnings as errors

---

### Installation

1. Clone the ft_printf project to your local computer using `git clone {git repository link} {customized name}` in your terminal.

2. Navigate to the project directory using `cd {directory name of the project folder}` in your terminal.

3. Run the command `make` in your terminal to create the object files (.o) of the functions and to compile the library "libftprintf.a".

4. The compiled version of the library "libftprintf.a" will be created in the project directory.

---

### Execution

To run the main program of the project "ft_printf", compile the program by using:

```bash
cc -Wall -Wextra -Werror {name of all functions used in this project} {name of the corresponding main program.c} -o {customized name of the compiled program}
./{customized name of the compiled program}
```

To use the library "libftprintf.a" on the main program of the project "ft_printf", compile the library "libftprintf.a" by using:

```bash
make
cc -Wall -Wextra -Werror {name of the main program.c corresponding to the function to be executed} libftprintf.a -o {customized name of the compiled program}
./{customized name of the compiled program}
```

---

### Test

To verify that the main function of the "ft_printf" project work properly, I created a main file named "test.c" which is located in a directory of my personal student account outside the git repository.

To run this test, the library "libftprintf.a" need to be compiled by using:

```bash
make
cc -Wall -Wextra -Werror ft_test.c libftprintf.a -o {customized name of the compiled program}
./{customized name of the compiled program}
```

---


## Resources

### General Resources

- AI assistant app **Claude.ai** for the explanation of some parts of the project "push_swap"

### Specific Research

**For explanation of the key principle and the composition of the project “push_swap”:**

- https://42-cursus.gitbook.io/guide/2-rank-02/push_swap
- https://github.com/OliverKingz/push_swap
- https://www.youtube.com/watch?v=OaG81sDEpVk

**For explanation of stack implementation:**

- https://www.youtube.com/watch?v=Flk5yrlx5Qo

**For explanation of the different operations (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr):**

- https://www.youtube.com/watch?v=4dMsuxfqufg

**For explanation of the Phony implementation in a Makefile:**

- https://www.youtube.com/watch?v=GO0MHokQn-E

**For explanation of all types of sorting algorithms:**

- https://www.youtube.com/watch?v=rbbTd-gkajw

**For explanation of simple sorting algorithms:**

- https://www.eecs.umich.edu/courses/eecs281/f04/lecnotes/10-elementary%20sorting.pdf
- https://www.geeksforgeeks.org/dsa/comparison-among-bubble-sort-selection-sort-and-insertion-sort/

**→ For insertion sort:**

- https://www.youtube.com/watch?v=JU767SDMDvA
- https://www.youtube.com/watch?v=nKzEJWbkPbQ

**→ For selection sort:**

- https://www.youtube.com/watch?v=EwjnF7rFLns

**→ For bubble sort:**

- https://www.youtube.com/watch?v=p__ETf2CKY4

**For explanation of medium  sorting algorithms:**

**→ For block-based sorting:**

- https://www.youtube.com/watch?v=InGeRuRk3f8

**→ For bucket sort:**

- https://www.youtube.com/watch?v=xeT31rm3bN0
- https://www.geeksforgeeks.org/dsa/bucket-sort-2/

**For explanation of benchmark mode:**

- https://en.wikipedia.org/wiki/Benchmark_(computing)


