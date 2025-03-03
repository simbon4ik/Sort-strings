#include <stdio.h>
#include <stdlib.h>

int getint(int *cnt,int a,int b){
                int op = 0;
                do {
                        op = scanf("%d", cnt);
			if (op == EOF){
				return EOF;
                        }
                        if ((op == 0) || (a>(*cnt)) || ((*cnt) > b)){
				printf("Повторите ввод \n");
				op = 0;
                        	scanf("%*[^\n]");
                        }
           		if (op == 1){
                        	return 1;
                        }
                }while (op == 0);
	return op;
}
