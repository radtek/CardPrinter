#ifndef REDCARD_H_
#define REDCARD_H_

#ifdef REDCARD_EXPORTS
#define REDCARD_API __declspec(dllexport)
#else
#define REDCARD_API __declspec(dllimport)
#endif

#include <string>
#include <list>
#include <map>
using namespace std;
#include "../CardInterface/Global.h"

class PrinterServiceServiceSoapBindingProxy;
class CDBAdo;

class REDCARD_API CRedCard
{
public:
	CRedCard(const char* serviceURL,const char* dbURL);
	virtual	~CRedCard();

	/// @brief check if the backend is alive
	///
	/// @return     :True: alive
	bool isAlive();

    bool Login(char* loginName, char* password, User* user);

    /// @brief get last error message
	///
	/// @return     :error message
	const char* GetErrorMessage(); 

	/// @brief get last error message
	///
	/// @return     :error message
	void SetErrorMessage(const char *error);

	bool GeneratePassword(char* password); 

    bool GetCardTypeRules(list<CardTypeRule>* cardTypeRules);

    bool StoreCard(Card **cards, int size, Card **pendingList, int& pendingSize);

	bool GetMainKey(char* mainKey); 

	bool GeneratePsamCardNo(char* cardNo); 

	bool StorePsamCard(Psam *psam);

protected:

private:
	PrinterServiceServiceSoapBindingProxy* serviceProxy;
    CDBAdo* dbAdo;
    string lastErrorMessage;
	char serviceURL[200];
	char dbURL[200];
	User currentUser;
};

#endif // REDCARD_H_