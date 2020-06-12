#include "config.hpp"

Config::Config(
	const std::string& _filename){


}

std::list<ConfigSection>& Config::get_sections(){

	return sections;
}

ConfigSection* Config::get_section(
	const std::string& _sectionname){

	std::list<ConfigSection>::iterator found = std::find_if(sections.begin(), sections.end(), [_sectionname](const ConfigSection& sect){ 

        return sect.name.compare(_sectionname) == 0;
    });

    return found != sections.end() ? &*found : NULL;
}

std::string Config::get_value(
	const std::string& _sectionname,
	const std::string& _keyname){

	ConfigSection* sect = get_section(_sectionname);
    if (sect != NULL) {
        std::unordered_map<std::string, std::string>::const_iterator it = sect->keyvalues.find(_keyname);
        if (it != sect->keyvalues.end())
            return it->second;
    }
    return "";
}