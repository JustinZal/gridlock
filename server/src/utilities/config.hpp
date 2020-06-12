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

	std::list<ConfigSection>& get_sections();

    ConfigSection* get_section(
    	const std::string& _sectionname);

    std::string get_value(
    	const std::string& _sectionname,
    	const std::string& _keyname);

    bool exists_value(
        const std::string& _sectionname,
        const std::string& _keyname);
};

#endif
