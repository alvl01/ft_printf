
int ft_printf(const char *to_print, ...)
{
  int i;
  va_list parameters;

  va_start(parameters, to_print);
  i = 0;
  while (to_print[i])
  {
    if (to_print[i] == '%')
    {
      i++;
      i = ft_detector(parameters, to_print, i);
    }
    else
      ft_putchar(to_print[i];
  }
  va_end(parameters);
}
