#include "PathHelper.h"
#include <direct.h>


PathHelper::PathHelper()
{
}


PathHelper::~PathHelper()
{
}

std::string PathHelper::getBasePath()
{
	char *path = NULL;
	path = _getcwd(NULL, 0); // or _getcwd
	std::string workingDir = path;
	return workingDir;
}

std::string PathHelper::removeFilePiceFromPath(const std::string& filepath)
{
	return filepath.substr(0, filepath.find_last_of("\\/"));
}
