#pragma once
#ifndef Header_H_
#define Header_H_

typedef struct tagPsamCard
{
    char psamCardNo[21];		//PSAM����
    int cardType;		        //PSAM������
    int cardVersion;		    //���汾
    char termId[13];	        //�ն˱��
    int termSeqNo;		    //�ն˽������
    int keyIndex;		        //��Կ������
    char startDate[9];	    //��������
    char expireDate[9];       //��Ч����
    char publishId[17];	    //���з���ʶ
    char userId[17];	        //ʹ�÷���ʶ
} PsamCard;                 //PSAM����Ϣ

#endif