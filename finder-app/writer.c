#include <syslog.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

// argv[1] = filePath; argv[2] = text
int main(int argc, char* argv[]){
	ssize_t nr;
	int fd;
	openlog( "writer", LOG_PID, LOG_USER );
	
	if (argc < 2){
		syslog(LOG_ERR, "Required 2 arguments, given %d", argc);
		return EXIT_FAILURE;
	}

	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC,
			S_IWUSR | S_IRUSR | S_IWGRP | S_IRGRP | S_IROTH);
	if (fd == -1){
		syslog(LOG_ERR, "File open error: %s", strerror(errno));
		return EXIT_FAILURE;
	}

	nr = write(fd, argv[2], strlen(argv[2]));
	if (nr == -1)
		syslog(LOG_ERR, "Write error: %s", strerror(errno));


	closelog();
	close(fd);
	return 0;
}

