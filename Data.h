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
    struct dict_ *next;//指向链表下一个节点的指针
} Dict;

typedef struct mist_
{
    char* title;    //错题的题目
    char* answer;   //错题的答案
    char* time;    //题目的时间
    struct mist_* next;
}Mist;   //错题

time_t timeP;   //获取时间的变量
struct tm *time_p;

Dict* p = 0;     //头指针
int wordNum = 0;   //单词总数

Mist* mp = 0;
int mistNum = 0;
