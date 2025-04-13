#include <map>
#include <iostream>

using namespace std;

template <typename T>
void printMap(T& m) {
    for (auto& n : m) {
        cout << "[";
        cout << n.first << " : " << n.second;
        cout << "] ";
    }
    cout << endl;
}

int main()
{
    // map 构造函数
    map<string, int> simap;
    simap["why"] = 1;
    simap["always"] = 2;
    simap["me"] = 3;   
    printMap(simap);
    
    // 插入操作
    pair<string, int> pr1("steve", 4);
    simap.insert(pr1);
    printMap(simap);
    
    // operator[]
    int number = simap["steve"];
    cout << "steve number = " << number << endl;

    // find 查找
    auto it = simap.find("why");
    if (it != simap.end()) {
        cout << "why found" << endl;
        simap.erase(it);  // erase
    }
    printMap(simap);
    return 0;
}

// 这个map对象simap是反常识的，键是string，值是int，根据键查找"steve"也得一字不落
