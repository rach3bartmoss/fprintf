#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include "../libftprintf.h"

typedef struct s_list
{
	va_list	ap;
	size_t	i;
	size_t	count;
	FILE	*fd;
}			t_list;

void	ft_putchar_fd(char c, int fd, t_list *op);


#endif