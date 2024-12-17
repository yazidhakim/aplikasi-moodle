#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
#include <string>
#define nil NULL

#define info(P) (P)->info
#define next(P) (P)->next
#define relation(P) (P)->relation
#define first(L) ((L).first)


using namespace std;

typedef struct elmStudent *adrStudent;
typedef struct elmCourse *adrCourse;
typedef struct elmRelation *adrRelation;

struct Student {
    int NIM;
    string nama;
    string kelas;
};

struct Course {
    int courseId;
    string soalQuiz;
    string soalTugas;
    string jawabanQuiz;
    string jawabanTugas;
};

struct Relation {
    int nilaiQuiz;
    int nilaiTugas;
    adrCourse course;
};

struct elmStudent {
    Student info;
    adrRelation relation;
    adrStudent next;
};

struct elmCourse {
    Course info;
    adrCourse next;
};

struct elmRelation {
    Relation info;
    adrRelation next;
};

struct listStudent {
    adrStudent first;
};

struct listCourse {
    adrCourse first;
};

void createListStudent(listStudent &LS);
adrStudent createStudent(Student data);
adrStudent findStudent(int nim, listStudent LS);
void insertStudent(adrStudent student, listStudent &LS);
void insertFirstStudent(adrStudent student, listStudent &LS);
void insertLastStudent(adrStudent student, listStudent &LS);
void deleteStudent(int nim, listStudent &LS);
void deleteFirstStudent(listStudent &LS);
void showStudent(listStudent LS);

adrRelation createRelation(Relation relation);
adrRelation findRelation(adrStudent student, adrCourse course);
void editRelationScore(adrRelation relation, int quizScore, int tugasScore);
void assignCourse(adrStudent &student, adrCourse course);
void unAssignAllRelation(adrStudent student);
void unAssignCourse(adrStudent &student, adrCourse course);
void deleteFirstRelation(adrStudent &student);
int countRelationFromStudent(adrStudent student);

void createListCourse(listCourse &LC);
adrCourse createCourse(Course data);
adrCourse findCourse(int courseID, listCourse LC);
void insertCourse(adrCourse course, listCourse &LC);
void insertFirstCourse(adrCourse course, listCourse &LC);
void insertLastCourse(adrCourse course, listCourse &LC);
void deleteCourse(int idCourse, listCourse &LC);
void deleteFirstCourse(listCourse &LC);
void showCourse(listCourse LC);

void teacherMenu(listCourse &LC, listStudent &LS);
void studentMenu(listCourse &LC, listStudent &LS, adrStudent &student);

void attendCourse(adrStudent &student, adrCourse course);
void showStudentCourses(adrStudent student);
void showStudentScore(adrStudent student, adrCourse course);
#endif // TUBES_H_INCLUDED



