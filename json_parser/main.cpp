#include "jsonParser/jsonParser.h"
#include <fstream>

int main(int argc, char* argv[])
{
	std::ifstream file(argv[1]);
	if(file.is_open())
	{
		JsonParser obj;
		obj.parse(file);
	}
	return EXIT_SUCCESS;
}
