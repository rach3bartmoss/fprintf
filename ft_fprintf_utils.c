#include "ft_fprintf.h"

void	ft_putchar_fd(char c, int fd, t_list *op)
{
	write (fd, &c, 1);
	op->count++;
}