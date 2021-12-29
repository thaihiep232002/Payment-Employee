class Company {
private:
    std::shared_ptr<DbSet> _database;
    std::vector<std::tuple<bool, int,
        std::string, std::shared_ptr<Employee>>> _employees;
    std::shared_ptr<EmployeeFactory> _factory;

    bool _isSuccess = true;
    int _error_code = 0;
    std::string _message = "";
    std::shared_ptr<Employee> _employee = NULL;
public:
    Company() {
        _database = std::make_shared<DbSet>("November2021.txt");
        _employees = _database->all();
        _factory = EmployeeFactory::instance();
    }
public:
    void CompanyLoop();
public:
    static void DisplayMenuUI();
};

void Company::DisplayMenuUI() {
    std::cout << "What do you want to do? " << std::endl;
    std::cout << "1. Display detailed payment for all of the employees" << std::endl;
    std::cout << "2. Find some employees by categories" << std::endl;
    std::cout << "3. Find some employees by name" << std::endl;
    std::cout << std::endl;
    std::cout << "0. Quit" << std::endl;
    std::cout << std::endl;
    std::cout << "Please enter your choice: ";
}

void Company::CompanyLoop() {
    int flag = 0;
    while (true) {
        system("cls");
        if (flag == 1) break;
        DisplayMenuUI();
        int choice;
        try {
            std::string bufferChoice;
            std::getline(std::cin, bufferChoice);
            if (bufferChoice != "0" && bufferChoice != "1" && bufferChoice != "2" && bufferChoice != "3") {
                throw (bufferChoice);
            }
            else {
                choice = stoi(bufferChoice);
            }
        }
        catch (std::string value) {
            std::cout << value << " is not format input!" << std::endl;
            std::cin.get();
            continue;
        }
        switch (choice)
        {
        case 1:
        {
            for (auto item : _employees) {
                tie(_isSuccess, _error_code, _message, _employee) = item;
                if (_isSuccess) {
                    std::cout << _employee->toString() << std::endl;
                }
                else {
                    std::cout << _message << std::endl;
                }
            }
            std::cin.get();
            break;
        }
        case 2:
        {
            system("cls");

            std::cout << "what do you want to choice?" << std::endl;
            _factory->displayMenu();
            std::cout << "Please enter your choice: ";
            std::string buffer;
            int choice;
            try {
                std::getline(std::cin, buffer);
                if (buffer != "1" && buffer != "2" && buffer != "3" && buffer != "4") {
                    throw (buffer);
                }
                else {
                    choice = stoi(buffer);
                }
            }
            catch (std::string value) {
                std::cout << value << " is not format input!" << std::endl;
                std::cin.get();
                continue;
            }
            auto prototypes = _factory->prototypes();
            auto target = _database->findCategory(prototypes[choice]->magicWord());

            for (auto item : target) {
                tie(_isSuccess, _error_code, _message, _employee) = item;
                if (_isSuccess) {
                    std::cout << _employee->toString() << std::endl;
                }
                else {
                    std::cout << _message << std::endl;
                }
            }
            std::cin.get();
            break;
        }
        case 3:
        {
            system("cls");

            std::cout << "what do you want to find?" << std::endl;
            std::cout << "Please enter your name: ";
            std::string name;
            std::getline(std::cin, name);
            auto target = _database->findName(name);

            for (auto item : target) {
                tie(_isSuccess, _error_code, _message, _employee) = item;
                if (_isSuccess) {
                    std::cout << _employee->toString() << std::endl;
                }
                else {
                    std::cout << _message << std::endl;
                }
            }
            std::cin.get();
            break;
        }
        case 0:
            flag = 1;
            break;
        default:
            break;
        }
    }
}