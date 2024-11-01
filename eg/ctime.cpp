#include <iostream>
#include <ctime>

using namespace std;

void test()
{
   // 基于当前系统的当前日期/时间
   time_t f_now = time(0); // 获取70秒

   cout << "1970 到目前经过秒数:" << f_now << endl;

   tm *ltm = localtime(&f_now); // 将70秒转化为tm结构体

   // 输出 tm 结构的各个组成部分
   cout << "年: " << 1900 + ltm->tm_year << endl;
   cout << "月: " << 1 + ltm->tm_mon << endl;
   cout << "日: " << ltm->tm_mday << endl;
   cout << "时间: " << ltm->tm_hour << ":";
   cout << ltm->tm_min << ":";
   cout << ltm->tm_sec << endl;
}

int main()
{
   /* 除了now，其他的时间变量都自带换行 */
   time_t now = time(0); // 获取距离1970年过了多少秒
   char *dt = ctime(&now); // 将70秒转化为可读的字符串时间
   cout << "距离1970年1月1日有: " << now << "秒" << endl;
   cout << "使用ctime转化为可读的时间: " << dt;

   tm *my_tm = localtime(&now); // 将70秒转化为tm结构（里面更精细化获取时间
   cout << "my_tm结构体对象里面的tm_hour成员是: " << my_tm->tm_hour << endl;
   cout << "my_tm结构体对象里面的tm_min成员是: " << my_tm->tm_min << endl;

   test();
}

// char *ctime(const time_t *time); 是char*
// struct tm *localtime(const time_t *time); 是tm*