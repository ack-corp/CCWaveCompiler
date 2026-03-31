// cc -g3 -O0 -fno-omit-frame-pointer -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wformat=2 -Wstrict-prototypes -Werror main.c -o main
// bash-5.2$ valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main
// ==888551== Memcheck, a memory error detector
// ==888551== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
// ==888551== Using Valgrind-3.26.0 and LibVEX; rerun with -h for copyright info
// ==888551== Command: ./main
// ==888551== 
// 1==888551== 
// ==888551== HEAP SUMMARY:
// ==888551==     in use at exit: 4 bytes in 1 blocks
// ==888551==   total heap usage: 2 allocs, 1 frees, 1,028 bytes allocated
// ==888551== 
// ==888551== 4 bytes in 1 blocks are definitely lost in loss record 1 of 1
// ==888551==    at 0x483FB26: malloc (vg_replace_malloc.c:447)
// ==888551==    by 0x400487: test (main.c:37)
// ==888551==    by 0x4004EB: main (main.c:54)
// ==888551== 
// ==888551== LEAK SUMMARY:
// ==888551==    definitely lost: 4 bytes in 1 blocks
// ==888551==    indirectly lost: 0 bytes in 0 blocks
// ==888551==      possibly lost: 0 bytes in 0 blocks
// ==888551==    still reachable: 0 bytes in 0 blocks
// ==888551==         suppressed: 0 bytes in 0 blocks
// ==888551== 
// ==888551== For lists of detected and suppressed errors, rerun with: -s
// ==888551== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

// Why does it return useless line insight ? what i would like it to return is the last usage of my var, 
// Here line 59


#include <stdio.h>
#include <stdlib.h>

int *test(void)
{
    int *x = malloc(sizeof(int));
    if (x == NULL) {
        return NULL;
    }

    *x = 0;
    return x;
}

void usage(int *x)
{
    printf("%d", *x);
    (*x)++;
}

int main(void)
{
    int *x = test();
    if (x == NULL) {
        return 1;
    }
    (*x)++;
    printf("%d", *x);
    return 0;
}
