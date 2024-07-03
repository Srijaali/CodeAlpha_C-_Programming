// Login and Registration System
// The login And Registration System project in
// C++ involves mainly the user registration
// process. User Credentials like usernames and
// passwords are asked from the user. If the
// registration of the user is successful then with
// the given credentials a file will be created of a
// particular user in the database.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Login{
    private:
    string username;

    string password;
    string original_password;

    public:
    Login():username("") , password("") , original_password("") {}

    void login_Registration(){
        cout<< "Enter the username: " << endl;
        cin >> username;

        cout << "Enter password: " << endl;
        cin >> original_password;

        cout << "Re-enter your password: " << endl;
        cin >> password;

        if(password == original_password){
            cout << "Registration and Login Successful!" << endl;
             saveCredentials();
        }
        else{
            cout << "Login and Registration failed!.. Try again." << endl;
        }
    }

    void saveCredentials(){
        string filename = username + "_credentials.txt";
        fstream new_file;
        new_file.open(filename , ios::out);
        
        if(!new_file){
            cout << "Error creating file. " << endl;
        }
        else{
            cout << "File created!" << endl;
            new_file << "Username: " << username << endl;
            new_file << "Password: " << original_password << endl;
            cout << "Credentials Saved!" << endl;
            new_file.close();
        }

    }
};

int main(){
    Login login;
    login.login_Registration();
}
