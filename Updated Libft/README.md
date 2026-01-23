# Libft

*This project has been created as part of the 42 curriculum by <sthinnes>.*

---

## Description

The project "Libft" requests the creation of our own library containing a variety of useful C functions. The main objective of this project is to self-implement these different functions to understand the key concepts and the purpose of the functions as well as how to use them effectively.

### Brief Overview

**Makefile:**

A Makefile is a special file to create and compile specific files by using the 'make' build automation tool. In this project, the Makefile is used to create the object files (.o) of the different functions of the project "Libft" and to compile the library "libft.a" of the project "Libft".

The Makefile of the project "Libft" contains this information:

```makefile
NAME	= libft.a
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I.
SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
          ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
          ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
          ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
          ft_strrchr.c ft_tolower.c ft_toupper.c ft_itoa.c ft_putchar_fd.c \
          ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
          ft_striteri.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c \
          ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
          ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
```

*Obligatory to include in the Makefile for this project: The command 'cc' (command to invoke the C Compiler of the terminal), the Compilation Flags '-Wall', '-Wextra' and '-Werror' to compile the source files to the required output and the rules '$(NAME)', 'all', 'clean', 'fclean' and 're'.*

---

**libft.h:**

A header file which contains all the function prototypes, include statements (necessary standard library headers) and the structure definition for Part 3 to compile the library "libft.a" properly.

---

**Part 1 - Libc functions:**

1. **isalpha:**

   Checks if a character is alphabetic (a-z, A-Z) {Special requirement: Return 1 if the character matches the tested category, return 0 if the character does not match the tested category}.

2. **isdigit:**

   Checks if a character is a digit (0-9) {Special requirement: Return 1 if the character matches the tested category, return 0 if the character does not match the tested category}.

3. **isalnum:**

   Checks if a character is alphanumeric (letter or digit) {Special requirement: Return 1 if the character matches the tested category, return 0 if the character does not match the tested category}.

4. **isascii:**

   Checks if a character is in the ASCII table (0-127) {Special requirement: Return 1 if the character matches the tested category, return 0 if the character does not match the tested category}.

5. **isprint:**

   Checks if a character is printable (including space) {Special requirement: Return 1 if the character matches the tested category, return 0 if the character does not match the tested category}.

6. **strlen:**

   Returns the length of a string.

7. **memset:**

   Fills memory with a constant byte.

8. **bzero:**

   Sets memory to zero.

9. **memcpy:**

   Copies memory area (non-overlapping).

10. **memmove:**

    Copies memory area (handles overlap).

11. **strlcpy:**

    Copies a string to a destination (safer than strcpy).

12. **strlcat:**

    Concatenates strings (safer than strcat).

13. **toupper:**

    Converts lowercase letter to uppercase letter.

14. **tolower:**

    Converts uppercase letter to lowercase letter.

15. **strchr:**

    Finds the first occurrence of a character in a string.

16. **strrchr:**

    Finds the last occurrence of a character in a string.

17. **strncmp:**

    Compares two strings up to n characters.

18. **memchr:**

    Searches for a character in memory.

19. **memcmp:**

    Compares two memory areas.

20. **strnstr:**

    Locates a substring within a string (up to n bytes).

21. **atoi:**

    Converts a string to an integer.

22. **calloc:**

    Allocates and zeros memory for an array.

23. **strdup:**

    Duplicates a string (allocates memory).

---

**Part 2 - Additional functions:**

1. **substr:**

   Extracts a substring from a string.

2. **strjoin:**

   Joins two strings into a new string.

3. **strtrim:**

   Removes specified characters from start and end.

4. **split:**

   Splits a string into an array using a delimiter.

5. **itoa:**

   Converts an integer to a string.

6. **strmapi:**

   Applies a function to each character of the string (passing its index as the first argument and the character itself as the second argument). Creates a new string to store the results from the sucessive applications of 'f'.

7. **striteri:**

   Applies a function to each character of the string passed as argument (passing its index as the first argument). Each character is passed by address to 'f' so it can be modified if it is necessary.

8. **putchar_fd:**

   Outputs a character to a specified file descriptor.

9. **putstr_fd:**

   Outputs a string to a specified file descriptor.

10. **putendl_fd:**

    Outputs a string to a specified file descriptor followed by a newline.

11. **putnbr_fd:**

    Outputs an integer to a specified file descriptor.

---

**Part 3 - Linked list:**

1. **lstnew:**

   Creates a new list node. The 'content' member variable is initialized with the given parameter 'content'. The variable 'next' is initialized to NULL.

2. **lstadd_front:**

   Adds the node 'new' at the beginning of a list.

3. **lstsize:**

   Counts the number of nodes in a list.

4. **lstlast:**

   Returns the last node of a list.

5. **lstadd_back:**

   Adds a node 'new' at the end of a list.

6. **lstdelone:**

   Deletes a single node and frees only the node itself by using the delete function.

7. **lstclear:**

   Deletes and frees all nodes in a list by using the delete function. Finally, set the pointer to the list to NULL.

8. **lstiter:**

   Iterates through a list and applies a function to each node's content.

9. **lstmap:**

   Iterates through a list and creates a new list by applying a function to each node's content. The delete function is used to delete the content of a node if it is needed.

---

## Instructions

### Compilation

To compile the library "libft.a", use the provided Makefile by typing the following commands in your terminal:

- **`make`** - Create the object files (.o) of the functions and compiles the library "libft.a"
- **`make clean`** - Remove the object files (.o) of the functions
- **`make fclean`** - Remove the object files (.o) of the functions and the library "libft.a"
- **`make re`** - Recompiles everything from scratch

---

### Compilation Flags

The library "libft.a" is compiled with the following flags:

- **`-Wall`** - Enable all warnings
- **`-Wextra`** - Enable extra warnings
- **`-Werror`** - Treat warnings as errors

---

### Installation

1. Clone the Libft project to your local computer using `git clone {git repository link} {customized name}` in your terminal.

2. Navigate to the project directory using `cd {directory name of the project folder}` in your terminal.

3. Run the command `make` in your terminal to create the object files (.o) of the functions and to compile the library "libft.a".

4. The compiled version of the library "libft.a" will be created in the project directory.

---

### Execution

To run a specific program, compile the program by using:

```bash
cc -Wall -Wextra -Werror {name of the chosen function.c} {name of the corresponding main program.c} -o {customized name of the compiled program}
./{customized name of the compiled program}
```

To use the library "libft.a" on a specific program, compile the library "libft.a" by using:

```bash
make
cc -Wall -Wextra -Werror {name of the main program.c corresponding to the function to be executed} libft.a -o {customized name of the compiled program}
./{customized name of the compiled program}
```

---

### Test

To verify that all the functions of the "Libft" project work properly, I created a huge main file named "bigtest_main.c" which is located in a directory of my personal student account outside the git repository.

To run this test, the library "libft.a" need to be compiled by using:

```bash
make
cc -Wall -Wextra -Werror ft_bigtest_main.c libft.a -o {customized name of the compiled program}
./{customized name of the compiled program}
```

---

## Resources

### General Resources

- AI assistant app **Claude.ai** for the explanation of some of the functions (such as the function "striteri", "strmapi", "lstiter", "lstmap" etc.) and for the creation of the main functions in my "bigtest_main.c"

- Website **Wikipedia** for the explanation of some of the functions (such as the function "striteri", "strmapi", "lstiter", "lstmap" etc.)

### Specific Research

**For the explanation of LIBC functions:**

- https://42-cursus.gitbook.io/guide/0-rank-00/libft/libc-functions

**For the explanation of functions which uses memory:**

- https://cs50.stackexchange.com/questions/14615/memory-overlap-in-c

**For memset:**

- https://www.youtube.com/watch?v=Njsn5HAnAnk

**For memmove:**

- https://www.geeksforgeeks.org/cpp/memmove-in-cc/
- https://www.youtube.com/watch?v=1eb0d9yCm2M

**For the explanation of substrings:**

- https://www.youtube.com/watch?v=lEvpLI50MSU

**For the explanation of malloc:**

- https://www.youtube.com/watch?v=n_Se6bt8jM0&t=28

**For the explanation of string concatenation:**

- https://www.youtube.com/watch?v=ZoAe4HKNMPg&t=28s

**For split:**

- https://www.youtube.com/watch?v=Vp6OELK4gmo&t=28s

**For the explanation of file descriptors:**

- https://www.youtube.com/watch?v=WCrTRPu1bQk&t=30s

**For strmapi:**

- https://42-cursus.gitbook.io/guide/0-rank-00/libft/additional-functions/ft_strmapi

**For striteri:**

- https://42-cursus.gitbook.io/guide/0-rank-00/libft/additional-functions/ft_striteri

**For the explanation of linked lists:**

- https://www.youtube.com/watch?v=N6dOwBde7-M&t=28s

**For the explanation of delete function:**

- https://www.youtube.com/watch?v=-PQRjsX_1i8


