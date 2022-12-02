#include "main.h"
/**
 * main - entry
 * 
*/
int main(void)
{
    int status = 1;
    char *line;
    char **args;

    while (status == 1)
    {
        status = isatty(0);

        if (status == 1)
            write(1,"$ ", 2);
        line = read_line();
        args = split_line(line);

        if (args == NULL)
        {
            isatty(0);
        }
        status = exec(args);
        free(args);
        free(line);
        status= isatty(0);
    }
    return(0);
}