/**
 * file:    main.c
 * author:  wallying@foxmail.com
 * date:    2019-12-25
 **/


#include <stdio.h>
#include <stdlib.h> /* for rand() and srand() */
#include <time.h>   /* for time() */
#include <string.h> /* for memset() */


/*******************************************************************************
方法: 生成[a, b)区间的整数随机数
算法: random = (rand() % (b - a)) + a;
证明: 由于rand()函数可以生成[0, RAND_MAX]区间的整随机数,
      所以(rand() % N)可以生成[0, N)区间的整随机数,
      因此[a, N + a)区间的整随机数,可以通过(rand() % N) + a表达式生成,
      如果令b = N + a,则N = b - a,
      所以[a, b)区间的整随机数,就可以通过(rand() % (b - a)) + a表达式生成.
*******************************************************************************/

#define ARRAY_NUM (10)
int random[ARRAY_NUM] = {0x00};

static void print_rand(void)
{
    for (int i = 0; i < ARRAY_NUM; ++i) {
        printf("%6d ", random[i]);
    }
    printf("\n");

    memset(random, 0x00, sizeof(random));
}

int main(int argc, char *argv[])
{
    printf("hello rand_exp!\n");


    for (int i = 0; i < ARRAY_NUM; ++i) {
        random[i] = rand();
    }
    print_rand();


    srand(time(NULL));
    for (int i = 0; i < ARRAY_NUM; ++i) {
        random[i] = rand();
    }
    print_rand();


    printf("rand() => [0, RAND_MAX] => random = rand()\n");

    printf("rand() => [a, b) => random = (rand() %% (b - a)) + a;\n");

    printf("rand() => [a, b] => random = (rand() %% (b + 1 - a)) + a;\n");

    printf("rand() => (a, b] => random = (rand() %% (b - a)) + a + 1;\n");


    return 0;
}
