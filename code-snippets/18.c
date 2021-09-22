// CVE - 2021 - 29266
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct event_fd_ctx
{
    char *buf;
    size_t len;
};

struct vhost_vdpa
{
    struct event_fd_ctx config_ctx;
} v0, *v;

static void vhost_vdpa_config_put(struct vhost_vdpa *v)
{
    if (&v->config_ctx)
    {
        printf("%s : %ld \n", v->config_ctx.buf, v->config_ctx.len);
        v->config_ctx.buf = "";
        v->config_ctx.len = 0;
    }
}

int main()
{
    char buf0buf[] = "This is a message";
    struct vhost_vdpa v0 = {buf0buf, strlen(buf0buf)};
    struct vhost_vdpa *v;
    v = &v0;
    vhost_vdpa_config_put(v);
    return 0;
}