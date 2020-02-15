//    Copyright (C) 2010, 2009 José Janaílton da Silva 
//		<josejanailton@gmail.com>
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



#include "socks_connection.h"

#include <stdexcept>
#include <cstdio>
using namespace std;

#include <windows.h>
#pragma comment( lib , "wsock32.lib" )

socks_connection::socks_connection( const std::string & home_url , const std::string & path_url, const int & port )
	: m_home_url( home_url ) , m_path_url( path_url ) , m_port( port )
{
   WSADATA w;
   int iResult = WSAStartup(MAKEWORD(2,0),&w);

    if (iResult != 0) 
	{
		throw new std::logic_error("Failed to connect");
    }

}

socks_connection::~socks_connection(void)
{
	WSACleanup();
}

const std::string socks_connection::Get()
{
	   int bytes = 0, ret = 0;
	   struct hostent* hostinfo;
	   SOCKET sock;
	   struct sockaddr_in info;


	   hostinfo = gethostbyname( m_home_url.c_str() ); /*captura do IP via DNS através da URL*/
	   if(hostinfo == NULL)
	   {
		   throw new std::logic_error( "Unable to resolve IP" );
		   return "FAIL";

	   }



	   sock = socket(AF_INET,SOCK_STREAM,0);
	   info.sin_family = AF_INET;
	   info.sin_port = htons( m_port );
	   info.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr*)hostinfo->h_addr));
	   memset(info.sin_zero,0,8);


	   bind(sock,(struct sockaddr*)&info,sizeof(info));

	   if((ret = connect(sock,(struct sockaddr*)&info,sizeof(info))) != SOCKET_ERROR)
		{ 
			char buffer[512];

			sprintf(buffer,"GET /%s HTTP/1.1\r\nHost:%s\r\nConnection: close\r\nUser-Agent: socks_connection\r\nContent-Type: application/x-www-form-urlencoded\r\n\r\n", m_path_url.c_str() , m_home_url.c_str() );
		    int snd = send(sock,buffer,strlen(buffer),0);
			  
			std::string return_string;

			while((bytes = recv(sock,buffer,512,0)) > 0)
			{

				 return_string.append( buffer , bytes );
			}

			 return return_string;
		}

	   return "FAIL";

}

inline const std::string socks_connection::set_string( std::string str , int size )
{
	str.resize( size );
	return str;
}
