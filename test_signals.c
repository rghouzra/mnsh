#include <libc.h>
#include <ctype.h>
#include <signal.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <string.h>
int is_runing;
void signal_handler(int sig)
{
	if(is_runing)
		return ;
	printf("sig->%d\n", sig);
}

void 
ft_putstr(char *line, int option)
{
	char *s;
	int signald = 0;
	if(option == 0)
	{
		if(strcmp(line, "test") == 0)
		{
			signald = 1;
			if(fork() == 0)
			while(1)
			{
				signal(SIGINT, SIG_DFL);
				line = readline("test>");
				if(!line)
					exit(1);
				ft_putstr(line, 1);
				
			}
			else
				waitpid(-1, 0, 0);
		signal(SIGINT, signal_handler);
		is_runing = 0;
		return ;
	}
	}
	s = line;
	while(*line)
	{
		if (option)
			*line = toupper(*line);
		else
			*line = tolower(*line);
		write(1, line, 1);
		line++;
	}
	write(1, "\n", 1);
	line = s;
	if(signald)
		signal(SIGINT, signal_handler);

}
int main()
{
	char *line;

	is_runing = 0;
	while(1)
	{
		signal(SIGINT, signal_handler);
		line = readline("$ > ");
		if(!line)
			break;
		ft_putstr(line, 0);
		free(line);
	}
	return 0;
}