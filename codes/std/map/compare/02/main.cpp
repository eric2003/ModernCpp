#include <iostream>  
#include <map>  
#include <string>  

// ����һ�� Person ��  
class Person {  
public:  
    std::string name;  
    int age;  

    Person(std::string name, int age) : name(name), age(age) {}  
};  

// �Զ���ȽϺ���������������  
struct CompareByAge {  
    bool operator()(const Person &a, const Person &b) const {  
        return a.age < b.age; // ������������  
    }  
};  

int main(int argc, char* argv[])
{  
    // ����һ�� std::map��ʹ�� CompareByAge ��������  
    std::map<Person, std::string, CompareByAge> people;  

    // ���һЩ Person ���� map ��  
    people.emplace(Person("Alice", 30), "Engineer");  
    people.emplace(Person("Bob", 25), "Designer");  
    people.emplace(Person("Charlie", 35), "Teacher");  

    // ��� map �е�����  
    for (const auto &entry : people) {  
        std::cout << entry.first.name << " (" << entry.first.age << ") is a " << entry.second << "\n";  
    }  

    return 0;  
}