// CVE-2021-33909
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define unlikely(x) __builtin_expect(!!(x), 0)
#define LIMIT 1000

struct seq_file
{
    char *buf;
    size_t size;
    size_t count;
};

void *seq_buffer_allocation(unsigned long size)
{
    return malloc(size);
}

int main()
{
    struct seq_file *m;
    struct seq_file n = {"", 2000, 0};
    m = &n;
    m->buf = (char *)seq_buffer_allocation(m->size);

    if (!m->buf)
    {
        printf("Memory allocation insuccessful");
    }
    else
    {
        printf("Memory allocated successfully");
    }
    return 0;
}