#include <stdio.h>
#include "ft_fprintf.h"

int	my_fprintf(FILE *stream, const char *format, ...)
{
	t_args	op;
	t_flags	flags;
	int		fd;

	if (stream == NULL || format == NULL)
		return (-1);
	fd = fileno(stream);  // Convert FILE* to file descriptor
	if (fd == -1)
		return (-1);
	op.count = 0;
	va_start(op.ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				ft_putchar_fd('%', fd, &op);
			else
			{
				parse_and_print_toFILE(&flags, format, &op.i);
			}
			// Adapt your existing print functions to use fd
		}
		else
			ft_putchar_fd(*format, fd, op);
	}
	va_end(op.ap);
	return (op.count);

}