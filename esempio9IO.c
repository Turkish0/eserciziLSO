#include <stdio.h>     /* perror */
#include <errno.h>     /* perror */
#include <unistd.h>    /* write, lseek, close, exit */
#include <sys/types.h> /* open, lseek */
#include <sys/stat.h>  /* open */
#include <fcntl.h>     /* open */
char    buf1[] = "abcdefghij";
char    buf2[] = "ABCDEFGHIJ";
int main(void){
    int fd;
    if ((fd = open("file.hole", O_RDWR|O_CREAT, S_IRWXU)) < 0)
        perror("open error");   
    if (write(fd, buf1, 10) != 10)
        perror("buf1 write error");  
         /* L'offset ora e' 10 */   
    
    if (lseek(fd, 20, SEEK_SET) == -1)
        perror("lseek error");   
        /* L'offset ora e' 20 */   

    if (write(fd, buf2, 10) != 10)
        perror("buf2 write error");   
        /* L'offset ora e' 30 */   
    close(fd);   
return 0;
}