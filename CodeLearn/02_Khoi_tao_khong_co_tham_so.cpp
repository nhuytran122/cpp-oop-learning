//https://codelearn.io/learning/lap-trinh-huong-doi-tuong-trong-cpp/2643251
#include <iostream>

using namespace std;

class Student {
public:
    string name;
    int age;
    void getInformation(){
        cin >> name >> age;
    }
    void display(){
        cout << "Name: " << name << endl << "Age: " << age;
    }
};

int main() {
    Student s1;
    s1.getInformation();
    s1.display();
    return 0;
}