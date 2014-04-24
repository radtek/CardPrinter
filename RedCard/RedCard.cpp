#include "RedCard.h"
#include "ws/soapH.h"
#include "ws/soapPrinterServiceServiceSoapBindingProxy.h"
#include "ws/PrinterServiceServiceSoapBinding.nsmap"
#include "ws/Codec.h"
#include "DBAdo.h"

CRedCard::CRedCard(const char* serviceURL,const char* dbURL)
{
	strcpy(this->serviceURL,serviceURL);
	strcpy(this->dbURL,dbURL);
	this->serviceProxy = new PrinterServiceServiceSoapBindingProxy(this->serviceURL);
	soap_set_mode(this->serviceProxy,SOAP_C_UTFSTRING);
	this->dbAdo = new CDBAdo();
	this->dbAdo->CreateInstance();
	this->dbAdo->SetConnectionString(this->dbURL);
}

CRedCard::~CRedCard()
{	
	if(this->serviceProxy!=NULL)
		delete serviceProxy;
	if(this->dbAdo!=NULL)
		delete dbAdo;
}

const char* CRedCard::GetErrorMessage()
{
	return lastErrorMessage.c_str();
}

void CRedCard::SetErrorMessage(const char* error)
{
	lastErrorMessage.clear();
	lastErrorMessage.append(error);
}

bool CRedCard::isAlive()
{
	return false;
}

bool CRedCard::Login(char* loginName, char* password, User* user)
{
	bool result = false;
	ns1__verifyUser request;
	ns1__verifyUserResponse response;
	WSRequestData requestData;
	WSResponseData responseData;
	std::map<std::string, ParamValue> entity;
	AddEntity(requestData,entity);
	AddParameter(requestData, "loginName",loginName);
	AddParameter(requestData, "password",password);

	std::string data = Encode(requestData); 
	char * content = new char[data.size()];
	memset(content,0x00,sizeof(content));
	strcpy(content,data.c_str());
	request.arg0 = content;

	int status = serviceProxy->verifyUser(this->serviceURL,"",&request,&response);
	if(status==SOAP_OK)
	{
		Decode(string(response.return_), responseData);
		if(responseData.isError==true)
		{
			SetErrorMessage(responseData.message.c_str());
		} else 
		{
			result = true;
			std::list<std::map<std::string, ParamValue>> entities = responseData.entities;
			if(entities.size()>0)
			{
				memset(&currentUser,0x00,sizeof(currentUser));
				std::map<std::string, ParamValue> entity = responseData.entities.front();
				ParamValue* value = GetParameter(entity,"userId");
				strcpy(user->userId,value->asString().c_str());
				strcpy(currentUser.userId,user->userId);
				value = GetParameter(entity,"loginName");
				strcpy(user->loginName,value->asString().c_str());
				strcpy(currentUser.loginName,user->loginName);
				value = GetParameter(entity,"userName");
				strcpy(user->userName,value->asString().c_str());
				strcpy(currentUser.userName,user->userName);
			} else 
			{
				SetErrorMessage("用户校验失败");
			}
		}
	} else 
	{
		SetErrorMessage("请求后台失败");
	}
	return result;
}

bool CRedCard::GeneratePassword(char* password)
{
	bool result = false;
	ns1__generatePassword request;
	ns1__generatePasswordResponse response;
	WSResponseData wsResponse;
	int status = serviceProxy->generatePassword(this->serviceURL,"",&request,&response);
	if(status==SOAP_OK)
	{
		Decode(string(response.return_), wsResponse);
		if(wsResponse.isError==true)
		{
			SetErrorMessage(wsResponse.message.c_str());
		} else 
		{
			result = true;
			std::list<std::map<std::string, ParamValue>> entities = wsResponse.entities;
			if(entities.size()>0)
			{
				ParamValue* value = GetParameter(wsResponse.entities.front(),"password");
				strcpy(password,value->asString().c_str());
			} else 
			{
				SetErrorMessage("未获得密码");
			}
		}
	} else 
	{
		SetErrorMessage("请求后台失败");
	}
	return result;
}

/**
bool CRedCard::GetCardTypeRules(list<CardTypeRule>* cardTypeRules)
{
	bool result = true;
	if(this->dbAdo->OpenConnection() && this->dbAdo->OpenRecordset("select fldId,fldName from tblCardTyperule"))
	{
		string strData;
		for(int i=0; i<this->dbAdo->GetRecordCount(); i++)
		{
			CardTypeRule cardTypeRule;
			memset(&cardTypeRule,0x00,sizeof(cardTypeRule));
			this->dbAdo->GetFieldValue("fldId", cardTypeRule.id);
			strData.clear();
			this->dbAdo->GetFieldValue("fldName",strData);
			memcpy(cardTypeRule.name,strData.c_str(),strData.size());
			this->dbAdo->MoveToNext();
			cardTypeRules->push_back(cardTypeRule);
		}
	} else 
	{
		this->SetErrorMessage(this->dbAdo->GetLastError());
		result = false;
	}
	this->dbAdo->CloseConnection();
	return result;
}
**/

bool CRedCard::GetCardTypeRules(list<CardTypeRule>* cardTypeRules)
{
	bool result = false;
	ns1__getCardTypeRules request;
	ns1__getCardTypeRulesResponse response;
	WSResponseData wsResponse;
	int status = serviceProxy->getCardTypeRules(this->serviceURL,"",&request,&response);
	if(status==SOAP_OK)
	{
		Decode(string(response.return_), wsResponse);
		if(wsResponse.isError==true)
		{
			SetErrorMessage(wsResponse.message.c_str());
		} else 
		{
			result = true;
			std::list<std::map<std::string, ParamValue>> entities = wsResponse.entities;
			if(entities.size()>0)
			{
				std::list<std::map<std::string, ParamValue>>::iterator iter;
				for(iter=entities.begin();iter!=entities.end();iter++)
				{
					std::map<std::string, ParamValue> entity = *iter;
					CardTypeRule cardTypeRule;
					memset(&cardTypeRule,0x00,sizeof(cardTypeRule));

					ParamValue* value = GetParameter(entity,"id");
					strcpy(cardTypeRule.id,value->asString().c_str());
					value = GetParameter(entity,"name");
					strcpy(cardTypeRule.name,value->asString().c_str());
					cardTypeRules->push_back(cardTypeRule);
				}
			} else 
			{
				SetErrorMessage("未获得卡规则");
			}
		}
	} else 
	{
		SetErrorMessage("请求后台失败");
	}
	return result;
}

bool CRedCard::StoreCard(Card ** cards, int size, Card** pendingList, int& pendingSize)
{
	soap soap;
	soap_init(&soap);
	soap_set_mode(&soap,SOAP_C_UTFSTRING);
	soap.mode |= SOAP_C_UTFSTRING;

	bool result = false;
	ns1__storeCard request;
	ns1__storeCardResponse response;
	WSRequestData requestData;
	WSResponseData wsResponse;
	list<Card*>::iterator iter;
	for(int i=0;i<size;i++)
	{
		Card * card = cards[i];
		std::map<std::string, ParamValue> entity;
		AddEntity(requestData,entity);
		AddParameter(requestData, "cardNo",card->cardNo);
		AddParameter(requestData, "expiredDate",card->expiredDate);
		AddParameter(requestData, "cardFaceValue",card->cardFaceValue);
		AddParameter(requestData, "secondTrack",card->secondTrack);
		AddParameter(requestData, "payPassword",card->payPassword);
		AddParameter(requestData, "cardTypeRuleId",card->cardTypeRuleId);
		AddParameter(requestData, "operateId",card->operateId);
		AddParameter(requestData, "phyid",card->phyid);
	}
	std::string data = Encode(requestData); 
	char * content = new char[data.size()];
	memset(content,0x00,sizeof(content));
	strcpy(content,data.c_str());
	request.arg0 = content;
	int status = serviceProxy->storeCard(this->serviceURL,"",&request,&response);
	if(status==SOAP_OK)
	{
		Decode(string(response.return_), wsResponse);
		if(wsResponse.isError)
		{
			SetErrorMessage(wsResponse.message.c_str());
		} else 
		{
			//actually, it's success message here
			SetErrorMessage(wsResponse.message.c_str());
			result = true;	
			std::list<std::map<std::string, ParamValue>> entities = wsResponse.entities;
			if(entities.size()>0)
			{
				std::list<std::map<std::string, ParamValue>>::iterator iter;
				int i=0;
				for(iter=entities.begin();iter!=entities.end();iter++)
				{
					std::map<std::string, ParamValue> entity = *iter;
					Card card;
					memset(&card,0x00,sizeof(card));

					ParamValue* value = GetParameter(entity,"cardNo");
					strcpy(card.cardNo,value->asString().c_str());
					value = GetParameter(entity,"expiredDate");
					strcpy(card.expiredDate,value->asString().c_str());
					value = GetParameter(entity,"cardFaceValue");
					strcpy(card.cardFaceValue,value->asString().c_str());
					value = GetParameter(entity,"secondTrack");
					strcpy(card.secondTrack,value->asString().c_str());
					value = GetParameter(entity,"payPassword");
					strcpy(card.payPassword,value->asString().c_str());
					value = GetParameter(entity,"cardTypeRuleId");
					strcpy(card.cardTypeRuleId,value->asString().c_str());
					value = GetParameter(entity,"comment");
					strcpy(card.comment,value->asString().c_str());
					
					pendingList[i++] = &card;
					pendingSize++;
				}
			}
		}
	} else 
	{
		SetErrorMessage("请求后台失败");
	}
	//delete[] content;
	return result;
}

bool CRedCard::GetMainKey(char* mainKey)
{
	bool result = false;
	ns1__getMainKey request;
	ns1__getMainKeyResponse response;
	WSResponseData wsResponse;
	int status = serviceProxy->getMainKey(this->serviceURL,"",&request,&response);
	if(status==SOAP_OK)
	{
		Decode(string(response.return_), wsResponse);
		if(wsResponse.isError==true)
		{
			SetErrorMessage(wsResponse.message.c_str());
		} else 
		{
			result = true;
			std::list<std::map<std::string, ParamValue>> entities = wsResponse.entities;
			if(entities.size()>0)
			{
				ParamValue* value = GetParameter(wsResponse.entities.front(),"mainKey");
				strcpy(mainKey,value->asString().c_str());
			} else 
			{
				SetErrorMessage("未获得根密钥");
			}
		}
	} else 
	{
		SetErrorMessage("请求后台失败");
	}
	return result;
}

bool CRedCard::GeneratePsamCardNo(char* cardNo)
{
	bool result = false;
	ns1__generatePsamCardNo request;
	ns1__generatePsamCardNoResponse response;
	WSResponseData wsResponse;
	int status = serviceProxy->generatePsamCardNo(this->serviceURL,"",&request,&response);
	if(status==SOAP_OK)
	{
		Decode(string(response.return_), wsResponse);
		if(wsResponse.isError==true)
		{
			SetErrorMessage(wsResponse.message.c_str());
		} else 
		{
			result = true;
			std::list<std::map<std::string, ParamValue>> entities = wsResponse.entities;
			if(entities.size()>0)
			{
				ParamValue* value = GetParameter(wsResponse.entities.front(),"cardNo");
				strcpy(cardNo,value->asString().c_str());
			} else 
			{
				SetErrorMessage("未获得PSAM卡号");
			}
		}
	} else 
	{
		SetErrorMessage("请求后台失败");
	}
	return result;
}

bool CRedCard::StorePsamCard(Psam *psam)
{
	soap soap;
	soap_init(&soap);
	soap_set_mode(&soap,SOAP_C_UTFSTRING);
	soap.mode |= SOAP_C_UTFSTRING;

	bool result = false;
	ns1__storePsamCard request;
	ns1__storePsamCardResponse response;
	WSRequestData requestData;
	WSResponseData wsResponse;
	

	std::map<std::string, ParamValue> entity;
	AddEntity(requestData,entity);
	AddParameter(requestData, "cardNo",psam->cardNo);
	AddParameter(requestData, "operateId",psam->operateId);
	
	std::string data = Encode(requestData); 
	char * content = new char[data.size()];
	memset(content,0x00,sizeof(content));
	strcpy(content,data.c_str());
	request.arg0 = content;
	int status = serviceProxy->storePsamCard(this->serviceURL,"",&request,&response);
	if(status==SOAP_OK)
	{
		Decode(string(response.return_), wsResponse);
		if(wsResponse.isError)
		{
			SetErrorMessage(wsResponse.message.c_str());
		} else 
		{
			//actually, it's success message here
			SetErrorMessage(wsResponse.message.c_str());
			result = true;	
		}
	} else 
	{
		SetErrorMessage("请求后台失败");
	}
	//delete[] content;
	return result;
}