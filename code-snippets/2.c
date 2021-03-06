// CVE-2021-38160
// data corruption or loss can be triggered by an untrusted device that supplies a buf->len value exceeding the buffer size.
#include <stdio.h>
#include <string.h>

struct buffer
{
    char *buf;   // Message string
    size_t size; // Size of string
    size_t len;  // Length occupied
};

// Define a min function
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main()
{
    char buf0buf[] = "This is a message";
    struct buffer buf0 = {buf0buf, 0, 0};
    struct buffer *buf;
    buf = &buf0;
    size_t length = 20;
    buf->size = strlen(buf->buf);
    // Fix for Buffer Overflow
    buf->len = MIN(buf->size, length);
    return 0;
}
