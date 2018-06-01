#include "csapp.h"


int main(int argc, char **argv)   //10_7
{
    int n, MAX_BUF;
    rio_t rio;
    char buf[MAX_BUF];

    Rio_readinitb(&rio, STDIN_FILENO);
    while ((n = Rio_readlineb(&rio, buf, MAXBUF)) != 0)
        Rio_writen(STDOUT_FILENO, buf, n);
}
