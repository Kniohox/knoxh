#include <iostream>

#include <knoxh/util/funclib.h>

namespace knoxh
{
	void error_callback(int error, const char* description)
	{
	    fputs(description, stderr);
	    _fgetchar();
	}
}
