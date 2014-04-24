#ifndef PRINTER_H_
#define PRINTER_H_

#include <map>
#include <string>
#include <vector>
using namespace std;

typedef unsigned short int uint16; //短整型，2字节 
typedef unsigned long int uint32;  //长整形，4字节

//短整型大小端互换，交换字节高低位
#define BigLittleSwap16(A) ((((uint16)(A) & 0xff00) >> 8) | (((uint16)(A) & 0x00ff) << 8)) 
//长整型大小端互换 
#define BigLittleSwap32(A) ((((uint32)(A) & 0xff000000) >> 24) | (((uint32)(A) & 0x00ff0000) >> 8) | (((uint32)(A) & 0x0000ff00) << 8) | (((uint32)(A) & 0x000000ff) << 24))

//验证本机是Big Endian Byte Order 还是 Little Endian Byte Order
//如果是Big Endian Byte Order，那么返回1，否则返回0
inline
int CheckCPUendian() 
{ 
	union
	{ 
		unsigned long int i; 
		unsigned char s[4]; 
	}c = {0x12345678}; 
	return (0x12 == c.s[0]); 
}

// 模拟htonl函数，本机字节序转网络字节序，4字节整形
#define HtoNl(A) (CheckCPUendian() ? (A) : BigLittleSwap32(A)) 
// 模拟ntohl函数，网络字节序转本机字节序 
#define NtoHl(A) HtoNl(A) 
// 模拟htons函数，本机字节序转网络字节序，2字节整形
#define HtoNs(A) (CheckCPUendian() ? (A) : BigLittleSwap16(A)) 
// 模拟ntohs函数，网络字节序转本机字节序 
#define NtoHs(A) HtoNs(A)

#define random(x) (rand()%x)

class CPrinter
{
public:
	CPrinter();
	virtual	~CPrinter();

	void SetDriverName(char *);

	char* GetDriverName();

	void SetPrinterName(char *);

	char* GetPrinterName();

	/// @brief get last error message
	///
	/// @return     :error message
	string GetErrorMessage();

	/// @brief Write the specific magnetic track
	///
	/// @param[in ] :trackNo the index of magnetic 
	/// @param[in ] :trackInfo magnetic track data
	/// @return     :True: done
	bool WriteTrack(int trackNo, string &trackInfo);

	/// @brief Read the specific magnetic track
	///
	/// @param[in ] :trackNo the index of magnetic 
	/// @param[out] :trackInfo magnetic track data
	/// @return     :True: done
	bool ReadTrack(int trackNo, string &trackInfo);

	bool ReadAllTrack(char *trackInfo1, char *trackInfo2, char *trackInfo3);

	/// @brief Read the specific magnetic track
	///
	/// @param[in ] :trackNo the index of magnetic 
	/// @param[out] :trackInfo magnetic track data
	/// @return     :True: done
	bool ReadAllTrack(string &trackInfo);

	HFONT GetFont(HDC hd,int height);

	/// @brief 打印卡片，包括有效日期和面值
	///
	/// @param[in ] :expiredDate 有效日期
	/// @param[in ] :parValue 面值
	/// @param[in ] :password 卡片密码
	/// @param[in ] :permission 用于判定需要打印哪些值 expiredDate(1)+parValue(2)+password(4)
	/// @param[in ] :back 卡片输入方式，是否背面朝上
	/// @return     :True: done
	bool Print(char* expiredDate, int parValue, char * password, int permission,bool back);

	/// @brief 打印卡片，包括有效日期和面值
	///
	/// @param[in ] :expiredDate 有效日期
	/// @param[in ] :parValue 面值
	/// @param[in ] :password 卡片密码
	/// @param[in ] :name 姓名
	/// @param[in ] :level 客户层级
	/// @param[in ] :permission 用于判定需要打印哪些值 expiredDate(1)+parValue(2)+password(4)
	/// @param[in ] :back 卡片输入方式，是否背面朝上
	/// @param[out ] :printedItem 用于记录当前已经打印了哪些项 expiredDate(1)+parValue(2)+password(4)
	/// @return     :True: done
	bool Print(char* expiredDate, int parValue, char * password, char* name, char* level, int permission,bool back, int & printedItem);

	/// @brief 打印卡片密码
	///
	/// @param[in ] :password 卡片密码
	/// @return     :True: done
	bool PrintPassword(char* password);

	/// @brief 弹出卡片
	///
	/// @return     :True: done
	bool EjectCardApp();

protected:
	char DriverName[128];

	char PrinterName[128];    //打印机名称

private:
	/// @brief 获取打印机状态信息
	///
	/// @param[in ] :session established session with the status monitor
	void GetPrinterMessage(HANDLE session);
	void GetRandom(char* random, int size);

	map<string,int> printerErrors;
	string lastErrorMessage;
};

#endif // PRINTER_H_
