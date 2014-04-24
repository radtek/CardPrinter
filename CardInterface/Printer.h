#ifndef PRINTER_H_
#define PRINTER_H_

#include <map>
#include <string>
#include <vector>
using namespace std;

typedef unsigned short int uint16; //�����ͣ�2�ֽ� 
typedef unsigned long int uint32;  //�����Σ�4�ֽ�

//�����ʹ�С�˻����������ֽڸߵ�λ
#define BigLittleSwap16(A) ((((uint16)(A) & 0xff00) >> 8) | (((uint16)(A) & 0x00ff) << 8)) 
//�����ʹ�С�˻��� 
#define BigLittleSwap32(A) ((((uint32)(A) & 0xff000000) >> 24) | (((uint32)(A) & 0x00ff0000) >> 8) | (((uint32)(A) & 0x0000ff00) << 8) | (((uint32)(A) & 0x000000ff) << 24))

//��֤������Big Endian Byte Order ���� Little Endian Byte Order
//�����Big Endian Byte Order����ô����1�����򷵻�0
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

// ģ��htonl�����������ֽ���ת�����ֽ���4�ֽ�����
#define HtoNl(A) (CheckCPUendian() ? (A) : BigLittleSwap32(A)) 
// ģ��ntohl�����������ֽ���ת�����ֽ��� 
#define NtoHl(A) HtoNl(A) 
// ģ��htons�����������ֽ���ת�����ֽ���2�ֽ�����
#define HtoNs(A) (CheckCPUendian() ? (A) : BigLittleSwap16(A)) 
// ģ��ntohs�����������ֽ���ת�����ֽ��� 
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

	/// @brief ��ӡ��Ƭ��������Ч���ں���ֵ
	///
	/// @param[in ] :expiredDate ��Ч����
	/// @param[in ] :parValue ��ֵ
	/// @param[in ] :password ��Ƭ����
	/// @param[in ] :permission �����ж���Ҫ��ӡ��Щֵ expiredDate(1)+parValue(2)+password(4)
	/// @param[in ] :back ��Ƭ���뷽ʽ���Ƿ��泯��
	/// @return     :True: done
	bool Print(char* expiredDate, int parValue, char * password, int permission,bool back);

	/// @brief ��ӡ��Ƭ��������Ч���ں���ֵ
	///
	/// @param[in ] :expiredDate ��Ч����
	/// @param[in ] :parValue ��ֵ
	/// @param[in ] :password ��Ƭ����
	/// @param[in ] :name ����
	/// @param[in ] :level �ͻ��㼶
	/// @param[in ] :permission �����ж���Ҫ��ӡ��Щֵ expiredDate(1)+parValue(2)+password(4)
	/// @param[in ] :back ��Ƭ���뷽ʽ���Ƿ��泯��
	/// @param[out ] :printedItem ���ڼ�¼��ǰ�Ѿ���ӡ����Щ�� expiredDate(1)+parValue(2)+password(4)
	/// @return     :True: done
	bool Print(char* expiredDate, int parValue, char * password, char* name, char* level, int permission,bool back, int & printedItem);

	/// @brief ��ӡ��Ƭ����
	///
	/// @param[in ] :password ��Ƭ����
	/// @return     :True: done
	bool PrintPassword(char* password);

	/// @brief ������Ƭ
	///
	/// @return     :True: done
	bool EjectCardApp();

protected:
	char DriverName[128];

	char PrinterName[128];    //��ӡ������

private:
	/// @brief ��ȡ��ӡ��״̬��Ϣ
	///
	/// @param[in ] :session established session with the status monitor
	void GetPrinterMessage(HANDLE session);
	void GetRandom(char* random, int size);

	map<string,int> printerErrors;
	string lastErrorMessage;
};

#endif // PRINTER_H_
