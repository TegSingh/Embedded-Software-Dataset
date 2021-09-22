// CVE-2021-3491
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_RW_COUNT 64
typedef unsigned int __u32;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

// Struct for input output buffer
struct io_buffer
{
    int list[10];
    unsigned long addr;
    // unsigned int since the value should not be negative
    unsigned int len;
    unsigned int bid;
};

struct io_provide_buf
{
    struct file *file;
    unsigned long addr;
    unsigned int len;
    unsigned int bgid;
    unsigned int nbufs;
    unsigned int bid;
};

struct file
{
    int size;
};

static int io_add_buffers(struct io_provide_buf *pbuf, struct io_buffer **head)
{
    printf("io_add_buffers method called\n");
    struct io_buffer *buf;
    unsigned long int addr = 4328742;
    unsigned int bid = 10;
    buf->addr = addr;
    buf->len = MIN(pbuf->len, MAX_RW_COUNT);
    printf("Buffer length: %d\n", buf->len);
    buf->bid = bid;
    addr += pbuf->len;
    return 0;
}

int main()
{
    int list[10] = {23, 54, 11, 76, 30, 45, 98, 11, 4, 65};

    struct io_buffer iobuf0 = {list, 291870, 10, 3};
    struct file file = {1};

    struct io_provide_buf ioprovidebuf0 = {&file, 47032, 43, 12, 42, 33};
    struct io_provide_buf *pbuf;
    pbuf = &ioprovidebuf0;
    printf("Initialized io provide buffer\n");

    struct io_buffer *buf;
    buf = &iobuf0;
    printf("Initialized io buffer\n");

    int rv = io_add_buffers(pbuf, &buf);
    return 0;
}