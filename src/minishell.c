#include "minishell.h"
#include <readline/readline.h>
#include <string.h>

int main(void)
{
    char *line;

    while (1)
    {
        line = readline("$prompt>");
        add_history(line);
        printf("line: %s\n", line);
        free(line);
    }
    return (0);
}
