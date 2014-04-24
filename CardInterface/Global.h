#pragma once
#ifndef GLOBAL_H_
#define GLOBAL_H_

#ifndef uint8
#define uint8  unsigned char
#endif

#define CHECK_PRINTER() if(printer==NULL) {lastErrorMessage.clear();lastErrorMessage.append("没有找到打印机");return NO_PRINTER;}

//系统返回码定义
#define SUCCESS 0                           //成功
#define NO_PRINTER 1001                     //未找到打印机
#define ERR_READ_TRACK 1002                 //读取磁道信息失败
#define ERR_WRITE_TRACK 1003                //写磁道信息失败

#define OK_PRINTER           0
#define ERR_PRINTER          1103
#define ERR_CDE              1104
#define ERR_PAR              1105
#define ERR_NEED_CLEAN       1107
#define ERR_TIME             1111
#define ERR_MECA_HOPPER      1113
#define ERR_HOPPER_FULL      1114
#define ERR_HOPPER_DOOR      1115
#define ERR_PRINT_HEAD       1116
#define ERR_COVER            1117
#define ERR_FEEDER           1118
#define ERR_CARD_JAM         1119
#define ERR_RIBBON           1120
#define ERR_FLASH            1122
#define ERR_CHECKSUM         1123
#define ERR_OPTION           1124
#define ERR_CHECK_M          1126
#define ERR_DATA_M           1127
#define ERR_WRITE_M          1128
#define	ERR_UNKNOW           1129
#define ERR_PRINT            1201
#define ERR_READ             1301
#define ERR_WRITE            1401
#define ERR_EJECT            1501
#define ERR_LOGIN            1601
#define ERR_GENERATE_P       1602

#define PRINT_EXPIRED_DATE   0x01
#define PRINT_PAR_VALUE      0x02
#define PRINT_PASSWORD       0x04
#define PRINT_RANDOM         0x08
#define PRINT_NAME           0x10
#define PRINT_LEVEL          0x20

typedef struct tagCardTypeRule
{
	char id[20];	        
	char name[200];	
	int cardLength;
	int binLength;
	int seqLength;
	int areaLength;
	int checkLength;
	int binStartPosition;
	int seqStartPosition;
	int areaStartPosition;
	int checkStartPosition;
	int fixedLength;
	int fixedStartPosition;
} CardTypeRule; //卡规则

typedef struct tagCard
{      
	char cardNo[20];	
	char expiredDate[20];
	char cardFaceValue[20];
	char secondTrack[50];
	char payPassword[20];
	char cardTypeRuleId[20];
	char operateId[20];
	char comment[2000];
	char phyid[50];
} Card; //卡规则

typedef struct tagUser
{      
	char userId[50];	
	char loginName[20];
	char userName[50];
} User; //卡规则

typedef struct tagPsam
{      
	char cardNo[50];	
	char operateId[20];
	char comment[2000];
} Psam; //卡规则

#endif