#define MAX_INT ((unsigned)(-1)>>1)
#define MIN_INT (~MAX_INT)

int myAtoi(char* str) {
    int negative = 1, min = MIN_INT, max = MAX_INT;
    char *p;
    long num = 0;
    while (str && *str == ' ') str++;

    if (str && *str == '+') {
        str++;
    } else if (str && *str == '-') {
        negative = -1;
        str++;
    }

    while (str && *str == '0') str++;

    p = str;
    while (p && *p >= '0' && *p <= '9') p++;
    if (p == str) return 0;
    else if (p - str > 10) {
        if (negative == 1) return max;
        else return min;
    }

    while (p - str > 0) {
        num = num * 10 + (*str - '0');
        str++;
    }

    num *= negative;

    if (num < min) return min;
    else if (num > max) return max;
    else return (int)num;
}
