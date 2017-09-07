

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Thu Sep 07 11:36:04 2017
 */
/* Compiler settings for SimpleActiveX.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0595 
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


#ifndef __SimpleActiveXidl_h__
#define __SimpleActiveXidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DSimpleActiveX_FWD_DEFINED__
#define ___DSimpleActiveX_FWD_DEFINED__
typedef interface _DSimpleActiveX _DSimpleActiveX;

#endif 	/* ___DSimpleActiveX_FWD_DEFINED__ */


#ifndef ___DSimpleActiveXEvents_FWD_DEFINED__
#define ___DSimpleActiveXEvents_FWD_DEFINED__
typedef interface _DSimpleActiveXEvents _DSimpleActiveXEvents;

#endif 	/* ___DSimpleActiveXEvents_FWD_DEFINED__ */


#ifndef __SimpleActiveX_FWD_DEFINED__
#define __SimpleActiveX_FWD_DEFINED__

#ifdef __cplusplus
typedef class SimpleActiveX SimpleActiveX;
#else
typedef struct SimpleActiveX SimpleActiveX;
#endif /* __cplusplus */

#endif 	/* __SimpleActiveX_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_SimpleActiveX_0000_0000 */
/* [local] */ 

#pragma once
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_SimpleActiveX_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_SimpleActiveX_0000_0000_v0_0_s_ifspec;


#ifndef __SimpleActiveXLib_LIBRARY_DEFINED__
#define __SimpleActiveXLib_LIBRARY_DEFINED__

/* library SimpleActiveXLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_SimpleActiveXLib;

#ifndef ___DSimpleActiveX_DISPINTERFACE_DEFINED__
#define ___DSimpleActiveX_DISPINTERFACE_DEFINED__

/* dispinterface _DSimpleActiveX */
/* [uuid] */ 


EXTERN_C const IID DIID__DSimpleActiveX;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("D8651415-CAA2-4169-AF97-362CF6F078B4")
    _DSimpleActiveX : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DSimpleActiveXVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DSimpleActiveX * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DSimpleActiveX * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DSimpleActiveX * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DSimpleActiveX * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DSimpleActiveX * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DSimpleActiveX * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DSimpleActiveX * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DSimpleActiveXVtbl;

    interface _DSimpleActiveX
    {
        CONST_VTBL struct _DSimpleActiveXVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DSimpleActiveX_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DSimpleActiveX_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DSimpleActiveX_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DSimpleActiveX_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DSimpleActiveX_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DSimpleActiveX_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DSimpleActiveX_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DSimpleActiveX_DISPINTERFACE_DEFINED__ */


#ifndef ___DSimpleActiveXEvents_DISPINTERFACE_DEFINED__
#define ___DSimpleActiveXEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DSimpleActiveXEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DSimpleActiveXEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("DE3ADEF6-CDC7-45CA-9B13-64EA5649D834")
    _DSimpleActiveXEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DSimpleActiveXEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DSimpleActiveXEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DSimpleActiveXEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DSimpleActiveXEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DSimpleActiveXEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DSimpleActiveXEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DSimpleActiveXEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DSimpleActiveXEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DSimpleActiveXEventsVtbl;

    interface _DSimpleActiveXEvents
    {
        CONST_VTBL struct _DSimpleActiveXEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DSimpleActiveXEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DSimpleActiveXEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DSimpleActiveXEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DSimpleActiveXEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DSimpleActiveXEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DSimpleActiveXEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DSimpleActiveXEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DSimpleActiveXEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SimpleActiveX;

#ifdef __cplusplus

class DECLSPEC_UUID("24695D2D-0C9C-460B-84D6-41C39507DFDD")
SimpleActiveX;
#endif
#endif /* __SimpleActiveXLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


