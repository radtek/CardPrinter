

/* this ALWAYS GENERATED file contains the proxy stub code */


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

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "CardOCX_i.h"

#define TYPE_FORMAT_STRING_SIZE   1075                              
#define PROC_FORMAT_STRING_SIZE   487                               
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   2            

typedef struct _CardOCX_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } CardOCX_MIDL_TYPE_FORMAT_STRING;

typedef struct _CardOCX_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } CardOCX_MIDL_PROC_FORMAT_STRING;

typedef struct _CardOCX_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } CardOCX_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const CardOCX_MIDL_TYPE_FORMAT_STRING CardOCX__MIDL_TypeFormatString;
extern const CardOCX_MIDL_PROC_FORMAT_STRING CardOCX__MIDL_ProcFormatString;
extern const CardOCX_MIDL_EXPR_FORMAT_STRING CardOCX__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ICardObject_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ICardObject_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const CardOCX_MIDL_PROC_FORMAT_STRING CardOCX__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure OCX_Init */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x24 ),	/* 36 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter retValue */

/* 24 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OCX_About */

/* 36 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 38 */	NdrFcLong( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 46 */	NdrFcShort( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 52 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 54 */	NdrFcShort( 0x1 ),	/* 1 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter message */

/* 60 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 62 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 64 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 66 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 68 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 70 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OCX_ReadTrack */

/* 72 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 74 */	NdrFcLong( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x9 ),	/* 9 */
/* 80 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 82 */	NdrFcShort( 0x6 ),	/* 6 */
/* 84 */	NdrFcShort( 0x8 ),	/* 8 */
/* 86 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 88 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 90 */	NdrFcShort( 0x1 ),	/* 1 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter trackNo */

/* 96 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 98 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 100 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter trackInfo */

/* 102 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 106 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 108 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 110 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OCX_WriteTrack */

/* 114 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 116 */	NdrFcLong( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0xa ),	/* 10 */
/* 122 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 124 */	NdrFcShort( 0x6 ),	/* 6 */
/* 126 */	NdrFcShort( 0x24 ),	/* 36 */
/* 128 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 130 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 134 */	NdrFcShort( 0x1 ),	/* 1 */
/* 136 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter trackNo */

/* 138 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 140 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 142 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter trackInfo */

/* 144 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 146 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 148 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Parameter retValue */

/* 150 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 152 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 154 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 156 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 158 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 160 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OCX_GetLastError */

/* 162 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 164 */	NdrFcLong( 0x0 ),	/* 0 */
/* 168 */	NdrFcShort( 0xb ),	/* 11 */
/* 170 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 174 */	NdrFcShort( 0x8 ),	/* 8 */
/* 176 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 178 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 180 */	NdrFcShort( 0x1 ),	/* 1 */
/* 182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 184 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter message */

/* 186 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 188 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 190 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 192 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 194 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 196 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OCX_EjectCard */

/* 198 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 200 */	NdrFcLong( 0x0 ),	/* 0 */
/* 204 */	NdrFcShort( 0xc ),	/* 12 */
/* 206 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 210 */	NdrFcShort( 0x24 ),	/* 36 */
/* 212 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 214 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 220 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter retValue */

/* 222 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 224 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 228 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 230 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 232 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OCX_PrintPassword */

/* 234 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 236 */	NdrFcLong( 0x0 ),	/* 0 */
/* 240 */	NdrFcShort( 0xd ),	/* 13 */
/* 242 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 246 */	NdrFcShort( 0x24 ),	/* 36 */
/* 248 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 250 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 254 */	NdrFcShort( 0x1 ),	/* 1 */
/* 256 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter password */

/* 258 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 260 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 262 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Parameter retValue */

/* 264 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 266 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 268 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 270 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 272 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 274 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OCX_SetPrinter */

/* 276 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 278 */	NdrFcLong( 0x0 ),	/* 0 */
/* 282 */	NdrFcShort( 0xe ),	/* 14 */
/* 284 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 288 */	NdrFcShort( 0x24 ),	/* 36 */
/* 290 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 292 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 296 */	NdrFcShort( 0x1 ),	/* 1 */
/* 298 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter printerName */

/* 300 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 302 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 304 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Parameter retValue */

/* 306 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 308 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 310 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 312 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 314 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 316 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OCX_GetPrinters */

/* 318 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 320 */	NdrFcLong( 0x0 ),	/* 0 */
/* 324 */	NdrFcShort( 0xf ),	/* 15 */
/* 326 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 330 */	NdrFcShort( 0x8 ),	/* 8 */
/* 332 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 334 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 336 */	NdrFcShort( 0x1 ),	/* 1 */
/* 338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 340 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter printers */

/* 342 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 344 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 346 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 348 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 350 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 352 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OCX_PrintAll */

/* 354 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 356 */	NdrFcLong( 0x0 ),	/* 0 */
/* 360 */	NdrFcShort( 0x10 ),	/* 16 */
/* 362 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 364 */	NdrFcShort( 0x8 ),	/* 8 */
/* 366 */	NdrFcShort( 0x24 ),	/* 36 */
/* 368 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 370 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 374 */	NdrFcShort( 0x1 ),	/* 1 */
/* 376 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter expiredDate */

/* 378 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 380 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 382 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Parameter parValue */

/* 384 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 386 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 388 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Parameter password */

/* 390 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 392 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 394 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Parameter permission */

/* 396 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 398 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter retValue */

/* 402 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 404 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 406 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 408 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 410 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 412 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OCX_IC_ReadCardNoAndTrack */

/* 414 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 416 */	NdrFcLong( 0x0 ),	/* 0 */
/* 420 */	NdrFcShort( 0x11 ),	/* 17 */
/* 422 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 426 */	NdrFcShort( 0x8 ),	/* 8 */
/* 428 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 430 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 432 */	NdrFcShort( 0x1 ),	/* 1 */
/* 434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 436 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fieldValues */

/* 438 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 440 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 442 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 444 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 446 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 448 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OCX_IC_ReadCardNo */

/* 450 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 452 */	NdrFcLong( 0x0 ),	/* 0 */
/* 456 */	NdrFcShort( 0x12 ),	/* 18 */
/* 458 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 462 */	NdrFcShort( 0x8 ),	/* 8 */
/* 464 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 466 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 468 */	NdrFcShort( 0x1 ),	/* 1 */
/* 470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 472 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fieldValues */

/* 474 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 476 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 478 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 480 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 482 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 484 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const CardOCX_MIDL_TYPE_FORMAT_STRING CardOCX__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  4 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/*  8 */	NdrFcShort( 0x1c ),	/* Offset= 28 (36) */
/* 10 */	
			0x13, 0x0,	/* FC_OP */
/* 12 */	NdrFcShort( 0xe ),	/* Offset= 14 (26) */
/* 14 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 16 */	NdrFcShort( 0x2 ),	/* 2 */
/* 18 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 20 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 22 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 24 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 26 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 28 */	NdrFcShort( 0x8 ),	/* 8 */
/* 30 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (14) */
/* 32 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 34 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 36 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 38 */	NdrFcShort( 0x0 ),	/* 0 */
/* 40 */	NdrFcShort( 0x4 ),	/* 4 */
/* 42 */	NdrFcShort( 0x0 ),	/* 0 */
/* 44 */	NdrFcShort( 0xffde ),	/* Offset= -34 (10) */
/* 46 */	
			0x11, 0x0,	/* FC_RP */
/* 48 */	NdrFcShort( 0x6 ),	/* Offset= 6 (54) */
/* 50 */	
			0x12, 0x0,	/* FC_UP */
/* 52 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (26) */
/* 54 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x4 ),	/* 4 */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (50) */
/* 64 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 66 */	NdrFcShort( 0x3e6 ),	/* Offset= 998 (1064) */
/* 68 */	
			0x13, 0x0,	/* FC_OP */
/* 70 */	NdrFcShort( 0x3ce ),	/* Offset= 974 (1044) */
/* 72 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 74 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 76 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 78 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 80 */	NdrFcShort( 0x2 ),	/* Offset= 2 (82) */
/* 82 */	NdrFcShort( 0x10 ),	/* 16 */
/* 84 */	NdrFcShort( 0x2f ),	/* 47 */
/* 86 */	NdrFcLong( 0x14 ),	/* 20 */
/* 90 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 92 */	NdrFcLong( 0x3 ),	/* 3 */
/* 96 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 98 */	NdrFcLong( 0x11 ),	/* 17 */
/* 102 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 104 */	NdrFcLong( 0x2 ),	/* 2 */
/* 108 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 110 */	NdrFcLong( 0x4 ),	/* 4 */
/* 114 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 116 */	NdrFcLong( 0x5 ),	/* 5 */
/* 120 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 122 */	NdrFcLong( 0xb ),	/* 11 */
/* 126 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 128 */	NdrFcLong( 0xa ),	/* 10 */
/* 132 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 134 */	NdrFcLong( 0x6 ),	/* 6 */
/* 138 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (370) */
/* 140 */	NdrFcLong( 0x7 ),	/* 7 */
/* 144 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 146 */	NdrFcLong( 0x8 ),	/* 8 */
/* 150 */	NdrFcShort( 0xff74 ),	/* Offset= -140 (10) */
/* 152 */	NdrFcLong( 0xd ),	/* 13 */
/* 156 */	NdrFcShort( 0xdc ),	/* Offset= 220 (376) */
/* 158 */	NdrFcLong( 0x9 ),	/* 9 */
/* 162 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (394) */
/* 164 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 168 */	NdrFcShort( 0xf4 ),	/* Offset= 244 (412) */
/* 170 */	NdrFcLong( 0x24 ),	/* 36 */
/* 174 */	NdrFcShort( 0x31c ),	/* Offset= 796 (970) */
/* 176 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 180 */	NdrFcShort( 0x316 ),	/* Offset= 790 (970) */
/* 182 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 186 */	NdrFcShort( 0x314 ),	/* Offset= 788 (974) */
/* 188 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 192 */	NdrFcShort( 0x312 ),	/* Offset= 786 (978) */
/* 194 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 198 */	NdrFcShort( 0x310 ),	/* Offset= 784 (982) */
/* 200 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 204 */	NdrFcShort( 0x30e ),	/* Offset= 782 (986) */
/* 206 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 210 */	NdrFcShort( 0x30c ),	/* Offset= 780 (990) */
/* 212 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 216 */	NdrFcShort( 0x30a ),	/* Offset= 778 (994) */
/* 218 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 222 */	NdrFcShort( 0x2f4 ),	/* Offset= 756 (978) */
/* 224 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 228 */	NdrFcShort( 0x2f2 ),	/* Offset= 754 (982) */
/* 230 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 234 */	NdrFcShort( 0x2fc ),	/* Offset= 764 (998) */
/* 236 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 240 */	NdrFcShort( 0x2f2 ),	/* Offset= 754 (994) */
/* 242 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 246 */	NdrFcShort( 0x2f4 ),	/* Offset= 756 (1002) */
/* 248 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 252 */	NdrFcShort( 0x2f2 ),	/* Offset= 754 (1006) */
/* 254 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 258 */	NdrFcShort( 0x2f0 ),	/* Offset= 752 (1010) */
/* 260 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 264 */	NdrFcShort( 0x2ee ),	/* Offset= 750 (1014) */
/* 266 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 270 */	NdrFcShort( 0x2ec ),	/* Offset= 748 (1018) */
/* 272 */	NdrFcLong( 0x10 ),	/* 16 */
/* 276 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 278 */	NdrFcLong( 0x12 ),	/* 18 */
/* 282 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 284 */	NdrFcLong( 0x13 ),	/* 19 */
/* 288 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 290 */	NdrFcLong( 0x15 ),	/* 21 */
/* 294 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 296 */	NdrFcLong( 0x16 ),	/* 22 */
/* 300 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 302 */	NdrFcLong( 0x17 ),	/* 23 */
/* 306 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 308 */	NdrFcLong( 0xe ),	/* 14 */
/* 312 */	NdrFcShort( 0x2ca ),	/* Offset= 714 (1026) */
/* 314 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 318 */	NdrFcShort( 0x2ce ),	/* Offset= 718 (1036) */
/* 320 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 324 */	NdrFcShort( 0x2cc ),	/* Offset= 716 (1040) */
/* 326 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 330 */	NdrFcShort( 0x288 ),	/* Offset= 648 (978) */
/* 332 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 336 */	NdrFcShort( 0x286 ),	/* Offset= 646 (982) */
/* 338 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 342 */	NdrFcShort( 0x284 ),	/* Offset= 644 (986) */
/* 344 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 348 */	NdrFcShort( 0x27a ),	/* Offset= 634 (982) */
/* 350 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 354 */	NdrFcShort( 0x274 ),	/* Offset= 628 (982) */
/* 356 */	NdrFcLong( 0x0 ),	/* 0 */
/* 360 */	NdrFcShort( 0x0 ),	/* Offset= 0 (360) */
/* 362 */	NdrFcLong( 0x1 ),	/* 1 */
/* 366 */	NdrFcShort( 0x0 ),	/* Offset= 0 (366) */
/* 368 */	NdrFcShort( 0xffff ),	/* Offset= -1 (367) */
/* 370 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 372 */	NdrFcShort( 0x8 ),	/* 8 */
/* 374 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 376 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 378 */	NdrFcLong( 0x0 ),	/* 0 */
/* 382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 386 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 388 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 390 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 392 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 394 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 396 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 404 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 406 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 408 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 410 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 412 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 414 */	NdrFcShort( 0x2 ),	/* Offset= 2 (416) */
/* 416 */	
			0x13, 0x0,	/* FC_OP */
/* 418 */	NdrFcShort( 0x216 ),	/* Offset= 534 (952) */
/* 420 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 422 */	NdrFcShort( 0x18 ),	/* 24 */
/* 424 */	NdrFcShort( 0xa ),	/* 10 */
/* 426 */	NdrFcLong( 0x8 ),	/* 8 */
/* 430 */	NdrFcShort( 0x5a ),	/* Offset= 90 (520) */
/* 432 */	NdrFcLong( 0xd ),	/* 13 */
/* 436 */	NdrFcShort( 0x7e ),	/* Offset= 126 (562) */
/* 438 */	NdrFcLong( 0x9 ),	/* 9 */
/* 442 */	NdrFcShort( 0x9e ),	/* Offset= 158 (600) */
/* 444 */	NdrFcLong( 0xc ),	/* 12 */
/* 448 */	NdrFcShort( 0xc8 ),	/* Offset= 200 (648) */
/* 450 */	NdrFcLong( 0x24 ),	/* 36 */
/* 454 */	NdrFcShort( 0x124 ),	/* Offset= 292 (746) */
/* 456 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 460 */	NdrFcShort( 0x140 ),	/* Offset= 320 (780) */
/* 462 */	NdrFcLong( 0x10 ),	/* 16 */
/* 466 */	NdrFcShort( 0x15a ),	/* Offset= 346 (812) */
/* 468 */	NdrFcLong( 0x2 ),	/* 2 */
/* 472 */	NdrFcShort( 0x174 ),	/* Offset= 372 (844) */
/* 474 */	NdrFcLong( 0x3 ),	/* 3 */
/* 478 */	NdrFcShort( 0x18e ),	/* Offset= 398 (876) */
/* 480 */	NdrFcLong( 0x14 ),	/* 20 */
/* 484 */	NdrFcShort( 0x1a8 ),	/* Offset= 424 (908) */
/* 486 */	NdrFcShort( 0xffff ),	/* Offset= -1 (485) */
/* 488 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 490 */	NdrFcShort( 0x4 ),	/* 4 */
/* 492 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 496 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 498 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 500 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 502 */	NdrFcShort( 0x4 ),	/* 4 */
/* 504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 506 */	NdrFcShort( 0x1 ),	/* 1 */
/* 508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 512 */	0x13, 0x0,	/* FC_OP */
/* 514 */	NdrFcShort( 0xfe18 ),	/* Offset= -488 (26) */
/* 516 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 518 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 520 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 522 */	NdrFcShort( 0x8 ),	/* 8 */
/* 524 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 526 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 528 */	NdrFcShort( 0x4 ),	/* 4 */
/* 530 */	NdrFcShort( 0x4 ),	/* 4 */
/* 532 */	0x11, 0x0,	/* FC_RP */
/* 534 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (488) */
/* 536 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 538 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 540 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 544 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 548 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 550 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 554 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 556 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 558 */	NdrFcShort( 0xff4a ),	/* Offset= -182 (376) */
/* 560 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 562 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 564 */	NdrFcShort( 0x8 ),	/* 8 */
/* 566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 568 */	NdrFcShort( 0x6 ),	/* Offset= 6 (574) */
/* 570 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 572 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 574 */	
			0x11, 0x0,	/* FC_RP */
/* 576 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (540) */
/* 578 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 582 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 586 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 588 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 592 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 594 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 596 */	NdrFcShort( 0xff36 ),	/* Offset= -202 (394) */
/* 598 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 600 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 602 */	NdrFcShort( 0x8 ),	/* 8 */
/* 604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 606 */	NdrFcShort( 0x6 ),	/* Offset= 6 (612) */
/* 608 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 610 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 612 */	
			0x11, 0x0,	/* FC_RP */
/* 614 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (578) */
/* 616 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 618 */	NdrFcShort( 0x4 ),	/* 4 */
/* 620 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 624 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 626 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 628 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 630 */	NdrFcShort( 0x4 ),	/* 4 */
/* 632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 634 */	NdrFcShort( 0x1 ),	/* 1 */
/* 636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 640 */	0x13, 0x0,	/* FC_OP */
/* 642 */	NdrFcShort( 0x192 ),	/* Offset= 402 (1044) */
/* 644 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 646 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 648 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 650 */	NdrFcShort( 0x8 ),	/* 8 */
/* 652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 654 */	NdrFcShort( 0x6 ),	/* Offset= 6 (660) */
/* 656 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 658 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 660 */	
			0x11, 0x0,	/* FC_RP */
/* 662 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (616) */
/* 664 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 666 */	NdrFcLong( 0x2f ),	/* 47 */
/* 670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 674 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 676 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 678 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 680 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 682 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 684 */	NdrFcShort( 0x1 ),	/* 1 */
/* 686 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 688 */	NdrFcShort( 0x4 ),	/* 4 */
/* 690 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 692 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 694 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 696 */	NdrFcShort( 0x10 ),	/* 16 */
/* 698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 700 */	NdrFcShort( 0xa ),	/* Offset= 10 (710) */
/* 702 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 704 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 706 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (664) */
/* 708 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 710 */	
			0x13, 0x0,	/* FC_OP */
/* 712 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (682) */
/* 714 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 716 */	NdrFcShort( 0x4 ),	/* 4 */
/* 718 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 722 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 724 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 726 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 728 */	NdrFcShort( 0x4 ),	/* 4 */
/* 730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 732 */	NdrFcShort( 0x1 ),	/* 1 */
/* 734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 738 */	0x13, 0x0,	/* FC_OP */
/* 740 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (694) */
/* 742 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 744 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 746 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 748 */	NdrFcShort( 0x8 ),	/* 8 */
/* 750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 752 */	NdrFcShort( 0x6 ),	/* Offset= 6 (758) */
/* 754 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 756 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 758 */	
			0x11, 0x0,	/* FC_RP */
/* 760 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (714) */
/* 762 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 764 */	NdrFcShort( 0x8 ),	/* 8 */
/* 766 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 768 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 770 */	NdrFcShort( 0x10 ),	/* 16 */
/* 772 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 774 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 776 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (762) */
			0x5b,		/* FC_END */
/* 780 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 782 */	NdrFcShort( 0x18 ),	/* 24 */
/* 784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 786 */	NdrFcShort( 0xa ),	/* Offset= 10 (796) */
/* 788 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 790 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 792 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (768) */
/* 794 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 796 */	
			0x11, 0x0,	/* FC_RP */
/* 798 */	NdrFcShort( 0xfefe ),	/* Offset= -258 (540) */
/* 800 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 802 */	NdrFcShort( 0x1 ),	/* 1 */
/* 804 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 808 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 810 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 812 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 814 */	NdrFcShort( 0x8 ),	/* 8 */
/* 816 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 818 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 820 */	NdrFcShort( 0x4 ),	/* 4 */
/* 822 */	NdrFcShort( 0x4 ),	/* 4 */
/* 824 */	0x13, 0x0,	/* FC_OP */
/* 826 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (800) */
/* 828 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 830 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 832 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 834 */	NdrFcShort( 0x2 ),	/* 2 */
/* 836 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 840 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 842 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 844 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 846 */	NdrFcShort( 0x8 ),	/* 8 */
/* 848 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 850 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 852 */	NdrFcShort( 0x4 ),	/* 4 */
/* 854 */	NdrFcShort( 0x4 ),	/* 4 */
/* 856 */	0x13, 0x0,	/* FC_OP */
/* 858 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (832) */
/* 860 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 862 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 864 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 866 */	NdrFcShort( 0x4 ),	/* 4 */
/* 868 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 872 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 874 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 876 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 878 */	NdrFcShort( 0x8 ),	/* 8 */
/* 880 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 882 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 884 */	NdrFcShort( 0x4 ),	/* 4 */
/* 886 */	NdrFcShort( 0x4 ),	/* 4 */
/* 888 */	0x13, 0x0,	/* FC_OP */
/* 890 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (864) */
/* 892 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 894 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 896 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 898 */	NdrFcShort( 0x8 ),	/* 8 */
/* 900 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 904 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 906 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 908 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 910 */	NdrFcShort( 0x8 ),	/* 8 */
/* 912 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 914 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 916 */	NdrFcShort( 0x4 ),	/* 4 */
/* 918 */	NdrFcShort( 0x4 ),	/* 4 */
/* 920 */	0x13, 0x0,	/* FC_OP */
/* 922 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (896) */
/* 924 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 926 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 928 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 930 */	NdrFcShort( 0x8 ),	/* 8 */
/* 932 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 934 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 936 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 938 */	NdrFcShort( 0x8 ),	/* 8 */
/* 940 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 942 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 944 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 946 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 948 */	NdrFcShort( 0xffec ),	/* Offset= -20 (928) */
/* 950 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 952 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 954 */	NdrFcShort( 0x28 ),	/* 40 */
/* 956 */	NdrFcShort( 0xffec ),	/* Offset= -20 (936) */
/* 958 */	NdrFcShort( 0x0 ),	/* Offset= 0 (958) */
/* 960 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 962 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 964 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 966 */	NdrFcShort( 0xfdde ),	/* Offset= -546 (420) */
/* 968 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 970 */	
			0x13, 0x0,	/* FC_OP */
/* 972 */	NdrFcShort( 0xfeea ),	/* Offset= -278 (694) */
/* 974 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 976 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 978 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 980 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 982 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 984 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 986 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 988 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 990 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 992 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 994 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 996 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 998 */	
			0x13, 0x0,	/* FC_OP */
/* 1000 */	NdrFcShort( 0xfd8a ),	/* Offset= -630 (370) */
/* 1002 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1004 */	NdrFcShort( 0xfc1e ),	/* Offset= -994 (10) */
/* 1006 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1008 */	NdrFcShort( 0xfd88 ),	/* Offset= -632 (376) */
/* 1010 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1012 */	NdrFcShort( 0xfd96 ),	/* Offset= -618 (394) */
/* 1014 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1016 */	NdrFcShort( 0xfda4 ),	/* Offset= -604 (412) */
/* 1018 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1020 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1022) */
/* 1022 */	
			0x13, 0x0,	/* FC_OP */
/* 1024 */	NdrFcShort( 0x14 ),	/* Offset= 20 (1044) */
/* 1026 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 1028 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1030 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 1032 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 1034 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1036 */	
			0x13, 0x0,	/* FC_OP */
/* 1038 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1026) */
/* 1040 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1042 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1044 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1046 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1050 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1050) */
/* 1052 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1054 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1056 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1058 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1060 */	NdrFcShort( 0xfc24 ),	/* Offset= -988 (72) */
/* 1062 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1064 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1066 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1068 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1072 */	NdrFcShort( 0xfc14 ),	/* Offset= -1004 (68) */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            }

        };



/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ICardObject, ver. 0.0,
   GUID={0xCB9772BE,0x7669,0x47EE,{0x90,0xAE,0xA1,0xEB,0x45,0xF0,0x2C,0xE8}} */

#pragma code_seg(".orpc")
static const unsigned short ICardObject_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    36,
    72,
    114,
    162,
    198,
    234,
    276,
    318,
    354,
    414,
    450
    };

static const MIDL_STUBLESS_PROXY_INFO ICardObject_ProxyInfo =
    {
    &Object_StubDesc,
    CardOCX__MIDL_ProcFormatString.Format,
    &ICardObject_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ICardObject_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    CardOCX__MIDL_ProcFormatString.Format,
    &ICardObject_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(19) _ICardObjectProxyVtbl = 
{
    &ICardObject_ProxyInfo,
    &IID_ICardObject,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* ICardObject::OCX_Init */ ,
    (void *) (INT_PTR) -1 /* ICardObject::OCX_About */ ,
    (void *) (INT_PTR) -1 /* ICardObject::OCX_ReadTrack */ ,
    (void *) (INT_PTR) -1 /* ICardObject::OCX_WriteTrack */ ,
    (void *) (INT_PTR) -1 /* ICardObject::OCX_GetLastError */ ,
    (void *) (INT_PTR) -1 /* ICardObject::OCX_EjectCard */ ,
    (void *) (INT_PTR) -1 /* ICardObject::OCX_PrintPassword */ ,
    (void *) (INT_PTR) -1 /* ICardObject::OCX_SetPrinter */ ,
    (void *) (INT_PTR) -1 /* ICardObject::OCX_GetPrinters */ ,
    (void *) (INT_PTR) -1 /* ICardObject::OCX_PrintAll */ ,
    (void *) (INT_PTR) -1 /* ICardObject::OCX_IC_ReadCardNoAndTrack */ ,
    (void *) (INT_PTR) -1 /* ICardObject::OCX_IC_ReadCardNo */
};


static const PRPC_STUB_FUNCTION ICardObject_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ICardObjectStubVtbl =
{
    &IID_ICardObject,
    &ICardObject_ServerInfo,
    19,
    &ICardObject_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    CardOCX__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x700022b, /* MIDL Version 7.0.555 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _CardOCX_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_ICardObjectProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _CardOCX_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_ICardObjectStubVtbl,
    0
};

PCInterfaceName const _CardOCX_InterfaceNamesList[] = 
{
    "ICardObject",
    0
};

const IID *  const _CardOCX_BaseIIDList[] = 
{
    &IID_IDispatch,
    0
};


#define _CardOCX_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _CardOCX, pIID, n)

int __stdcall _CardOCX_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_CardOCX_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo CardOCX_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _CardOCX_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _CardOCX_StubVtblList,
    (const PCInterfaceName * ) & _CardOCX_InterfaceNamesList,
    (const IID ** ) & _CardOCX_BaseIIDList,
    & _CardOCX_IID_Lookup, 
    1,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

