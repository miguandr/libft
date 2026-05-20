# libft+

A comprehensive C standard library reimplementation built from scratch as part of the [42 School](https://42berlin.de) curriculum. This library bundles three complete projects: **libft**, **ft_printf**, and **get_next_line** — compiled into a single static archive (`libft.a`) for use across all subsequent 42 projects.

> Compiled with `-Wall -Wextra -Werror`. Zero allowed external functions beyond `write`, `malloc`, `free`, and `read`.

---

## Modules

### libft — Standard Library Functions (47 functions)

A complete reimplementation of essential `<string.h>`, `<ctype.h>`, and `<stdlib.h>` functions, plus additional utility functions and a linked list API.

**Character classification & conversion**

| Function | Description |
|---|---|
| `ft_isalpha` | Check if character is alphabetic |
| `ft_isdigit` | Check if character is a digit |
| `ft_isalnum` | Check if character is alphanumeric |
| `ft_isascii` | Check if character is in ASCII range |
| `ft_isprint` | Check if character is printable |
| `ft_toupper` | Convert character to uppercase |
| `ft_tolower` | Convert character to lowercase |

**Memory functions**

| Function | Description |
|---|---|
| `ft_memset` | Fill memory block with a byte value |
| `ft_bzero` | Zero out a memory block |
| `ft_memcpy` | Copy memory area (no overlap) |
| `ft_memmove` | Copy memory area (handles overlap) |
| `ft_memchr` | Locate byte in memory block |
| `ft_memcmp` | Compare two memory blocks |
| `ft_calloc` | Allocate and zero-initialize memory |

**String functions**

| Function | Description |
|---|---|
| `ft_strlen` | Compute string length |
| `ft_strlcpy` | Size-bounded string copy |
| `ft_strlcat` | Size-bounded string concatenation |
| `ft_strchr` | Locate first occurrence of character |
| `ft_strrchr` | Locate last occurrence of character |
| `ft_strncmp` | Compare first n bytes of two strings |
| `ft_strnstr` | Locate substring within bounded length |
| `ft_strdup` | Duplicate a string (heap-allocated) |
| `ft_substr` | Extract substring |
| `ft_strjoin` | Concatenate two strings (heap-allocated) |
| `ft_strtrim` | Trim characters from both ends of a string |
| `ft_split` | Split string by delimiter into array |
| `ft_strmapi` | Apply function to each char (new string) |
| `ft_striteri` | Apply function to each char (in-place) |

**Conversion**

| Function | Description |
|---|---|
| `ft_atoi` | Convert string to integer |
| `ft_itoa` | Convert integer to string (heap-allocated) |

**File descriptor output**

| Function | Description |
|---|---|
| `ft_putchar_fd` | Write character to file descriptor |
| `ft_putstr_fd` | Write string to file descriptor |
| `ft_putendl_fd` | Write string + newline to file descriptor |
| `ft_putnbr_fd` | Write integer to file descriptor |

**Linked list (bonus)**

| Function | Description |
|---|---|
| `ft_lstnew` | Create new list node |
| `ft_lstadd_front` | Prepend node to list |
| `ft_lstadd_back` | Append node to list |
| `ft_lstsize` | Count nodes in list |
| `ft_lstlast` | Get last node |
| `ft_lstdelone` | Delete a single node |
| `ft_lstclear` | Delete and free entire list |
| `ft_lstiter` | Apply function to each node |
| `ft_lstmap` | Map function over list into new list |

---

### ft_printf — Variadic Output Formatter

A reimplementation of `printf(3)` using variadic arguments (`<stdarg.h>`). Parses a format string and dispatches to type-specific handlers. Returns the total number of characters written.

**Supported specifiers**

| Specifier | Output |
|---|---|
| `%c` | Single character |
| `%s` | String (prints `(null)` for NULL) |
| `%p` | Pointer address in hex (`0x…`, or `(nil)`) |
| `%d` / `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Unsigned hex (lowercase) |
| `%X` | Unsigned hex (uppercase) |
| `%%` | Literal percent sign |

**Architecture:** The main `ft_printf` loop dispatches to `ft_specifiers`, which calls one dedicated function per type. Each handler returns the number of bytes it wrote, enabling accurate total-length tracking.

---

### get_next_line — Buffered Line Reader

Reads one line at a time from a file descriptor, preserving state between calls via a `static` buffer. Handles files, pipes, and stdin. `BUFFER_SIZE` is configurable at compile time.

```c
char *get_next_line(int fd);
```

- Returns the next line including the trailing `\n` (if present)
- Returns `NULL` on EOF or error
- Works correctly with any `BUFFER_SIZE ≥ 1`
- Change buffer size at compile time: `cc -D BUFFER_SIZE=4096 ...`

**Internal design:** Three helper functions manage state cleanly — `read_from_file` accumulates chunks into a growing buffer until a newline is found, `extract_line` carves out the current line, and `obtain_rest` trims it off the buffer for the next call.

---

## Building

```bash
make        # build libft.a
make clean  # remove object files
make fclean # remove object files + libft.a
make re     # full rebuild
```

Link against your project:

```bash
cc -Wall -Wextra -Werror -I libft/includes your_file.c -L libft -lft -o your_program
```

---

## Project Structure

```
libft/
├── Makefile
├── README.md
├── libft.a                      (generated)
│
├── libft/
│   ├── include/
│   │   └── libft.h
│   └── src/                     (47 source files)
│       ├── ft_strlen.c
│       └── ...
│
├── ft_printf/
│   ├── include/
│   │   └── ft_printf.h
│   └── src/
│       ├── ft_printf.c
│       ├── ft_printf_func.c
│       ├── ft_printf_hexa.c
│       ├── ft_printf_ptr.c
│       └── ft_printf_un.c
│
├── get_next_line/
│   ├── include/
│   │   └── get_next_line.h
│   └── src/
│       ├── get_next_line.c
│       └── get_next_line_utils.c
│
└── obj/                         (generated)
```
