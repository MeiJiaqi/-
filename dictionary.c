//
// Created by 86191 on 2022/7/13.
//

#include "Method.h"


int main() {
    char filename1[] = "D:\\program file\\clion\\ElectronicDictionary\\Ӣ���ʵ�.txt";
    char filename2[] = "D:\\program file\\clion\\ElectronicDictionary\\���Ȿ.txt";
    wordNum = load_dirt(&p,filename1);
    mistNum = load_mist(&mp,filename2);
    if(wordNum==0)
    {
        printf("����ʧ��\n");

    }
    else
    {
        printf("���ص�������Ϊ%d\n",wordNum);
    }
    int choice;
    char str[50] = {0};
    while(1)
    {
        printf("��ӭ�����ü��ǵ��Ӵʵ�\n");
        printf("|*******************|\n");
        printf("|***** 1.Ӣ�뺺 *****|\n");
        printf("|***** 2.����Ӣ *****|\n");
        printf("|****  3.��ӡ�ʵ� ***|\n");
        printf("|***** 4.������ *****|\n");
        printf("|***** 5.�޸Ĵ��� ***|\n");
        printf("|***** 6.�鿴���Ȿ *|\n");
        printf("|***** 7.�˳� ******|\n");
        printf("|*******************|\n");
        printf("���������ѡ��?\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                eToc_tran();
                break;
            case 2:
                cToe_tran();
                break;
            case 3:
                showDict();
                break;
            case 4:
                words_game();
                break;
            case 5:
                modify_dict();
                break;
            case 6:
                showMist();
                break;
            case 7:
                exit(0);
            default:
                printf("�޸�ѡ��\n");
                break;
        }
    }

    return 0;
}
