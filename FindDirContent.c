#include "csapp.h"

int main(int argc, char **argv)   //一直查找目录的内容
{
    DIR *streamp, *streamp1, *temp;
    struct stat stat, stat1;
    struct dirent *dep, *dep1;

    streamp = Opendir(".");

    errno = 0;
    while ((dep = readdir(streamp)) != NULL) {
        printf("1: %s\n", dep->d_name);
        Stat(dep->d_name, &stat);

        if (S_ISDIR(stat.st_mode)) {
            streamp1 = Opendir(dep->d_name);
            while ((dep1 = readdir(streamp1)) != NULL) {
                printf("    2:%s\n", dep1->d_name);
                char *dir;
//                dir = strcat(dir, "./");
                dir = strcat(dir, dep->d_name);
                printf("fuck    %s\n", dep->d_name);
                dir = strcat(dir, "/");
                dir = strcat(dir, dep1->d_name);
                printf("%s\n", dir);
                Stat(dir, &stat1);

                if (S_ISDIR(stat1.st_mode)) {
                    temp = Opendir(dir);
                    streamp1 = temp;
                }
            }
            Closedir(streamp1);
        }
    }

    if (errno != 0)
        unix_error("readdir error");

    Closedir(streamp);
    exit(0);
}
