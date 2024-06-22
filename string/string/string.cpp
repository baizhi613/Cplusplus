#include "string.h" // �����Զ����string���ͷ�ļ�

namespace bit {
    // ���캯������C����ַ�������һ���Զ����string����
    string::string(const char* str) {
        _size = strlen(str); // ��ȡ�ַ����ĳ���
        _capacity = _size; // ��ʼ���������ַ����ĳ���
        _str = new char[_capacity + 1]; // �����㹻���ڴ棬������ֹ��
        strcpy(_str, str); // �����ַ�������
    }

    // �������캯����ʹ�ô��������ַ������ݹ���һ���¶���
    string::string(const string& s) {
        string tmp(s._str); // ����һ����ʱ����
        swap(tmp); // ������ʱ����͵�ǰ���������
    }

    // �����������ͷŶ�̬������ڴ�
    string::~string() {
        delete[] _str; // ɾ���ַ�����
        _str = nullptr; // ��ָ����Ϊnullptr
        _size = 0; // ���ô�С
        _capacity = 0; // ��������
    }

    // ��ֵ�������ͨ����ֵ��ʽʵ�ָ�ֵ��ʹ��swap�����������Ҹ�ֵ����
    string& string::operator=(string s) {
        swap(s); // ��������
        return *this; // ���ص�ǰ���������
    }

    // �����±������������ָ��λ�õ��ַ�
    const char& string::operator[](size_t pos) const {
        assert(pos <= _size); // ����λ������Ч��Χ��
        return _str[pos]; // �����ַ�����
    }

    // �ǳ����±������������ָ��λ�õ��ַ��������޸�
    char& string::operator[](size_t pos) {
        assert(pos <= _size); // ����λ������Ч��Χ��
        return _str[pos]; // �����ַ�����
    }

    // Ԥ���ռ䣺�����ַ���������
    void string::reserve(size_t n) {
        if (n > _capacity) {
            char* tmp = new char[n + 1]; // �������ڴ�
            strcpy(tmp, _str); // ����ԭ�ַ�������
            delete[] _str; // �ͷž��ڴ�
            _str = tmp; // ����ָ��
            _capacity = n; // ��������
        }
    }

    // ����ַ����ַ���ĩβ
    void string::push_back(char ch) {
        if (_size == _capacity) {
            size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2; // �������Ϊ0���ʼ��Ϊ4����������Ϊԭ��������
            reserve(newcapacity); // ��������
        }
        _str[_size] = ch; // ����ַ�
        _size++; // ���´�С
        _str[_size] = '\0'; // �����ֹ��
    }

    // ��������string���������
    void string::swap(string& s) {
        std::swap(_str, s._str); // �����ַ���ָ��
        std::swap(_size, s._size); // ������С
        std::swap(_capacity, s._capacity); // ��������
    }

    // ׷���ַ���
    void string::append(const char* str) {
        size_t len = strlen(str); // ��ȡ׷���ַ����ĳ���
        if (_size + len > _capacity) {
            reserve(_size + len); // �����������������ַ���
        }
        strcpy(_str + _size, str); // ׷���ַ�������
        _size += len; // ���´�С
    }

    // ׷���ַ����ַ���ĩβ
    string& string::operator+=(char ch) {
        push_back(ch); // ����push_back����
        return *this; // ���ص�ǰ���������
    }

    // ׷���ַ������ַ���ĩβ
    string& string::operator+=(const char* str) {
        append(str); // ����append����
        return *this; // ���ص�ǰ���������
    }

    // ��ָ��λ�ò����ַ�
    void string::insert(size_t pos, char ch) {
        assert(pos <= _size); // ����λ������Ч��Χ��
        if (_size == _capacity) {
            size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2; // ��������
            reserve(newcapacity); // ��������
        }
        size_t end = _size + 1; // ����ĩβλ��
        while (end > pos) {
            _str[end] = _str[end - 1]; // �ƶ��ַ�
            --end;
        }
        _str[pos] = ch; // �����ַ�
        _size++; // ���´�С
    }

    // ��ָ��λ�ò����ַ���
    void string::insert(size_t pos, const char* str) {
        assert(pos <= _size); // ����λ������Ч��Χ��
        size_t len = strlen(str); // ��ȡ�����ַ����ĳ���
        if (_size + len > _capacity) {
            reserve(_size + len); // �����������������ַ���
        }
        int end = _size;
        while (end >= (int)pos) {
            _str[end + len] = _str[end]; // �ƶ��ַ�
            --end;
        }
        strncpy(_str + pos, str, len); // �����ַ�������
        _size += len; // ���´�С
    }

    // ɾ����ָ��λ�ÿ�ʼ�������ַ�
    void string::erase(size_t pos, size_t len) {
        assert(pos < _size); // ����λ������Ч��Χ��
        if (len == npos || pos + len >= _size) {
            _str[pos] = '\0'; // ���ɾ�����ȳ�����Χ��ֱ�ӽض��ַ���
            _size = pos; // ���´�С
        }
        else {
            strcpy(_str + pos, _str + pos + len); // ɾ��ָ�����ȵ��ַ�
            _size -= len; // ���´�С
        }
    }

    // �����ַ����ַ����е�λ��
    size_t string::find(char ch, size_t pos) {
        for (size_t i = pos; i < _size; i++) {
            if (_str[i] == ch) {
                return i; // �ҵ��ַ���������λ��
            }
        }
        return npos; // δ�ҵ��ַ�������npos
    }

    // �����ַ������ַ����е�λ��
    size_t string::find(const char* str, size_t pos) {
        const char* ptr = strstr(_str + pos, str); // �������ַ���
        if (ptr == nullptr) {
            return npos; // δ�ҵ����ַ���������npos
        }
        else {
            return ptr - _str; // �ҵ����ַ�����������λ��
        }
    }

    // ��ȡ���ַ���
    string string::substr(size_t pos, size_t len) {
        assert(pos < _size); // ����λ������Ч��Χ��
        size_t end = pos + len;
        if (len == npos || pos + len >= _size) {
            len = _size; // ������ַ������ȳ�����Χ����������
        }
        string str;
        str.reserve(end - pos); // �����������������ַ���
        for (size_t i = pos; i < _size; i++) {
            str += _str[i]; // �������ַ�������
        }
        return str; // �������ַ���
    }

    // ����ַ�������
    void string::clear() {
        _size = 0; // ���ô�С
        _str[0] = '\0'; // �ÿ��ַ���
    }

    // ������������
    ostream& operator<<(ostream& out, const string& s) {
        for (auto ch : s) {
            out << ch; // ���ÿ���ַ�
        }
        return out; // ���������
    }

    // �������������
    istream& operator>>(istream& in, string& s) {
        s.clear(); // ��յ�ǰ�ַ���
        char buff[128];
        char ch = in.get();
        int i = 0;
        while (ch != ' ' && ch != '\n') { // ��ȡ�ַ���ֱ�������ո���з�
            buff[i++] = ch;
            if (i == 127) { // ��������
                buff[i] = '\0';
                s += buff; // ׷�ӻ��������ݵ��ַ���
                i = 0;
            }
            ch = in.get();
        }
        if (i > 0) { // ��������ʣ������
            buff[i] = '\0';
            s += buff; // ׷�ӻ��������ݵ��ַ���
        }
        return in; // ����������
    }
}
