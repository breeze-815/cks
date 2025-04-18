#include <all_func.h>	
typedef unsigned char BYTE;

/***********************************************
Function:PrintCC
Description:输出一行(或竖排模式下的一列)汉字 
Input:
	x0,y0为字符串左上角的位置，str为纯汉字字符串，font为字体
	size为字体大小，tracking为字间距，color为字体颜色 
Return:void 
Remark:
	1.str必须为纯汉字字符串(可以包含空格)
	2.tracking是字间距，tracking=0时两个汉字紧邻而不是重合 
	3.font可选的值为
		FANGSONG(仿宋)
		HEI(黑体)
		KAI(楷体) 
		SONG(宋体)
		SONG_BOLD(粗宋体)
		TRADITIONAL(繁宋体)
		FANGSONG_VERT(竖排仿宋)
		HEI_VERT(竖排黑体)
		KAI_VERT(竖排楷体)
		SONG_VERT(竖排宋体)
		SONG_BOLD_VERT(竖排粗宋体)
		TRADITIONAL_VERT(竖排繁宋体)
	4.size可选值为12/16/24/32/48
	5.并不是每一种字体与字号的组合都有 
***********************************************/
void PrintCC(int x0,int y0,unsigned char str[],int font,int size,int tracking,int color)
{
	FILE *fpHZK=NULL;
	int vertical=0;//是否为纵向排版
	if(font>5)
	{
		vertical=1;
		font-=6;
	}
	//根据参数打开对应的字库文件
	//目前支持的字库列表(字体名称:支持的字体大小) 
	//     FANGSONG(仿宋):16,24,32,48
	//          HEI(黑体):16,24,32,48
	//          KAI(楷体):16,24,32,48
	//         SONG(宋体):12,16,24,32,48
	//  SONG_BOLD(粗宋体):16,32
	//TRADITIONAL(繁宋体):16
	if(font==FANGSONG)
	{
		if(size==16)
		{
			fpHZK=fopen(".\\font\\HZK16F","rb");
		}
		else if(size==24)
		{
			fpHZK=fopen(".\\font\\HZK24F","rb");
		}
		else if(size==32)
		{
			fpHZK=fopen(".\\font\\HZK32F","rb");
		}
		else if(size==48)
		{
			fpHZK=fopen(".\\font\\HZK48F","rb");
		}
	}
	else if(font==HEI)
	{
		if(size==16)
		{
			fpHZK=fopen(".\\font\\HZK16H","rb");
		}
		else if(size==24)
		{
			fpHZK=fopen(".\\font\\HZK24H","rb");
		}
		else if(size==32)
		{
			fpHZK=fopen(".\\font\\HZK32H","rb");
		}
		else if(size==48)
		{
			fpHZK=fopen(".\\font\\HZK48H","rb");
		}
	}
	else if(font==KAI)
	{
		if(size==16)
		{
			fpHZK=fopen(".\\font\\HZK16K","rb");
		}
		else if(size==24)
		{
			fpHZK=fopen(".\\font\\HZK24K","rb");
		}
		else if(size==32)
		{
			fpHZK=fopen(".\\font\\HZK32K","rb");
		}
		else if(size==48)
		{
			fpHZK=fopen(".\\font\\HZK48K","rb");
		}
	}
	else if(font==SONG)
	{
		if(size==12)
		{
			fpHZK=fopen(".\\font\\HZK12S","rb");
		}
		else if(size==16)
		{
			fpHZK=fopen(".\\font\\HZK16S","rb");
		}
		else if(size==24)
		{
			fpHZK=fopen(".\\font\\HZK24S","rb");
		}
		else if(size==32)
		{
			fpHZK=fopen(".\\font\\HZK32S","rb");
		}
		else if(size==48)
		{
			fpHZK=fopen(".\\font\\HZK48S","rb");
		}
	}
	else if(font==SONG_BOLD)
	{
		if(size==16)
		{
			fpHZK=fopen(".\\font\\HZK16S_B","rb");
		}
		else if(size==32)
		{
			fpHZK=fopen(".\\font\\HZK32S_B","rb");
		}
	}
	else if(font==TRADITIONAL)
	{
		if(size==16)
		{
			fpHZK=fopen(".\\font\\HZK16S_T","rb");
		}	
	}
	//判断指定字库文件是否存在，即是否打开成功
	if(fpHZK!=NULL)
	{
		int i,x,y;
		int Q,W;//当前汉字的区位码
		int BytePerCC=(size<=16?16:size)*size/8;//储存每个汉字所用字节数
		long offset;//当前汉字在字库文件中的位置偏移量
		BYTE fontMatrix[288];//字体点阵信息
		//遍历汉字字符串，每次处理两个字节
		for(i=0;str[i];i+=2)
		{
			//特殊判断空格 
			if(str[i]==' '&&str[i+1]==' ')
			{
				if(vertical)
				{
					y0+=size;
					y0+=tracking;
				}
				else
				{
					x0+=size;
					x0+=tracking;
				}
				continue;
			}
			//当前汉字的区位码
			Q=str[i]-0xA0; 
			W=str[i+1]-0xA0;
			//区位码从1开始标号，此处转换为从0开始 
			Q--,W--;
			//根据每个汉字所用字节数确定偏移量 
			offset=(long)(Q*94+W)*BytePerCC;
			//读取汉字字模，保存到fontMatrix中 
			fseek(fpHZK,offset,SEEK_SET);
			fread(fontMatrix,1,BytePerCC,fpHZK);
			//在屏幕上输出汉字 
			for(y=0;y<size;y++)
			{
				for(x=0;x<size;x++)
				{
					//当前像素点在fontMatrix中的位号
					//注意12*12汉字会被保存在16*12点阵中 
					int pos=(size<=16?16:size)*y+x;
					//判定出界 
					if(fontMatrix[pos/8]&(128>>(pos%8)))
					if(0<=x0+x&&x0+x<1024&&0<=y0+y&&y0+y<768)
					{
						Putpixel64k(x0+x,y0+y,color);
					}
				}
			}
			if(vertical)
			{
				y0+=size;
				//竖排文字向下移字间距的宽度 
				y0+=tracking;
			}
			else
			{
				x0+=size;
				//横排文字向右移字间距的宽度 
				x0+=tracking;
			}
		}
		fclose(fpHZK); 
	}
	return;
}

/***********************************************
Function:PrintText 
Description:输出一行文本
Input:
	x0,y0为字符串左上角的位置，str为文本字符串，font为字体
	size为字体大小，tracking为字间距，color为字体颜色 
Return:void 
Remark:
	1.此函数可以输出中英混排的字符串 
	2.tracking是汉字字间距，ASCII字符字间距为tracking/2
	3.font可选的值为
		FANGSONG(仿宋)
		HEI(黑体)
		KAI(楷体)
		SONG(宋体)
		SONG_BOLD(粗宋体)
		TRADITIONAL(繁宋体)
	4.size可选值为12/16/24/32/48
	5.12号字只可选择宋体，16号字六种字体均可选择
	6.ASCII字符的字体样式不随font的取值而改变
	7.为了排版的整体效果，12号英文整体下移1px，16号英文整体下移2px
***********************************************/
void PrintText(int x0, int y0, unsigned char str[], int font, int size, int tracking, int color)
{
    FILE *fpASC = NULL;
    FILE *fpHZK = NULL;

    char ascPath[64];
    char hzkPath[64];

    int width_char, width_hanzi;
    int height;
    int BytePerChar, BytePerCC;

    unsigned char fontMatrix[512]; // 足够容纳最大点阵
    int i, x, y;
    int isChar;
    int charWidth;
    int bytes;
    long offset;
    int ch, Q, W;
    int pos, draw_y;

    // 构造 ASCII 字体路径
    sprintf(ascPath, ".\\font\\ASC%d", size);

    // 构造 HZK 路径
    if (size == 12 && font == SONG)
        sprintf(hzkPath, ".\\font\\HZK12S");
    else if (size == 16)
    {
        if (font == FANGSONG) sprintf(hzkPath, ".\\font\\HZK16F");
        else if (font == HEI) sprintf(hzkPath, ".\\font\\HZK16H");
        else if (font == KAI) sprintf(hzkPath, ".\\font\\HZK16K");
        else if (font == SONG) sprintf(hzkPath, ".\\font\\HZK16S");
        else if (font == SONG_BOLD) sprintf(hzkPath, ".\\font\\HZK16S_B");
        else if (font == TRADITIONAL) sprintf(hzkPath, ".\\font\\HZK16S_T");
        else return;
    }
    else if (size == 24)
    {
        if (font == FANGSONG) sprintf(hzkPath, ".\\font\\HZK24F");
        else if (font == HEI) sprintf(hzkPath, ".\\font\\HZK24H");
        else if (font == KAI) sprintf(hzkPath, ".\\font\\HZK24K");
        else if (font == SONG) sprintf(hzkPath, ".\\font\\HZK24S");
        else return;
    }
    else if (size == 32)
    {
        if (font == FANGSONG) sprintf(hzkPath, ".\\font\\HZK32F");
        else if (font == HEI) sprintf(hzkPath, ".\\font\\HZK32H");
        else if (font == KAI) sprintf(hzkPath, ".\\font\\HZK32K");
        else if (font == SONG) sprintf(hzkPath, ".\\font\\HZK32S");
        else return;
    }
    else if (size == 48)
    {
        if (font == FANGSONG) sprintf(hzkPath, ".\\font\\HZK48F");
        else if (font == HEI) sprintf(hzkPath, ".\\font\\HZK48H");
        else if (font == KAI) sprintf(hzkPath, ".\\font\\HZK48K");
        else if (font == SONG) sprintf(hzkPath, ".\\font\\HZK48S");
        else return;
    }
    else
    {
        return; // 不支持字号
    }

    // 打开字体文件
    fpASC = fopen(ascPath, "rb");
    fpHZK = fopen(hzkPath, "rb");
    if (!fpASC || !fpHZK)
    {
        if (fpASC) fclose(fpASC);
        if (fpHZK) fclose(fpHZK);
        return;
    }

    // 计算字体参数
    width_char = size / 2;
	if (size == 24)
    {
        width_char = 16; // ASC24: 16*24 点阵字库
    }
    else if (size == 32)
    {
        width_char = 24; // ASC32: 24*32 点阵字库
    }
    else if (size == 48)
    {
        width_char = 32; // ASC48: 32*48 点阵字库
    }
    width_hanzi = size;
    height = size;
    BytePerChar = (width_char * height) / 8;
    BytePerCC = (width_hanzi * height) / 8;

    // 遍历字符
    for (i = 0; str[i]; i++)
    {
        isChar = (str[i] < 128);
        charWidth = isChar ? width_char : width_hanzi;
        bytes = isChar ? BytePerChar : BytePerCC;

        offset = 0;

        if (isChar)
        {
            ch = str[i];
            if (size == 12) ch -= 32;
            offset = (long)ch * BytePerChar;
            fseek(fpASC, offset, SEEK_SET);
            fread(fontMatrix, 1, BytePerChar, fpASC);
        }
        else
        {
            Q = str[i] - 0xA0;
            i++;
            W = str[i] - 0xA0;
            Q--; W--;
            offset = (long)(Q * 94 + W) * BytePerCC;
            fseek(fpHZK, offset, SEEK_SET);
            fread(fontMatrix, 1, BytePerCC, fpHZK);
        }

        // 显示点阵
        for (y = 0; y < height; y++)
        {
            for (x = 0; x < charWidth; x++)
            {
                pos = charWidth * y + x;
                if (fontMatrix[pos / 8] & (0x80 >> (pos % 8)))
                {
                    draw_y = y0 + y;
                    if (isChar)
                    {
                        if (size == 12) draw_y += 1;
                        else if (size == 16) draw_y += 2;
                    }

                    if (0 <= x0 + x && x0 + x < 1024 && 0 <= draw_y && draw_y < 768)
                    {
                        Putpixel64k(x0 + x, draw_y, color);
                    }
                }
            }
        }

        // 更新位置
        x0 += charWidth + (isChar ? tracking / 2 : tracking);
    }

    fclose(fpASC);
    fclose(fpHZK);
}


