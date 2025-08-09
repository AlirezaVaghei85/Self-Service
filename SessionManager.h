#ifndef SESSIONMANAGER_H_INCLUDE
#define SESSIONMANAGER_H_INCLUDE
#include <iostream>
#include "SessionBase.h"
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

    public:
        // Admin currentAdmin();
        static bool sign_in(); // for adding new admin
        void load_session() override;
        void save_session() override;
        void login() override;
        void logout() override;

        static SessionManager &instance()
        {
            static SessionManager instance;
            return instance;
        }

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
        ShoppingCart shopping_cart;
        int studentID;

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

        Student getCurrentStudent() { return currentStudent; }
        ShoppingCart getShoppingCart() { return shopping_cart; }
    };
}
#endif