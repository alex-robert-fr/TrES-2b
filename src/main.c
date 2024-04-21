#include "manage_files.h"

int	main(void) {
	int	fd = 0;

	fd = open_file();
	read_file(fd);
	close_file(fd);
	return (0);
}
