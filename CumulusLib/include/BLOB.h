/* 
	Copyright 2010 cumulus.dev@gmail.com
 
	This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License received along this program for more
	details (or else see http://www.gnu.org/licenses/).

	This file is a part of Cumulus.
*/

#pragma once

#include "Cumulus.h"
#include "Poco/Data/BLOB.h"

namespace Cumulus {

class CUMULUS_API BLOB : public Poco::Data::BLOB {
public:
	BLOB();
		/// Creates an empty BLOB.
	BLOB(const Poco::UInt8* content, std::size_t size);
	BLOB(const std::string& content);
	virtual ~BLOB();

	const Poco::UInt8* begin() const;
	void assignRaw(const Poco::UInt8* content, std::size_t count);

};

inline const Poco::UInt8* BLOB::begin() const {
	return (const Poco::UInt8*)Poco::Data::BLOB::rawContent();
}

inline void BLOB::assignRaw(const Poco::UInt8* content, std::size_t count) {
	Poco::Data::BLOB::assignRaw((const char*)content,count);
}

} // namespace Cumulus