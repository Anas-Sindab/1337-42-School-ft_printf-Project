# ft_printf - Custom Printf Implementation

[![1337](https://img.shields.io/badge/1337-000000?style=for-the-badge&logoColor=white)](https://www.1337.ma/)
[![UM6P](https://img.shields.io/badge/UM6P-C1392B?style=for-the-badge)](https://um6p.ma/)

[![42 Badge](https://img.shields.io/badge/ft__printf-00babc?style=for-the-badge&logo=42)](https://42.fr)
![Makefile](https://img.shields.io/badge/Makefile-2C2D30?style=for-the-badge&logo=data:image/svg+xml;base64,PHN2ZyB3aWR0aD0iMjQiIGhlaWdodD0iMjQiIHZpZXdCb3g9IjAgMCAyNCAyNCIgZmlsbD0ibm9uZSIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIj4KPHBhdGggZD0iTTEyIDJMMiAxMkwxMiAyMkwyMiAxMkwxMiAyWiIgZmlsbD0id2hpdGUiLz4KPC9zdmc+)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

> A complete reimplementation of the printf function from scratch, handling multiple format specifiers and variadic arguments.

---

## 📖 Overview

**ft_printf** is a project that challenges you to recreate one of C's most versatile functions - `printf()`. This project deepens understanding of variadic functions, string parsing, type conversion, and formatted output - essential skills for systems programming.

The implementation handles all major format specifiers and edge cases, providing a production-ready alternative to the standard library's printf.

### Key Achievements
- Implemented printf with 9 format specifiers from scratch
- Mastered variadic functions using stdarg.h
- Handled complex type conversions (decimal, hexadecimal, pointers)
- Comprehensive edge case handling (NULL pointers, NULL strings)

---

## 🎯 Project Goals

1. **Variadic function mastery** - Understanding va_list, va_start, va_arg, va_end
2. **Type conversion algorithms** - Converting integers to various bases (10, 16)
3. **String parsing** - Processing format strings with multiple specifiers
4. **Output management** - Tracking character count across multiple write calls
5. **Code modularity** - Clean separation of concerns across multiple files

---

## 🔧 Technical Implementation

### Supported Format Specifiers

| Specifier | Type | Description |
|-----------|------|-------------|
| `%c` | char | Single character |
| `%s` | string | String of characters |
| `%p` | pointer | Pointer address in hexadecimal |
| `%d` | integer | Signed decimal integer |
| `%i` | integer | Signed decimal integer |
| `%u` | unsigned int | Unsigned decimal integer |
| `%x` | unsigned int | Unsigned hexadecimal (lowercase) |
| `%X` | unsigned int | Unsigned hexadecimal (uppercase) |
| `%%` | literal | Percent sign |

### Function Prototypes

#### Main Function
```c
int ft_printf(const char *format_str, ...);
```

#### Helper Functions
```c
void    ft_putchar(char c, int *count);
void    ft_putstr(char *s, int *count);
void    ft_putnbr(int n, int *count);
void    ft_putsigned(unsigned int nbr, int *count);
void    ft_puthex(unsigned int hex, char check, int *count);
void    ft_putptr(unsigned long ptn, int *count);
void    ft_ptr_check(void *ptr, int *count);
```

---

## 💡 Key Features

### Edge Case Handling

**NULL String Protection**
```c
ft_printf("String: %s\n", NULL);
// Output: String: (null)
```

**NULL Pointer Handling**
```c
ft_printf("Pointer: %p\n", NULL);
// Output: Pointer: (nil)
```

**Negative Numbers**
```c
ft_printf("Number: %d\n", -2147483648);
// Output: Number: -2147483648
```

### Hexadecimal Conversion
```c
ft_printf("Lowercase: %x\n", 255);   // Output: ff
ft_printf("Uppercase: %X\n", 255);   // Output: FF
```

### Pointer Formatting
```c
int x = 42;
ft_printf("Address: %p\n", &x);
// Output: Address: 0x7ffeeb2a4a8c
```

---

## 🚀 Usage

### Building the Library

```bash
# Clone the repository
git clone https://github.com/yourusername/ft_printf.git
cd ft_printf

# Compile the library
make
```

This generates `libftprintf.a`, a static library ready for linking.

### Compilation

```bash
# Link with your project
gcc -Wall -Wextra -Werror main.c libftprintf.a -o program

# Example usage in code
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "World");
    ft_printf("Number: %d, Hex: %x\n", 42, 42);
    ft_printf("Pointer: %p\n", &main);
    return (0);
}
```

### Makefile Rules

| Command | Action |
|---------|--------|
| `make` | Compile the library |
| `make clean` | Remove object files |
| `make fclean` | Remove objects and library |
| `make re` | Recompile from scratch |

---

## 💻 Technical Highlights

### Variadic Arguments
```c
int ft_printf(const char *format_str, ...)
{
    va_list args;
    int count = 0;
    
    va_start(args, format_str);
    // Process each argument based on format specifier
    va_end(args);
    
    return (count);
}
```

### Recursive Number Conversion
All numeric conversions use recursion for elegant digit extraction:

```c
void ft_putnbr(int n, int *count)
{
    long num = (long)n;
    
    if (num < 0)
    {
        num = -num;
        *count += write(1, "-", 1);
    }
    if (num > 9)
        ft_putnbr(num / 10, count);
    
    char c = (num % 10) + '0';
    *count += write(1, &c, 1);
}
```

### Base Conversion Algorithm
Hexadecimal conversion with case sensitivity:

```c
void ft_puthex(unsigned int hex, char check, int *count)
{
    char *str;
    
    if (check == 'x')
        str = "0123456789abcdef";
    else (check == 'X')
        str = "0123456789ABCDEF";
    
    if (hex >= 16)
        ft_puthex((hex / 16), check, count);
    
    ft_putchar(str[hex % 16], count);
}
```

---

## 📊 Implementation Strategy

### 1. Format String Parsing
```
"Hello %s, number: %d" → Parse → Identify specifiers → Extract arguments
```

### 2. Type Identification
```c
static void ft_check_specifier(const char *format_str, int *count, va_list args)
{
    if (*format_str == 'c')
        ft_putchar(va_arg(args, int), count);
    else if (*format_str == 's')
        ft_putstr(va_arg(args, char *), count);
    // ... handle all specifiers
}
```

### 3. Character Count Tracking
Each write operation updates a count pointer, ensuring accurate return value.

---

## 🧪 Testing Examples

```c
#include "ft_printf.h"

int main(void)
{
    int ret;
    
    // Basic usage
    ret = ft_printf("Character: %c\n", 'A');
    ft_printf("Returned: %d\n\n", ret);
    
    // Multiple specifiers
    ret = ft_printf("String: %s, Number: %d, Hex: %x\n", 
                    "Hello", 42, 42);
    ft_printf("Returned: %d\n\n", ret);
    
    // Edge cases
    ft_printf("NULL string: %s\n", NULL);
    ft_printf("NULL pointer: %p\n", NULL);
    ft_printf("MIN_INT: %d\n", -2147483648);
    
    // Comparison with real printf
    printf("Real printf: %x\n", 255);
    ft_printf("ft_printf:   %x\n", 255);
    
    return (0);
}
```

---

## 📂 Project Structure

```
ft_printf/
├── Makefile                  # Build automation
├── includes/
│   └── ft_printf.h          # Header with all prototypes
├── srcs/
│   ├── ft_printf.c          # Main function and format parsing
│   ├── ft_putchar.c         # Character output
│   ├── ft_putstr.c          # String output
│   ├── ft_putnbr.c          # Signed integer output
│   ├── ft_putsigned.c       # Unsigned integer output
│   ├── ft_puthex.c          # Hexadecimal conversion
│   ├── ft_putptr.c          # Pointer value conversion
│   └── ft_ptr_check.c       # Pointer formatting with NULL check
└── README.md                # Documentation
```

---

## 🎓 Learning Outcomes

This project provided deep insights into:

1. **Variadic functions**: Complete understanding of stdarg.h macros
2. **Type system**: Working with different data types and their representations
3. **Base conversion**: Converting numbers between decimal and hexadecimal
4. **Pointer arithmetic**: Understanding memory addresses and their display
5. **Recursion**: Elegant solutions for digit extraction and base conversion
6. **Edge case handling**: Dealing with NULL values, negative numbers, and INT_MIN
7. **Modular design**: Separating concerns across multiple helper functions

---

## 🔗 Related Projects

Part of the 42 curriculum progression:
- **Libft** - Custom C library foundation
- **get_next_line** - File reading with static variables
- **Born2beroot** - System administration
- **push_swap** - Advanced algorithm optimization
- **minitalk** - Unix signals and bitwise operations

---

## 🎯 Skills Demonstrated

- Variadic function implementation
- Format string parsing
- Type conversion algorithms
- Recursive number processing
- Base conversion (decimal ↔ hexadecimal)
- Memory address handling
- Edge case management
- Modular code architecture
- Test-driven development

---

## 📝 License

This project is part of the 42 Network curriculum. Feel free to reference for learning purposes.

---

## 👤 Author

- GitHub: [@Anas-Sindab](https://github.com/Anas-Sindab)
- LinkedIn: [Anas-Sindab](https://linkedin.com/in/yourprofile)
- 42 Intra: `anasinda`

---

*Developed at UM6P - 1337 Coding School (42 Network) - 2025*
