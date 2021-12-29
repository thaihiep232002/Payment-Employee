#include "DbSet.h"
#include <fstream>


std::vector<std::tuple<bool, int,
	std::string, std::shared_ptr<Employee>>> DbSet::all() {
	std::vector<std::tuple<bool, int,
		std::string, std::shared_ptr<Employee>>> result;
	bool isSuccess;
	int error_code;
	std::string message;
	std::shared_ptr<Employee> employee = NULL;

	std::ifstream fin(_filename);
	if (!fin.is_open()) {
		isSuccess = false;
		message = "Can not open file!";
		error_code = 1;
	}
	else {
		while (!fin.eof()) {
			std::string bufferline1;
			getline(fin, bufferline1);
			std::string bufferline2;
			getline(fin, bufferline2);

			if (bufferline1 == "" || bufferline2 == "") {
				break;
			}
			int twodots = bufferline1.find(":");
			std::string catelogy = bufferline1.substr(0, twodots);
			std::string name, bufferPayment, total, fixedPayment = "";

			if (catelogy == "Manager") {
				name = bufferline1.substr(twodots + 2, bufferline1.size() - twodots - 2);
				int equal1 = bufferline2.find("=");
				int semicolon1 = bufferline2.find(";");
				int equal2 = bufferline2.find("=", semicolon1);
				int semicolon2 = bufferline2.find(";", equal2);
				int equal3 = bufferline2.find("=", semicolon2);
				fixedPayment = bufferline2.substr(equal1 + 1, semicolon1 - equal1 - 1);
				total = bufferline2.substr(equal2 + 1, semicolon2 - equal2 - 1);
				try {
					int tryConvertTotal = stoi(total);
				}
				catch (...) {
					isSuccess = false;
					error_code = 1;
					message = "Invalid total format exception!";
					result.push_back(make_tuple(isSuccess, error_code, message, employee));
					_total = result;
					continue;
				}
				bufferPayment = bufferline2.substr(equal3 + 1, bufferline2.size() - equal3 - 1);

				long long buffer0, buffer1;
				Dollar payment(bufferPayment);
				Dollar fixedpayment(fixedPayment);
				auto tryConvertPayment = _itc.convertBack(payment);
				auto tryConvertFixedPayment = _itc.convertBack(fixedpayment);
				tie(isSuccess, error_code, message, buffer0) = tryConvertPayment;
				if (!isSuccess) {
					result.push_back(make_tuple(isSuccess, error_code, message, employee));
					_total = result;
					continue;
				}
				else {
					tie(isSuccess, error_code, message, buffer0) = tryConvertFixedPayment;
					if (isSuccess) {
						employee = _factory->create(catelogy);
						employee->setName(name);
						employee->setSalaryPayment(payment);
						employee->setTotal(stoi(total));
						employee->setFixedPayment(fixedPayment);
					}
					result.push_back(make_tuple(isSuccess, error_code, message, employee));
					_total = result;
				}
			}
			else {
				name = bufferline1.substr(twodots + 2, bufferline1.size() - twodots - 2);
				int equal1 = bufferline2.find("=");
				int semicolon = bufferline2.find(";");
				int equal2 = bufferline2.find("=", semicolon);
				bufferPayment = bufferline2.substr(equal1 + 1, semicolon - equal1 - 1);
				total = bufferline2.substr(equal2 + 1, bufferline2.size() - equal2 - 1);
				try {
					int tryConvertTotal = stoi(total);
				}
				catch (...) {
					isSuccess = false;
					error_code = 1;
					message = "Invalid total format exception!";
					result.push_back(make_tuple(isSuccess, error_code, message, employee));
					_total = result;
					continue;
				}

				long long buffer0, buffer1;
				Dollar payment(bufferPayment);
				auto tryConvertPayment = _itc.convertBack(payment);

				tie(isSuccess, error_code, message, buffer0) = tryConvertPayment;
				if (isSuccess) {
					employee = _factory->create(catelogy);
					employee->setName(name);
					employee->setSalaryPayment(payment);
					employee->setTotal(stoi(total));
					employee->setFixedPayment(fixedPayment);
				}
				result.push_back(make_tuple(isSuccess, error_code, message, employee));
				_total = result;
			}
		}
	}
	fin.close();
	return result;
}

std::vector<std::tuple<bool, int,
	std::string, std::shared_ptr<Employee>>> DbSet::findCategory(const std::string& magicWord) {
	std::vector<std::tuple<bool, int,
		std::string, std::shared_ptr<Employee>>> result;
	for (auto item : _total) {
		if (get<3>(item)->magicWord() == magicWord) {
			result.push_back(item);
		}
	}
	return result;
}

std::vector<std::tuple<bool, int,
	std::string, std::shared_ptr<Employee>>> DbSet::findName(const std::string& name) {
	std::vector<std::tuple<bool, int,
		std::string, std::shared_ptr<Employee>>> result;
	for (auto item : _total) {
		if (get<3>(item)->getName().find(name) != -1) {
			result.push_back(item);
		}
	}
	return result;
}