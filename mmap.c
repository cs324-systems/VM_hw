#include <stdio.h>
#include <stdlib.h> //yes
#include <unistd.h> //yes
#include <sys/mman.h> //yes
#include <fcntl.h>
#include <sys/types.h>//yes
#include <sys/stat.h> //yes

int main(int argc, char * argv[]) {
  int fd;
  char *bufp;
  struct stat stat;

  if (argc != 2) {
    printf("USAGE: %s <filename>\n", argv[0]);
    exit(0);
  }

  fd = open(argv[1], O_RDWR, 0);

  fstat(fd, &stat);
  
  bufp = mmap(NULL, stat.st_size, PROT_WRITE, MAP_SHARED, fd, 0);

  bufp[0] = 'J';

  return 0;
}
