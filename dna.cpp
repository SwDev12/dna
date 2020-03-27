#include <stdio.h>
//#include <string.h>

#define MAX_LENGTH 3001
#define CAPACITY 20000

char input[MAX_LENGTH];
unsigned len;
unsigned uniq_len, uniq_num;

struct word {
    struct word *a;
    struct word *c;
    struct word *g;
    struct word *t;
    unsigned cnt;
};

struct word word_arr[MAX_LENGTH * MAX_LENGTH / 2];
static struct word *curr;
static struct word root;
//static struct word *word_it;

struct word *alloc(void)
{
    curr->a = curr->c = curr->g = curr->t = 0;
    curr->cnt = 0;
    return curr++;
}

unsigned strlen(char *str)
{
    unsigned length;

    for (length = 0; str[length] != '\0'; length++);

    return length;
}

void solve(void)
{
    unsigned limit;
    unsigned nodes;
    unsigned last_uniq_capacity;
    unsigned end;
    register struct word *word_it;

    curr = word_arr;
    root.a = root.c = root.g = root.t = 0;

    for (unsigned length = 0; length < len; length++) {
//        printf("length = %u\n", length);
        limit = len - length;
//        printf("length = %u, endee = %u\n", length, end);
        nodes = 0;
        last_uniq_capacity = 0;
        for (unsigned start = 0; start < limit; start++) {
//            printf("start = %u, endee = %u\n", start, end);
            word_it = &root;
            end = start + length;
            register unsigned i;
            for (i = start; i < end; i++) {
                switch (input[i]) {
                case 'a':
                    word_it = word_it->a;
                    break;
                case 'c':
                    word_it = word_it->c;
                    break;
                case 'g':
                    word_it = word_it->g;
                    break;
                case 't':
                    word_it = word_it->t;
                    break;
                }

            }
            switch (input[i]) {
            case 'a':
                if (word_it->a == 0) {
                    word_it->a = alloc();
                    word_it = word_it->a;
                    word_it->cnt = 1;
                    nodes++;
                } else {
                    word_it = word_it->a;
                    if (word_it->cnt == 1) {
                        last_uniq_capacity++;
                    }
                    word_it->cnt++;
                }
                break;
            case 'c':
                if (word_it->c == 0) {
                    word_it->c = alloc();
                    word_it = word_it->c;
                    word_it->cnt = 1;
                    nodes++;
                } else {
                    word_it = word_it->c;
                    if (word_it->cnt == 1) {
                        last_uniq_capacity++;
                    }
                    word_it->cnt++;
                }
                break;
            case 'g':
                if (word_it->g == 0) {
                    word_it->g = alloc();
                    word_it = word_it->g;
                    word_it->cnt = 1;
                    nodes++;
                } else {
                    word_it = word_it->g;
                    if (word_it->cnt == 1) {
                        last_uniq_capacity++;
                    }
                    word_it->cnt++;
                }
                break;
            case 't':
                if (word_it->t == 0) {
                    word_it->t = alloc();
                    word_it = word_it->t;
                    word_it->cnt = 1;
                    nodes++;
                } else {
                    word_it = word_it->t;
                    if (word_it->cnt == 1) {
                        last_uniq_capacity++;
                    }
                    word_it->cnt++;
                }
                break;
            }
            //printf("%c", input[i]);
//          printf("\n");
        }
//        printf("nodes = %u, last_uniq_capacity = %u\n", nodes, last_uniq_capacity);
        if (nodes > last_uniq_capacity) {
//            printf("Looks like is answer\n");
            uniq_len = length + 1;
            uniq_num = nodes - last_uniq_capacity;
//          printf("uniq_len = %u, uniq_num = %u\n", uniq_len, uniq_num);
            return;
        } else if (length == 0) {
//            printf("We are here, root.a = %p, cnt = %u\n", root.a, root.a->cnt);
            uniq_num = length + 1;
            if (root.a && root.a->cnt == len) {
                uniq_len = root.a->cnt;
                break;
            } else if (root.c && root.c->cnt == len) {
                uniq_len = root.c->cnt;
                break;
            } else if (root.g && root.g->cnt == len) {
                uniq_len = root.g->cnt;
                break;
            } else if (root.t && root.t->cnt == len) {
                uniq_len = root.t->cnt;
                break;
            }
        }
    }
}

int main(void)
{
    unsigned cases;

    scanf("%d", &cases);
    cases++;
    //printf("cases = %d\n", cases);

//    printf("sizeof(struct word) = %zu\n", sizeof(struct word));
    for (unsigned c = 1; c < cases; c++) {
        scanf("%s", input);
        len = strlen(input);
//        printf("len = %u\n", len);
        solve();
        printf("#%u %u %u\n", c, uniq_len, uniq_num);
    }

    return 0;
}
