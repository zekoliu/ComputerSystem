#include "csapp.h"

void *thread(void *vargp);

#define DEFAULT 4

int main(int argc, char **argv)
{
    int N;
    if (argc > 2)
        unix_error("too many param");
    else if (argc == 2)
        N = atoi(argv[1]);
    else
        N = DEFAULT;

    pthread_t tid;
    int i;
    for (i = 0; i < N; i++) {
        Pthread_create(&tid, NULL, thread, NULL);
    }
    Pthread_join(tid, NULL);
    exit(0);
}

void *thread(void *vargp)
{
    printf("Hello World!\n");
    return NULL;
}
