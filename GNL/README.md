## Description

Get Next Line is a function that reads a file line by line. The goal is to implement a function that returns one line at a time from a file descriptor, handling any buffer size efficiently. This project teaches file I/O operations, static variables, and dynamic memory management in C.

## Instructions

**Compilation:**
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

**Usage:**
```c
#include "get_next_line.h"

int fd = open("file.txt", O_RDONLY);

printf("%s", get_next_line(fd));
...
close(fd);
```

## Algorithm

The implementation uses a **static buffer (stash)** to store data between function calls:

1. **Read phase**: Read `BUFFER_SIZE` bytes from the file descriptor and accumulate in the stash
2. **Extract phase**: Extract the first line (up to `\n` or EOF) from the stash
3. **Update phase**: Keep the remaining data in the stash for the next call

## Resources

- [Linux man pages: read(2)](https://man7.org/linux/man-pages/man2/read.2.html)
- [Static variables in C](https://en.cppreference.com/w/c/language/static)
- 42 Get Next Line subject

**AI Usage**: GitHub Copilot was used for suggestions.
