#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;
namespace bit {
	class string
	{
	public:
		string(const string& s);

		string(const char* str = "");

		~string();

		string& operator=(string s);

		const char& operator[](size_t pos) const;

		char& operator[](size_t pos);

		void reserve(size_t n);

		void push_back(char ch);

		void swap(string& s);

		void append(const char* str);

		string& operator+=(char ch);

		string& operator+=(const char* str);

		void insert(size_t pos, char ch);

		void insert(size_t pos, const char* str);

		void erase(size_t pos, size_t len);
	private:
		size_t _size = 0;
		size_t _capacity = 0;
		char* _str = nullptr;
		const static size_t npos = -1;
	};
}
