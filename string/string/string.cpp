#include "string.h" // 引入自定义的string类的头文件

namespace bit {
    // 构造函数：从C风格字符串构造一个自定义的string对象
    string::string(const char* str) {
        _size = strlen(str); // 获取字符串的长度
        _capacity = _size; // 初始容量等于字符串的长度
        _str = new char[_capacity + 1]; // 分配足够的内存，包括终止符
        strcpy(_str, str); // 复制字符串内容
    }

    // 拷贝构造函数：使用传入对象的字符串数据构造一个新对象
    string::string(const string& s) {
        string tmp(s._str); // 创建一个临时对象
        swap(tmp); // 交换临时对象和当前对象的数据
    }

    // 析构函数：释放动态分配的内存
    string::~string() {
        delete[] _str; // 删除字符数组
        _str = nullptr; // 将指针设为nullptr
        _size = 0; // 重置大小
        _capacity = 0; // 重置容量
    }

    // 赋值运算符：通过传值方式实现赋值，使用swap技术避免自我赋值问题
    string& string::operator=(string s) {
        swap(s); // 交换数据
        return *this; // 返回当前对象的引用
    }

    // 常量下标运算符：返回指定位置的字符
    const char& string::operator[](size_t pos) const {
        assert(pos <= _size); // 断言位置在有效范围内
        return _str[pos]; // 返回字符引用
    }

    // 非常量下标运算符：返回指定位置的字符，允许修改
    char& string::operator[](size_t pos) {
        assert(pos <= _size); // 断言位置在有效范围内
        return _str[pos]; // 返回字符引用
    }

    // 预留空间：增加字符串的容量
    void string::reserve(size_t n) {
        if (n > _capacity) {
            char* tmp = new char[n + 1]; // 分配新内存
            strcpy(tmp, _str); // 复制原字符串内容
            delete[] _str; // 释放旧内存
            _str = tmp; // 更新指针
            _capacity = n; // 更新容量
        }
    }

    // 添加字符到字符串末尾
    void string::push_back(char ch) {
        if (_size == _capacity) {
            size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2; // 如果容量为0则初始化为4，否则扩容为原来的两倍
            reserve(newcapacity); // 调整容量
        }
        _str[_size] = ch; // 添加字符
        _size++; // 更新大小
        _str[_size] = '\0'; // 添加终止符
    }

    // 交换两个string对象的数据
    void string::swap(string& s) {
        std::swap(_str, s._str); // 交换字符串指针
        std::swap(_size, s._size); // 交换大小
        std::swap(_capacity, s._capacity); // 交换容量
    }

    // 追加字符串
    void string::append(const char* str) {
        size_t len = strlen(str); // 获取追加字符串的长度
        if (_size + len > _capacity) {
            reserve(_size + len); // 调整容量以容纳新字符串
        }
        strcpy(_str + _size, str); // 追加字符串内容
        _size += len; // 更新大小
    }

    // 追加字符到字符串末尾
    string& string::operator+=(char ch) {
        push_back(ch); // 调用push_back函数
        return *this; // 返回当前对象的引用
    }

    // 追加字符串到字符串末尾
    string& string::operator+=(const char* str) {
        append(str); // 调用append函数
        return *this; // 返回当前对象的引用
    }

    // 在指定位置插入字符
    void string::insert(size_t pos, char ch) {
        assert(pos <= _size); // 断言位置在有效范围内
        if (_size == _capacity) {
            size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2; // 调整容量
            reserve(newcapacity); // 调整容量
        }
        size_t end = _size + 1; // 更新末尾位置
        while (end > pos) {
            _str[end] = _str[end - 1]; // 移动字符
            --end;
        }
        _str[pos] = ch; // 插入字符
        _size++; // 更新大小
    }

    // 在指定位置插入字符串
    void string::insert(size_t pos, const char* str) {
        assert(pos <= _size); // 断言位置在有效范围内
        size_t len = strlen(str); // 获取插入字符串的长度
        if (_size + len > _capacity) {
            reserve(_size + len); // 调整容量以容纳新字符串
        }
        int end = _size;
        while (end >= (int)pos) {
            _str[end + len] = _str[end]; // 移动字符
            --end;
        }
        strncpy(_str + pos, str, len); // 插入字符串内容
        _size += len; // 更新大小
    }

    // 删除从指定位置开始的若干字符
    void string::erase(size_t pos, size_t len) {
        assert(pos < _size); // 断言位置在有效范围内
        if (len == npos || pos + len >= _size) {
            _str[pos] = '\0'; // 如果删除长度超出范围，直接截断字符串
            _size = pos; // 更新大小
        }
        else {
            strcpy(_str + pos, _str + pos + len); // 删除指定长度的字符
            _size -= len; // 更新大小
        }
    }

    // 查找字符在字符串中的位置
    size_t string::find(char ch, size_t pos) {
        for (size_t i = pos; i < _size; i++) {
            if (_str[i] == ch) {
                return i; // 找到字符，返回其位置
            }
        }
        return npos; // 未找到字符，返回npos
    }

    // 查找字符串在字符串中的位置
    size_t string::find(const char* str, size_t pos) {
        const char* ptr = strstr(_str + pos, str); // 查找子字符串
        if (ptr == nullptr) {
            return npos; // 未找到子字符串，返回npos
        }
        else {
            return ptr - _str; // 找到子字符串，返回其位置
        }
    }

    // 提取子字符串
    string string::substr(size_t pos, size_t len) {
        assert(pos < _size); // 断言位置在有效范围内
        size_t end = pos + len;
        if (len == npos || pos + len >= _size) {
            len = _size; // 如果子字符串长度超出范围，调整长度
        }
        string str;
        str.reserve(end - pos); // 调整容量以容纳子字符串
        for (size_t i = pos; i < _size; i++) {
            str += _str[i]; // 复制子字符串内容
        }
        return str; // 返回子字符串
    }

    // 清空字符串内容
    void string::clear() {
        _size = 0; // 重置大小
        _str[0] = '\0'; // 置空字符串
    }

    // 重载输出运算符
    ostream& operator<<(ostream& out, const string& s) {
        for (auto ch : s) {
            out << ch; // 输出每个字符
        }
        return out; // 返回输出流
    }

    // 重载输入运算符
    istream& operator>>(istream& in, string& s) {
        s.clear(); // 清空当前字符串
        char buff[128];
        char ch = in.get();
        int i = 0;
        while (ch != ' ' && ch != '\n') { // 读取字符，直到遇到空格或换行符
            buff[i++] = ch;
            if (i == 127) { // 缓冲区满
                buff[i] = '\0';
                s += buff; // 追加缓冲区内容到字符串
                i = 0;
            }
            ch = in.get();
        }
        if (i > 0) { // 缓冲区有剩余内容
            buff[i] = '\0';
            s += buff; // 追加缓冲区内容到字符串
        }
        return in; // 返回输入流
    }
}
