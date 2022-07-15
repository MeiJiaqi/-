//
// Created by 86191 on 2022/7/13.
//

#ifndef CLION_METHOD_H
#define CLION_METHOD_H
#endif //CLION_METHOD_H


#include "Data.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"


int word_spell();
int choose_meaning();
void clear();
void insert_mist(char ti[],char an[],char tim[]);
void get_time(char str[]);



int load_dirt(Dict** p,const char* filename)
{
     FILE *file = fopen(filename,"r");
     if(file==NULL)
     {
         printf("文件打开失败！请检查文件名或路径！\n");
         return 0;
     }

     size_t len = 0;
     int counter = 0;
    *p = (struct dict_*) malloc(sizeof (Dict));
    memset(*p,0,sizeof(Dict));
    Dict* headP = *p;
    char line[500]={0};
    while (!feof(file))
    {
        int result = fscanf(file,"%[^\n]",line);
        len = strlen(line);
        if(result == -1)
        {
            break;
        }
        char c;
        fscanf(file,"%c",&c);
        if(len>0)
        {
            char* temp = NULL;
           temp=strtok(line,"   ");

           headP->word=(char*) malloc(strlen(temp)*sizeof (char));
           memset(headP->word, 0, strlen(temp));
           strcpy(headP->word, temp);

           temp = strtok(NULL,"   ");

           headP->meaning=(char*) malloc(strlen(temp)*sizeof (char));
           memset(headP->meaning, 0, strlen(temp));
           strcpy(headP->meaning, temp);


            headP->next = (Dict*) malloc(sizeof (Dict));
            memset(headP->next,0,sizeof (Dict));
            headP=headP->next;
            counter++;

        }

    }
    fclose(file);
    return counter;
}     //从文件中读入词典，返回单词个数
int load_mist(Mist** p,const char* filename) {
    FILE *file = fopen(filename,"r");
    if(file==NULL)
    {
        printf("文件打开失败！请检查文件名或路径！\n");
        return 0;
    }
    size_t len = 0;
    int counter = 0;
    *p = (struct mist_*) malloc(sizeof (Mist));
    memset(*p,0,sizeof(Mist));
    Mist* headP = *p;
    char line[500]={0};
    while (!feof(file))
    {
        int result = fscanf(file,"%[^\n]",line);

        len = strlen(line);
        if(result==-1)
        {
            break;
        }
        char c;
        fscanf(file,"%c",&c);
        if(len>0)
        {
            char* temp = NULL;
            temp=strtok(line,"   ");     //分割符号为三个空格

            headP->title=(char*) malloc(strlen(temp)*sizeof (char));     //读取title
            memset(headP->title, 0, strlen(temp));
            strcpy(headP->title, temp);

            temp = strtok(NULL,"   ");

            headP->answer=(char*) malloc(strlen(temp)*sizeof (char));   //读取answer
            memset(headP->answer, 0, strlen(temp));
            strcpy(headP->answer, temp);

            temp = strtok(NULL,"   ");

            headP->time=(char*) malloc(strlen(temp)*sizeof (char));  //读取time
            memset(headP->time, 0, strlen(temp));
            strcpy(headP->time, temp);

            headP->next = (Mist *) malloc(sizeof (Mist));    //给下一个节点分配空间
            memset(headP->next,0,sizeof (Mist));
            headP=headP->next;
            counter++;

        }
    }
    fclose(file);
    return counter;
}     //从文件中读取错题
int search_word(Dict** p1,const char* str,char* result)
{
    Dict* headP = *p1;
    while(headP)
    {

        if(headP->word&&strcmp(headP->word,str)==0)
        {
            strcpy(result,headP->meaning);  //根据单词查意思
            return 1;
        }
        else if(headP->meaning&&strstr(headP->meaning,str))
        {
            strcpy(result,headP->word);  //根据意思查单词，模糊查找
            return 1;
        }
        headP = headP->next;
    }
    return 0;
}   //查找函数，可根据给定字符串查找单词会意思，返回到result;
void eToc_tran(){
    printf("请输入英语单词：");
    char words[50] = { 0 };
    scanf("%s",words);
    char result[50] ;
    if(search_word(&p,words,result)==0)
    {
        printf("未能查到该单词\n");
    }
    else
    {
        printf("该单词意思如下：%s\n",result);
    }
}     //英文查中文
void cToe_tran(){
    printf("请输入中文意思：");
    char words[50] = { 0 };
    scanf("%s",words);
    char result[50];
    if(search_word(&p,words,result)==0)
    {
        printf("未能查到该单词\n");
    }
    else
    {
        printf("查到单词如下：%s\n",result);
    }
}      //中文查英文
void showDict()
{
    Dict *head = p;
    while(head)
    {
        printf("%s %s\n",head->word,head->meaning);
        head=head->next;
    }
}
void words_game()
{
    printf("选择方式：\n");
    printf("1.单词拼写\n");
    printf("2.选择意思\n");
    printf("3.随机方式\n");
    int op=0;
    scanf("%d",&op);
    while(op!=1&&op!=2&&op!=3)
    {
        printf("请输入其中的一个！\n");
        scanf("%d",&op);
    }
    srand(time(NULL));
    int i = 1;
    int fenshu=0;
    printf("请输入题目数量：\n");
    int count;
    scanf("%d",&count);
    int t;
    for(i=1;i<=count;i++)
    {
        printf("%d/%d\n",i,count);
        switch (op) {
            case 1:
                if(word_spell())
                    fenshu++;
                break;
            case 2:
                if(choose_meaning())
                    fenshu++;
                break;
            case 3:
                t = rand()%100;
                if(t<50)
                {
                    if(word_spell())
                        fenshu++;
                }
                else
                {
                    if(choose_meaning())
                        fenshu++;
                }
                break;
            default:
                break;
        }

    }
    printf("游戏结束，您的分数为%d/%d\n",fenshu,count);
}    //游戏
int word_spell()
{
    int t = rand()%wordNum;
    Dict *head = p;
    while(t--&&head->next)
    {
        head = head->next;
    }
    printf("单词意思为: %s \n请输入单词：",head->meaning);
    char title[50] = { 0 };
    snprintf(title,50,"单词意思为：%s，请输入单词：",head->meaning);
    char temp[50] = {0};
    scanf("%s",temp);
    char answer[50] = {0};
    snprintf(answer,50,"您的回答为：%s，正确拼写为：%s",temp,head->word);
    char time[50] = {0};
    get_time(time);
    if(strcmp(temp,head->word)==0)
    {
        printf("恭喜你答对了！\n");
        return 1;
    }
    else
    {
        insert_mist(title,answer,time);
        printf("回答错误，正确拼写为 %s\n",head->word);
        return 0;
    }

}     //拼写游戏
int choose_meaning()
{

    int t = rand()%wordNum;
    Dict *head = p;
    while(t--&&head->next)
    {
        head = head->next;
    }
    printf("单词为 %s\n",head->word);
    char title[200] = {0};
    snprintf(title,200,"单词为%s,请选择意思：",head->word);
    char an[100]= {0};
    strcpy(an,head->meaning);
    t = rand()%4 +1;
    for(int i=1;i<5;i++)
    {

        int j = rand()%wordNum;
        head = p;
        while(j--&&head->next)
        {
            head = head->next;
        }
        if(i!=t)
        {
            char tem[50] = {0};
            snprintf(tem,50,"*%d.%s",i,head->meaning);
            strcat(title,tem);
            printf("%d. %s\n",i,head->meaning);
        }
        else
        {
            char tem[50] = {0};
            snprintf(tem,50,"*%d.%s",i,an);
            strcat(title,tem);
            printf("%d. %s\n",t,an);
        }


    }
    printf("请选择：");
    int op;
    scanf("%d",&op);
    if(op==t)
    {
        printf("恭喜你答对了！\n");
        return 1;
    }
    else
    {
        char answer[50] = { 0 };
        snprintf(answer,50,"您的答案为：%d，正确答案为：%d",op,t);
        char time[50] = {0};
        get_time(time);

        insert_mist(title,answer,time);
        printf("回答错误，正确答案为 %d\n",t);
        return 0;
    }

}  //选择游戏
int modify_dict()
{

    printf("请选择输入英文或中文来查找词条：\n1.输入单词\n2.输入中文\n");
    int op;
    scanf("%d",&op);
    switch (op) {
        case 1:
            printf("请输入单词：\n");
            break;
        case 2:
            printf("请输入意思：\n");
            break;
        default:
            printf("输入无效！\n");
            break;
    }
    char str[50] = {0};
    scanf("%s",str);
    char result[100] = {0};
    if(search_word(&p,str,result)==0)
    {
        printf("未查找到该单词\n");
        return 0;
    }
    else
    {
        printf("查找到以下单词：\n");
        if(op==1)
        {
            printf("%s %s\n",str,result);
        }
        else
        {
            printf("%s %s\n",result,str);
        }

    }
    Dict *head = p;
    if(op==1)
    {
        while(head!=NULL&&head->word&&strcmp(str,head->word)!=0)
            head = head ->next;
    }
    if(op==2)
    {
        while(head!=NULL&&head->meaning&&strcmp(str,head->meaning)!=0)
            head = head ->next;
    }
    printf("请输入修改后的单词和意思：\n单词：");
    scanf("%s",str);
    printf("意思：");
    scanf("%s",result);
    strcpy(head->word,str);
    strcpy(head->meaning,result);
    printf("修改完成！\n");
}     //修改
void get_time(char str[])
{
    time(&timeP);
    time_p= gmtime(&timeP);
    char len[50] = {0};
    snprintf(len, 50, "%d-%d-%d(%d:%d:%d)", 1900 + time_p->tm_year, 1 + time_p->tm_mon, time_p->tm_mday, 8 + time_p->tm_hour,time_p->tm_min, time_p->tm_sec);
    strcpy(str,len);
}  //获取时间
void insert_mist(char ti[],char an[],char tim[])
{
    Mist* head = mp;
    while(head->next!=NULL)
    {
        head = head ->next;
    }

    head->title = (char *) malloc(strlen(ti)*sizeof(char));   //给新的title赋值
    memset(head->title,0,sizeof(ti));
    strcpy(head->title,ti);

    head->answer = (char *) malloc(sizeof(char)*strlen(an));   //给新的answer赋值
    memset(head->answer,0,sizeof(an));
    strcpy(head->answer,an);

    head->time = (char *) malloc(sizeof(char)*strlen(tim));   //给新的time赋值
    memset(head->time,0,sizeof(tim));
    strcpy(head->time,tim);

    head->next = (Mist *) malloc(sizeof (Mist));    //给下一个节点分配空间
    memset(head->next,0,sizeof (Mist));

}    //向错题本链表中插入结点
void showMist()
{
    Mist *head = mp;
    int i = 1;
    char* temp = NULL;
    char tem[200] = {0};

    while(head)
    {
        if(head->title&&head->answer&&head->time)
        {
            strcpy(tem,head->title);
           temp = strtok(tem,"*");
            printf("%d. %s\n",i,temp);
            while(temp!=NULL)
            {

                temp= strtok(NULL,"*");
                if(temp)
                printf("%s\n",temp);
            }
            printf("%s\n%s\n",head->answer,head->time);
        }
        printf("\n");
        head=head->next;
        i++;
    }
}
void save_to_file()
{
    FILE *file = fopen(ci_dian_file,"w");
    if(file==NULL)
    {
        printf("文件打开失败！请检查文件名或路径！\n");
        return;
    }
    Dict* head = p;

    while(head)
    {

        if(head->next)
        {
            fprintf(file,"%s   %s\n",head->word,head->meaning);
        }

        head=head->next;

    }
    fclose(file);


    FILE *file1 = fopen(cuo_ti_file,"w");
    if(file1==NULL)
    {
        printf("文件打开失败！请检查文件名或路径！\n");
        return;
    }
    Mist* head1 = mp;
    while(head1)
    {
        if(head1->title)
        fprintf(file1,"%s   %s   %s\n",head1->title,head1->answer,head1->time);
        head1 = head1 ->next;
    }
    fclose(file1);
}
void free_all()
{
    Dict* head =  p;

    while(head)
    {
        free(head->word);
        free(head->meaning);
        Dict *temp = head->next;
        free(head);
        head = temp;
    }

    Mist * head1 = mp;
    while(head1)
    {
        free(head1->title);
        free(head1->answer);
        free(head1->time);
        Mist * temp = head1->next;
        free(head1);
        head1 = temp;
    }
}
void clear()
{
    system("cls");
}
