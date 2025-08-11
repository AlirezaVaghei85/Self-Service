#ifndef CONFIGPATHS_H_INCLUDE
#define CONFIGPATHS_H_INCLUDE
#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

class ConfigPaths
{
private:
    ConfigPaths() = default;

    fs::path c_students;
    fs::path d_logs = "logs";
    fs::path d_config = "config";
    fs::path d_foodservice = "foodservice";
    fs::path d_sessions = "sessions";
    fs::path d_student_sessions = "sessions/students";
    fs::path d_admin_sessions = "sessions/admins";
    fs::path j_admin_config = d_config / "admin_config.json";
    fs::path j_ConfigPaths = d_config / "ConfigPaths.json";
    fs::path j_meals = "meals.json";
    fs::path j_dininghalls = "dininghalls.json";
    fs::path j_foodservice_ids = d_foodservice / "foodservice_ids.json";
    fs::path l_students_log_file = d_logs / "students.log";
    fs::path l_admins_log_file = d_logs / "admins.log";
    fs::path t_student_transactions = d_student_sessions / "transactions.txt";

public:
    static ConfigPaths &instance()
    {
        static ConfigPaths instance;
        return instance;
    }

    ConfigPaths(const ConfigPaths &) = delete;
    ConfigPaths operator=(const ConfigPaths &) = delete;
};

#endif