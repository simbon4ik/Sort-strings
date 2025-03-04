#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Для memcpy и strlen
	
char* readline2(const char *s){ //Собственный ридлайн
    int n = 0, len = 0;
    char buf[51];       //Буффер для ввода
	printf("%s",s);   
    n = scanf("%50[^\n]",buf);  //Считываем 50 символов в буфер 
	char *ptr = (char*)calloc(1,sizeof(char));
    while (n > 0){
	    len += strlen(buf);
        ptr = (char*)realloc(ptr,len+1);    //Расширяем строку
        memcpy(ptr + len - strlen(buf),buf,strlen(buf));                //Переносим данные
        n = scanf("%50[^\n]",buf);          //Считываем следующие 50 символов
    }
    if (n == 0){
	    scanf("%*c");       //Очищаем буфер
        ptr[len] = '\0';    //Завершаем строку терм.нулем
    }else{
		free(ptr);          //Обработка ошибок считывания
		ptr = NULL;
	}
    return ptr;
}

char* freadline2(FILE *f){      //Ридлайн для считывания строки из файла
    int n = 0, len = 0;
    char buf[51];
    n = fscanf(f,"%50[^\n]",buf);       //scanf для файла, остальное аналогично
	char *ptr = (char*)calloc(1,sizeof(char));
    while (n > 0){
		len += strlen(buf);
        ptr = (char*)realloc(ptr,len+1);
            //strcat(ptr, buf);
        memcpy(ptr + len - strlen(buf),buf,strlen(buf));                //Переносим данные
        n = fscanf(f,"%50[^\n]",buf);
    }
    if (n == 0){
		fscanf(f,"%*c");
        ptr[len] = '\0';
    }else{
		free(ptr);
		ptr = NULL;
	}
    return ptr;
}

