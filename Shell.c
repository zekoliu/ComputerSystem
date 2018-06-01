#include "csapp.h"

void eval(char *cmdline);
int parseline(char *buf, char **argv);
int builitin_command(char **argv);

int main()
{
    char cmdline[MAXLINE];

    while (1) {
        printf(">");
        Fgets(cmdline, MAXLINE, stdin);
        if (feof(stdin))
            exit(0);

        eval(cmdline);
    }
}

void eval(char *cmdline)
{
    char *argv[MAXLINE];
    char buf[MAXLINE];
    char *build_in_argv[MAXLINE] = {"/bin/ls", "/bin/ping", "/src/bintree",
                                    "/bin/cp", "/src/bin/find"};
    int bg, i;
    pid_t pid;

    strcpy(buf, cmdline);
    bg = parseline(buf, argv);
    if (argv[0] == NULL)
        return;

    if (!builitin_command(argv)) {
        if ((pid = Fork()) == 0) {
            for (i = 0; i < strlen(build_in_argv); i++)
            {
                if (build_in_argv[i] == argv[0]) {      //8_26_1
                    execve(build_in_argv[i], argv, environ);
                    exit(0);
                    break;
                }
            }

            if ((i == strlen(build_in_argv) && (execve(argv[0], argv, environ) < 0))) {
                printf("%s: Command not found.\n", argv[0]);
                exit(0);
            }


            if (argv[strlen(argv) - 1] == "&")      //8_26_3
                ;
        }
        if (!bg) {
            int status;
            if (waitpid(pid, &status, 0) < 0)
                unix_error("waitfg: waitpid error");
        } else
            printf("%d %s", pid, cmdline);
    }
    return;
}

int builitin_command(char **argv)
{
    if (!strcmp(argv[0], "quit"))
        exit(0);
    if (!strcmp(argv[0], "&"))
        return 1;
    return 0;
}

int parseline(char *buf, char **argv)
{
    char *delim;
    int argc;
    int bg;

    buf[strlen(buf)-1] = ' ';
    while (*buf && (*buf == ' '))
        buf++;

    argc = 0;
    while ((delim = strchr(buf, ' '))) {
        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf && (*buf == ' '))
            buf++;
    }
    argv[argc] = NULL;

    if (argc == 0)
        return 1;

    if ((bg = (*argv[argc-1] == '&')) != 0)
        argv[--argc] = NULL;

    return bg;
}

