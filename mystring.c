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
        memcpy(ptr,buf,len);                //Переносим данные
        n = scanf("%50[^\n]",buf);          //Считываем следующие 50 символов
    }
    if (n == 0){
	    scanf("%*c");       //Очищаем буфер
        ptr[len] = '\0';    //Завершаем строку терм.нулем
    }
	else{
		free(ptr);          //Обработка ошибок считывания
		ptr = NULL;
	}
    return ptr;
}
