#include <stdio.h>
#include <stdlib.h>

#define BOOL(x) (!(!(x)))

#define BitSet(arg,posn) ((arg) | (1L << (posn)))
#define BitClr(arg,posn) ((arg) & ~(1L << (posn)))
#define BitTst(arg,posn) BOOL((arg) & (1L << (posn)))
#define BitFlp(arg,posn) ((arg) ^ (1L << (posn)))

#define BITOP(a,b,op) \
 ((a)[(size_t)(b)/(8*sizeof *(a))] op ((size_t)1<<((size_t)(b)%(8*sizeof *(a)))))

int bitmanip(int word)
{
      word = BitSet(word, 2);
      word = BitSet(word, 7);
      word = BitClr(word, 3);
      word = BitFlp(word, 9);
      return word;
}

int main()
{
	int test=0xffff;
	int test1=0x0000;
	test1 |= 0x0100;
	printf("test1=%x\n",test1);
	test=BitClr(test, 6);
	printf("test=%x\n",test);
	
}
//return ((n) & ~(1L << (k-1)))