//    Copyright (C) 2009 José Janaílton da Silva <josejanailton@gmail.com>
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


#pragma hdrstop

#include "UnitVersao.h"
#include <windows.h>

//---------------------------------------------------------------------------

#pragma package(smart_init)

 GUID IGEst_get_GUID(int id)
 {
	 switch (id) {
	 case 1: return __uuidof(MAGIC_GUID::MGU_001);
	 case 2: return __uuidof(MAGIC_GUID::MGU_002);
	 case 3: return __uuidof(MAGIC_GUID::MGU_003);
	 case 4: return __uuidof(MAGIC_GUID::MGU_004);
	 case 5: return __uuidof(MAGIC_GUID::MGU_005);
	 case 6: return __uuidof(MAGIC_GUID::MGU_006);
	 case 7: return __uuidof(MAGIC_GUID::MGU_007);
	 case 8: return __uuidof(MAGIC_GUID::MGU_008);
	 case 9: return __uuidof(MAGIC_GUID::MGU_009);
	 case 10: return __uuidof(MAGIC_GUID::MGU_010);
	 case 11: return __uuidof(MAGIC_GUID::MGU_011);
	 case 12: return __uuidof(MAGIC_GUID::MGU_012);
	 case 13: return __uuidof(MAGIC_GUID::MGU_013);
	 case 14: return __uuidof(MAGIC_GUID::MGU_014);
	 case 15: return __uuidof(MAGIC_GUID::MGU_015);
	 case 16: return __uuidof(MAGIC_GUID::MGU_016);
	 case 17: return __uuidof(MAGIC_GUID::MGU_017);
	 case 18: return __uuidof(MAGIC_GUID::MGU_018);
	 case 19: return __uuidof(MAGIC_GUID::MGU_019);
	 case 20: return __uuidof(MAGIC_GUID::MGU_020);
	 default: return __uuidof(IUnknown);
	 }
 }

 void IGEst_save_GUID_to_file(GUID aguid, IGEST_API::IGEst_Default_String filename)
 {
	 TStringStream *f = new TStringStream();
	 f->WriteString(GUIDToString(aguid));
     f->SaveToFile(filename);
	 delete f;
 }

 void IGEst_save_GUID_ex()
 {
	IGEst_save_GUID_to_file(IGEst_get_GUID(10),"guid10.txt");
 }

/*
template<typename T> GUID IGEst_get_GUID_from_obj(T& obj)
{
	return __uuidof(typeof(obj));
}


HResult hQueryInterface( GUID& ID, void** obj){

	class AnyClass;
    AnyClass *anyclass1;
	HResult _result = 0;

	if (ID == __uuidof(MAGIC_GUID::MGU_001)) {

        _result = 1;
	}else
		if (ID == __uuidof(IUnknown)) {

			*obj = reinterpret_cast<IUnknown*>(anyclass1);
			static_cast<IUnknown*>(*obj)->AddRef();
			_result =0xcafe;
		}
	return _result;
}


*/
