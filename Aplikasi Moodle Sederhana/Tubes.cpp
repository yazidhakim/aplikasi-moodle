#include "tubes.h"

#include <utility>

void createListStudent(listStudent &LS) {
    first(LS) = nil;
}
adrStudent createStudent(Student data) {
    adrStudent S = new elmStudent;
    info(S) = std::move(data);
    relation(S) = nil;
    next(S) = nil;
    return S;
}

adrStudent findStudent(int nim, listStudent LS) {
    adrStudent found = first(LS);
    if (found == nil) {
        cout << "Tidak Terdapat data pada list" << endl;
        return nil;
    }
    while (found != nil && info(found).NIM != nim) {
        found = next(found);
    }
    if (found != nil && info(found).NIM == nim) {
        return found;
    } else {
        cout << "Tidak ditemukan mahasiswa dengan nim tersebut" << endl;
        return nil;
    }
}

void insertStudent(adrStudent student, listStudent &LS) {
    if (first(LS) == nil) {
        insertFirstStudent(student, LS);
    } else {
        insertLastStudent(student, LS);
    }
}
void insertFirstStudent(adrStudent student, listStudent &LS) {
    first(LS) = student;
}

void insertLastStudent(adrStudent student, listStudent &LS) {
    adrStudent P = first(LS);
    while (next(P) != nil) {
        P = next(P);
    }
    next(P) = student;
}

void deleteStudent(int nim, listStudent &LS) {
    adrStudent P = findStudent(nim, LS);
    if (P == nil) {
        cout << "Siswa Tidak Ditemukan" << endl;
        return;
    }
    if (P == first(LS)) {
        deleteFirstStudent(LS);
        if (relation(P) != nil) {
            unAssignAllRelation(P);
        }
    } else {
        adrStudent pointer = first(LS);
        while (next(pointer) != P) {
            pointer = next(pointer);
        }
        next(pointer) = next(P);
        next(P) = nil;
        if (relation(P) != nil) {
            unAssignAllRelation(P);
        }
    }
}

void deleteFirstStudent(listStudent &LS) {
    adrStudent P = first(LS);
    first(LS) = next(P);
    next(P) = nil;
}

void showStudent(listStudent LS) {
    int i = 1;
    adrStudent P = first(LS);
    if (P == nil) {
        cout << "Tidak Terdapat data pada list" << endl;
        return;
    }
    while (P != nil) {
        int totalCourse = countRelationFromStudent(P);
        cout << "[" << i << "]" << endl;
        cout << "NIM: "<< info(P).NIM << endl;
        cout << "Nama: "<< info(P).nama << endl;
        cout << "Kelas: "<< info(P).kelas << endl;
        cout << "Total Course: "<< totalCourse << endl;
        i++;
        P = next(P);
    }
    cout << endl;
}

adrRelation createRelation(adrCourse course) {
    adrRelation R = new elmRelation;
    info(R).course = course;
    info(R).nilaiTugas = 0;
    info(R).nilaiQuiz = 0;
    next(R) = nil;
    return R;
}

adrRelation findRelation(adrStudent student, adrCourse course) {
    adrRelation found = relation(student);
    if (found == nil) {
        cout << "Tidak terdapat course yang diambil" << endl;
        return nil;
    }
    while (found != nil && info(found).course != course) {
        found = next(found);
    }
    if (found != nil && info(found).course == course) {
        return found;
    } else {
        cout << "Tidak terdapat course yang diambil" << endl;
        return nil;
    }
}

void editRelationScore(adrRelation relation, int quizScore, int tugasScore) {
    info(relation).nilaiQuiz = quizScore;
    info(relation).nilaiTugas = tugasScore;
}

void assignCourse(adrStudent &student, adrCourse course) {
    adrRelation relationAdr = createRelation(course);
    adrRelation relationPointer = relation(student);
    if (relationPointer == nil) {
        relation(student) = relationAdr;
    } else {
        while (next(relationPointer) != nil) {
            relationPointer = next(relationPointer);
        }
        next(relationPointer) = relationAdr;
    }
}

void unAssignAllRelation(adrStudent student) {
    adrRelation relationAdr = relation(student);
    if (relationAdr == nil) {
        cout << "Tidak terdapat course yang diambil" << endl;
        return;
    }
    while (relationAdr != nil) {
        info(relationAdr).course = nil;
        relationAdr = next(relationAdr);
    }
}
void unAssignCourse(adrStudent &student, adrCourse course) {
    adrRelation relationAdr = findRelation(student, course);
    adrRelation pointer = relation(student);
    if (relationAdr != nil) {
        if (relation(student) == relationAdr) {
            deleteFirstRelation(student);
        } else {
            while(next(pointer) != relationAdr) {
                pointer = next(pointer);
            }
            next(pointer) = next(relationAdr);
            next(relationAdr) = nil;
            info(relationAdr).course = nil;
        }
    }
}
void deleteFirstRelation(adrStudent &student) {
    adrRelation relationAdr = relation(student);
    relation(student) = next(relationAdr);
    next(relationAdr) = nil;
    info(relationAdr).course = nil;
}

int countRelationFromStudent(adrStudent student) {
    int courseAssigned = 0;

    adrRelation pointer = relation(student);
    while (pointer != nil) {
        courseAssigned++;
        pointer = next(pointer);
    }
    return courseAssigned;
}

void createListCourse(listCourse &LC) {
    first(LC) = nil;
}
adrCourse createCourse(Course data) {
    adrCourse C = new elmCourse;
    info(C) = data;
    next(C) = nil;
    return C;
}
adrCourse findCourse(int courseID, listCourse LC) {
    adrCourse found = first(LC);

    if (found == nil) {
        cout << "Tidak Terdapat data pada list" << endl;
        return nil;
    }

    adrCourse firstVisited = nil;  // Initialize with nil
    while (found != firstVisited && info(found).courseId != courseID) {
        if (firstVisited == nil) {
            firstVisited = found;  // Update firstVisited on the first iteration
        }

        found = next(found);
    }

    if (info(found).courseId == courseID) {
        return found;
    } else {
        cout << "Tidak ditemukan mahasiswa dengan nim tersebut" << endl;
        return nil;
    }

}
void insertCourse(adrCourse course, listCourse &LC) {
    if (first(LC) == nil) {
        insertFirstCourse(course, LC);
    } else {
        insertLastCourse(course, LC);
    }
}

void insertFirstCourse(adrCourse course, listCourse &LC) {
    next(course) = course;
    first(LC) = course;
}

void insertLastCourse(adrCourse course, listCourse &LC) {
    adrCourse P = first(LC);

    while (next(P) != first(LC)) {
        P = next(P);
    }
    next(P) = course;
    next(course) = first(LC);  // Make it circular
}

void deleteCourse(int idCourse, listCourse &LC) {
    adrCourse course = findCourse(idCourse, LC);

    if (course == nil) {
        return;
    }

    if (first(LC) == course) {
        deleteFirstCourse(LC);
    } else {
        adrCourse pred = first(LC);
        while (next(pred) != course && next(pred) != first(LC)) {
            pred = next(pred);
        }
        next(pred) = next(course);
        next(course) = nil;
    }
}

void deleteFirstCourse(listCourse &LC) {
    adrCourse deletedNode = first(LC);

    if (next(deletedNode) == deletedNode) {
        // Only one node in the list
        first(LC) = nil;  // Make the list empty
    } else {
        // More than one node in the list
        adrCourse lastNode = first(LC);
        while (next(lastNode) != first(LC)) {
            lastNode = next(lastNode);
        }

        first(LC) = next(deletedNode);  // Update the first node
        next(lastNode) = first(LC);    // Make it circular
    }
}

void showCourse(listCourse LC) {
    int i = 1;
    adrCourse P = first(LC);

    if (P == nil) {
        cout << "Tidak Terdapat data pada list" << endl;
        return;
    }

    do {
        cout << "[" << i << "]" << endl;
        cout << "Course ID: " << info(P).courseId << endl;
        cout << "Soal Quiz: " << info(P).soalQuiz << endl;
        cout << "Jawaban Quiz: " << info(P).jawabanQuiz << endl;
        cout << "Soal Tugas: " << info(P).soalTugas << endl;
        cout << "Jawaban Tugas: " << info(P).jawabanTugas << endl;
        i++;
        P = next(P);
    } while (P != first(LC)); // Modified loop condition for circular list

    cout << endl;
}



void showStudentCourses(adrStudent student) {
    adrRelation relasi = relation(student);
    if (relasi == nil) {
        cout << "Siswa ini tidak mengikuti course apapun" << endl;
        return;
    }
    int i = 1;

    while (relasi != nil) {
        adrCourse P = info(relasi).course;
        cout << "[" << i << "]" << endl;
        cout << "NIM: "<< info(P).courseId << endl;
        cout << "Soal Quiz: "<< info(P).soalQuiz << endl;
        cout << "Nilai Quiz: "<< info(relasi).nilaiQuiz << endl;
        cout << "Soal Tugas: "<< info(P).soalTugas << endl;
        cout << "Nilai Tugas: "<< info(relasi).nilaiTugas << endl;
        i++;
        relasi = next(relasi);
    }
}

void studentMenu(listCourse &LC, listStudent &LS, adrStudent &student) {
    int adminChoice = -1;
    adrCourse courseAdr;
    int idCourse;

    while (adminChoice != 0) {
        cout << "Student Menu: " << endl;
        cout << "1. Tambah Course" << endl;
        cout << "2. Hapus Course" << endl;
        cout << "3. Tampilkan Seluruh Course yang Diikuti" << endl;
        cout << "4. Ikuti Course" << endl;
        cout << "0. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> adminChoice;

        switch (adminChoice) {
            case 1: {
                // Tambah Course
                showCourse(LC);
                Course dataCourse;
                cout << "Enter Course ID: ";
                cin >> dataCourse.courseId;

                adrCourse newCourse = findCourse(dataCourse.courseId, LC);
                if (newCourse != nil) {
                    assignCourse(student, newCourse);
                    cout << "Course added successfully!" << endl;
                }
                break;
            }

            case 2: {
                // Tambah Course
                showCourse(LC);
                Course dataCourse;
                cout << "Enter Course ID: ";
                cin >> dataCourse.courseId;

                adrCourse newCourse = findCourse(dataCourse.courseId, LC);
                if (newCourse != nil) {
                    unAssignCourse(student, newCourse);
                    cout << "Course Delete successfully!" << endl;
                }
                break;
            }

            case 3:
                // Tampilkan Seluruh Course
                showStudentCourses(student);
                break;

            case 4:
                showStudentCourses(student);
                if (relation(student) != nil) {
                    cout << "Masukkan ID Course yang ingin diikuti: "; cin >> idCourse;
                    courseAdr = findCourse(idCourse, LC);

                    if (courseAdr != nil) {
                        attendCourse(student, courseAdr);
                    }
                }
                break;
            case 0:
                cout << "Logging out..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}

void teacherMenu(listCourse &LC, listStudent &LS) {
    int adminChoice = -1;
    Student newStudent;
    adrStudent newStudentAr;
    while (adminChoice != 0) {
        cout << "Admin Menu: " << endl;
        cout << "1. Tambah Course" << endl;
        cout << "2. Hapus Course" << endl;
        cout << "3. Tampilkan Seluruh Course" << endl;
        cout << "4. Tambahkan Siswa" << endl;
        cout << "5. Hapus Siswa" << endl;
        cout << "6. Tampilkan Seluruh Siswa" << endl;
        cout << "7. Tampilkan nilai Siswa" << endl;
        cout << "0. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> adminChoice;

        switch (adminChoice) {
            case 1: {
                // Tambah Course
                Course dataCourse;
                cout << "Enter Course ID: ";
                cin >> dataCourse.courseId;
                cout << "Enter Quiz Question: ";
                cin.ignore(); // Ignore newline character left in the buffer
                getline(cin, dataCourse.soalQuiz);
                cout << "Enter Quiz Answer: ";
                getline(cin, dataCourse.jawabanQuiz);
                cout << "Enter Assignment Question: ";
                getline(cin, dataCourse.soalTugas);
                cout << "Enter Assignment Answer: ";
                getline(cin, dataCourse.jawabanTugas);

                adrCourse newCourse = createCourse(dataCourse);
                insertCourse(newCourse, LC);
                cout << "Course added successfully!" << endl;
                break;
            }

            case 2: {
                // Hapus Course
                showCourse(LC);
                int courseIdToDelete;
                cout << "Enter Course ID to delete: ";
                cin >> courseIdToDelete;
                deleteCourse(courseIdToDelete, LC);
                cout << "Course deleted successfully!" << endl;
                break;
            }

            case 3:
                // Tampilkan Seluruh Course
                showCourse(LC);
                break;
            case 4:
                // Tambahkan Siswa
                cout << "Enter NIM: ";
                cin >> newStudent.NIM;

                cout << "Enter Name: ";
                cin.ignore(); // Ignore newline character left in the buffer
                getline(cin, newStudent.nama);

                cout << "Enter Class: ";
                getline(cin, newStudent.kelas);
                newStudentAr = createStudent(newStudent);
                insertStudent(newStudentAr, LS);
                break;
            case 5:
                showStudent(LS);
                if (first(LS) != nil) {
                    cout << "Enter NIM Yang Mau Dihapus: ";
                    cin >> newStudent.NIM;
                    deleteStudent(newStudent.NIM, LS);
                } else {
                    cout << "Tidak Ada Siswa Pada List" << endl;
                }
                break;
            case 6:
                showStudent(LS);
                break;
            case 7:
        // Tampilkan detail nilai mahasiswa untuk suatu mata kuliah tertentu
                showStudent(LS);
                if (first(LS) != nil) {
                    int studentNIM;
                    cout << "Enter NIM of the student: ";
                    cin >> studentNIM;

                    adrStudent student = findStudent(studentNIM, LS);
                    if (student != nil) {
                        showStudentCourses(student);
                        int courseID;
                        cout << "Enter Course ID to view scores: ";
                        cin >> courseID;

                        adrCourse course = findCourse(courseID, LC);
                        if (course != nil) {
                            showStudentScore(student, course);
                        } else {
                            cout << "Course not found." << endl;
                        }
                    } else {
                        cout << "Student not found." << endl;
                    }
                } else {
                    cout << "No students in the list." << endl;
                }
                break;
            case 0:
                cout << "Logging out..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}



void attendCourse(adrStudent &student, adrCourse course) {
    adrRelation relation = findRelation(student, course);
    if (relation == nil) {
        return;
    }

    string jawabanQuiz;
    string jawabanTugas;
    int scoreQuiz = 0;
    int scoreTugas = 0;

    cout << "Soal Quiz: " << info(course).soalQuiz << endl;
    cout << "Masukkan jawaban quiz: "; cin >> jawabanQuiz; cin.ignore();
    cout << "Soal Tugas: " << info(course).soalTugas << endl;
    cout << "Masukkan jawaban tugas: "; cin >> jawabanTugas; cin.ignore();

    if (jawabanQuiz == info(course).jawabanQuiz) {
        scoreQuiz = 100;
    }

    if (jawabanTugas == info(course).jawabanTugas) {
        scoreTugas = 100;
    }

    editRelationScore(relation, scoreQuiz, scoreTugas);
}
void showStudentScore(adrStudent student, adrCourse course) {
    adrRelation relation = findRelation(student, course);
    if (relation != nil) {
        cout << "Student NIM: " << info(student).NIM << endl;
        cout << "Course ID: " << info(course).courseId << endl;
        cout << "Quiz Score: " << info(relation).nilaiQuiz << endl;
        cout << "Assignment Score: " << info(relation).nilaiTugas << endl;
    } else {
        cout << "Student has not attended this course." << endl;
    }
}

