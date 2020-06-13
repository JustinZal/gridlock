#ifndef GRIDLOCK_CONFIGPARSER_HPP
#define GRIDLOCK_CONFIGPARSER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <filesystem>
#include <cstdlib>


#include "config.hpp"

struct ConfigSection{

    std::string name;
    std::unordered_map<std::string, std::string> keyvalues;
};

class Config{

private:
	std::list<ConfigSection> sections;

public:
	Config(
		const std::string& _filename);

	std::list<ConfigSection>& getSections();

    ConfigSection* getSection(
    	const std::string& _sectionname);

    std::string getValue(
    	const std::string& _sectionname,
    	const std::string& _keyname);

    bool existsValue(
        const std::string& _sectionname,
        const std::string& _keyname);
};

#endif
