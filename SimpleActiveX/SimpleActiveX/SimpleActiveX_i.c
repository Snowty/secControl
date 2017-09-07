

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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

MIDL_DEFINE_GUID(IID, LIBID_SimpleActiveXLib,0x818DFE54,0xE590,0x40B0,0xBD,0x8A,0x96,0x90,0x49,0xC6,0x6A,0x7C);


MIDL_DEFINE_GUID(IID, DIID__DSimpleActiveX,0xD8651415,0xCAA2,0x4169,0xAF,0x97,0x36,0x2C,0xF6,0xF0,0x78,0xB4);


MIDL_DEFINE_GUID(IID, DIID__DSimpleActiveXEvents,0xDE3ADEF6,0xCDC7,0x45CA,0x9B,0x13,0x64,0xEA,0x56,0x49,0xD8,0x34);


MIDL_DEFINE_GUID(CLSID, CLSID_SimpleActiveX,0x24695D2D,0x0C9C,0x460B,0x84,0xD6,0x41,0xC3,0x95,0x07,0xDF,0xDD);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



