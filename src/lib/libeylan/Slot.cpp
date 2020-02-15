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





#include "Slot.h"

Slot::Slot( int numElements)
{
  data.reserve(numElements);         
}            
 
Slot::~Slot()
{
             
}

void Slot::Add(double _data)
{
     data.push_back(_data);               
}

int Slot::getSize()
{
    return data.size();   
}    

float Slot::getElement( int element)
{
 return data[element];     
}      

void Slot::sort()
{
	std::sort (data.begin(), data.end());
}
void Slot::empty()
{
	data.empty();

}
     
