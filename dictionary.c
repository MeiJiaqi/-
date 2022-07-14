//
// Created by 86191 on 2022/7/13.
//

#include "Method.h"


int main() {
    char filename1[] = "D:\\program file\\clion\\ElectronicDictionary\\英汉词典.txt";
    char filename2[] = "D:\\program file\\clion\\ElectronicDictionary\\错题本.txt";
    wordNum = load_dirt(&p,filename1);
    mistNum = load_mist(&mp,filename2);
    if(wordNum==0)
    {
        printf("加载失误\n");

    }
    else
    {
        printf("加载单词数量为%d\n",wordNum);
    }
    int choice;
    char str[50] = {0};
    while(1)
    {
        printf("欢迎来到好记星电子词典\n");
        printf("|*******************|\n");
        printf("|***** 1.英译汉 *****|\n");
        printf("|***** 2.汉译英 *****|\n");
        printf("|****  3.打印词典 ***|\n");
        printf("|***** 4.背单词 *****|\n");
        printf("|***** 5.修改词条 ***|\n");
        printf("|***** 6.查看错题本 *|\n");
        printf("|***** 7.退出 ******|\n");
        printf("|*******************|\n");
        printf("请输入你的选择?\n");
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
                printf("无该选择！\n");
                break;
        }
    }

    return 0;
}
