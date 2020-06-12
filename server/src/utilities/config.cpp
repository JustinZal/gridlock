#include "config.hpp"

Config::Config(
	const std::string& _filename){
		std::fstream config_file;
	  const std::string DIRECTORY = "etc/gridlock";
	  const std::string opening_path = DIRECTORY + "/" + _filename;
	  config_file.open(opening_path);

	  if (!config_file) {
	    std::__fs::filesystem::create_directories(_directory);
	    config_file.open(opening_place, std::fstream::out);
	  }

		std::string file_stream = "";
		std::list<ConfigSection> _sections;
		int iterator = -1;

		while (inFile >> file_stream) {
			if (file_stream[0] == "[") {
				iterator++;
				_sections[iterator] = new ConfigSection {};
				_sections.name = file_stream.erase(std::remove(str.begin(), str.end(), 'a'), str.end());
			};

		}
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
