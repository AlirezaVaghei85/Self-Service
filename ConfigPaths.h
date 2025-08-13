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
    fs::path d_logs = d_data / "logs";
    fs::path d_config = d_data / "config";
    fs::path d_foodservice = d_data / "foodservice";
    fs::path d_sessions = d_data / "sessions";
    fs::path d_student_sessions = d_data / "sessions/students";
    fs::path d_admin_sessions = d_data / "sessions/admins";
    fs::path j_admin_config = d_config / "admin_config.json";
    fs::path j_ConfigPaths = d_config / "ConfigPaths.json";
    fs::path j_meals = d_data / "meals.json";
    fs::path j_dininghalls = d_data / "dininghalls.json";
    fs::path j_foodservice_ids = d_foodservice / "foodservice_ids.json";
    fs::path l_students_log_file = d_logs / "students.log";
    fs::path l_admins_log_file = d_logs / "admin.log";
    fs::path t_student_transactions = d_student_sessions / "transactions";

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