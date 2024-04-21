TARGET	=	TrES
CC			= gcc
CFLAGS	= -Wall -Wextra -Wpedantic -Wformat=2 -Wshadow -Wwrite-strings -Wstrict-prototypes -Wold-style-definition -Wredundant-decls -Wnested-externs -Wmissing-include-dirs -I./includes
LDFLAGS	=	-g
SOURCES =	./src/main.c	\
					./src/manage_files.c	\
					./src/parsing.c
OBJECTS	=	$(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

clean:
	rm -rf $(OBJECTS) $(TARGET)
	rm -f ./test_exec/massif.out.*

re: clean all

run: all
	cd ./test_exec && ../$(TARGET)

memory: all
	cd ./test_exec && valgrind --leak-check=full ../$(TARGET)

profiler: re
	cd ./test_exec && valgrind --tool=massif ../$(TARGET)
	ms_print test_exec/massif.out.*

.PHONY: all clean re run memory
