// CVE-2021-28375
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define FASTRPC_INIT_HANDLE 1

static int fastrpc_internal_invoke(int kernel, int handle)
{
    if (handle == FASTRPC_INIT_HANDLE && !kernel)
    {
        printf("User app trying to send RPC messages\n");
        return -EPERM;
    }

    return 1;
}

int main()
{
    int n;
    n = fastrpc_internal_invoke(0, 1);
    return 0;
}