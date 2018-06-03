#include <iostream>
#include <gtest/gtest.h>
#include "../src/ini_io.h"


TEST(IniIOTests, GetValueBySectionAndKey)
{
    IniIO iniFile("testIni_01.ini");
    std::string value = iniFile.get_value("owner", "name");

    ASSERT_STREQ(value.c_str(), "JohnDoe");
}

TEST(IniIOTests, GetValueByKey)
{
    IniIO iniFile("testIni_01.ini");
    std::string value = iniFile.get_value("file");

    ASSERT_STREQ(value.c_str(), "\"payroll.dat\"");
}

TEST(IniIOTests, SetValue)
{
    IniIO iniFile("testIni_01.ini");
    iniFile.set_value("database", "port", "8");

    std::string value = iniFile.get_value("database", "port");

    ASSERT_STREQ(value.c_str(), "8");
}