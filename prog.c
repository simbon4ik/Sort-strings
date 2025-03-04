#include <stdio.h>
#include <limits.h> //Для int_max
#include <stdlib.h>
#include <string.h>
#include "mystring.h"
#include "input.h"      //Для getintа
#include "library.h"   //Для работы с файлами

#define default_len_array 10
#define default_len 40

void clear_array(char** array, int len){
    for (int i = 0; i < len; ++i){
        free(array[i]);
    }
    free(array);
}

int main(){
    int len = default_len;
	int type = 0;

    char** array_string_file = (char**)malloc(default_len_array * sizeof(char*));        //Создаем массив строк (которые считаем из файла)

    int op = inputfile(&array_string_file, &len);       //Считываем массив строк из файла
    if (op != 0){
        clear_array(array_string_file, default_len_array);
        return 1;
    }
    printf("Выберите: Выбор алгоритма сортировки\n1. Сортировка строк во всем файле\n2. Сортировка внутри каждой строки по словам\n");
    op = getint(&type,0,INT_MAX);
	if (op == -1) return 0; //Обработка неккоректного ввода
	switch(type){
		case 1:
		    qsort(array_string_file, len, sizeof(char*), strings_comp);
			break;
		case 2:
            for (int i = 0; i < len; ++i){
			    qsort(array_string_file[i], strlen(array_string_file[i]), sizeof(char), words_comp);
            }
			break;
		default:
			puts("Введите число от 1 до 2 \n");
	}
	outfile(array_string_file, len);    //Запись в файл
    if (len < default_len_array){
        clear_array(array_string_file, default_len_array);  //Очистка памяти
    }else clear_array(array_string_file, len);  //Очистка памяти
	return 0;
}
