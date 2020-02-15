//    Copyright (C) 2020 - 2009 José Janaílton da Silva <josejanailton@gmail.com>
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

#ifndef __UnitVersao_H__
#define __UnitVersao_H__
//---------------------------------------------------------------------------

#include "IGEST_API.h"
#include <string>
using namespace std;

namespace IGEST_VERSAO{

const string __declspec(uuid("{C07BC34D-4A07-4637-8894-23A74C83CECF}")) APPNAME	=		"IGEst - Interface Gráfica Para Estatística";
const string VERSAO		= 		"3.10.3";
const string AUTOR		=		"José Janaílton da Silva";
const string CONTACT	=		"josejanailton@gmail.com";
const string SITE		=		"http://igest.sf.net";
const string SITE_PROJ_SRC   =	"https://github.com/janailton/IGEst-Estatistica";
const string UPDATE_SERVER = 	"igest.sourceforge.net";
const string UPDATE_INFO   =	"info.xml";
const string DefaultVersionGUID   =	"{8D796329-7FDA-495C-AAF1-4666EA688BB5}";


const string GNULICENSE =

	"Copyright (C) 2020 - 2009 José Janaílton da Silva\n"
	"Contact  <josejanailton@gmail.com>\n\n"

	"This program is free software; you can redistribute it and/or modify\n"
	"it under the terms of the GNU General Public License as published by\n"
	"the Free Software Foundation; either version 2 of the License, or\n"
	"(at your option) any later version.\n\n"

	"This program is distributed in the hope that it will be useful,\n"
	"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
	"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
	"GNU General Public License for more details.\n\n"

	"You should have received a copy of the GNU General Public License\n"
	"along with this program; if not, write to the Free Software\n"
	"Foundation, Inc., 51 Franklin Steet, Fifth Floor, Boston, MA  02111-1307  USA\n";


}

namespace IGEst_License{

	const __declspec(uuid("{C580B97C-1AC7-4275-A608-E402DAB40FA3}")) IGEST_API::IGEst_Default_String Title = "IGEst Estatistica";
	const __declspec(uuid("{1393B76F-640E-43A0-8AF6-DD29B93A2846}")) IGEST_API::IGEst_Default_String License_file_name = "NULL";
	const __declspec(uuid("{709A4815-FAD3-45B7-8D09-86E132BBBA49}")) IGEST_API::IGEst_Default_String Trial_license = "NULL";
	const __declspec(uuid("{C569C76A-A879-4860-921D-14AC00923D1D}")) IGEST_API::IGEst_Default_String License_Expiration_Date = "31/12/3020";
	const __declspec(uuid("{E0D3FB47-5334-411C-868F-760BB7BEE4B5}")) int Days_Left =  0xffffffff;
	const __declspec(uuid("{C90770BC-11CB-40BE-9781-0000F178685F}")) IGEST_API::IGEst_Default_String License_Type = "GNU GENERAL PUBLIC LICENSE Version 2, June 1991";
	const __declspec(uuid("{46DD1FB7-47A0-4B88-8EAF-61742B1E3AC5}")) IGEST_API::IGEst_Default_String Serial_Number = ".........";
	const __declspec(uuid("{95D46EFA-6F28-41E6-BD94-6AE18F591A35}")) bool Registered = false;
	const __declspec(uuid("{73C5BDA4-F479-4A90-8066-6144169B0FA3}")) IGEST_API::IGEst_Default_String Platform = "Windows";
	const __declspec(uuid("{1D0DA8C8-B9FB-4CE8-B185-864ACAD70641}")) boolean Commercial_use = false;

}

namespace MAGIC_16{

	const __declspec(uuid("{0200023C-DB8B-4E38-9F83-8E5F0829D4C0}")) IGEST_API::MAGIC_TYPE _0AE = 0xcafe;
	const __declspec(uuid("{5D3DEDC9-D276-43D8-9D76-9E503F693829}")) IGEST_API::MAGIC_TYPE _0TJ = 0xcafe + 0xaabb + 0x0c00;
	const __declspec(uuid("{17462233-364A-4052-A502-A1412E38A216}")) IGEST_API::MAGIC_TYPE _0PI = 0xcafe+ 0xaabb + 0x0d00;
	const __declspec(uuid("{C4E9CBDC-B97A-4EE7-A1EC-ADB2C48AD4A7}")) IGEST_API::MAGIC_TYPE _0GA = 0xcafe+ 0xaabb + 0x0e00;
	const __declspec(uuid("{AF45AF7C-2458-43BD-A519-626D0A2B897E}")) IGEST_API::MAGIC_TYPE _0FL = 0xcafe+ 0xaabb + 0x0f00;
	const __declspec(uuid("{FFE3EEA7-16EE-4089-A387-633B348AA434}")) IGEST_API::MAGIC_TYPE _0HL = 0xcafe+ 0xaabb + 0x0ca0;
	const __declspec(uuid("{7A2A6533-0CA7-4D4C-A80B-ACD3A37B452C}")) IGEST_API::MAGIC_TYPE _0TB = 0xcafe+ 0xaabb + 0x0cb0;
	const __declspec(uuid("{C4628936-49CE-4193-9865-E73F78C23C64}")) IGEST_API::MAGIC_TYPE _0LL = 0xcafe+ 0xaabb + 0x0cc0;
	const __declspec(uuid("{D2C3C119-F166-4CFB-931D-43EC33D0D50B}")) IGEST_API::MAGIC_TYPE _0CX = 0xcafe+ 0xaabb + 0x0cd0;
	const __declspec(uuid("{1E576FC3-8536-4416-A98D-12A804E7D34B}")) IGEST_API::MAGIC_TYPE _0ZZ = 0xcafe+ 0xaabb + 0x0ce0;
	const __declspec(uuid("{12EA5C22-A157-4DC6-94A7-3C4E0CFFDE1D}")) IGEST_API::MAGIC_TYPE _0AA = 0xcafe+ 0xaabb + 0x0cf0;
	const __declspec(uuid("{360F51DB-8422-4E13-9C0E-FB346157A0CA}")) IGEST_API::MAGIC_TYPE _0SW = 0xcafe+ 0xaabb + 0x0c01;
	const __declspec(uuid("{BD4D4AB2-DA7F-4665-A01E-28EFC4366D7D}")) IGEST_API::MAGIC_TYPE _0XS = 0xcafe+ 0xaabb + 0x0c02;
	const __declspec(uuid("{E55275EF-C0E1-47BD-8059-E891BDCE3D30}")) IGEST_API::MAGIC_TYPE _0VK = 0xcafe+ 0xaabb + 0x0c03;
	const __declspec(uuid("{096774B3-5A50-4455-A8A4-F2E9D87A14DB}")) IGEST_API::MAGIC_TYPE _0XP = 0xcafe+ 0xaabb + 0x0c04;
	const __declspec(uuid("{399EDB8C-54F0-43B1-9ED6-A8BF801AA7B4}")) IGEST_API::MAGIC_TYPE _0AR = 0xcafe+ 0xaabb + 0x0c05;
	const __declspec(uuid("{FE0F76B3-6E1C-4BBA-8791-B8B767921657}")) IGEST_API::MAGIC_TYPE _0YK = 0xcafe+ 0xaabb + 0x0c06;
	const __declspec(uuid("{7E88A092-84E0-45AC-A84C-9A1CBB344ABD}")) IGEST_API::MAGIC_TYPE _1LM = 0xcafe+ 0xaabb + 0x0c08;
	const __declspec(uuid("{C890E7F5-A5CA-4E71-AF7D-4EF5FBE786DB}")) IGEST_API::MAGIC_TYPE _2LD = 0xcafe+ 0xaabb + 0x0c010;
	const __declspec(uuid("{8C4CC087-758B-4632-B8F4-4ED5FABD4DB6}")) IGEST_API::MAGIC_TYPE _10Z = 0xcafe+ 0xaabb + 0x0c07;
	const __declspec(uuid("{403A4095-7ACB-486F-942B-DE65BFE8F85A}")) IGEST_API::MAGIC_TYPE _0KM = 0xcafe+ 0xaabb + 0x0c0a;
	const __declspec(uuid("{EC927F0C-989B-490D-A45A-D9CFACA6021A}")) IGEST_API::MAGIC_TYPE _0AV = 0xcafe+ 0xaabb + 0x0c0b;
	const __declspec(uuid("{E2272560-C581-4EA1-A300-D84B63B0B2DB}")) IGEST_API::MAGIC_TYPE _3HL = 0xcafe+ 0xaabb + 0x0c0c;
	const __declspec(uuid("{1D34A804-807A-44EC-89EE-80FC3ED59A4B}")) IGEST_API::MAGIC_TYPE _021H = 0xcafe+ 0xaabb + 0x0c0d;
	const __declspec(uuid("{6B09AEA4-0B58-454F-8E9D-BE4060013F2D}")) IGEST_API::MAGIC_TYPE _4FF = 0xcafe+ 0xaabb + 0x0c0e;
	const __declspec(uuid("{54CEDC75-7477-4B73-9E35-A5E0667B31BE}")) IGEST_API::MAGIC_TYPE _0SL = 0xcafe+ 0xaabb + 0x0c0f;
	const __declspec(uuid("{69EF128D-F8DB-47B8-9B95-10D9516DBAAF}")) IGEST_API::MAGIC_TYPE _8JL = 0xcafe+ 0xaabb + 0x0c00 + 0xbbaf;
	const __declspec(uuid("{1F20A165-7B1D-42BD-AB97-CD0D5FB284D2}")) IGEST_API::MAGIC_TYPE _0SQ = 0xcafe+ 0xaabb + 0x0c00+ 0xbbae;
	const __declspec(uuid("{ABC7026E-503C-4A46-91AD-1BB76BEEC0DE}")) IGEST_API::MAGIC_TYPE _9AK = 0xcafe+ 0xaabb + 0x0c00+ 0xbbad;
	const __declspec(uuid("{0FD8BE8F-AFBF-4B3B-B7C2-A6FF1205FDF7}")) IGEST_API::MAGIC_TYPE _7AJ = 0xcafe+ 0xaabb + 0x0c00+ 0xbbac;
	const __declspec(uuid("{95A0DF85-5E4D-4C1A-9B37-3EE13EE8D4FE}")) IGEST_API::MAGIC_TYPE _1EA = 0xcafe+ 0xaabb + 0x0c00+ 0xbbab;
	const __declspec(uuid("{646E40A0-632B-46F5-B96F-66CBD7BBAF4E}")) IGEST_API::MAGIC_TYPE _032 = 0xcafe+ 0xaabb + 0x0c00+ 0xbba0;

}

namespace MAGIC_GUID{
	const struct __declspec(uuid("{189A04DF-1A5B-42D7-A490-4FC8BE2ABE30}")) MGU_001; // use const UUID iid = __uuidof(MAGIC_GUID::MGS_001);
	const struct __declspec(uuid("{88E7E0F0-30ED-4A49-9D6C-E71927AFE628}")) MGU_002;
	const struct __declspec(uuid("{3707A0DD-6BF1-4507-8DDE-CD8259D2C840}")) MGU_003;
	const struct __declspec(uuid("{BD83FD56-AB50-4E6C-9197-18301251AA87}")) MGU_004;
	const struct __declspec(uuid("{7D26E7B6-EE5D-48E3-9E5B-D05FA014C862}")) MGU_005;
	const struct __declspec(uuid("{DF3E0C85-65F3-45D8-9619-51605F32D566}")) MGU_006;
	const struct __declspec(uuid("{2F9713EC-CB95-4606-9C74-5013BB66F2C4}")) MGU_007;
	const struct __declspec(uuid("{162AE74F-DDBB-4641-998B-EEE2F6E5BBBF}")) MGU_008;
	const struct __declspec(uuid("{D4E4B518-1FA6-438E-A45D-C8B33C29A8E2}")) MGU_009;
	const struct __declspec(uuid("{104F6F32-3EF8-4137-948F-47559CA8C571}")) MGU_010;
	const struct __declspec(uuid("{38ED839D-0090-47F2-9E9C-6DBA0E919591}")) MGU_011;
	const struct __declspec(uuid("{4F9C0F1E-13CC-4549-93CA-6E43F27D8178}")) MGU_012;
	const struct __declspec(uuid("{C9DDF8BF-270C-4FD5-AC62-AC5D86AD17F1}")) MGU_013;
	const struct __declspec(uuid("{F6D0779E-9A7C-4FFE-8829-800E22B45CEC}")) MGU_014;
	const struct __declspec(uuid("{E49847D1-93E8-4DA0-9244-648B7B6A6DC5}")) MGU_015;
	const struct __declspec(uuid("{8A44438F-0E39-4DEB-AEF4-4BCB9A6B7E88}")) MGU_016;
	const struct __declspec(uuid("{98F4828A-2104-49C4-841E-FD10979F3521}")) MGU_017;
	const struct __declspec(uuid("{D93F715A-D85A-4767-B711-CC002259F05E}")) MGU_018;
	const struct __declspec(uuid("{CB5F66AF-70FA-4362-9307-DDD54151529B}")) MGU_019;
	const struct __declspec(uuid("{5C57A9BB-0307-425F-9F3C-74E9B8E92A69}")) MGU_020;
}

GUID IGEst_get_GUID(int id);
void IGEst_save_GUID_to_file(GUID aguid, IGEST_API::IGEst_Default_String filename);
void IGEst_save_GUID_ex();

#endif
