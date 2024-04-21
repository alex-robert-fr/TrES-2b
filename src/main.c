#include "manage_files.h"

int	main(void) {
	char	buffer[BUFFER_SIZE];
	char	*p_buf = buffer;
	int	fd = 0;

	fd = open_file();
	read_file(fd, p_buf);
	close_file(fd);
	return (0);
}
