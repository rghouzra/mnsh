#include <dirent.h>
#include <libc.h>
#include <stdio.h>
#include <termios.h>

// Function to disable terminal echo
void	disableEcho(void)
{
	struct termios	term;

	tcgetattr(fileno(stdin), &term);
	term.c_lflag &= ~ECHO;
	tcsetattr(fileno(stdin), TCSAFLUSH, &term);
}

// Function to enable terminal echo
void	enableEcho(void)
{
	struct termios	term;

	tcgetattr(fileno(stdin), &term);
	term.c_lflag |= ECHO;
	tcsetattr(fileno(stdin), TCSAFLUSH, &term);
}

int	main(void)
{
	DIR				*dir;
	struct dirent	*entry;
	char			password[100];
	int				passwordLength;

	passwordLength = 0;
	// Open current directory
	dir = opendir(".");
	if (dir == NULL)
	{
		printf("Error opening directory.\n");
		return (1);
	}
	// Read directory entries
	// while ((entry = readdir(dir)) != NULL) {
	//     // Print only regular files
	//     if (entry->d_type == DT_REG) {
	//         printf("File: %s\n", entry->d_name);
	//     }
	// }
	closedir(dir);
	// Prompt for password
	printf("Enter password: ");
	disableEcho();
	fgets(password, sizeof(password), stdin);
	enableEcho();
	// Determine password length
	while (password[passwordLength] != '\0')
	{
		passwordLength++;
	}
	// Remove newline character from the end of the password
	if (password[passwordLength - 1] == '\n')
	{
		password[passwordLength - 1] = '\0';
		passwordLength--;
	}
	printf("\nEntered password: %s\n", password);
	return (0);
}
