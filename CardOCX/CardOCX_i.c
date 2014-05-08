

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu May 08 22:38:18 2014
 */
/* Compiler settings for CardOCX.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_ICardObject,0xCB9772BE,0x7669,0x47EE,0x90,0xAE,0xA1,0xEB,0x45,0xF0,0x2C,0xE8);


MIDL_DEFINE_GUID(IID, LIBID_CardOCXLib,0xE6078CCC,0x6FAA,0x4670,0xAA,0xBB,0x3C,0xB3,0xD9,0x18,0xE3,0xB7);


MIDL_DEFINE_GUID(IID, DIID__ICardObjectEvents,0xB4A99C75,0x0B07,0x4839,0x84,0xEA,0xF5,0xC7,0x27,0x58,0xA8,0x1C);


MIDL_DEFINE_GUID(CLSID, CLSID_CardObject,0x038090D9,0x4C74,0x4A87,0xBA,0x43,0x12,0xC4,0x8C,0x0D,0x29,0xFA);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



