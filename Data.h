//
// Created by 86191 on 2022/7/13.
//

#ifndef CLION_DATA_H
#define CLION_DATA_H
#endif //CLION_DATA_H
#include "time.h"
typedef struct dict_
{
    char *word;
    char *meaning;
    struct dict_ *next;//ָ��������һ���ڵ��ָ��
} Dict;

typedef struct mist_
{
    char* title;    //�������Ŀ
    char* answer;   //����Ĵ�
    char* time;    //��Ŀ��ʱ��
    struct mist_* next;
}Mist;   //����

time_t timeP;   //��ȡʱ��ı���
struct tm *time_p;

Dict* p = 0;     //ͷָ��
int wordNum = 0;   //��������

Mist* mp = 0;    //���Ȿ����ͷָ��
Mist* tmp = 0;   //���Ȿ����βָ��
int mistNum = 0;

char ci_dian_file[] = "D:\\program file\\clion\\ElectronicDictionary\\Ӣ���ʵ�.txt";
char cuo_ti_file[] = "D:\\program file\\clion\\ElectronicDictionary\\���Ȿ.txt";