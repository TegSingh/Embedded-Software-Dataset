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

    if (nbytes >= MAX_DRC_NAME_LEN)
        return 0;

    memcpy(drc_name, buf, nbytes);
    printf("String copied successfully\n");

    end = strchr(drc_name, '\n');
    // Wrong specification of end character for string
    if (!end)
        end = &drc_name[nbytes];
    *end = '\0';

    return nbytes;
}

int main()
{
    char buf[] = "This is a message which can possibly create errors in case this message is longer than MAX_DRC_NAME_LEN";
    size_t nbytes = strlen(buf);
    size_t rv = add_slot_source(buf, nbytes);
    printf("%ld\n", rv);
    return 0;
}