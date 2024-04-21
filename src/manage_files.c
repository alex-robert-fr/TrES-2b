#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include "manage_files.h"
#include "parsing.h"

int	open_file(void) {
	int	fd = 0;

	fd = open(FILENAME, O_RDONLY);
	if (fd == -1) {
		perror("Erreur à l'ouverture du fichier");
		exit(1);
	}
	else {
		printf("Fichier ouvert fd: %i\n", fd);
	}
	return (fd);
}

void	read_file(int fd, char *buf) {
	char tmp_buf[BUFFER_SIZE];
	int char_read = 0;
	int	i = 0, j;

	while ((char_read = read(fd, tmp_buf, BUFFER_SIZE)) > 0) {
		printf("char_read: %i\n", char_read);
		while (i < char_read) {
			i = split_line(tmp_buf, buf, i);
			j = 0;
			while (buf[j]) {
				write(1, &buf[j], 1);
				j++;
			}
			printf("\n%i | ----------\n", j);
			clear_buffer(buf);
		}
	}
}

void	close_file(int fd) {
	close(fd);
}

void manage_file(void) {
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
		if (!strcmp(entry->d_name, "TrES.2b")) {
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

}
