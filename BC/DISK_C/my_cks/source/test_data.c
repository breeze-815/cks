#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �����û��ṹ��
typedef struct {
    char name[12];  // �û���
    char code[12];  // ����
    char type;       // �û�����
    char number[15];// �ֻ���
    char address;    // ��ַ
} USER;

// �����û����Ա�ṹ��
typedef struct {
    USER *elem;     // �û�����
    short length;     // ��ǰ�û�����
    short listsize;   // ���Ա�����
} UserList;

// ��ʾ�����û���Ϣ
void DisplayAllUsers() {
    FILE *fp = fopen("C:\\Users\\xianyuh\\Documents\\GitHub\\cks\\BC\\DISK_C\\my_cks\\userinfo.dat", "rb");
    if (fp == NULL) {
        printf("�޷����ļ���\n");
        return;
    }

    int length, listsize;
    fread(&length, sizeof(short), 1, fp);    // ��ȡ�û�����
    fread(&listsize, sizeof(short), 1, fp);  // ��ȡ���Ա�����

    printf("�û�����: %d\n", length);
    printf("���Ա�����: %d\n", listsize);
    printf("--------------------------------\n");

    USER user;
    for (int i = 0; i < length; i++) {
        // ȷ����ȷ��ȡ�ַ�������
        fread(user.name, sizeof(char), 12, fp);
        fread(user.code, sizeof(char), 12, fp);
        fread(&user.type, sizeof(char), 1, fp);
        fread(user.number, sizeof(char), 15, fp);
        fread(&user.address, sizeof(char), 1, fp);
        
        printf("�û� %d:\n", i + 1);
        printf("  �û���: %s\n", user.name);
        printf("  ����: %s\n", user.code);
        printf("  �û�����: %d\n", user.type);
        printf("  �ֻ���: %s\n", user.number);
        printf("  ��ַ: %d\n", user.address);
        printf("--------------------------------\n");
    }

    fclose(fp);
}

int main() {
    DisplayAllUsers();
    return 0;
}   
