#include <string>

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