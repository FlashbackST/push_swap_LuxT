/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:23:36 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/16 17:23:41 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <unistd.h>
//#include <string.h>
//#include <stdarg.h>

static int	handle_format(const char **format, va_list args)
{
	int	count;

	count = 0;
	(*format)++;
	if (**format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (**format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (**format == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (**format == 'd' || **format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (**format == 'u')
		count += ft_putunsignednbr(va_arg(args, unsigned int));
	else if (**format == 'x')
		count += ft_puthex_lower(va_arg(args, unsigned int));
	else if (**format == 'X')
		count += ft_puthex_upper(va_arg(args, unsigned int));
	else if (**format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			count += handle_format(&format, args);
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}

/*int	main(int argc, char *argv[])
{
	int	i;
	int	num;

	if (argc < 2)
	{
		ft_printf("No arguments provided\n");
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '\0' && argv[i][1] == '\0')
		{
			ft_printf("%c\n", argv[i][0]);
			ft_printf("Address of %s: %p\n", argv[i], argv[i]);
		}
		else if (*argv[i] >= '0' && *argv[i] <= '9')
		{
			num = ft_atoi(argv[i]);
			ft_printf("%d\n", num);
			ft_printf("Lowercase hex: %x\n", num);
			ft_printf("Uppercase hex: %X\n", num);
			ft_printf("Address of %s: %p\n", argv[i], argv[i]);
		}
		else
		{
			ft_printf("%s\n", argv[i]);
			ft_printf("Address of %s: %p\n", argv[i], argv[i]);
		}
		i++;
	}
	return (0);
}*/
