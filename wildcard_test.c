#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <fnmatch.h>

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// bool ft_fnmatch(const char *filename, const char *pattern) {
//     while (*filename && *pattern) {
//         if (*pattern == '?') {
//             // Matches any single character
//             filename++;
//             pattern++;
//         } else if (*pattern == '*') {
//             // Matches any sequence of characters
//             const char *nextPattern = pattern + 1;
//             if (*nextPattern == '\0') {
//                 // Trailing '*' matches everything
//                 return true;
//             }
//             while (*filename) {
//                 if (fnmatch(filename, nextPattern)) {
//                     return true;
//                 }
//                 filename++;
//             }
//             return false;
//         } else {
//             // Regular character comparison
//             if (*filename != *pattern) {
//                 return false;
//             }
//             filename++;
//             pattern++;
//         }
//     }

//     if (*filename == '\0' && *pattern == '\0') {
//         return true;
//     }

//     return false;
// }

// int main() {
//     const char *filename = "example.txt";
//     const char *pattern = "*.txt";

//     if (fnmatch(filename, pattern)) {
//         printf("Pattern matches the filename!\n");
//     } else {
//         printf("Pattern does not match the filename.\n");
//     }

//     return 0;
// }

#include "/Users/rghouzra/mnsh/libs/libmylist/my_list.h"
int file_ismatch(char *file, char *to_match)
{
    int        i;
    int        j;

    i = 0;
    j = 0;
    while (file[i] && to_match[j]) 
    {
        if (to_match[j] == '*')
        {
            if (!to_match[j + 1])
                return (1);
            while (file[i])
            {
                if (file_ismatch(file + i, to_match + j + 1))
                    return (1);
                i += 1;
            }
            return (0);
        }
        if (file[i] != to_match[j])
            return (0);
        i += 1;
        j += 1;
    }
    return ((!file[i]) && (!to_match[j]));
}

t_my_list	*pattern_matching(char *patter)
{
	DIR	*dir;
	struct dirent *entry;
	t_my_list	*matched_pattern;

	matched_pattern = NULL;
	dir = opendir(".");
	if(dir == NULL)
		return (NULL);
	entry = readdir(dir);
	while(entry)
	{
		if(file_ismatch(entry->d_name, patter) == 1)
			printf("%s\n", entry->d_name);
		entry = readdir(dir);
	}
	closedir(dir);
	return NULL;
}
int main(int argc, char **argv) {
	pattern_matching("*");
}