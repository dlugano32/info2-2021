
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BLKSIZE 1024

void *copyfilepass(void *fds);
int copyfile(int fromfd, int tofd);

int main (int argc, char *argv[]) {
   int error;
   int fds[2];
   pthread_t tid;


   if (((fds[0] = open(argv[1], O_RDONLY)) == -1) ||
       ((fds[1] = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1)) {
      perror("Falla en la apertura de los archivos");
      return 1;
   }
   if ( (error = pthread_create(&tid, NULL, copyfilepass, fds) ) )
   {
      fprintf(stderr, "Falla pthread_create: %s\n", strerror(error));
      return 1;
   }
   pthread_join(tid, NULL);
   return 0;
}

void *copyfilepass(void *fds)
{
       int *fdsint;
       int ret;

       fdsint = (int *)fds;
       ret = copyfile(fdsint[0], fdsint[1]);
       close(fdsint[0]);
       close(fdsint[1]);

       pthread_exit(NULL);
}

int copyfile(int fromfd, int tofd) {
   int bytesread;
   char buf[BLKSIZE];
   int totalbytes = 0;
   struct stat stat;
   int sizeFile;

   fstat( fromfd, &stat );
   sizeFile = stat.st_size;

   printf("Tamaño del archivo: %d\n", sizeFile);

   while ((bytesread = read(fromfd, buf, BLKSIZE)) > 0)
   {
       write(tofd, buf, bytesread);
        totalbytes += bytesread;
   }

   printf("Cantidad de bytes copiados: %d\n", totalbytes);

   return bytesread;

}
