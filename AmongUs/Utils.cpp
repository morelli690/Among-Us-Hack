#include "Utils.h"
#include "List.h"

const char* Utils::RandomString(int length)
{
    static char* string = new char[41];

    const char alphanum[] =
        "0123456789"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 40; ++i) {
        string[i] = alphanum[rand() % 36];
    }

    string[40] = 0;

    return string;
}

Il2CppString* Utils::ToIl2CppString(const char* string)
{
    return Runtime::il2cpp_string_new(string);
}

const char* Utils::FromIl2CppString(Il2CppString* string)
{
    return Utils::ToConstChar(Runtime::GetString(string));
}

std::string Utils::FromConstChar(const char* string)
{
    return std::string(string);
}

const char* Utils::ToConstChar(std::string string)
{
    return string.c_str();
}

template<typename T>
inline T Utils::ArrayToList(Il2CppArray* array, T Type)
{
    return List<Type>(array);
}