// CVE - 2021 - 37576
#include <stdio.h>
#include <string.h>
#include <errno.h>

struct rtas_args
{
    int nargs;
    int args[16];
};

int main()
{
    int arr[16] = {1, 2, 3, 4, 5, 6, 7, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    struct rtas_args old = {17, arr};
    struct rtas_args *args;
    args = &old;
    if (args->nargs >= sizeof(args->args))
    {
        return EINVAL;
    }
    else
    {
        return 0;
    }
}