#include "main.h"

int _cd(char **args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
        perror("Error");
    }
  }
  return 1;
}