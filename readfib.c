#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_wk.h"

static void add_str(char *a, char *b, char *out)
{
    size_t size_a = strlen(a), size_b = strlen(b);
    int i, sum, carry = 0;
    if (size_a >= size_b) {
        for (i = 0; i < size_b; i++) {
            sum = (a[i] - '0') + (b[i] - '0') + carry;
            out[i] = '0' + sum % 10;
            carry = sum / 10;
        }

        for (i = size_b; i < size_a; i++) {
            sum = (a[i] - '0') + carry;
            out[i] = '0' + sum % 10;
            carry = sum / 10;
        }
    } else {
        for (i = 0; i < size_a; i++) {
            sum = (a[i] - '0') + (b[i] - '0') + carry;
            out[i] = '0' + sum % 10;
            carry = sum / 10;
        }

        for (i = size_a; i < size_b; i++) {
            sum = (b[i] - '0') + carry;
            out[i] = '0' + sum % 10;
            carry = sum / 10;
        }
    }

    if (carry)
        out[i++] = '0' + carry;
    out[i] = '\0';
}

static char *fib_sequence(long long k)
{
    str_t *f = malloc((k + 2) * sizeof(str_t));

    strncpy(f[0].numberStr, "0", 1);
    f[0].numberStr[1] = '\0';
    strncpy(f[1].numberStr, "1", 1);
    f[1].numberStr[1] = '\0';

    for (int i = 2; i <= k; i++) {
        add_str(f[i - 1].numberStr, f[i - 2].numberStr, f[i].numberStr);
    }
    size_t retSize = strlen(f[k].numberStr);
    reverse_str(f[k].numberStr, retSize);
    f[k].numberStr[retSize] = '\0';
    return f[k].numberStr;
}

int main()
{
    int offset = 500;

    for (int i = 0; i <= offset; i++) {
        char *read_buf;
        read_buf = fib_sequence(i);
        printf(
            "Reading from FIB_DEV"
            " at offset %d, returned the sequence "
            "%s.\n",
            i, read_buf);
    }
}
