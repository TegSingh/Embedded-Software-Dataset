// CVE - 2021 - 29154
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define unlikely(x) __builtin_expect(!!(x), 0)
#define BPF_MAX_INSN_SIZE 128

struct prog
{
    int len;
};

int do_jit(struct prog prog, int oldproglen, int *addrs)
{
    int proglen = 120;
    int ilen = BPF_MAX_INSN_SIZE;
    for (int i = 0; i < prog.len; i++)
        if (unlikely(proglen + ilen > oldproglen))
            return -1;
}

int main()
{
    int proglen, oldproglen = 0;
    struct prog prog = {100};
    int addrs[prog.len];
    int i = 0;
    for (proglen = 0, i = 0; i < prog.len; i++)
    {
        proglen += 64;
        addrs[i] = proglen;
    }

    proglen = do_jit(prog, oldproglen, addrs);
    return 0;
}