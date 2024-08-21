/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags_toFILE.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:49:46 by dopereir          #+#    #+#             */
/*   Updated: 2024/08/21 10:49:48 by dopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"
#include <ctype.h>
#include <stdlib.h>

void	parse_padding(fd_flags *flags, const char *format, size_t *i)
{
	while (strchr("+-0# ", format[*i]))
	{
		if (format[*i] == '+' || format[*i] == ' ' || format[*i] == '#')
			flags->padding = format[*i];
		else if (format[*i] == '0')
			flags->zero_pad = 1;
		else if (format [*i] == '-')
			flags->left_align = '-';
		(*i)++;
	}
}

void	parse_number(int *field, const char *format, size_t *i)
{
	if (isdigit(format[*i]))
	{
		*field = atoi(&format[*i]);
		while (isdigit(format[*i]))
			(*i)++;
	}
}

void	parse_flags_fd(fd_flags *flags, const char *format, size_t *i)
{
	parse_padding(flags, format, i);
	parse_number(&(flags->width), format, i);
	if (format[*i] == '.')
	{
		(*i)++;
		flags->precision = 0;
		parse_number(&(flags->precision), format, i);
	}
	if (ft_strchr("cspdiuxX%", format[*i]))
	{
		flags->specifier = format[*i];
		(*i)++;
	}
}
/*void	parse_flags(t_flags *flags, const char *format, size_t *i)
{
	flags->width = 0;
	flags->precision = -1;
	flags->len_flags = NULL;
	flags->conversion = '\0';
	flags->padding = '\0';
	flags->specifier = '\0';
	(*i)++;
	while (format[*i] == '+' || format[*i] == '-' || format[*i] == '0'
		|| format[*i] == ' ' || format[*i] == '#')
	{
		flags->padding = format[*i];
		(*i)++;
	}
	if (isdigit(format[*i]))
	{
		flags->width = atoi(&format[*i]);
		while (isdigit(format[*i]))
			(*i)++;
	}
	if (format[*i] == '.')
	{
		(*i)++;
		flags->precision = atoi(&format[*i]);
		while (isdigit(format[*i]))
			(*i)++;
	}
	if (format[*i] == 'h' || format[*i] == 'l'
		|| format[*i] == 'j' || format[*i] == 'z')
	{
		if (format[*i] == 'h' && format[*i + 1] == 'h')
		{
			flags->len_flags = "hh";
			(*i)++;
		}
		else if (format[*i] == 'l' && format[*i + 1] == 'l')
		{
			flags->len_flags = "ll";
			(*i)++;
		}
		else
			flags->len_flags = (char []){format[*i], '\0'};
		(*i)++;
	}
	if (strchr("sSpdDioOuUxXcC", format[*i]))
	{
		flags->conversion = format[*i];
		(*i)++;
	}
}*/
