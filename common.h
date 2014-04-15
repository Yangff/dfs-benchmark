#ifndef _COMMON_H_
#define _COMMON_H_

#ifndef STACK_MAX
#define STACK_MAX 10000000
#endif
unsigned long long stack[STACK_MAX], bak;

#define _STACK_BEGIN			\
asm __volatile__				\
(								\
	"mov %%rsp, %0\n\t"			\
	"mov %1, %%rsp\n\t":		\
	"=g"(bak):					\
	"g"(stack + STACK_MAX - 1):	\
);

#define _STACK_END				\
asm __volatile__				\
(								\
	"mov %0, %%rsp\n\t":		\
	:							\
	"g"(bak)					\
);

#include <ctime>
#include <cstdio>

#define START_TIME static clock_t common_start = clock();

#define END_TIME printf("%d %d\n", clock() - common_start, CLOCKS_PER_SEC);

#endif
