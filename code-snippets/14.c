// CVE-2021-28972
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_DRC_NAME_LEN 64

char *strscpy(char *dest, const char *src, size_t n)
{
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];

    return dest;
}

size_t add_slot_source(const char *buf, size_t nbytes)
{
    char drc_name[MAX_DRC_NAME_LEN];
    char *end;
    int rc;

    // No size handling

    strscpy(drc_name, buf, nbytes + 1);
    printf("String copied successfully\n");

    // add comments and document these changes
    end = strchr(drc_name, '\n');
    if (end)
        *end = '\0';

    return nbytes;
}

int main()
{
    char buf[] = "This is a message and this is supposed to be higher than the drc name value specified such that a user-controlled buffer overflow occurs";
    size_t nbytes = strlen(buf);
    size_t rv = add_slot_source(buf, nbytes);
    printf("%ld\n", rv);
    return 0;
}