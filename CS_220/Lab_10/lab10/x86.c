#include <stdio.h>

int func1(int a, int b);
int func2(int a);

enum flavors {
	vanilla,
	chocolate,
	strawberry,
	coffee,
	tuttifrutti
};

int func3(enum flavors t);

int main() {
	int a1=func2(5);
	int b1=func3(chocolate);
	int result=func1(a1,b1);
	printf("Result=%d\n",result);
	return 0;
}

int func1(int a, int b) {
	int c=0;
	if(a>b){
		c=1;
	}else if(b>a){
		c=-1;	
	}else{
		c=0;
	}
	return c;
}

int func2(int a) {
	int x=0;
	int y=3;
	while(x<a){
		y+=a;
		x+=1;
	}
	return y;
}

int func3(enum flavors t) {
	int like=0;
	switch(t){
		case 0:
			like=10;
			break;
		case 1:
			like=7;
			break;	
		case 2:
			like =-6;
			break;
		case 4:
			like=6;
			break;
		default:
			like=-2;
	}	
	return like;
}
