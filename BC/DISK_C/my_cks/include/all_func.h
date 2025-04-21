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
#include "user_food.h"
#include "food_order.h"
#include "button.h"
#include "de_order.h"

#include "busi.h"
#include "busi_order.h"
#include "busi_det.h"

#include "ride.h"
#include "route.h"
#include "acp_order.h"
#include "account.h"
#include "HZK.h"
#include "draw_shape.h"
#include "arrange.h"
#include "acp_det.h"
extern MOUSE mouse;

extern USER users;

extern Shop shops;

extern Product products[84];
extern CartItem carts[84];
extern ShoppingCart cart;

extern Deliver delivers;

extern Food foods[12];
extern FoodCart food_carts[12];
extern ShoppingFood shopping_food;

extern Order orders;
extern Canteen canteen[17];

extern Node node[410];
extern Company companys[8];
extern Station stations[8];

extern Button button [79];
extern Acp_order acp_orders[4];
extern RouteState route_state;
#define white 0xFFFF
#define snow 0xFFDF
#define black 0x0000
#define deepblue 0x0235
#define lightblue 0x435c
#define skyblue 0xB71C
#define grey 0xC618
#define lightred 0XF800
#define Red 0xF800
#define deepgrew 0XC618
#define lightgrew 0xDEFB
#endif

