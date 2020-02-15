//    Copyright (C) 2020 - 2009 José Janaílton da Silva
//	  <josejanailton@gmail.com>
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

#ifndef IGEST_APIH
#define IGEST_APIH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <Classes.hpp>
#include <sysutils.hpp>
#include <windows.hpp>
#include <ustring.h>
#include <map>
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <iterator>
#include "../lib/alglib/include/ap.h"


namespace IGEST_API {

	// Strings

    typedef long long IGEst_integer64;
	typedef UnicodeString IGEst_Default_String;
	typedef AnsiString IGEst_OS_WIN_String;

    // Arrays
	typedef ap::integer_2d_array IGEst_int_2d_array;
	typedef ap::real_2d_array  IGEst_real_2d_array;
	typedef ap::template_2d_array<long double,true> IGEst_extended_2d_array;
    typedef unsigned short int MAGIC_TYPE;


	class __declspec(uuid("{92DA399B-932F-4AE3-95FF-BD07BA9BE25C}")) IGEstBase;
	static int IGEstObjCount = 0;
	static std::map<int, IGEstBase*> IGEstBaseObj;

	#define __IGEst_APP_ID__ 1562
	#define __MAIN_FORM_ID__ 1563

	class IGEstBase{
		protected:
			IGEstBase(){
				IGEstBaseObj[IGEstObjCount] = this;
				IGEstObjCount++;
			};
		public:
			virtual int ID() = 0;
            //virtual GUID GetGUID() = 0;
			virtual IGEstBase* _IGEstBase()=0;
	};

}

//-- <macros> ----------------------------------------------------

#define __IMP_IGEstBase__(id) \
	virtual int ID() { \
		return id;   \
	}; \
	virtual IGEST_API::IGEstBase* _IGEstBase(){\
		return this; \
	};

#define __IMP_GUID__(klass)                     \
	virtual GUID klass::GetGUID(){ \
		return __uuidof(this);						   \
	};      \

#define __ClassFactory__(klass ) \
	static klass *_new##klass(){ \
		return new  klass(); \
	}


#define __IGEstAPI_Implementation__ \
	__IMP_IGEstBase__(100) \
	__ClassFactory__(TEst)


//-- </macros> ----------------------------------------------------

#endif
