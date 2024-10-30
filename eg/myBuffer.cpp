#include <iostream>
#include <string>


class myBuffer
{
private: 
    std::string _buffer;
    // 利用string类对象来管理字符串buffer（缓存）
public:
    myBuffer() noexcept = default;
    myBuffer(const myBuffer &lhs) = default;
    ~myBuffer() noexcept = default;

    myBuffer &operator=(const char *buf)
    {
        _buffer = buf;
        return *this;
    }

    myBuffer &operator+=(const char *buf)
    {
        _buffer += buf;
        return *this;
    }

    inline size_t
    size() const noexcept { return _buffer.size(); }

    inline const char *
    c_str() const noexcept { return _buffer.c_str(); }

    inline void
    clear() noexcept { _buffer.clear(); }

    inline void 
    setBuffer(const char *buf) { this->_buffer = buf; }

    inline void 
    append(const char *buf, size_t size) noexcept { _buffer.append(buf, size); }

    inline void
    getline() { std::getline(std::cin, _buffer); }
};


void printBuf(const myBuffer &buf);

int main()
{
    myBuffer mybuffer;
    mybuffer = "helloBuffer";
    printBuf(mybuffer);
    mybuffer = "=buffer";
    printBuf(mybuffer);
    mybuffer += " +=mine。";
    printBuf(mybuffer);

    mybuffer.clear();
    std::cout << "clear()" << std::endl;
    printBuf(mybuffer);
    mybuffer.append("append(\"input a getline\")\ninput a getline", 64);
    printBuf(mybuffer);
    mybuffer.getline();
    printBuf(mybuffer);

    return 0;
}

void printBuf(const myBuffer &buf)
{
    std::cout << buf.c_str() << std::endl;
}