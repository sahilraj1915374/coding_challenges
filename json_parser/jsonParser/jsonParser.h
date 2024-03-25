#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
#include <sstream>

union JsonValue
{
	bool jsonBool;
	int jsonInt;
	double jsonDouble;
	std::string* jsonString;
	std::vector<JsonValue>* jsonArray;
	std::unordered_map<std::string, JsonValue>* jsonObject;
};

class JsonParser
{
	public:
		void parse(const std::string& input);
		void parse(std::istream& str);

	private:
		bool matches(std::istream& dataStream, const char* pattern);
		void printInvalidJson();
		void printValidJson();
		void parseObject(std::istream& dataStream);
		void parseKey(std::istream& dataStream, std::string& key);
		void parseColon(std::istream& dataStream);
		void parseValue(std::istream& dataStream, JsonValue& val);
		bool parseComma(std::istream& dataStream);
		void parseString(std::istream& dataStream, std::string& str);
		std::unordered_map<std::string, JsonValue> objectMap_;
};
#endif
