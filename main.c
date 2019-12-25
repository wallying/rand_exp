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
����: ����[a, b)��������������
�㷨: random = (rand() % (b - a)) + a;
֤��: ����rand()������������[0, RAND_MAX]������������,
      ����(rand() % N)��������[0, N)������������,
      ���[a, N + a)������������,����ͨ��(rand() % N) + a���ʽ����,
      �����b = N + a,��N = b - a,
      ����[a, b)������������,�Ϳ���ͨ��(rand() % (b - a)) + a���ʽ����.
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
