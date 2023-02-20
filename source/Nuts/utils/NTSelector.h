typedef struct __SEL {
    int x;
    char *(*call)(struct __SEL *str, int y);
} SEL;
