

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __CardOCX_i_h__
#define __CardOCX_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICardObject_FWD_DEFINED__
#define __ICardObject_FWD_DEFINED__
typedef interface ICardObject ICardObject;
#endif 	/* __ICardObject_FWD_DEFINED__ */


#ifndef ___ICardObjectEvents_FWD_DEFINED__
#define ___ICardObjectEvents_FWD_DEFINED__
typedef interface _ICardObjectEvents _ICardObjectEvents;
#endif 	/* ___ICardObjectEvents_FWD_DEFINED__ */


#ifndef __CardObject_FWD_DEFINED__
#define __CardObject_FWD_DEFINED__

#ifdef __cplusplus
typedef class CardObject CardObject;
#else
typedef struct CardObject CardObject;
#endif /* __cplusplus */

#endif 	/* __CardObject_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ICardObject_INTERFACE_DEFINED__
#define __ICardObject_INTERFACE_DEFINED__

/* interface ICardObject */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICardObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CB9772BE-7669-47EE-90AE-A1EB45F02CE8")
    ICardObject : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OCX_Init( 
            /* [retval][out] */ LONG *retValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OCX_About( 
            /* [retval][out] */ BSTR *message) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OCX_ReadTrack( 
            /* [in] */ SHORT trackNo,
            /* [retval][out] */ BSTR *trackInfo) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OCX_WriteTrack( 
            /* [in] */ SHORT trackNo,
            /* [in] */ BSTR *trackInfo,
            /* [retval][out] */ LONG *retValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OCX_GetLastError( 
            /* [retval][out] */ BSTR *message) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OCX_EjectCard( 
            /* [retval][out] */ LONG *retValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OCX_PrintPassword( 
            /* [in] */ BSTR *password,
            /* [retval][out] */ LONG *retValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OCX_SetPrinter( 
            /* [in] */ BSTR *printerName,
            /* [retval][out] */ LONG *retValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OCX_GetPrinters( 
            /* [retval][out] */ VARIANT *printers) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OCX_PrintAll( 
            /* [in] */ BSTR *expiredDate,
            /* [in] */ BSTR *parValue,
            /* [in] */ BSTR *password,
            /* [in] */ LONG permission,
            /* [retval][out] */ LONG *retValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OCX_IC_ReadCardNoAndTrack( 
            /* [retval][out] */ VARIANT *fieldValues) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OCX_IC_ReadCardNo( 
            /* [retval][out] */ VARIANT *fieldValues) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICardObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICardObject * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICardObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICardObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICardObject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICardObject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICardObject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICardObject * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OCX_Init )( 
            ICardObject * This,
            /* [retval][out] */ LONG *retValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OCX_About )( 
            ICardObject * This,
            /* [retval][out] */ BSTR *message);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OCX_ReadTrack )( 
            ICardObject * This,
            /* [in] */ SHORT trackNo,
            /* [retval][out] */ BSTR *trackInfo);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OCX_WriteTrack )( 
            ICardObject * This,
            /* [in] */ SHORT trackNo,
            /* [in] */ BSTR *trackInfo,
            /* [retval][out] */ LONG *retValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OCX_GetLastError )( 
            ICardObject * This,
            /* [retval][out] */ BSTR *message);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OCX_EjectCard )( 
            ICardObject * This,
            /* [retval][out] */ LONG *retValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OCX_PrintPassword )( 
            ICardObject * This,
            /* [in] */ BSTR *password,
            /* [retval][out] */ LONG *retValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OCX_SetPrinter )( 
            ICardObject * This,
            /* [in] */ BSTR *printerName,
            /* [retval][out] */ LONG *retValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OCX_GetPrinters )( 
            ICardObject * This,
            /* [retval][out] */ VARIANT *printers);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OCX_PrintAll )( 
            ICardObject * This,
            /* [in] */ BSTR *expiredDate,
            /* [in] */ BSTR *parValue,
            /* [in] */ BSTR *password,
            /* [in] */ LONG permission,
            /* [retval][out] */ LONG *retValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OCX_IC_ReadCardNoAndTrack )( 
            ICardObject * This,
            /* [retval][out] */ VARIANT *fieldValues);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OCX_IC_ReadCardNo )( 
            ICardObject * This,
            /* [retval][out] */ VARIANT *fieldValues);
        
        END_INTERFACE
    } ICardObjectVtbl;

    interface ICardObject
    {
        CONST_VTBL struct ICardObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICardObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICardObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICardObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICardObject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICardObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICardObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICardObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICardObject_OCX_Init(This,retValue)	\
    ( (This)->lpVtbl -> OCX_Init(This,retValue) ) 

#define ICardObject_OCX_About(This,message)	\
    ( (This)->lpVtbl -> OCX_About(This,message) ) 

#define ICardObject_OCX_ReadTrack(This,trackNo,trackInfo)	\
    ( (This)->lpVtbl -> OCX_ReadTrack(This,trackNo,trackInfo) ) 

#define ICardObject_OCX_WriteTrack(This,trackNo,trackInfo,retValue)	\
    ( (This)->lpVtbl -> OCX_WriteTrack(This,trackNo,trackInfo,retValue) ) 

#define ICardObject_OCX_GetLastError(This,message)	\
    ( (This)->lpVtbl -> OCX_GetLastError(This,message) ) 

#define ICardObject_OCX_EjectCard(This,retValue)	\
    ( (This)->lpVtbl -> OCX_EjectCard(This,retValue) ) 

#define ICardObject_OCX_PrintPassword(This,password,retValue)	\
    ( (This)->lpVtbl -> OCX_PrintPassword(This,password,retValue) ) 

#define ICardObject_OCX_SetPrinter(This,printerName,retValue)	\
    ( (This)->lpVtbl -> OCX_SetPrinter(This,printerName,retValue) ) 

#define ICardObject_OCX_GetPrinters(This,printers)	\
    ( (This)->lpVtbl -> OCX_GetPrinters(This,printers) ) 

#define ICardObject_OCX_PrintAll(This,expiredDate,parValue,password,permission,retValue)	\
    ( (This)->lpVtbl -> OCX_PrintAll(This,expiredDate,parValue,password,permission,retValue) ) 

#define ICardObject_OCX_IC_ReadCardNoAndTrack(This,fieldValues)	\
    ( (This)->lpVtbl -> OCX_IC_ReadCardNoAndTrack(This,fieldValues) ) 

#define ICardObject_OCX_IC_ReadCardNo(This,fieldValues)	\
    ( (This)->lpVtbl -> OCX_IC_ReadCardNo(This,fieldValues) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICardObject_INTERFACE_DEFINED__ */



#ifndef __CardOCXLib_LIBRARY_DEFINED__
#define __CardOCXLib_LIBRARY_DEFINED__

/* library CardOCXLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_CardOCXLib;

#ifndef ___ICardObjectEvents_DISPINTERFACE_DEFINED__
#define ___ICardObjectEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ICardObjectEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__ICardObjectEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B4A99C75-0B07-4839-84EA-F5C72758A81C")
    _ICardObjectEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ICardObjectEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ICardObjectEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ICardObjectEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ICardObjectEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _ICardObjectEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _ICardObjectEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _ICardObjectEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _ICardObjectEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _ICardObjectEventsVtbl;

    interface _ICardObjectEvents
    {
        CONST_VTBL struct _ICardObjectEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ICardObjectEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _ICardObjectEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _ICardObjectEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _ICardObjectEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _ICardObjectEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _ICardObjectEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _ICardObjectEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ICardObjectEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CardObject;

#ifdef __cplusplus

class DECLSPEC_UUID("038090D9-4C74-4A87-BA43-12C48C0D29FA")
CardObject;
#endif
#endif /* __CardOCXLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


