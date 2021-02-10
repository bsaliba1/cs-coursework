#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int main(int argc,char **argv) {

	if (argc != 2) {
		printf("Arguments to %s is an abstract number to analyze\n",argv[0]);
		exit(1);
	}

	union {
		float f;
		int i;
		unsigned char c[4];
	} representations;

	bool negative;

	representations.f=atof(argv[1]);
	printf("%s = (float    ) %12f = %g = 0x%08x = (char) %02x %02x %02x %02x\n",argv[1],representations.f,representations.f,representations.i,representations.c[0],representations.c[1],representations.c[2],representations.c[3]);
	negative=(representations.i & 0x80000000);
	unsigned int EXP=(representations.i & 0x7f800000)>>23;
	unsigned int FRAC=(representations.i & 0x007fffff);

	printf("   Sign=%s or %c\n",negative?"true":"false",negative?'-':'+');

	if (EXP==255) {
			printf("   Special case... bits EXP is 255...");
			if (FRAC==0) {
				printf(" and FRAC bits are zero... abstract values is %c infinity.\n",negative?'-':'+');
			} else {
				printf(" and FRAC bits are non-zero... abstract value is %c Not a Number (NaN)\n",negative?'-':'+');
			}
	} else {
		printf("   EXP bits=0x%02x =%u Abstract exponent=%d\n",EXP,EXP,EXP-127);
		float abstract_frac;
		// Special case if exponent bits are zero
		if (EXP==0) {
			printf("   Special case... EXP bits are zero... ignore implied 1.xxx in abstract fraction.\n");
			abstract_frac=((float)FRAC/(float)0x00800000);
		} else {
			abstract_frac=1.0 + ((float)FRAC/(float)0x00800000);
		}
		printf("   FRAC bits=0x%06x Abstract fraction=%f\n",FRAC,abstract_frac);
	}




   exit(0);

}