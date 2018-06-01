#include "csapp.h"

int main(int argc, char **argv)       //rwx --- filename
{
    struct stat stat;
    struct dirent *dir;
    DIR *streamp;

    streamp = Opendir(argv[1]);
    while ((dir = readdir(streamp)) != NULL) {
        Stat(dir->d_name, &stat);
        if ((stat.st_mode & S_IRUSR))
            printf("r");
        else
            printf("-");
        if ((stat.st_mode & S_IWUSR))
            printf("w");
        else
            printf("-");
        if ((stat.st_mode & S_IXUSR))
            printf("x  ");
        else
            printf("-  ");
        if ((stat.st_mode & S_IROTH))
            printf("r");
        else
            printf("-");
        if ((stat.st_mode) & S_IWOTH)
            printf("w");
        else
            printf("-");
        if ((stat.st_mode) & S_IXOTH)
            printf("x  ");
        else
            printf("-  ");

        if ((dir = readdir(streamp)) != NULL)
            printf("%s\n", dir->d_name);
    }
}
