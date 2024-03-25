#include "jsonParser.h"

void JsonParser::parse(const std::string& str)
{
	std::istringstream ss(str);
	parse(str);
}

void JsonParser::parse(std::istream& dataStream)
{
	if(!matches(dataStream,"{"))
	{
		printInvalidJson();
		exit(EXIT_FAILURE);
	}

	parseObject(dataStream);

	if(!matches(dataStream,"}"))
	{
		printInvalidJson();
		exit(EXIT_FAILURE);
	}
	
	printValidJson();
}

bool JsonParser::matches(std::istream& dataStream, const char* pattern)
{
	dataStream >> std::ws;
	char ch(0);
	dataStream.get(ch);
	if(ch == '\"' || ch == '}')
	{
		dataStream.putback(ch);
	}
	return pattern[0] == ch;
}

void JsonParser::parseObject(std::istream& dataStream)
{
	do
	{
		std::string key;
		JsonValue val{};
		
		parseKey(dataStream, key);
		if(key.empty())
		{
			return;
		}
		parseColon(dataStream);
		parseValue(dataStream, val);

		objectMap_.insert(std::make_pair(key, val));
	}
	while(!dataStream.eof() && parseComma(dataStream));
}

void JsonParser::parseKey(std::istream& dataStream, std::string& key)
{
	if(matches(dataStream,"\""))
	{
		parseString(dataStream, key);
	}
}

void JsonParser::parseColon(std::istream& dataStream)
{
	if(!matches(dataStream,":"))
	{
		printInvalidJson();
		exit(EXIT_FAILURE);
	}
}

void JsonParser::parseValue(std::istream& dataStream, JsonValue& val)
{
}

void JsonParser::parseString(std::istream& dataStream, std::string& str)
{
	char ch(0);
	dataStream.get(ch);
	while(ch != EOF)
	{
		str.push_back(ch);
		dataStream.get(ch);
	}
}

void JsonParser::printInvalidJson()
{
	std::cerr << "Invalid Json" << std::endl;
}

void JsonParser::printValidJson()
{
	std::cout << "Valid Json" << std::endl;
}

bool JsonParser::parseComma(std::istream& dataStream)
{
	return true;
}
