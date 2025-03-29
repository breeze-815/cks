#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ================= 用户结构体 =================
typedef struct {
    char name[12];   // 用户名
    char code[12];   // 密码
    char type;       // 用户类型
    char number[12]; // 手机号
    char address; // 地址
} USER;

typedef struct {
    USER *elem;
    short length;
    short listsize;
} UserList;

// =============== 订单结构体相关 ================
typedef struct CartItem{
    int id;//商品id
    int type;//种类
    char name[20];//商品名称
    float price;//价格
    char photo[20];
    int quantity;//数量
    int index_in_products;//在商品数组中的索引，即cnt
} CartItem;//购物车内的商品 

typedef struct {
    char id;//订单号
    char user_name[12];//用户名
    char user_phone[12];//用户手机号
    char order_time[20];//下单时间
    CartItem item[20];//购物车内物品信息
    int itemCount;//购物车内物品数量
    float total_amount;//总价
} Order;

typedef struct {
    Order *elem;
    short length;
    short listsize;
} OrderList;

// ============ 显示所有用户信息 ============
void DisplayAllUsers() {
    FILE *fp = fopen("C:\\Users\\xianyuh\\Documents\\GitHub\\cks\\BC\\DISK_C\\my_cks\\data\\userinfo.dat", "rb");
    if (fp == NULL) {
        printf("无法打开用户数据文件！\n");
        return;
    }

    short length, listsize;
    fread(&length, sizeof(short), 1, fp);
    fread(&listsize, sizeof(short), 1, fp);

    printf("用户数量: %d\n", length);
    printf("线性表容量: %d\n", listsize);
    printf("--------------------------------\n");

    USER user;
    for (int i = 0; i < length; i++) {
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

// ============ 显示所有订单信息 ============
void DisplayAllOrders() {
    FILE *fp = fopen("C:\\Users\\xianyuh\\Documents\\GitHub\\cks\\BC\\DISK_C\\my_cks\\data\\order.dat", "rb");
    if (fp == NULL) {
        printf("无法打开订单数据文件！\n");
        return;
    }

    short length, listsize;
    fread(&length, sizeof(short), 1, fp);
    fread(&listsize, sizeof(short), 1, fp);

    printf("订单数量: %d\n", length);
    printf("线性表容量: %d\n", listsize);
    printf("--------------------------------\n");

    Order order;
    for (int i = 0; i < length; i++) {
        fread(&order.id, sizeof(char), 1, fp);
        fread(order.user_name, sizeof(char), 12, fp);
        fread(order.user_phone, sizeof(char), 12, fp);
        fread(order.order_time, sizeof(char), 20, fp);
        fread(&order.itemCount, sizeof(int), 1, fp);
        fread(&order.total_amount, sizeof(float), 1, fp);

        for (int j = 0; j < order.itemCount; j++) {
            fread(&order.item[j].id, sizeof(int), 1, fp);
            fread(&order.item[j].type, sizeof(int), 1, fp);
            fread(order.item[j].name, sizeof(char), 20, fp);
            fread(&order.item[j].price, sizeof(float), 1, fp);
            fread(order.item[j].photo, sizeof(char), 20, fp);
            fread(&order.item[j].quantity, sizeof(int), 1, fp);
            fread(&order.item[j].index_in_products, sizeof(int), 1, fp);
        }

        printf("订单 %d:\n", i + 1);
        printf("  订单号: %d\n", order.id);
        printf("  用户名: %s\n", order.user_name);
        printf("  用户手机号: %s\n", order.user_phone);
        printf("  下单时间: %s\n", order.order_time);
        printf("  购物车内物品种类数量: %d\n", order.itemCount);
        printf("  总价: %.2f\n", order.total_amount);
        for (int j = 0; j < order.itemCount; j++) {
            printf("    商品 %d:\n", j + 1);
            printf("      商品id: %d\n", order.item[j].id);
            printf("      种类: %d\n", order.item[j].type);
            printf("      商品名称: %s\n", order.item[j].name);
            printf("      价格: %.2f\n", order.item[j].price);
            printf("      数量: %d\n", order.item[j].quantity);
        }
        printf("--------------------------------\n");
    }

    fclose(fp);
}

// ============ 主函数 ============
int main() {
    printf("========= 用户信息 =========\n");
    DisplayAllUsers();
    
    printf("\n========= 订单信息 =========\n");
    DisplayAllOrders();

    return 0;
}
