#ifndef SESSIONMANAGER_H_INCLUDE
#define SESSIONMANAGER_H_INCLUDE
#include <iostream>
#include "SessionBase.h"
#include "ConfigPaths.h"
#include "Storage.h"
#include "Admin.h"
#include "Student.h"
#include "ShoppingCart.h"

namespace AdminSession
{
    class SessionManager : public SessionBase
    {
    private:
        Admin currentAdmin;
        int adminID;
        ConfigPaths &CP = ConfigPaths::instance();
        Storage &S = Storage::instance();

    public:
        // Admin currentAdmin();
        void sign_up();         // for adding new admin
        bool isThereAnyAdmin(); // for checking if there is any admin in the system
        void load_session() override {}
        void save_session() override {}
        void login() override;
        void logout() override {}

        static SessionManager &instance()
        {
            static SessionManager instance;
            return instance;
        }

        void setCurrentAdmin(Admin A) { currentAdmin = A; }

        Admin getcurrentAdmin() { return currentAdmin; }
        int getAdminID() { return adminID; }
    };
}
namespace StudentSession
{
    class SessionManager : public SessionBase
    {
    private:
        Student currentStudent;
        ShoppingCart *shopping_cart;
        int studentID;
        ConfigPaths &CP = ConfigPaths::instance();
        Storage &S = Storage::instance();

    public:
        // Student currentStudent();
        // ShoppingCart shoppingCart();
        void load_session() override {}
        void save_session() override;
        void login() override;
        void logout() override {}

        static SessionManager &instance()
        {
            static SessionManager instance;
            return instance;
        }

        void setCurrentStudent(Student S) { currentStudent = S; }

        Student getCurrentStudent() { return currentStudent; }
        ShoppingCart getShoppingCart() { return *shopping_cart; }
    };
}

#endif