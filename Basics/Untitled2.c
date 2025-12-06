#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR 1000
#define MAX_PAT  200
#define MAX_REP  200


void replace_all(const char *str, const char *pat, const char *rep, char *out, size_t out_size) {
    size_t n = strlen(str);
    size_t p = strlen(pat);
    size_t r = strlen(rep);

    if (p == 0) {
        strncpy(out, str, out_size - 1);
        out[out_size - 1] = '\0';
        return;
    }

    size_t i = 0;
    size_t j = 0;

    while (i < n) {

        if (i + p <= n && strncmp(&str[i], pat, p) == 0) {

            if (j + r >= out_size) break;
            strncpy(&out[j], rep, r);
            j += r;
            i += p; /* skip past the pattern in input (non-overlapping) */
        } else {
            /* copy single character */
            if (j + 1 >= out_size) break; /* avoid overflow */
            out[j++] = str[i++];
        }
    }

    /* copy any remaining characters */
    while (i < n && j + 1 < out_size) {
        out[j++] = str[i++];
    }

    out[j] = '\0';
}

static void strip_newline(char *s) {
    size_t L = strlen(s);
    if (L > 0 && s[L - 1] == '\n') s[L - 1] = '\0';
}

int main(void) {
    char str[MAX_STR];
    char pat[MAX_PAT];
    char rep[MAX_REP];
    char ans[MAX_STR * 2];

    printf("Enter main string (up to %d chars):\n", MAX_STR - 1);
    if (!fgets(str, sizeof str, stdin)) return 1;
    strip_newline(str);

    printf("Enter pattern string to find (up to %d chars):\n", MAX_PAT - 1);
    if (!fgets(pat, sizeof pat, stdin)) return 1;
    strip_newline(pat);

    printf("Enter replacement string (up to %d chars):\n", MAX_REP - 1);
    if (!fgets(rep, sizeof rep, stdin)) return 1;
    strip_newline(rep);

    replace_all(str, pat, rep, ans, sizeof ans);

    if (strcmp(ans, str) == 0 && strstr(str, pat) == NULL) {
        printf("Pattern not found.\n");
    } else {
        printf("The resultant string is:\n%s\n", ans);
    }

    return 0;
}
