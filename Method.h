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
         printf("�ļ���ʧ�ܣ������ļ�����·����\n");
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
}     //���ļ��ж���ʵ䣬���ص��ʸ���
int load_mist(Mist** p,const char* filename) {
    FILE *file = fopen(filename,"r");
    if(file==NULL)
    {
        printf("�ļ���ʧ�ܣ������ļ�����·����\n");
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
            temp=strtok(line,"   ");     //�ָ����Ϊ�����ո�

            headP->title=(char*) malloc(strlen(temp)*sizeof (char));     //��ȡtitle
            memset(headP->title, 0, strlen(temp));
            strcpy(headP->title, temp);

            temp = strtok(NULL,"   ");

            headP->answer=(char*) malloc(strlen(temp)*sizeof (char));   //��ȡanswer
            memset(headP->answer, 0, strlen(temp));
            strcpy(headP->answer, temp);

            temp = strtok(NULL,"   ");

            headP->time=(char*) malloc(strlen(temp)*sizeof (char));  //��ȡtime
            memset(headP->time, 0, strlen(temp));
            strcpy(headP->time, temp);

            headP->next = (Mist *) malloc(sizeof (Mist));    //����һ���ڵ����ռ�
            memset(headP->next,0,sizeof (Mist));
            headP=headP->next;
            counter++;

        }
    }
    fclose(file);
    return counter;
}     //���ļ��ж�ȡ����
int search_word(Dict** p1,const char* str,char* result)
{
    Dict* headP = *p1;
    while(headP)
    {

        if(headP->word&&strcmp(headP->word,str)==0)
        {
            strcpy(result,headP->meaning);  //���ݵ��ʲ���˼
            return 1;
        }
        else if(headP->meaning&&strstr(headP->meaning,str))
        {
            strcpy(result,headP->word);  //������˼�鵥�ʣ�ģ������
            return 1;
        }
        headP = headP->next;
    }
    return 0;
}   //���Һ������ɸ��ݸ����ַ������ҵ��ʻ���˼�����ص�result;
void eToc_tran(){
    printf("������Ӣ�ﵥ�ʣ�");
    char words[50] = { 0 };
    scanf("%s",words);
    char result[50] ;
    if(search_word(&p,words,result)==0)
    {
        printf("δ�ܲ鵽�õ���\n");
    }
    else
    {
        printf("�õ�����˼���£�%s\n",result);
    }
}     //Ӣ�Ĳ�����
void cToe_tran(){
    printf("������������˼��");
    char words[50] = { 0 };
    scanf("%s",words);
    char result[50];
    if(search_word(&p,words,result)==0)
    {
        printf("δ�ܲ鵽�õ���\n");
    }
    else
    {
        printf("�鵽�������£�%s\n",result);
    }
}      //���Ĳ�Ӣ��
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
    printf("ѡ��ʽ��\n");
    printf("1.����ƴд\n");
    printf("2.ѡ����˼\n");
    printf("3.�����ʽ\n");
    int op=0;
    scanf("%d",&op);
    while(op!=1&&op!=2&&op!=3)
    {
        printf("���������е�һ����\n");
        scanf("%d",&op);
    }
    srand(time(NULL));
    int i = 1;
    int fenshu=0;
    printf("��������Ŀ������\n");
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
    printf("��Ϸ���������ķ���Ϊ%d/%d\n",fenshu,count);
}    //��Ϸ
int word_spell()
{
    int t = rand()%wordNum;
    Dict *head = p;
    while(t--&&head->next)
    {
        head = head->next;
    }
    printf("������˼Ϊ: %s \n�����뵥�ʣ�",head->meaning);
    char title[50] = { 0 };
    snprintf(title,50,"������˼Ϊ��%s�������뵥�ʣ�",head->meaning);
    char temp[50] = {0};
    scanf("%s",temp);
    char answer[50] = {0};
    snprintf(answer,50,"���Ļش�Ϊ��%s����ȷƴдΪ��%s",temp,head->word);
    char time[50] = {0};
    get_time(time);
    if(strcmp(temp,head->word)==0)
    {
        printf("��ϲ�����ˣ�\n");
        return 1;
    }
    else
    {
        insert_mist(title,answer,time);
        printf("�ش������ȷƴдΪ %s\n",head->word);
        return 0;
    }

}     //ƴд��Ϸ
int choose_meaning()
{

    int t = rand()%wordNum;
    Dict *head = p;
    while(t--&&head->next)
    {
        head = head->next;
    }
    printf("����Ϊ %s\n",head->word);
    char title[200] = {0};
    snprintf(title,200,"����Ϊ%s,��ѡ����˼��",head->word);
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
    printf("��ѡ��");
    int op;
    scanf("%d",&op);
    if(op==t)
    {
        printf("��ϲ�����ˣ�\n");
        return 1;
    }
    else
    {
        char answer[50] = { 0 };
        snprintf(answer,50,"���Ĵ�Ϊ��%d����ȷ��Ϊ��%d",op,t);
        char time[50] = {0};
        get_time(time);

        insert_mist(title,answer,time);
        printf("�ش������ȷ��Ϊ %d\n",t);
        return 0;
    }

}  //ѡ����Ϸ
int modify_dict()
{

    printf("��ѡ������Ӣ�Ļ����������Ҵ�����\n1.���뵥��\n2.��������\n");
    int op;
    scanf("%d",&op);
    switch (op) {
        case 1:
            printf("�����뵥�ʣ�\n");
            break;
        case 2:
            printf("��������˼��\n");
            break;
        default:
            printf("������Ч��\n");
            break;
    }
    char str[50] = {0};
    scanf("%s",str);
    char result[100] = {0};
    if(search_word(&p,str,result)==0)
    {
        printf("δ���ҵ��õ���\n");
        return 0;
    }
    else
    {
        printf("���ҵ����µ��ʣ�\n");
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
    printf("�������޸ĺ�ĵ��ʺ���˼��\n���ʣ�");
    scanf("%s",str);
    printf("��˼��");
    scanf("%s",result);
    strcpy(head->word,str);
    strcpy(head->meaning,result);
    printf("�޸���ɣ�\n");
}     //�޸�
void get_time(char str[])
{
    time(&timeP);
    time_p= gmtime(&timeP);
    char len[50] = {0};
    snprintf(len, 50, "%d-%d-%d(%d:%d:%d)", 1900 + time_p->tm_year, 1 + time_p->tm_mon, time_p->tm_mday, 8 + time_p->tm_hour,time_p->tm_min, time_p->tm_sec);
    strcpy(str,len);
}  //��ȡʱ��
void insert_mist(char ti[],char an[],char tim[])
{
    Mist* head = mp;
    while(head->next!=NULL)
    {
        head = head ->next;
    }

    head->title = (char *) malloc(strlen(ti)*sizeof(char));   //���µ�title��ֵ
    memset(head->title,0,sizeof(ti));
    strcpy(head->title,ti);

    head->answer = (char *) malloc(sizeof(char)*strlen(an));   //���µ�answer��ֵ
    memset(head->answer,0,sizeof(an));
    strcpy(head->answer,an);

    head->time = (char *) malloc(sizeof(char)*strlen(tim));   //���µ�time��ֵ
    memset(head->time,0,sizeof(tim));
    strcpy(head->time,tim);

    head->next = (Mist *) malloc(sizeof (Mist));    //����һ���ڵ����ռ�
    memset(head->next,0,sizeof (Mist));

}    //����Ȿ�����в�����
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
        printf("�ļ���ʧ�ܣ������ļ�����·����\n");
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
        printf("�ļ���ʧ�ܣ������ļ�����·����\n");
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
