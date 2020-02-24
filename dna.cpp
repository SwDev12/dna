#include <stdio.h>
//#include <string.h>

#define MAX_LENGTH 3001
#define CAPACITY 20000

char input[MAX_LENGTH];
unsigned len;

struct word {
    struct word *a;
    struct word *c;
    struct word *g;
    struct word *t;
    unsigned len;
    unsigned cnt;
};

struct word word_arr[CAPACITY];
static struct word *curr;

struct word *alloc(void)
{
    curr->a = 0;
    curr->c = 0;
    curr->g = 0;
    curr->t = 0;
    curr->len = 0;
    curr->cnt = 0;

    return curr++;
}

unsigned strlen(char *str)
{
    unsigned length;

    for (length = 0; str[length] != '\0'; length++);

    return length;
}

void solve(unsigned *uniq_len, unsigned *uniq_num)
{
    (void)uniq_len;
    (void)uniq_num;
    unsigned start;
    unsigned end;

    curr = word_arr;

    for (unsigned length = 1; length <= len; len++) {
        for (start = 0; start < len; start++) {

        }
    }
}

int main(void)
{
    unsigned cases;

    scanf("%d", &cases);
    cases++;
    printf("cases = %d\n", cases);

    printf("sizeof(struct word) = %zu\n", sizeof(struct word));
    for (unsigned c = 1; c < cases; c++) {
        scanf("%s", input);
        len = strlen(input);
        printf("len = %u\n", len);
    }

    return 0;
}
