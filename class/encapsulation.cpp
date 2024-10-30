// 来自GPT的数据封装代码示例

#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Getter函数用于获取私有数据成员的值
    std::string getName() const {
        return name;
    }

    // Setter函数用于设置私有数据成员的值
    void setName(const std::string& newName) {
        name = newName;
    }

    // 同样的，可以添加获取和设置年龄的函数
    int getAge() const {
        return age;
    }

    void setAge(int newAge) {
        age = newAge;
    }
};

int main() {
    Person person;
    person.setName("Alice");
    person.setAge(30);

    std::cout << "Name: " << person.getName() << ", Age: " << person.getAge() << std::endl;

    return 0;
}
