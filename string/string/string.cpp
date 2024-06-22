#include"string.h"
namespace bit
{
	string::string(const char* str)
	{
		_size = strlen(str);
		_capacity = _size;
		_str = new char[_capacity + 1];
		strcpy(_str, str);
	}
	string::string(const string& s)
	{
		string tmp(s._str);
		swap(tmp);
	}
	string::~string()
	{
		delete[] _str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}
	string& string::operator=(string s)
	{
		swap(s);
		return *this;
	}
	const char& string::operator[](size_t pos) const
	{
		assert(pos <= _size);
		return _str[pos];
	}
	char& string::operator[](size_t pos)
	{
		assert(pos <= _size);
		return _str[pos];
	}
	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}
	void string::push_back(char ch)
	{
		if (_size == _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
			reserve(newcapacity);
		}
		_str[_size] = ch;
		_size++;
		_str[_size] = '\0';
	}
	void string::swap(string& s)
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}
	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		strcpy(_str + _size, str);
		_size += len;
	}
	string& string::operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}
	string& string::operator+=(const char* str)
	{
		append(str);
		return *this;
	}
	void string::insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		if (_size == _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
			reserve(newcapacity);
		}
		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			--end;
		}
		_str[pos] = ch;
		_size++;
	}
	void string::insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		int end = _size;
		while (end >= (int)pos)
		{
			_str[end + len] = _str[end];
			--end;
		}
		strncpy(_str + pos, str, len);
		_size += len;
	}
	void string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (len == npos || pos + len >= _size)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			strcpy(_str + pos, _str + pos + len);
			_size -= len;
		}
	}
	size_t string::find(char ch, size_t pos)
	{
		for (size_t i = pos; i < _size; i++)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}
		return npos;
	}
	size_t string::find(const char* str, size_t pos)
	{
		const char* ptr = strstr(_str + pos, str);
		if (ptr == nullptr)
		{
			return npos;
		}
		else
		{
			return ptr - _str;
		}
	}
	string string::substr(size_t pos, size_t len)
	{
		assert(pos < _size);
		size_t end = pos + len;
		if (len == npos || pos + len >= _size)
		{
			len = _size;
		}
		string str;
		str.reserve(end - pos);
		for (size_t i = pos; i < _size; i++)
		{
			str += _str[i];
		}
		return str;
	}
	void string::clear()
	{
		_size = 0;
		_str[0] = '\0';
	}
	ostream& operator<<(ostream& out, const string& s)
	{
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}
	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char buff[128];
		char ch = in.get();
		int i = 0;
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i > 0)
		{
			buff[i] = '\0';
			s += buff;
		}
		return in;
	}
}
