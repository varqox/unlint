#include "usefull.h"

#include <dirent.h>
#include <sys/stat.h>

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>

void remove_r(const char* path) {
	DIR* directory;
	dirent* current_file;
	std::string tmp_dir_path=path;
	if (*tmp_dir_path.rbegin() != '/')
		tmp_dir_path += '/';
	if ((directory = opendir(path)))
		while ((current_file = readdir(directory)))
			if (strcmp(current_file->d_name, ".") && strcmp(current_file->d_name, ".."))
				remove_r((tmp_dir_path + current_file->d_name).c_str());
	remove(path);
}

std::string FileGetContents(const std::string& file_name) {
	FILE* file = fopen(file_name.c_str(), "r");
	// Determine file size
	fseek(file, 0, SEEK_END);
	size_t size = ftell(file);
	char* content = new char[size];
	rewind(file);
	fread(content, sizeof(char), size, file);
	fclose(file);
	std::string out(content, content+size);
	delete[] content;
	return out;
}

void FilePutContents(const std::string& file_name, const std::string& contents) {
	FILE* file = fopen(file_name.c_str(), "w");
	fwrite(contents.c_str(), sizeof(char), contents.size(), file);
	fclose(file);
}

std::string ToString(long long a) {
	std::string w;
	while (a > 0) {
		w = static_cast<char>(a%10 + '0') + w;
		a /= 10;
	}
	if (w.empty())
		w = "0";
	return w;
}

TemporaryDirectory::TemporaryDirectory(const char* new_name): _M_name(new char[strlen(new_name) + 2]) {
	unsigned size = strlen(new_name);
	memcpy(_M_name, new_name, size);
	_M_name[size] = _M_name[size + 1] = '\0';
	if (NULL == mkdtemp(_M_name)) {
		struct exception : std::exception {
			const char* what() const _GLIBCXX_USE_NOEXCEPT { return "Cannot create temporary directory\n"; }
		};
		throw exception();
	}
	_M_name[size] = '/';
	chmod(_M_name, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
}