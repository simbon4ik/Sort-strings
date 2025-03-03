#include <stdio.h>
#include "input.h"      //Для getintа
#include "mystring.h"   //Для ридлайна
#include <limits.h> //Для int_max
#include <stdlib.h>

int main(){
	int type = 0;
    char* file_in = readline2("Введите имя входного файла:\n");
    char* file_out = readline2("Введите имя выходного файла:\n");
    puts("Выберите: Выбор алгоритма сортировки\n1. Сортировка строк во всем файле\n2. Сортировка внутри каждой строки по словам\n");
    int op = getint(&type,0,INT_MAX);
	if (op == -1) return 0; //Обработка неккоректного ввода
	switch(type){
		case 1:
		//	stats = sortik(slova,number,napravl,len);
			break;
		case 2:
			//stats = sortik(slova,number,napravl,len);
			break;
		default:
			puts("Введите число от 1 до 2 \n");
	}
    free(file_in);
    free(file_out);
	return 0;
}
