// CVE - 2021 - 3489
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BPF_RINGBUF_HDR_SZ 64

#define ROUND_UP(N, S) ((((N) + (S)-1) / (S)) * (S))

// Struct for bpf ring buffer
struct bpf_ringbuf
{
    unsigned long mask;
};

static void bpf_ringbuf_reserve(struct bpf_ringbuf *rb, unsigned long size)
{
    unsigned int len;
    len = ROUND_UP(size + BPF_RINGBUF_HDR_SZ, 8);

    if (len > rb->mask + 1)
        return NULL;

    printf("Len: %d\n", len);
    printf("Mask: %d\n", rb->mask);
}

int main()
{
    struct bpf_ringbuf rb0 = {98};
    struct bpf_ringbuf *rb;
    rb = &rb0;
    printf("Initialized bpf ring buffer\n");
    bpf_ringbuf_reserve(rb, 13);
    return 0;
}