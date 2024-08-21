#include "ft_fprintf.h"

void	ft_putchar_fd(char c, int fd, t_args *op)
{
	write (fd, &c, 1);
	op->count++;
}

void	handle_specifier_toFILE(fd_flags *flags, t_args *op, int fd)
{
	if (flags->specifier == 'd' || flags->specifier == 'i')
		print_int(flags, op);
	else if (flags->specifier == 'c')
		print_char(flags, op);
	else if (flags->specifier == 's')
		print_string(flags, op);
	else if (flags->specifier == 'p')
		print_ptr(flags, op);
	else if (flags->specifier == 'x' || flags->specifier == 'X')
		print_hex(flags, op);
	else if (flags->specifier == 'u')
		print_unsigned(flags, op);
}

void	parse_and_print_toFILE(const char *format, t_args *op, int fd)
{
	size_t		start_i;
	fd_flags	flags;

	flags.width = 0;
	flags.precision = -1;
	flags.specifier = 0;
	flags.padding = 0;
	flags.zero_pad = 0;
	flags.left_align = 0;
	start_i = op->i;
	parse_flags_toFILE(&flags, format, &op->i);
	handle_specifier_toFILE(&flags, op, fd);
	op->i = op->i - start_i;
}
