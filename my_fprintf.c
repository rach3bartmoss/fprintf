#include <stdio.h>
#include "ft_fprintf.h"

int	my_fprintf(FILE *stream, const char *format, ...)
{
	t_list op;
	t_flags flags;
	int fd;

	if (stream == NULL || format == NULL)
		return -1;

	fd = fileno(stream);  // Convert FILE* to file descriptor
	if (fd == -1)
		return -1;

	op.count = 0;
	va_start(op.ap, format);

	for (op.i = 0; format[op.i]; op.i++)
	{
		if (format[op.i] == '%')
		{
			op.i++;
			parse_flags(&flags, format, &op.i);
			// Adapt your existing print functions to use fd
		}
		else
		{
			putchar_fd(format[op.i], fd);
			op.count++;
		}
	}

	va_end(op.ap);
	return op.count;

}