#include <vcl.h>
#include <tchar.h>

#ifdef MAKE_DLL
	#define API_EXTERN_C extern "C"
	#define EYLAN_LIB_API __declspec(dllexport)
	#define API_CALL __stdcall
#else
	#define API_EXTERN_C extern "C"
	#define EYLAN_LIB_API __declspec(dllimport)
	#define API_CALL __stdcall
    #pragma comment( lib, "eylan-hardware-api.lib")
#endif



