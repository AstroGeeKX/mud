#include <iostream>
#include <string>
// #include <cctype> // for std::isspace

using namespace std;

// 原函数
// 利用find()和substr()函数找到空格位置，然后三段截取内容，参数引用传递修改值
// 重载1：find(查的内容)    重载2：find(查的内容, 开始位置)
// 重载1：substr(开始位置) 一直找到字符串末尾    重载2：substr(开始位置， 字节长度)
// 开始查找之前，首先截掉结尾的\r\n，不然会连带在`版本号`里
bool parseHttpRequestInfo(std::string httpRequest, std::string& method, std::string& uri, std::string& version){
    int recvSize = httpRequest.size();
    
    //查找请求头
    std::string strRequestHead = httpRequest;
    int pos = httpRequest.find("\r\n");
    // strRequestHead = httpRequest.substr(0, pos);

    //解析请求类型
    method = strRequestHead.substr(0, strRequestHead.find(" "));
    //解析uri
    uri = strRequestHead.substr(strRequestHead.find(" ") + 1, strRequestHead.find(" ", strRequestHead.find(" ") + 1) - strRequestHead.find(" "));
    //解析http版本
    version = strRequestHead.substr(strRequestHead.rfind(" "), strRequestHead.size() - strRequestHead.rfind(" "));
    return true;
}

// 天工AI
// 判断空字符串的情况 -> 截掉\r\n -> 
bool parseHttpRequestInfo2(const std::string& httpRequest, std::string& method, std::string& uri, std::string& version) {
    // 处理空字符串情况
    if (httpRequest.empty()) {
        return false;
    }
    int recvSize = httpRequest.size();
    // 查找请求头
    std::string strRequestHead;
    int pos = httpRequest.find("\r\n");
    if (pos == std::string::npos) {
        // 如果没有找到\r\n，直接处理整个字符串作为请求头
        strRequestHead = httpRequest;
    } else {
        strRequestHead = httpRequest.substr(0, pos);
    }

    size_t start;
    size_t end;
    // method解析
    start = 0;
    end = strRequestHead.find(' ', start);
    method = strRequestHead.substr(start, end - start);
    // 解析uri
    // find_first_not_of(' ') 查找不匹配字符的第一个位置，用来跨过多个空格
    // start = strRequestHead.find_first_not_of(' ', end);
    start = end + 1;
    end = strRequestHead.find(' ', start);
    uri = strRequestHead.substr(start, end - start);
    // 解析version
    // start = strRequestHead.find_first_not_of(' ', end);
    start = end + 1;
    version = strRequestHead.substr(start); // version后面已经没有空格了，直接截取到字符串尾部
    return true;
}

// chat GPT
// start部分，利用find_first_not_of()函数，跨过多个空格的不规范情况
bool parseHttpRequestInfo3(const std::string& httpRequest, std::string& method, std::string& uri, std::string& version) {
    if (httpRequest.empty()) {
        return false;
    }

    // 查找请求行的结束位置（第一个 \r\n）
    int pos = httpRequest.find("\r\n");
    if (pos == std::string::npos) {
        return false; // 如果没有找到 \r\n，则请求行格式有问题
    }
    std::string strRequestHead = httpRequest.substr(0, pos); // 抹去\r\n
    // 去除请求行两端的空白字符
    size_t start = strRequestHead.find_first_not_of(" \t\r\n");
    size_t end = strRequestHead.find_last_not_of(" \t\r\n");
    if (start == std::string::npos || end == std::string::npos || start > end) {
        return false; // 请求行格式不对
    }
    strRequestHead = strRequestHead.substr(start, end - start + 1); // 抹去左右两端的空白字符

    // 解析 method    开头部分只需要算end
    size_t method_end = strRequestHead.find(' ');
    if (method_end == std::string::npos) {
        return false; // 请求行格式错误，method后面一直没有空格
    }
    method = strRequestHead.substr(0, method_end - 0);

    // 解析 URI    中间部分只需要算start和end
    size_t uri_start = strRequestHead.find_first_not_of(' ', method_end);
    size_t uri_end = strRequestHead.find(' ', uri_start);
    if (uri_end == std::string::npos) {
        return false; // 请求行格式错误，uri后面一直没有空格
    }
    uri = strRequestHead.substr(uri_start, uri_end - uri_start);

    // 解析 version    结尾部分只需要算start
    size_t version_start = strRequestHead.find_first_not_of(' ', uri_end);
    version = strRequestHead.substr(version_start);
    
    // 进一步验证 version 格式 (HTTP/1.1)
    if (version.find("HTTP/") != 0) {
        return false; // version 应该以 "HTTP/" 开头
    }

    return true;
}

int main()
{
    string requestHead = "GET /index.html HTTP/1.1\r\n******";
    string subStr, method, uri, version; // 声明三个参数的对象

    // 不能截断\r\n  不能忽略多余的空格  不能去除左右两端空白字符  
    // cout << parseHttpRequestInfo(requestHead, method, uri, version) << endl;
    // 不能忽略多余空格  不能去除左右两端空白字符
    // cout << parseHttpRequestInfo2(requestHead, method, uri, version) << endl;
    // 较为完善  还能判断基本的格式问题
    cout << parseHttpRequestInfo3(requestHead, method, uri, version) << endl;
    cout << "`" << method << "`" << endl;
    cout << "`" << uri << "`" << endl;
    cout << "`" << version << "`" << endl;

    return 0;
}
