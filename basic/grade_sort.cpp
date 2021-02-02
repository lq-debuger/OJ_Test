#include<bits/stdc++.h>

using namespace std;

//成绩排序问题  清华大学

struct stu
{
    string name;
    int value;
    int id;
};

bool comp_1(stu stu1, stu stu2){
    if (stu1.value == stu2.value)
        return stu1.id < stu2.id;
    return stu1.value > stu2.value;
    
}

bool comp_0(stu stu1, stu stu2){
    if (stu1.value == stu2.value)
        return stu1.id < stu2.id;
    return stu1.value < stu2.value;
}

int main(int argc, const char** argv) {
    int count , fun;
    cin >> count >> fun;
    stu students[100];
    string name;
    int grade;
    stu student;
    for (int i = 0; i < count; i++)
    {
        cin >> name >> grade;
        student.name = name;
        student.value = grade;
        student.id = i;
        students[i] = student;
    }
    if (fun == 0)
    {   
        sort(students,students+count,comp_0);
    }
    if (fun == 1)
    {   
        sort(students,students+count,comp_1);
    }
    
    for (int i = 0; i < count; i++)
    {
        cout << students[i].name  << " " << students[i].value << endl;
    }
    
    
    return 0;
}