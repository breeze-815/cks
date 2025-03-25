#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义用户结构体
typedef struct {
    char name[12];  // 用户名
    char code[12];  // 密码
    char type;       // 用户类型
    char number[15];// 手机号
    char address;    // 地址
} USER;

// 定义用户线性表结构体
typedef struct {
    USER *elem;     // 用户数组
    short length;     // 当前用户数量
    short listsize;   // 线性表容量
} UserList;

// 显示所有用户信息
void DisplayAllUsers() {
    FILE *fp = fopen("C:\\Users\\xianyuh\\Documents\\GitHub\\cks\\BC\\DISK_C\\my_cks\\userinfo.dat", "rb");
    if (fp == NULL) {
        printf("无法打开文件！\n");
        return;
    }

    int length, listsize;
    fread(&length, sizeof(short), 1, fp);    // 读取用户数量
    fread(&listsize, sizeof(short), 1, fp);  // 读取线性表容量

    printf("用户数量: %d\n", length);
    printf("线性表容量: %d\n", listsize);
    printf("--------------------------------\n");

    USER user;
    for (int i = 0; i < length; i++) {
        // 确保正确读取字符串数据
        fread(user.name, sizeof(char), 12, fp);
        fread(user.code, sizeof(char), 12, fp);
        fread(&user.type, sizeof(char), 1, fp);
        fread(user.number, sizeof(char), 15, fp);
        fread(&user.address, sizeof(char), 1, fp);
        
        printf("用户 %d:\n", i + 1);
        printf("  用户名: %s\n", user.name);
        printf("  密码: %s\n", user.code);
        printf("  用户类型: %d\n", user.type);
        printf("  手机号: %s\n", user.number);
        printf("  地址: %d\n", user.address);
        printf("--------------------------------\n");
    }

    fclose(fp);
}

int main() {
    DisplayAllUsers();
    return 0;
}   
