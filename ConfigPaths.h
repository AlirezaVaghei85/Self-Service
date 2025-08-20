#ifndef CONFIGPATHS_H_INCLUDE
#define CONFIGPATHS_H_INCLUDE
#include <iostream>
#include <filesystem>
#include "Student.h"

using namespace std;
namespace fs = std::filesystem;

class ConfigPaths
{
private:
    ConfigPaths() = default;

public:
    fs::path d_data = "Data";
    fs::path c_students = "studentsCsvFile.csv";
    fs::path d_logs = d_data / "Logs";
    fs::path d_config = d_data / "Config";
    fs::path d_foodservice = d_data / "Food Service";
    fs::path d_sessions = d_data / "Sessions";
    fs::path d_student_sessions = d_data / "Sessions" / "Students";
    fs::path d_admin_sessions = d_data / "Sessions" / "Admin";
    fs::path j_admin_config = d_config / "Admin Config";
    fs::path j_ConfigPaths = d_config / "Config Paths";
    fs::path j_meals = d_foodservice / "Meals";
    fs::path j_dininghalls = d_foodservice / "DiningHalls";
    fs::path j_foodservice_ids = d_foodservice / "Food Service IDs";
    fs::path l_students_log_file = d_logs / "Students.log";
    fs::path l_admins_log_file = d_logs / "Admin.log";
    fs::path t_student_transactions = d_student_sessions / "Transactions";

    fs::path j_reservations(Student * = nullptr);
    fs::path t_transactions(Student * = nullptr);

    void Creat_Directories();

    static ConfigPaths &instance()
    {
        static ConfigPaths instance;
        return instance;
    }

    ConfigPaths(const ConfigPaths &) = delete;
    ConfigPaths operator=(const ConfigPaths &) = delete;
};

#endif