#include "main.h"
/**
 * _help - function to help you
 * 
 * Return: 0
*/
int _help(char **args)
{
  int i;
  _putchar("Stephen Brennan's LSH\n");
  _putchar("Type program names and arguments, and hit enter.\n");
  _putchar("The following are built in:\n");

  for (i = 0; i < num_builtins(); i++) {
    _putchar("  %s\n", builtin_str[i]);
  }

  _putchar("Use the man command for information on other programs.\n");
  return 1;
}
