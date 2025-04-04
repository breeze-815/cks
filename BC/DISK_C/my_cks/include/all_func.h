#ifndef __ALL_FUNC_H__
#define __ALL_FUNC_H__

#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<bios.h>
#include<string.h>
#include<dos.h>
#include<math.h>
#include<time.h>


#include "mouse.h"
#include "SVGA.H"

#include "user_re.h"
#include "welcome.h"
#include "lgfunc.h"

#include "user.h"
#include "user_shop.h"
#include "user_take.h"
#include "user_de.h"
#include "user_cart.h"
#include "user_order.h"

#include "busi.h"
#include "busi_order.h"
#include "busi_det.h"

#include "ride.h"


#include "HZK.h"
#include "draw_shape.h"

extern MOUSE mouse;
extern USER users;
extern Shop shops;
extern Product products[50];
extern CartItem carts[50];
extern ShoppingCart cart;
extern Deliver deliver;
extern Order orders;

#define white 0xFFFF
#define snow 0xFFDF
#define black 0x0000
#define deepblue 0x0235
#define lightblue 0x435c
#define skyblue 0xB71C
#define grey 0xC618
#define lightred 0XF800

#endif

