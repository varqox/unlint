#include <string>

#pragma once

template<class C>
inline std::string& operator<<(const std::string& s, const C& x)
{return const_cast<std::string&>(s) += x;}

void remove_r(const char* path);
std::string FileGetContents(const std::string& file_name);
void FilePutContents(const std::string& file_name, const std::string& contents);
std::string ToString(long long a);

class TemporaryDirectory {
private:
	char* _M_name;
	TemporaryDirectory(const TemporaryDirectory&): _M_name() {}
	TemporaryDirectory& operator=(const TemporaryDirectory&) { return *this; }

public:
	explicit TemporaryDirectory(const char* new_name);

	~TemporaryDirectory() {
		remove_r(_M_name);
		delete[] _M_name;
	}

	const char* name() const { return _M_name; }
	std::string sname() const { return std::string(_M_name); }
	operator const char*() const { return _M_name; }
	operator std::string() const { return std::string(_M_name); }
};