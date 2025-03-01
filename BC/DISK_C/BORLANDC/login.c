#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>

#define USER_FILE "users.dat"
#define MAX_USERS 100
#define MAX_LEN 20

typedef struct {
    char username[MAX_LEN];
    char password[MAX_LEN];
} User;

User users[MAX_USERS];
int userCount = 0;

void loadUsers() {
    FILE *fp = fopen(USER_FILE, "r");
    if (fp) {
        while (fscanf(fp, "%s %s", users[userCount].username, 
                      users[userCount].password) != EOF) {
            userCount++;
        }
        fclose(fp);
    }
}

void saveUsers() {
    FILE *fp = fopen(USER_FILE, "w");
    if (fp) {
        for (int i = 0; i < userCount; i++) {
            fprintf(fp, "%s %s\n", users[i].username, users[i].password);
        }
        fclose(fp);
    }
}

void drawButton(int x1, int y1, int x2, int y2, char *text, int pressed) {
    setcolor(WHITE);
    rectangle(x1, y1, x2, y2);
    setfillstyle(SOLID_FILL, pressed ? LIGHTGRAY : DARKGRAY);
    bar(x1+3, y1+3, x2-3, y2-3);
    setcolor(BLACK);
    outtextxy((x1+x2)/2 - textwidth(text)/2, 
             (y1+y2)/2 - textheight(text)/2, text);
}

int getButton(int x1, int y1, int x2, int y2) {
    int mx, my;
    while (!kbhit()) {
        mx = mousex();
        my = mousey();
        if (mx >= x1 && mx <= x2 && my >= y1 && my <= y2) {
            if (MouseTrigger() == 1) return 1;
        }
    }
    return 0;
}

void inputBox(int x, int y, char *str, int maxlen, int showStar) {
    int i = 0;
    char ch;
    setcolor(WHITE);
    rectangle(x, y, x+200, y+20);
    setfillstyle(SOLID_FILL, BLACK);
    bar(x+2, y+2, x+198, y+18);
    
    while ((ch = getch()) != 13) {
        if (ch == 8 && i > 0) { // Backspace
            i--;
            str[i] = '\0';
        }
        else if (i < maxlen-1 && ch >= 32 && ch <= 126) {
            str[i++] = ch;
            str[i] = '\0';
        }
        
        bar(x+5, y+5, x+195, y+15);
        setcolor(WHITE);
        if (showStar) {
            for (int j = 0; j < i; j++) outtextxy(x+5+j*8, y+5, "*");
        } else {
            outtextxy(x+5, y+5, str);
        }
    }
}

void registerUser() {
    char user[MAX_LEN] = {0};
    char pass[MAX_LEN] = {0};
    
    cleardevice();
    setcolor(WHITE);
    outtextxy(100, 100, "Username:");
    inputBox(100, 120, user, MAX_LEN, 0);
    
    outtextxy(100, 160, "Password:");
    inputBox(100, 180, pass, MAX_LEN, 1);
    
    // Check if user exists
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, user) == 0) {
            outtextxy(100, 220, "User already exists!");
            getch();
            return;
        }
    }
    
    // Add new user
    strcpy(users[userCount].username, user);
    strcpy(users[userCount].password, pass);
    userCount++;
    saveUsers();
    
    outtextxy(100, 220, "Registration successful!");
    getch();
}

void login() {
    char user[MAX_LEN] = {0};
    char pass[MAX_LEN] = {0};
    
    cleardevice();
    setcolor(WHITE);
    outtextxy(100, 100, "Username:");
    inputBox(100, 120, user, MAX_LEN, 0);
    
    outtextxy(100, 160, "Password:");
    inputBox(100, 180, pass, MAX_LEN, 1);
    
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, user) == 0 && 
            strcmp(users[i].password, pass) == 0) {
            outtextxy(100, 220, "Login successful!");
            getch();
            return;
        }
    }
    
    outtextxy(100, 220, "Invalid username or password!");
    getch();
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\BORLANDC\\BGI");
    
    // Initialize mouse
    union REGS regs;
    regs.x.ax = 0;
    int86(0x33, &regs, &regs);
    
    loadUsers();
    
    while (1) {
        cleardevice();
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        
        // Draw title
        setcolor(YELLOW);
        outtextxy(200, 50, "Login System");
        
        // Draw buttons
        drawButton(200, 150, 400, 200, "Login", 0);
        drawButton(200, 220, 400, 270, "Register", 0);
        drawButton(200, 290, 400, 340, "Exit", 0);
        
        // Detect mouse click
        while (!kbhit()) {
            if (getButton(200, 150, 400, 200)) {
                login();
                break;
            }
            if (getButton(200, 220, 400, 270)) {
                registerUser();
                break;
            }
            if (getButton(200, 290, 400, 340)) {
                closegraph();
                return 0;
            }
        }
    }
    
    closegraph();
    return 0;
}