#ifndef MANAGE_FILES_H
# define MANAGE_FILES_H
# define FILENAME	"TrES.2b"
# define BUFFER_SIZE 512

void manage_file(void);
int		open_file(void);
void	read_file(int fd, char *buf);
void	close_file(int fd);

#endif
