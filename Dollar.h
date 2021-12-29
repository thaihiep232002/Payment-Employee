#include <string>
#include <tuple>
#include <regex>

class IntegerToDollarUIConverter;
class Dollar;
class Util;

class IntegerToDollarUIConverter {
private:
    std::string _thousandSeparator = ".";
    std::string _currency = "$";
public:
    bool isValidFormat(const std::string&) const;
    Dollar convert(const long long&);
    std::tuple<bool, int, std::string, long long> convertBack(const Dollar&) const;
};

class Dollar {
private:
    std::string _value;
public:
    Dollar() {
        _value = "0$";
    }

    Dollar(std::string value) 
        :_value(value){}

public:
    std::string getValue() const { return _value; }
    void Setter(const std::string &value) { _value = value; }
};

class Util {
public:
    static Dollar Mutilply(const Dollar& argument, const long long& value);

    static Dollar Add(const Dollar& argument0, const Dollar& argument1);
};