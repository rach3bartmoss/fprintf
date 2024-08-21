#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
//# include "../libftprintf.h"

typedef struct fd_flags
{
	int		width; // ex = %10s "print min of 10 char from str"
	int		precision; // ".precision" ex: input = 1234 %.3d = "123"
	char	specifier; // "sSpdDioOuUxXcC" %d, %i, %s etc..-
	char	padding; // "+(SPACE)#" 
	char	left_align; // for '-' flag
	int		zero_pad; // for '0' flags
}		fd_flags;

typedef struct s_args
{
	va_list	ap;
	size_t	i;
	size_t	count;
	FILE	*fd;
}			t_args;

void	ft_putchar_fd(char c, int fd, t_args *op);


#endif