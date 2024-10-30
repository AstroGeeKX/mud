// 用于测试编译器是否定义了__STL_MEMBER_TEMPLATES宏
// 代表编译器是否支持成员模板，尽管成员模板已经广泛支持
// 但这个宏是非标准的宏，编译器里没有定义
/*
    这样的做法是不准确的，正确做法是直接实用成员模板的特性，而不是通过宏来判断
*/
#include <iostream>

using namespace std;

int main()
{
    #ifdef __STL_MEMBER_TEMPLATES
        cout << "MEMBER_TEMPLATES" << endl;
    #else /* __STL_MEMBER_TEMPLATES */
        cout << "NO member_templates" << endl;
    #endif/* __STL_MEMBER_TEMPLATES */
    return 0;
}


// #include <iostream>

// class TestClass {
// public:
// #ifdef __STL_MEMBER_TEMPLATES
//     template<typename T>
//     void testFunction(T value) {
//         std::cout << "成员模板版本的 testFunction 被调用，值为: " << value << std::endl;
//     }
// #else
//     void testFunction(int value) {
//         std::cout << "非模板版本的 testFunction 被调用，值为: " << value << std::endl;
//     }
// #endif
// };

// int main() {
//     TestClass testObj;

// #ifdef __STL_MEMBER_TEMPLATES
//     testObj.testFunction(10); // 调用成员模板版本
//     testObj.testFunction(3.14); // 调用成员模板版本
// #else
//     testObj.testFunction(10); // 调用非模板版本，只能传入 int 类型
// #endif

//     return 0;
// }



// #include <iostream>

// template <typename T>
// class MyClass {
// public:
//     template <typename U>
//     void print(U value) {
//         std::cout << value << std::endl;
//     }
// };

// int main() {
//     MyClass<int> myObject;
//     myObject.print(42);      // 使用 int
//     myObject.print(3.14);    // 使用 double
//     myObject.print("Hello");  // 使用 const char*
//     return 0;
// }
