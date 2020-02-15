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


#ifndef __SOCKS_CONNECTION_H__
#define __SOCKS_CONNECTION_H__

#include <string>

class socks_connection
{
public:
	socks_connection( const std::string & home_url , const std::string & path_url , const int & port );
	~socks_connection(void);

	const std::string Get();
	inline static const std::string set_string( std::string str , int size );

private:
	std::string m_home_url;
	std::string m_path_url;
	int m_port;
};


#endif
