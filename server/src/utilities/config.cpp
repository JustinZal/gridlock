#include "config.hpp"

Config::Config(
    const std::string& _filename){

    ConfigSection currentSection;
    std::ifstream config_file;
    std::__fs::filesystem::path path(_filename);
    config_file.open(path);

    if (!config_file.is_open()){
        std::system((std::string("mkdir -p ")+std::string(path.parent_path().c_str())).c_str());
        std::system((std::string("touch ")+std::string(path.c_str())).c_str());
        config_file.open(path);
        if(!config_file.is_open()){
            return;
        }
    }

    for(std::string line; std::getline(config_file,line);){
        if(!line.empty() && line[0] != ';' && line[0] != '#'){
        	if(line[0] == '['){
        		size_t end = line.find_first_of(']');
                if (end != std::string::npos) {

                    // this is a new section so if we have a current section populated, add it to list
                    if (!currentSection.name.empty()) {
                        sections.push_back(currentSection);  // copy
                        currentSection.name.clear();  // clear section for re-use
                        currentSection.keyvalues.clear();
                    }
                    currentSection.name = line.substr(1, end - 1);
                }
                else {
                    // section has no closing ] char
                }
        	}
            else{
                size_t end = line.find_first_of("=:");
                if (end != std::string::npos) {
                    std::string name = line.substr(0, end);
                    std::string value = line.substr(end + 1);

                    currentSection.keyvalues[name] = value;
                }
            }
        }
    }

    if (!currentSection.name.empty()) {
        sections.push_back(currentSection);  // copy
        currentSection.name = "";
        currentSection.keyvalues.clear();
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

bool Config::exists_value(
        const std::string& _sectionname,
        const std::string& _keyname){

    ConfigSection* sect = get_section(_sectionname);
    if (sect != NULL) {
        std::unordered_map<std::string, std::string>::const_iterator it = sect->keyvalues.find(_keyname);
        if (it != sect->keyvalues.end())
            return true;
    }
    return false;
}
