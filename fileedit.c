#include <stdio.h>

int main(int j,char *name[]){
    //создаётся символ для работы с изначальным текстом файла
    char ch;
    //создаётся переменная счётчик
    int i=0;
    //создаются указатели на файл для подсчёта символов, их записи, а также для записи желаемого текста
    FILE *counter, *reader, *writer;
    //открывается поток файла для чтения, которое нужно для подсчёта количества символов
    counter = fopen(name[1],"r");
    if(counter==NULL){
    	printf("Файл не был найден, перезапустите программу\n");
        return 0;
    }else{
        //происходит подсчёт количества символов в файле
        while((ch=fgetc(counter))!= EOF){
        i++;
        }
        fclose(counter);
    }
    //создаётся массив символов изначального файла
    char cmass[i];
    //открывается поток файла для чтения символов в массив
    reader = fopen(name[1],"r");
    if(reader==NULL){
        printf("Файл не был найден, перезапустите программу\n");
    }else{
        //в цикле происходит занесение в массив символов через ранее введенную переменную
        for(i=0;(ch=fgetc(reader))!=EOF;i++){
        cmass[i]=ch;
        }
        fclose(reader);
    }
    //открывается поток файла для записи введенной строки и изначального набора символов файла
    writer = fopen(name[1],"w");
    if(writer==NULL){
        printf("Файл не был найден, перезапустите программу\n");
        return 0;
    }else{
        //создаётся переменная количества символов записываемых данных
        int length;
        printf("Введите количество символов записываемого предложения\n");
        scanf("%d",&length);
        //создаётся массив записываемых данных
        char sentence[length];
        printf("Введите предложение\n");
        scanf("%s", sentence);
        //в массив изначальных данных запиывается ввёденный пользователем набор символов
        fprintf(writer,"%s",sentence);
        fprintf(writer,"\n");
        //занесение в текст изначального набора символов
        for(int j=0;j<i;j++){
            fputc(cmass[j],writer);
        }
        fclose(writer);
    }
    return 0;
}