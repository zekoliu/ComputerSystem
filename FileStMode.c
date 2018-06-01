#include "csapp.h"

int main(int argc, char **argv)       //查询和处理一个文件的描述符的st_mode位
{
    struct stat stat;
    char *type, *readok;
    int fd;

    if (argc < 0)
        return NULL;
    fd = atoi(argv[1]);

    Fstat(fd, &stat);
    if (S_ISREG(stat.st_mode))
        type = "regular";
    else if (S_ISDIR(stat.st_mode))
        type = "directory";
    else
        type = "other";
    if ((stat.st_mode & S_IRUSR))
        readok = "yes";
    else
        readok = "no";

    printf("type: %s, read: %s\n", type, readok);
