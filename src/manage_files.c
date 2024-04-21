#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include "manage_files.h"

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
			j = 0;
			while (tmp_buf[i] != '\n') {
				buf[j] = tmp_buf[i];
				i++;
				j++;
			}
			i++;
			j = 0;
			while (buf[j]) {
				write(1, &buf[j], 1);
				j++;
			}
			printf("\n%i | ----------\n", j);
			j = 0;
			while (j < BUFFER_SIZE) {
				buf[j] = '\0';
				j++;
			}
		}
	}
/*
	int		len = 0;
	int readint = 0;
	while ((readint = read(fd, buf, 255)) > 0) {
		printf("%i\n", readint);
		len = strlen(buf);
		printf("LEN: %i\n", len);
		int	i = 0;
		char file_text[readint];
		while (i < readint) {
			file_text[i] = buf[i];
			i++;
		}
		file_text[i] = '\0';
		printf("READ : %s\n", file_text);
	}
	printf("fin\n");
	*/
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
