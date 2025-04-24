#include "all_func.h"

Deliver delivers={0};//存储信息的快递结构体
Company companys[8]={
    {"顺丰快递"},
    {"韵达快递"},
    {"申通快递"},
    {"中通快递"},
    {"京东快递"},
    {"邮政快递"},
    {"圆通快递"},
    {"其他快递"}
};
Station stations[8]={
	{"韵苑1栋"},
	{"韵苑2栋"},
	{"韵苑3栋"},
	{"东教工17栋"},
    {"东4驿站"},
    {"紫菘13栋"},
    {"紫菘1栋"},
    {"西十舍"},
};

void user_deliver(){
    UserList UL = {0};
    DeliverList DL = {0};
    USER currentUser;
    int last_index=-1;//记录上次选择的服务提供商
    int last_index_station=-1;//记录上次选择的站点
    int state=0; //判断是否需要完善信息

    //这三个变量在选择地址时使用
    int cur_index = -1;
    int cur_community=0;
    int returned_index;

    ReadAllUser(&UL); // 读取用户列表
    ReadAllDeliver(&DL); // 读取订单列表

    currentUser=UL.elem[users.pos];// 获取当前用户信息

    delivers.id=DL.length+1;// 订单号
    strcpy(delivers.name, currentUser.name);// 用户名
    strcpy(delivers.number, currentUser.number);// 用户手机号
    delivers.community=currentUser.community;// 用户地址
    delivers.building=currentUser.building;// 用户楼栋
    delivers.index=currentUser.index;// 

    DestroyUList(&UL); // 释放用户列表空间
    DestroyDList(&DL); // 释放订单列表空间

    mouse_off_arrow(&mouse);
	
	draw_user_deliver();

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1)
        {
            return;
			//welcome();//首页
		}
        else if(mouse_press(40, 276, 160, 326)==1)
        {
            press_func(1);//进入超市页面
            user_shop();//用户超市页面 
            return;
        }
        else if(mouse_press(40, 439, 160, 489)==1)
        {
            press_func(2);//进入外卖页面
            user_takeout();//用户外卖页面 
            return;
        }
        else if(mouse_press(40, 602, 160, 652)==1)
        {
            press_func(3);//进入快递页面
            user_deliver();//用户快递页面 
            return;
        }

        //
        if(state==0){
            if(mouse_press(440, 35, 660, 85)==1)
            {
                deliver_input(delivers.code, 445, 40, 655, 80); // 输入取件码
            }
            else if(mouse_press(730, 35, 850, 85)==1)//保存取件码按钮
            {
                save_Deliver(delivers);
                PrintCC(750, 120, "保存成功", HEI, 24, 1, lightred);
                delay(500);
                bar1(750, 120, 1024, 160, white);
            }
            else if(mouse_press(800, 700, 1000, 750)==1)//点击生成订单按钮
            {
                if (delivers.company == 0) // 未选择服务提供商
                { 
                    PrintCC(750, 120, "请选择服务提供商", HEI, 24, 1, lightred);
                    delay(500);
                    bar1(750, 120, 1024, 160, white);
                }
                else if (delivers.station == 0) // 未选择站点
                { 
                    PrintCC(750, 120, "请选择驿站", HEI, 24, 1, lightred);
                    delay(500);
                    bar1(750, 120, 1024, 160, white);
                }
                else if(strlen(delivers.code)==0){//未输入取件码
                    PrintCC(750, 120, "请输入取件码", HEI, 24, 1, lightred);
                    delay(500);
                    bar1(750, 120, 1024, 160, white);
                }
                else if (currentUser.index == 0 || strlen(currentUser.number) == 0)// 判断用户信息是否完善
                {
                    mouse_off_arrow(&mouse);
                    draw_info();
                    mouse_on_arrow(mouse);
                    state = 1;
                }
                else//输入正确,保存信息
                {
                    strcpy(delivers.time, get_current_time()); // 保存时间
                    save_Deliver(delivers); // 保存订单信息
                    de_order();//进入订单页面
                }

            }
            else if(mouse_press(250, 175, 750+185, 375)==1)//选择服务提供商
            {
                int index;
                MouseGet(&mouse);
                mouse_off_arrow(&mouse);
                
                index=choose_company(mouse.x, mouse.y, &last_index);

                if(index!=-1)
                {
                    delivers.company=index;//记录选择的服务提供商
                    save_Deliver(delivers);
                }

                mouse_on_arrow(mouse);
            }
            else if(mouse_press(250, 455, 750+185, 655)==1)//选择驿站
            {
                int index_station;
                MouseGet(&mouse);
                mouse_off_arrow(&mouse);
                
                index_station=choose_station(mouse.x, mouse.y, &last_index_station);

                if(index_station!=-1)
                {
                    delivers.station=index_station;//记录选择的站点
                    save_Deliver(delivers);
                }

                mouse_on_arrow(mouse);
            }
        }
        
        // 完善用户信息
        if(state==1)
        {
            if(mouse_press(430, 105, 650, 155)==1)
            {
                number_input(currentUser.number, 435, 110, 645, 150); // 输入手机号
            }
            else if(mouse_press(710, 105, 830, 155)==1)
            {
                if(strlen(currentUser.number)==11)
                {
                    save_user(currentUser);
                    strcpy(delivers.number, currentUser.number);//保存手机号
                    save_Deliver(delivers);//保存手机号到订单信息中
                    PrintCC(800,50,"保存成功",HEI,24,1,lightred);
                    delay(500);
                    bar1(800,50,950,100,white);
                }
                else
                {
                    PrintCC(800,50,"长度不合法",HEI,24,1,lightred);
                    delay(500);
                    bar1(800,50,950,100,white);
                }
            }
            else if(mouse_press(440, 180, 560, 230)==1)
            {
                cur_index = -1;
                press_func(4);//按钮状态切换
                draw_button(1);
                cur_community=1; 
            
            }
            else if(mouse_press(620, 180, 740, 230)==1)
            {
                cur_index = -1;
                press_func(5);//西区
                draw_button(2);
                cur_community=2;
            }
            else if(mouse_press(800, 180, 920, 230)==1)
            {
                cur_index = -1;
                press_func(6);//南区
                draw_button(3);
                cur_community=3;
        
            }
            else if(mouse_press(530, 255, 650, 305)==1)
            {
                cur_index = -1;
                press_func(7);//紫菘
                draw_button(4);
                cur_community=4;
            }
            else if(mouse_press(750, 255, 870, 305)==1)
            {
                cur_index = -1;
                press_func(8);//韵苑
                draw_button(5);
                cur_community=5;
            }
            else if (mouse_press(200, 310, 1024, 768) == 1) { 

                MouseGet(&mouse);
                mouse_off_arrow(&mouse);
                returned_index = press_button(mouse.x, mouse.y, cur_index, cur_community);//获取按钮编号

                if(returned_index>=0)//如果返回值大于等于0,则说明选择了按钮
                {
                    currentUser.community = button[returned_index].commmunity;//获取社区编号
                    currentUser.index = button[returned_index].index;//获取楼号编号
                    
                    delivers.community=currentUser.community;//保存社区编号
                    delivers.station=currentUser.index;//保存楼号编号

                    save_user(currentUser);//保存用户信息
                    save_Deliver(delivers);//保存订单信息
                }

                cur_index = returned_index;//更新当前按钮编号

                mouse_on_arrow(mouse);

                delay(200);
            }

            if(mouse_press(950, 50, 975,75)==1)
            {
                state = 0;
                mouse_off_arrow(&mouse);
                draw_user_deliver();
                mouse_on_arrow(mouse);
            }
        }
    }
}

void draw_user_deliver(){
    int i,j;
    bar1(200, 0, 1024, 768,white);

    Draw_Rounded_Rectangle(440, 35, 660, 85, 5, 1,deepblue);//取件码输入框 
    Draw_Rounded_Rectangle(730, 35, 850, 85, 25, 1,deepblue);//保存按钮

    PrintCC(250,50,"请输入取件码：",HEI,24,1,deepblue);
    PrintCC(250,120,"请选择服务提供商：",HEI,24,1,deepblue);
    PrintCC(250,400,"请选择驿站：",HEI,24,1,deepblue);
    PrintCC(765,50,"保存",HEI,24,1,deepblue);

    for(i=0;i<3;i++)//绘制服务提供商按钮
    {
        for(j=0;j<3;j++)
        {
            if(i*3+j>=8) break; // 超出快递数量则退出
            Draw_Rounded_Rectangle(250+250*j, 175+75*i, 250+185+250*j, 175+50+75*i, 5,1,deepblue);
            PrintText(250+40+250*j,175+13+75*i,companys[i*3+j].name,HEI,24,1,deepblue);
        }
    }

    for(i=0;i<3;i++)//绘制驿站地址
    {
        for(j=0;j<3;j++)
        {
            if(i*3+j>=8) break; // 超出驿站数量则退出
            Draw_Rounded_Rectangle(250+250*j, 455+75*i, 250+185+250*j, 455+50+75*i, 5,1,deepblue);
            PrintText(250+40+250*j,455+13+75*i,stations[i*3+j].name,HEI,24,1,deepblue);
        }
    }

    Draw_Rounded_Rectangle(800, 700, 1000, 750, 5, 1, deepblue); // 生成订单
    PrintCC(850, 715, "生成订单", HEI, 24, 1, deepblue);
}


int choose_company(int x, int y, int* last_index) {
    int i, j;
    int index = -1;
    int station_count = 8;

    for (i = 0; i < 3; i++) {           // 行
        for (j = 0; j < 3; j++) {       // 列
            int x1 = 250 + 250 * j;
            int y1 = 175 + 75 * i;
            int x2 = x1 + 185;
            int y2 = y1 + 50;
            
            index = i * 3 + j;
            if (index >= station_count) break; // 超出快递数量则退出

            

            if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {

                // 恢复上一个按钮
                if (*last_index != -1 && *last_index != index) {
                    int pre_row = *last_index / 3;
                    int pre_col = *last_index % 3;
                    int pre_x1 = 250 + 250 * pre_col;
                    int pre_y1 = 175 + 75 * pre_row;
                    int pre_x2 = pre_x1 + 185;
                    int pre_y2 = pre_y1 + 50;

                    Fill_Rounded_Rectangle(pre_x1, pre_y1, pre_x2, pre_y2, 5, white);
                    Draw_Rounded_Rectangle(pre_x1, pre_y1, pre_x2, pre_y2, 5, 1, deepblue);
                    PrintCC(pre_x1 + 40, pre_y1 + 13, companys[*last_index].name, HEI, 24, 1, deepblue);
                }

                // 当前按钮高亮
                Fill_Rounded_Rectangle(x1, y1, x2, y2, 5, deepblue);
                Draw_Rounded_Rectangle(x1, y1, x2, y2, 5, 1, deepblue);
                PrintCC(x1 + 40, y1 + 13, companys[index].name, HEI, 24, 1, white);

                *last_index = index;
                return index + 1; // 返回快递公司编号（1~8）
            }
        }
    }
    return -1; // 未选中任何按钮
}

int choose_station(int x, int y, int* last_index_station) {
    int i, j;
    int index = -1;
    int station_count = 8;

    for (i = 0; i < 3; i++) {           // 行
        for (j = 0; j < 3; j++) {       // 列
            int x1 = 250 + 250 * j;
            int y1 = 455 + 75 * i;
            int x2 = x1 + 185;
            int y2 = y1 + 50;
            
            index = i * 3 + j;
            if (index >= station_count) break; // 超出快递数量则退出

            

            if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {

                // 恢复上一个按钮
                if (*last_index_station != -1 && *last_index_station != index) {
                    int pre_row = *last_index_station / 3;
                    int pre_col = *last_index_station % 3;
                    int pre_x1 = 250 + 250 * pre_col;
                    int pre_y1 = 455 + 75 * pre_row;
                    int pre_x2 = pre_x1 + 185;
                    int pre_y2 = pre_y1 + 50;

                    Fill_Rounded_Rectangle(pre_x1, pre_y1, pre_x2, pre_y2, 5, white);
                    Draw_Rounded_Rectangle(pre_x1, pre_y1, pre_x2, pre_y2, 5, 1, deepblue);
                    PrintText(pre_x1 + 40, pre_y1 + 13, stations[*last_index_station].name, HEI, 24, 1, deepblue);
                }

                // 当前按钮高亮
                Fill_Rounded_Rectangle(x1, y1, x2, y2, 5, deepblue);
                Draw_Rounded_Rectangle(x1, y1, x2, y2, 5, 1, deepblue);
                PrintText(x1 + 40, y1 + 13, stations[index].name, HEI, 24, 1, white);

                *last_index_station = index;
                return index + 1; // 返回驿站编号（1~8）
            }
        }
    }
    return -1; // 未选中任何按钮
}


void deliver_input(char *deliver_code,int bar_x1,int bar_y1,int bar_x2,int bar_y2)
{
	int length;
	char showtemp[2]= "\0";//存储输入字符,用于输入框展示
	int i=0,k,temp;  // i为字符个数,temp为从键盘上读取输入字符的ACSII码
	int bDeliver; //光标的横坐标	    
	int x1,y1;
	x1=bar_x1+4;
	y1=bar_y1+5;//光标相较于输入框的偏移量
	bDeliver=x1+4;//每个字符占8个像素,每输入一个字符光标右移8个像素
	
    if(deliver_code[0]=='\0') //如果取件码为空，则显示输入框
        bar1(bar_x1, bar_y1, bar_x2, bar_y2,0xFFFF);
    else
    {            //光标定位至文本末尾
        length=strlen(deliver_code);
        i=length;
        bDeliver+=12*i;
        cursor(bDeliver,y1);
    }	

	while(1) 
    {
		cursor(bDeliver,y1);
		if(mouse_location(455,255,845,295)==1 && mouse_location(455,335,845,375)==1 && mouse_location(455,415,845,455)==1)
			mouse_show_cursor(&mouse);
		else
			mouse_show_arrow(&mouse);
		if(bioskey(1)) //如果有键盘输入
		{
			temp=bioskey(0)&0x00ff; //获取键盘输入
			if(temp!='\r'&&temp!='\n')	//检测输入不为回车键，则继续，否则输入结束
			{
				if((('0'<=temp&&temp<='9')||('a'<=temp&&temp<='z')||('A'<=temp && temp<='Z')||(temp=='-'))&& i <10)//检测为数字或字母或-，则记录
				{
					hide_cursor(bDeliver,y1); //隐藏原光标
					
					deliver_code[i]=temp;//字符送入给定字符串，用于保存取件码信息
								
					*showtemp=temp;  //temp转化为字符串
					PrintText(bDeliver,y1+2,showtemp,HEI,24,1,0); //显示新的字符串达到画面与实际输入的同步
					i++;	//字符个数自增
					
					deliver_code[i]='\0';//标记字符串结尾
							
					bDeliver+=12;	//光标横坐标右移12像素
					draw_cursor(bDeliver,y1);
				}
				else if(temp=='\b'&&i>0)  //检测是否为退格键，是则消除前一个字符
				{
					hide_cursor(bDeliver,y1);	//隐藏原光标
					bDeliver-=12;	//光标左移12像素
					i--;	//字符个数自减
				
					deliver_code[i]='\0';//将存储的字符用0覆盖
					
					bar1(bDeliver,y1,bDeliver+10, y1+24, 0xffff);	//清空原字符
					draw_cursor(bDeliver,y1);
				}
				else if(i>=10)
				{
					mouse_off_arrow(&mouse);
					mouse_show_arrow(&mouse);
					PrintCC(750,120,"长度超过限制",HEI,24,1,lightred);
					delay(500);
					bar1(750,120,900,160,white);
				}
			}
			else
			{	
				break;
			}
		}
		else if (mouse_press(bar_x1,bar_y1,bar_x2,bar_y2)==2)  //点击框外
		{
			hide_cursor(bDeliver,y1);//隐藏光标
			break;
		}	
	}
}	

int Deliver_pos(DeliverList DL,Deliver delivers)
{
	int i=-1;
	for(i=0;i<DL.length;i++)
	{
		if(delivers.id == DL.elem[i].id)
		{
			return i;
		}	
	}
	return -1;
}

void DListInsert(DeliverList*DL,Deliver delivers) 
{
    Deliver*newbase=NULL;//创建新基址
    if(DL->length>=DL->listsize)//如果线性表已满
    {
        if((newbase=(Deliver*)realloc(DL->elem,(DL->listsize+D_LISTINCEREMENT)*sizeof(Deliver)))==NULL)////重新分配内存
        {
        CloseSVGA();
        printf("No enough memory!\n");
        printf("DListInsert\n");
        exit(-1);
        }
        DL->elem=newbase;//更新基址
        DL->listsize+=D_LISTINCEREMENT;//更新线性表容量
    }
    *(DL->elem+(DL->length))=delivers;//插入新元素
    DL->length++;//线性表长度加一
}

int save_Deliver(Deliver delivers) {
    int i = 0;
    DeliverList DL = {0};
	int deliver_pos;
	FILE *fp = NULL;

	ReadAllDeliver(&DL);//读取所有订单信息

    if ((fp = fopen("data\\Deliver.dat", "wb")) == NULL) {
        printf("无法打开文件！\n");
        return -1;
    }

    // 先查找订单是否已经存在
	deliver_pos = Deliver_pos(DL, delivers);

	if (deliver_pos == -1)  // 如果订单不存在
	{
		DListInsert(&DL, delivers); // 插入订单
	}
	else  // 如果订单存在，更新原有订单信息
	{
		delivers.id = DL.elem[deliver_pos].id; // 保留原订单ID
		DL.elem[deliver_pos] = delivers;
	}


    // 重新将线性表写入文件
    rewind(fp);//将文件指针移动到文件开头
    fwrite(&DL.length, sizeof(short), 1, fp);//写入线性表长度
    fwrite(&DL.listsize, sizeof(short), 1, fp);//写入线性表容量
 
    // 逐个写入数据
    for (i = 0; i < DL.length; i++) {
        fwrite(&DL.elem[i], sizeof(Deliver), 1, fp);
    }

    fclose(fp);
    DestroyDList(&DL);
    return 0;
}

//保存线性表
void save_DL(DeliverList *DL) {
    int i;
    FILE *fp = NULL;

	if ((fp = fopen("data\\Deliver.dat", "wb")) == NULL) {
        printf("无法打开文件！\n");
        return ;
    }
    // 重新将线性表写入文件
    rewind(fp);//将文件指针移动到文件开头
    fwrite(&DL->length, sizeof(short), 1, fp);//写入线性表长度
    fwrite(&DL->listsize, sizeof(short), 1, fp);//写入线性表容量
 
    // 逐个写入数据
    for (i = 0; i < DL->length; i++) {
        fwrite(&DL->elem[i], sizeof(Deliver), 1, fp);
    }

    fclose(fp);
}

void DestroyDList(DeliverList*DL)	
{
	free(DL->elem);
    DL->elem=NULL;
	DL->listsize=0;
	DL->length=0;
}

void ReadAllDeliver(DeliverList *DL) {
    int i = 0;
    short length = 0;//线性表初始长度
    short listsize = 10; //线性表初始容量（能够存储10个订单）
    FILE *fp = NULL;

    if ((fp = fopen("data\\Deliver.dat", "rb")) == NULL) {//如果打开文件失败
        fp = fopen("data\\Deliver.dat", "wb");// 如果文件不存在则创建一个新的文件
        if (fp == NULL) {//如果创建文件失败
            printf("无法创建文件！\n");
            return;//无法创建文件则返回，不需要继续执行下面的代码
        }
        fwrite(&length, sizeof(short), 1, fp); //如果创建成功则写入初始长度0
        fwrite(&listsize, sizeof(short), 1, fp); //写入初始容量10
        fclose(fp);//关闭文件
        return;//创建完成后返回，不需要继续执行下面的代码
    }
    //如果打开文件成功则读取长度和容量
    fread(&length, sizeof(short), 1, fp); 
    fread(&listsize, sizeof(short), 1, fp); 
    //把读取的长度和容量赋值给线性表
    DL->length = length;
    DL->listsize = listsize;
    DL->elem = (Deliver *)malloc(listsize * sizeof(Deliver)); //分配存储空间
    //如果线性表的存储空间分配失败则输出错误信息并退出程序
    if (DL->elem == NULL) {
        printf("No enough memory!\n");
        printf("ReadAllDeliver\n");
        fclose(fp);
        exit(-1);
    }
    //如果分配成功就逐个读取订单数据
    //并把读取的数据存储到线性表中
    for (i = 0; i < length; i++) {
        fread(&DL->elem[i], sizeof(Deliver), 1, fp);
    }

    fclose(fp);
}