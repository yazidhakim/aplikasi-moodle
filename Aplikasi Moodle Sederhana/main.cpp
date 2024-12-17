#include "tubes.h"
#include "Tubes.cpp"
int main() {
    listStudent LS;
    listCourse LC;
    adrStudent student;
    createListCourse(LC);
    createListStudent(LS);

    int nim;
    int role;

    do {
        cout << "Login menu:" << endl;
        cout << "1. Teacher" << endl;
        cout << "2. Student" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> role;
        if (role == 1) {
            // Admin login
            teacherMenu(LC, LS);
        } else if (role == 2) {
            // User login
            cout << "Enter NIM: ";
            cin >> nim;
            student = findStudent(nim, LS);
            if (student != nil) {
                studentMenu(LC, LS, student);
            } else {
                cout << "Invalid Student NIM" << endl;
            }
        } else if (role == 3) {
            cout << "Exit program." << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while(role != 3);


    return 0;
}
