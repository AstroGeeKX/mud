#include <string>
#include <iostream>

class Buffer {
public:
    Buffer() noexcept {} // Use noexcept for constructors that won't throw exceptions
    ~Buffer() noexcept {} // Use noexcept for destructors that won't throw exceptions

    void append(const char* str, size_t size) noexcept {
        // Avoid manual loops, use string's own append which is optimized
        buf.append(str, size);
    }

    size_t size() const noexcept { // Use size_t for size and add const
        return buf.size();
    }

    const char* c_str() const noexcept { // Add const
        return buf.c_str();
    }

    void clear() noexcept { // Add noexcept
        buf.clear();
    }

    // 读取行之后有一个换行
    void getline() {
        std::string line;
        std::getline(std::cin, line);
        buf += line; // Use += for appending
        buf += '\n'; // Optionally add a newline at the end
    }

    void setBuf(const char* buf) noexcept {
        this->buf = buf; // Use assignment operator which is optimized
    }

private:
    std::string buf;
};

// Example usage
int main() {
    Buffer *buffer = new Buffer();
    buffer->setBuf("Hello");
    std::cout << buffer->c_str() << std::endl;
    buffer->append(" World", 6);
    std::cout << buffer->c_str() << std::endl;
    buffer->setBuf("new set");
    std::cout << buffer->c_str() << std::endl;

    return 0;
}

// buffer对象不是标准的字符串，需要提取（获取）里面的字符串再打印
// 用c_str()成员函数返回字符串