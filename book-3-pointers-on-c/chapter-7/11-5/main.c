/**
 * @file     book-3-pointers-on-c/chapter-7/11-5/main.c
 * @author   mtueih
 * @date     2025-12-03 09:42
 * @brief    简化的 printf 函数。
 */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int my_simple_printf(const char *format, ...);
int print_interger(int n);
int print_float(float n);

int main(void) {
	int ret = 0;

	ret = my_simple_printf("int: %d, float: %f, string: %s, char: %c\n", 666, 3.14, "SB", '@');

	my_simple_printf("一共输入了 %d 个字符。\n", ret);

	return EXIT_SUCCESS;
}

int my_simple_printf(const char *format, ...) {
	va_list args;
	int ret;
	int format_char_count;
	const char *str;

	va_start(args, format);
	format_char_count = 0;

	for (ret = 0; *format != '\0'; ++format) {
		if (*format == '%') {
			format_char_count = 1;
			continue;
		}

		if (format_char_count == 1) {
			switch (*format) {
			case 'd':
				ret += print_interger(va_arg(args, int));
				break;
			case 'f':
				ret += print_float(va_arg(args, double));
				break;
			case 's':
				str = va_arg(args, const char *);
				while (*str != '\0') {
					putchar(*str);
					++ret;
					++str;
				}
				break;
			case 'c':
				putchar(va_arg(args, int));
				++ret;
				break;
			default:
				putchar('%');
				putchar(*format);
				ret += 2;
				break;
			}
			format_char_count = 0;
			continue;
		}

		putchar(*format);
		++ret;
	}

end:
	va_end(args);
	return ret;
}

int print_interger(int n) {
	int ret;

	ret = printf("%d", n);

	return ret;
}
int print_float(float n) {
	int ret;

	ret = printf("%f", n);

	return ret;
}