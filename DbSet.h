#include <string>
#include <vector>
#include <memory>
#include "EmployeeFactory.h"
#include <tuple>

class DbSet {
private:
	std::string _filename;
	std::shared_ptr<EmployeeFactory> _factory;
	IntegerToDollarUIConverter _itc;
	std::vector<std::tuple<bool, int,
		std::string, std::shared_ptr<Employee>>> _total;
public:
	DbSet() {
		_factory = EmployeeFactory::instance();
	}

	DbSet(std::string filename) {
		_filename = filename;
		_factory = EmployeeFactory::instance();
	}
public:
	std::vector<std::tuple<bool, int, 
		std::string, std::shared_ptr<Employee>>> all();
public:
	std::vector<std::tuple<bool, int,
		std::string, std::shared_ptr<Employee>>> findCategory(const std::string&);

public:
	std::vector<std::tuple<bool, int,
		std::string, std::shared_ptr<Employee>>> findName(const std::string&);
};
