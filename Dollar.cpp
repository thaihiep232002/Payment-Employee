//
//  IntegerToDollarUIConverter.cpp
//  Project02
//
//  Created by ThaiHiep on 08/12/2021.
//

#include "Dollar.h"

bool IntegerToDollarUIConverter::isValidFormat(const std::string& value) const {
    std::string pattern = "[0-9]{1,3}(\\.[0-9]{3})*\\$";
    std::regex dollarPattern(pattern);
    bool result = std::regex_match(value, dollarPattern);
    return result;
}

Dollar IntegerToDollarUIConverter::convert(const long long& value) {
    std::string temp = "";
    temp = std::to_string(value);
    int i = temp.size() - 3;
    while (i > 0) {
        temp.insert(i, _thousandSeparator);
        i -= 3;
    }
    temp.append(_currency);
    Dollar result;
    result.Setter(temp);
    return result;
}

std::tuple<bool, int, std::string, long long> IntegerToDollarUIConverter::convertBack(const Dollar &temp) const {
    bool succeeded = true;
    int error_code = 0;
    std::string message = "";
    std::string dollar = temp.getValue();
    long long data = 0;

    bool isValid = isValidFormat(dollar);
    if (isValid) {
        succeeded = true;
        dollar.erase(remove(dollar.begin(), dollar.end(), '.'), dollar.end());
        data = stoll(dollar);
    }
    else {
        succeeded = false;
        error_code = 1;
        message = "Invalid dollar format exception!";
    }
    auto result = make_tuple(succeeded, error_code, message, data);
    return result;
}

Dollar Util::Mutilply(const Dollar& argument, const long long& value) {
    Dollar result;
    IntegerToDollarUIConverter itc;
    bool isSuccess = true;
    int error_code = 0;
    std::string message = "";
    long long data = 0;
    auto target = itc.convertBack(argument);
    tie(isSuccess, error_code, message, data) = target;
    data *= value;
    result = itc.convert(data);
    return result;
}

Dollar Util::Add(const Dollar& argument0, const Dollar& argument1) {
    Dollar result;
    IntegerToDollarUIConverter itc;
    bool isSuccess = true;
    int error_code = 0;
    std::string message = "";
    long long data0 = 0;
    long long data1 = 0;

    auto target0 = itc.convertBack(argument0);
    auto target1 = itc.convertBack(argument1);
    tie(isSuccess, error_code, message, data0) = target0;
    tie(isSuccess, error_code, message, data1) = target1;

    result = itc.convert(data0 + data1);
    return result;
}