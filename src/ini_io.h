#ifndef INIREADER_INI_IO_H
#define INIREADER_INI_IO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <vector>

/*
 * SECTION REGEX:           (\[([^#;\r\n]+)\])
 * KEY-VALUE PAIR REGEX:    (([^\[\]\r\n=#;]+)=([^#;\\\r\n]*(?:\\.[^#;\\\r\n]*)*))
 * COMMENTS REGEX:          ((#|;)(?<comm>.+)$)
 * */

struct SectionUnit {
    std::string section_name;
    std::vector<std::pair<std::string, std::string>> kv_pairs;
};

class IniIO {
public:
    explicit IniIO(const std::string &filename);

    std::string get_value(std::string_view section_name, std::string_view key) const;

    std::string get_value(std::string_view key) const;

    std::vector<std::pair<std::string, std::string>> get_kvps(std::string_view section_name) const;

    void set_value(std::string_view section_name, std::string_view key, std::string_view value);

private:
    std::string filename;
    std::vector<SectionUnit> sections;

    void save_file();

    std::pair<ptrdiff_t, ptrdiff_t> get_positions(std::string_view section_name, std::string_view key) const;

    ptrdiff_t get_section_pos(std::string_view section) const;

    ptrdiff_t get_key_pos(std::string_view key, ptrdiff_t section_pos) const;

    bool is_section(std::string str, std::cmatch &results) const;

    bool is_key_value(std::string str, std::cmatch &results) const;

    std::pair<std::string, std::string> split_key_value(std::string str);

//    void add_value(const std::string &section_name, const std::string &key, const std::string &value);
};

#endif //INIREADER_INI_IO_H
