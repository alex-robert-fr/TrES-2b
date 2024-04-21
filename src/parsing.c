#include "parsing.h"
#include "manage_files.h"

void	clear_buffer(char *buf) {
	int	i = 0;

	while (i < BUFFER_SIZE) {
		buf[i] = '\0';
		i++;
	}
}

int	split_line(char *buffer, char *dest, int start) {
	int	i = start, j = 0;
	while (buffer[i] != '\n') {
		dest[j] = buffer[i];
		i++;
		j++;
	}
	return (i + 1);
}
