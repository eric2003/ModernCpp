#include <iostream>  
#include <map>  
#include <string>  

// 定义一个 Person 类  
class Person {  
public:  
    std::string name;  
    int age;  

    Person(std::string name, int age) : name(name), age(age) {} 
    bool operator < (const Person &rhs) const
    {
        //return this->age < rhs.age;
        return this->name < rhs.name;
    }  
};  

int main(int argc, char* argv[])
{  
    // 创建一个 std::map，使用 CompareByAge 进行排序  
    std::map<Person, std::string> people;  

    // 添加一些 Person 对象到 map 中  
    people.emplace(Person("Alice", 30), "Engineer");  
    people.emplace(Person("Bob", 25), "Designer");  
    people.emplace(Person("Charlie", 35), "Teacher");  

    // 输出 map 中的内容  
    for (const auto &entry : people) {  
        std::cout << entry.first.name << " (" << entry.first.age << ") is a " << entry.second << "\n";  
    }  

    return 0;  
}