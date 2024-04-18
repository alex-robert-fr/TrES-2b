#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

int	main(void) {
	write(1, "Hello\n", 6);

	DIR	*dir;
	struct dirent	*entry;
	char	*filename = NULL;
	FILE	*file_ptr = NULL;
	char	line[1024];
	dir = opendir("./");
	if (!dir)
	{
		printf("error\n");
		exit(1);
	}
	while ((entry = readdir(dir)) != NULL) {
		printf("%s\n", entry->d_name);
		if (entry->d_type == DT_REG && !strcmp(entry->d_name, "TrES.2b")) {
			printf("\033[31m[ Find ]\033[0m\n");
			filename = entry->d_name;
			break ;
		}
	}
	printf("NAME IS : %s\n", filename);
	file_ptr = fopen(filename, "r");
	if (!file_ptr)
	{
		perror("ERROR");
		exit(1);
	}
	while (fgets(line, sizeof(line), file_ptr) != NULL) {
		printf("- %s", line);
	}
	fclose(file_ptr);
	closedir(dir);
	return (0);
}
