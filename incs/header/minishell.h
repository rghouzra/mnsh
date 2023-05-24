#ifndef MINISHELL_H
# define MINISHELL_H

# include "header.h"

#ifdef __linux__
       #include <readline/readline.h>
       #include <readline/history.h>
#elif defined(__APPLE__) && defined(__MACH__)
# include "readline/history.h"
# include "readline/readline.h"
#endif
# include <errno.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <termios.h>
# include <unistd.h>
#endif
