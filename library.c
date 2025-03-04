#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mystring.h"

#define default_len_array 10

int outfile(char **ptr, int len){
	char *filename = readline2("Введите имя файла txt для записи \n");
	FILE *f = fopen(filename,"a");      //Открываем файлик на дописывание в конец (если существует), иначе создаем
    for(int i = 0; i < len; ++i){
		fprintf(f, "%s\n", *(ptr+i));    //Записываем в файлик строку
	}
	fclose(f);          //Закрываем файлик
	free(filename);     //Очищаем памяять
	return 0;
}


int inputfile(char ***ptr, int *len){
	char *filename = readline2("Введите имя файла txt для чтения\n");
	FILE *f = fopen(filename,"r");  //Открываем файл для чтения
	if (f == NULL){
		printf("Файлика не существует :( \n");
		free(filename);
	    return 1;
	}
    *len = 0;	    //Обнуляем число строк в файле
	while (!feof(f)){       //Идем до конца файла
		char *s = freadline2(f);
        *((*ptr) + (*len)) = s;
		*len += 1;  //Количество строк в файле
	    if ((*len) % default_len_array == 0){
            (*ptr) = (char**)realloc(*ptr,sizeof(char*)*(default_len_array + (*len)));  //Если больше, чем 10 строк
        }
    }
    *len -= 1;
	fclose(f);          //Закрываем файлик
	free(filename);
	return 0;
}


int strings_comp(const void *a, const void *b){     //Компаратор для сравнения строк 
	char* x = *(char**) a;
	char* y = *(char**) b;
    return strcmp(x, y);
}

int words_comp(const void *a, const void *b){       //Компаратор для сравнения символов (в каждой строке символы становятся отсортированными, а порядок строк не меняется)
    return (*(char*)a - *(char*)b);
}
