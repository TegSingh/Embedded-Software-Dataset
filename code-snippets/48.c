// CVE-2021-28972
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_DRC_NAME_LEN 64

char *strscpy(char *dest, const char *src, size_t n)
{
    size_t i = 0;

    while (i < n && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    return dest;
}

size_t add_slot_source(const char *buf, size_t nbytes)
{
    char drc_name[MAX_DRC_NAME_LEN];
    char *end;
    int rc;

    if (nbytes >= MAX_DRC_NAME_LEN)
        return 0;

    strscpy(drc_name, buf, nbytes + 1);
    printf("String copied successfully\n");

    end = strchr(drc_name, '\n');
    if (end)
        *end = '\0';

    return nbytes;
}

int main()
{
    char buf[] = "This is a short message";
    size_t nbytes = strlen(buf);
    size_t rv = add_slot_source(buf, nbytes);
    printf("%ld\n", rv);
    return 0;
}