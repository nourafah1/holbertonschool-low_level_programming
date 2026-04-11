void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i, j;
	char *sep = "";   /* 🔥 حطيه هنا بدل تحت */
	char types[] = {'c', 'i', 'f', 's'};
	void (*funcs[])(va_list, char *) = {
		print_char,
		print_int,
		print_float,
		print_string
	};

	/* 🔥 سطر فاضي هنا */

	va_start(args, format);
	i = 0;
	while (format && format[i])
	{
		j = 0;
		while (j < 4)
		{
			if (format[i] == types[j])
			{
				funcs[j](args, sep);
				sep = ", ";
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(args);
}
