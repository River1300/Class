/* �þ�Դ� C++ - <4 - 5. ���� ����� String Ŭ����> https://modoocode.com/198 */

// ���� ����� ���ڿ� Ŭ����(MyString)

/*
���ڿ� Ŭ������ ������

���� C ������ ���ڿ��� ��Ÿ���� ���� �� ���� ���ڿ�(Null-terstd::minating string)�̶�� ������ �����ؼ� 
���ڿ� ���� NULL ���ڸ� �ٿ� ���ڿ��� ��Ÿ���� ����� ����Ͽ���.

������ C ��� ���ڿ��� ����ϴµ����� ���ŷο��� ���Ҵµ�, 
���� �� ������� ���ڿ��� ũ�⸦ �ٲ۴ٴ���, ���ڿ� �ڿ� �ٸ� ���ڿ��� ���δٴ��� ���� �۾����� ����� ���α׷��� ���忡���� ������ �� �ۿ� ����. 

��� C++ ������ ǥ�� ���̺귯���� string Ŭ������ �����ϰ� �ִ�. (������ <string> ��������� include �ϸ� ����� �� �ִ�.)

�ϴ� ������ �����ؼ� �츮�� ���� MyString Ŭ������ ��� ������ ������ �ʿ����� �����غ���. 
�Ƹ�, ��ǥ������ �Ʒ� �� ���� �����͵��� �ʿ��ϴٰ� �� �� �ִ�.

1. ���ڿ� �����Ͱ� ����� ������ ����Ű�� ������
2. ���ڿ� �������� ����

�� ��ü�� ���ڿ� �����͸� ���� �����ϴ� ���� �ƴ϶�, �� ����� ������ ����Ű�� �����͸� �����ϳİ� ���� �� �ִ�. 
�̷��� �ϴ� ������ ���߿� ���ڿ� �������� ũ�Ⱑ �ٲ� ��, 
����� ������ ����Ű�� ������� �ϸ� �� �޸𸮸� ������ �ڿ�, �ٽ� �Ҵ��� �� ������ ���� �����ϸ� �׷� �� ���� �����̴�.

����, ���ڿ� �������� ���̸� �����ϴ� ������ ���ڿ� ���̸� ����� ���� ������ ������, �� �� ���� ��� ���̸� ���ϴ� ���� ����� ���ʿ��� ���̱� �����̴�. 
���� ���̸� �� �� ���س��� ���̰� �ٲ� �� ���� �������� �ʴ� ����� ������ ���̴�.
*/

/*
class MyString 
{
  char* string_content;  // ���ڿ� �����͸� ����Ű�� ������
  int string_length;     // ���ڿ� ����
};

�ϴ� �� �� ������ private ���� �����Ͽ���. 
�ֳ��ϸ� �츮�� �ٸ� ���α׷��Ӱ� MyString �� �̿��ϸ鼭 �߿��� �����鿡 �Ժη� �����ϱ⸦ ��ġ �ʴ´�.
���α׷��Ӱ� �Ǽ��� string_length �� �����ϴ� ����� ��ٰ� ��ĩ �߸��ϱ�� �ϸ� ��ڳ�. 
�׷��⿡ �츮�� �ٸ� ���α׷��Ӱ� ���� MyString �� string_length �� string_content �� 
���� ������ �ʰ� �׵��� ���ϴ� ��� �۾����� ������ �� �ֵ��� ����� '�Լ�' ���� �����ؾ� �� ���̴�.

�׷� �����ڵ��� ���.

MyString(char c);
MyString(const char* str);
MyString(const MyString& str);

���� ���� �����ڵ��� ����� ����, ��� ������� ���ڿ��� ������ �������� ���� ���� �����غ���. 
���� �״�� string_content �� C ������ ���ڿ� (�� ���� ���ڿ�) �� �����ϴ� ���� ������, 
�ƴϸ� �ʿ���� �������� ���� (�� �� �������� �� ����) ���� '����' �� �ش��ϴ� �κи��� ������.

C ������ ���ڿ��� �״�� �����Ѵٸ�, ���ڿ��� �� �κ��� ���� üũ�� �� �ִٴ� ������ ������ �� ������ �츮�� string_length ��� ������ ���� ���������ν� �ذ��� �� �ְ� �Ǿ���. 
����, MyString Ŭ���������� ���� ���ڿ� �ش��ϴ� ���븸�� string_content �� �����ϵ��� �Ѵ�.

MyString::MyString(char c) 
{
  string_content = new char[1];
  string_content[0] = c;
  string_length = 1;
}

MyString::MyString(const char* str) 
{
  string_length = strlen(str);
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}

MyString::MyString(const MyString& str) 
{
  string_length = str.string_length;
  for (int i = 0; i != string_length; i++)
    string_content[i] = str.string_content[i];
}

MyString::~MyString() { delete[] string_content; }

���� ���� 3 ���� �����ڵ��� �����Ͽ���, string_content �� ���� �Ҵ����� ó���Ͽ��� ������ �ݵ�� �Ҹ��ڿ��� �̸� ���������ϴ� ���� ó������߸� �Ѵ�.
�̰��� Ŭ������ ū �����̶�� �� �� �ִµ�, C ���� ����ü���� ������ ���ڿ��� �����Ͽ��ٸ� �̸� ������ ���� �ϴ� �͵� ó������� �߾��� �����̴�. 
�� �״��, Ŭ������ ����ϴ� ����� �ȿ��� ��� ���ư����� ���� �Ű澲�� �ʰ� ����� �� �ְ� �Ǵ� ���̴�.

�׷� ���� �ſ� ���� ���ڿ��� ���̸� ���ϴ� �Լ��� ���� �� �ְ� �Ǿ���. 
�ܼ��� string_length �� ������ �ָ� �Ǵ� ��. 
����� ���� ������ ������ �ٲ��� �ʴ´ٸ� �� ��� �Լ��� �������ִ� ���� ����.

length �Լ� ���� string_length �� ���� �б⸸ �ϹǷ� ��� �Լ��� �����Ͽ���.

int MyString::length() const { return string_length; }

�ٸ� �̷��� ������� ���ڿ��� ���̸� ���Ѵٸ�, ���ڿ� ���۽ÿ� string_length �� ���� �ùٸ� ������ �����ؾ߸� �Ѵ�. 
���� ��, �� ���ڿ��� ���� ���ؼ� ���ο� ���ڿ��� ���� �� ���ο� ���ڿ��� string_length �� �� ���ڿ��� string_length �� ���� �� ���̴�. 
���������� �κ� ���ڿ��� �����ϰų�, ���� �ϳ��� ����� �� ��� �۾��� �� �� string_length ���� ��Ȯ�ϰ� �����ؾ߸� �Ѵ�.

void MyString::print() 
{
  for (int i = 0; i != string_length; i++) 
  {
    std::cout << string_content[i];
  }
}

�׸��� ����������, MyString Ŭ������ ������ ���� ���ؼ�, ���ڿ��� ����ϴ� �Լ� print �� println �� �������. 
(���� �������� ������ �ϴ��� ���ϴ����� ����) ���������� print �� println ��� ���ڿ��� �б⸸ �ϹǷ� ��� �Լ��� �������.
*/

/*
#include <iostream>

// string.h �� strlen ������ include �ߴµ�, ��� ���� strlen�� ���� �Լ��� ���� �ᵵ �ȴ�.
#include <string.h>

class MyString 
{
  char* string_content;  // ���ڿ� �����͸� ����Ű�� ������
  int string_length;     // ���ڿ� ����

 public:
  // ���� �ϳ��� ����
  MyString(char c);

  // ���ڿ��� ���� ����
  MyString(const char* str);

  // ���� ������
  MyString(const MyString& str);

  ~MyString();

  int length() const;

  void print() const;
  void println() const;
};

MyString::MyString(char c) 
{
  string_content = new char[1];
  string_content[0] = c;
}

MyString::MyString(const char* str) 
{
  string_length = strlen(str);
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) {
    string_content[i] = str[i];
  }
}

MyString::MyString(const MyString& str) 
{
  string_length = str.string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++)
    string_content[i] = str.string_content[i];
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void MyString::print() const 
{
  for (int i = 0; i != string_length; i++) 
  {
    std::cout << string_content[i];
  }
}

void MyString::println() const 
{
  for (int i = 0; i != string_length; i++) 
  {
    std::cout << string_content[i];
  }

  std::cout << std::endl;
}

int main() 
{
  MyString str1("hello world!");
  MyString str2(str1);

  str1.println();
  str2.println();
}

���������� ������ �Ͽ��ٸ�

hello world!
hello world!

�� ���� �� ������� �� �� �ִ�.
*/

/*
assign �Լ�

assign �Լ��� '�����ϴ�' ��� ���� ���� �Լ���, �츮�� ���� �����ϴ� '=' �� ������ ������ �ϰ� �ȴ�. 
���� �� MyString ���� str ����

str.assign("abc");

�� �ϰ� �ȴٸ� str ���� ���� �־��� ���ڿ��� �������� abc �� ���� �ȴ�. 
�׷��ٸ� ������ ���� �� ���� assign �Լ��� �غ��� �� �ִ�.

MyString& assign(const MyString& str);
MyString& assign(const char* str);

���� �� assign �Լ����� ���� ��ü�� �ſ� �����ϰ� �� �� �ִ�.

MyString& MyString::assign(const MyString& str) 
{
  if (str.string_length > string_length) 
  {
    // �׷��� �ٽ� �Ҵ��� ����߸� �Ѵ�.
    delete[] string_content;

    string_content = new char[str.string_length];
  }

  for (int i = 0; i != str.string_length; i++) 
  {
    string_content[i] = str.string_content[i];
  }

  // �׸��� ���� str.string_length + 1 ~ string_length �κ��� �ʱ�ȭ
  // ��ų �ʿ�� ����. �ֳ��ϸ� �ű� ������ �о������ �ʱ� �����̴�.

  string_length = str.string_length;

  return *this;
}

MyString& MyString::assign(const char* str) 
{
  int str_length = strlen(str);

  if (str_length > string_length) 
  {
    // �׷��� �ٽ� �Ҵ��� ����߸� �Ѵ�.
    delete[] string_content;

    string_content = new char[str_length];
  }

  for (int i = 0; i != str_length; i++) 
  {
    string_content[i] = str[i];
  }

  string_length = str_length;

  return *this;
}
*/

/*
string �� ũ�Ⱑ ������ ���� �Ҵ��� �����ϴµ� ū �ð��� �ʿ����� �ʰ�����, 
MyString Ŭ������ � ũ���� ���ڿ��� ���ؼ��� ���� ������ �����־�߸� �ϱ� ������ �� ó�� ���ڷ� �Է¹޴� ���ڿ��� ũ�Ⱑ, 
���� ���ڿ��� ũ�� ���� �۴ٸ� ���� ���� �Ҵ��� �� �ʿ䰡 ���� �ȴ�.

���� �� ��쿡�� �׳� �״�� �����ϰ� �ȴ�. 
������, ���ڷ� �Է¹޴� ���ڿ��� ũ�Ⱑ �� ũ�ٸ�, ��������� ������ �������� �Ҵ�� �޸� �ٷ� �ڿ� �޸𸮸� �߰��ϴ� ����� �����Ƿ�, ���� �����Ҵ��� ����߸� �Ѵ�.

�׷��� �̷��� ������� �����ϴµ����� �ణ�� ������ �ִ�. 
���� ��� ������ ���� ��Ȳ�� ��������.

MyString str1("very very very long string");
str1.assign("short string");
str1.assign("very long string");

�� ó���� str1 �� ���� �� ���ڿ��� �Ҵ��Ͽ���. 
���� �� �� ���ڿ��� ���̰� 1000 ����Ʈ ��� ��������. 
�׷� ������ str1 �� �ٽ� ª�� ���ڿ��� assign �Ͽ��ٰ� �����ϸ�

assign �Լ��� ������ �̹� �� ���ڿ��� �Ҵ� �Ǿ� ���� ���, 
�� ª�� ���ڿ��� assign �Ѵٸ� Ư���� ���� �Ҵ��� ������ �ʿ� ���� �׳� string_length �� ���̰� �׳� ª�� ���ڿ��� ���� ����� �ȴ�.

�׷��� ������ �ٽ� str1 �� �� ���ڿ��� assign �ÿ� �߻��ϰ� �ȴ�.
(�̹��� �� ���ڿ��� ������ ���� �� ���ڿ� ���ٴ� �ణ ª�ٰ� ����) 
��� str1 �� �̹� 1000 ����Ʈ�� ���ϴ� ������ �Ҵ�Ǿ� �ִµ��� �ұ��ϰ� ���� ª�� ���ڿ��� �ֱ� ������ 
���Ӱ� �� ���ڿ��� assign �ÿ� �̹� 1000 ����Ʈ�� �Ҵ�Ǿ� �ִٴ� ����� �� �� ���� �ȴ�.

����, assign �Լ��� ���ڿ��� ª�� ���ڿ��� ���� ���� ũ�⿡ �������� �Ҵ�Ǿ� �ִٰ� �����Ͽ� �޸𸮸� �����ϰ� �ٽ� ���� ���� �޸𸮸� �Ҵ��ϴ� 
�ſ� ��ȿ�� ���� �۾��� �ϰ� �ȴ�. 
*/

/*
���� �̷��� ��ȿ�� ���� ���� ���ؼ��� �󸶳� ���� ������ �Ҵ�Ǿ� �ִ��� �� �� �ִ� ������ ���� �����ϴ� ���� ���� ���̶� �����ȴ�. 
�̸� ���� memory_capacity ���, ���� �Ҵ�� �޸� ������ ũ�⸦ ��Ÿ���� ���ο� ������ �߰��Ѵ�.

MyString& MyString::assign(const MyString& str) 
{
  if (str.string_length > memory_capacity) 
  {
    // �׷��� �ٽ� �Ҵ��� ����߸� �Ѵ�.
    delete[] string_content;

    string_content = new char[str.string_length];
    memory_capacity = str.string_length;
  }

  for (int i = 0; i != str.string_length; i++) 
  {
    string_content[i] = str.string_content[i];
  }

  // �׸��� ���� str.string_length + 1 ~ string_length �κ��� �ʱ�ȭ
  // ��ų �ʿ�� ����. �ֳ��ϸ� �ű� ������ �о������ �ʱ� �����̴�.

  string_length = str.string_length;

  return *this;
}

MyString& MyString::assign(const char* str) 
{
  int str_length = strlen(str);

  if (str_length > memory_capacity) 
  {
    // �׷��� �ٽ� �Ҵ��� ����߸� �Ѵ�.
    delete[] string_content;

    string_content = new char[str_length];
    memory_capacity = str_length;
  }

  for (int i = 0; i != str_length; i++) 
  {
    string_content[i] = str[i];
  }

  string_length = str_length;

  return *this;
}
*/

/*
�̷��� �ϰ� �ȴٸ�, �ռ� �׸����� ��Ÿ���� ��Ȳ�� ���� ������ ������ �� �ְ� �ȴ�. 
�̷��� capacity �� ���������ν� �������� ���ο� �Լ����� �߰��� �� �ְ� �Ǿ���. 
���� ��, �Ҵ��� ���ڿ��� ũ�⸦ �̸� ������ ���� reserve �Լ��� ���� ���ڿ��� �Ҵ�� �޸� ũ�⸦ ��Ÿ���� capacity �Լ��� ���� �� �ִ�. 

int MyString::capacity() { return memory_capacity; }

void MyString::reserve(int size) 
{
  if (size > memory_capacity) 
  {
    char *prev_string_content = string_content;

    string_content = new char[size];
    memory_capacity = size;

    for (int i = 0; i != string_length; i++)
      string_content[i] = prev_string_content[i];

    delete[] prev_string_content;
  }

  // ���� �����Ϸ��� size �� ���� capacity ���� �۴ٸ�
  // �ƹ��͵� ���ص� �ȴ�.
}
*/

/*
����� reserve �Լ��� ���, ���� �Ҵ��Ϸ��� ũ�Ⱑ ������ �Ҵ�� ũ�⺸�� �۴ٸ� ���� �Ҵ��� �ʿ䰡 ���� �ȴ�. 

#include <iostream>
#include <string.h>

class MyString 
{
  char* string_content;  // ���ڿ� �����͸� ����Ű�� ������
  int string_length;     // ���ڿ� ����
  int memory_capacity;   // ���� �Ҵ�� �뷮

 public:
  // ���� �ϳ��� ����
  MyString(char c);

  // ���ڿ��� ���� ����
  MyString(const char* str);

  // ���� ������
  MyString(const MyString& str);

  ~MyString();

  int length() const;
  int capacity() const;
  void reserve(int size);

  void print() const;
  void println() const;

  MyString& assign(const MyString& str);
  MyString& assign(const char* str);
};

MyString::MyString(char c) 
{
  string_content = new char[1];
  string_content[0] = c;
  memory_capacity = 1;
  string_length = 1;
}

MyString::MyString(const char* str) 
{
  string_length = strlen(str);
  memory_capacity = string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) 
  {
    string_content[i] = str[i];
  }
}

MyString::MyString(const MyString& str) 
{
  string_length = str.string_length;
  memory_capacity = str.string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) {
    string_content[i] = str.string_content[i];
  }
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void MyString::print() const 
{
  for (int i = 0; i != string_length; i++) 
  {
    std::cout << string_content[i];
  }
}

void MyString::println() const 
{
  for (int i = 0; i != string_length; i++) 
  {
    std::cout << string_content[i];
  }

  std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) 
{
  if (str.string_length > memory_capacity) {
    // �׷��� �ٽ� �Ҵ��� ����߸� �Ѵ�.
    delete[] string_content;

    string_content = new char[str.string_length];
    memory_capacity = str.string_length;
  }
  for (int i = 0; i != str.string_length; i++) {
    string_content[i] = str.string_content[i];
  }

  // �׸��� ���� str.string_length + 1 ~ string_length �κ��� �ʱ�ȭ
  // ��ų �ʿ�� ����. �ֳ��ϸ� �ű� ������ �о������ �ʱ� �����̴�.

  string_length = str.string_length;

  return *this;
}

MyString& MyString::assign(const char* str) 
{
  int str_length = strlen(str);
  if (str_length > memory_capacity) {
    // �׷��� �ٽ� �Ҵ��� ����߸� �Ѵ�.
    delete[] string_content;

    string_content = new char[str_length];
    memory_capacity = str_length;
  }
  for (int i = 0; i != str_length; i++) {
    string_content[i] = str[i];
  }

  string_length = str_length;

  return *this;
}

int MyString::capacity() const { return memory_capacity; }

void MyString::reserve(int size) 
{
  if (size > memory_capacity) 
  {
    char* prev_string_content = string_content;

    string_content = new char[size];
    memory_capacity = size;

    for (int i = 0; i != string_length; i++)
      string_content[i] = prev_string_content[i];

    delete[] prev_string_content;
  }

  // ���� �����Ϸ��� size �� ���� capacity ���� �۴ٸ�
  // �ƹ��͵� ���ص� �ȴ�.
}
int main() 
{
  MyString str1("very very very long string");
  str1.reserve(30);

  std::cout << "Capacity : " << str1.capacity() << std::endl;
  std::cout << "String length : " << str1.length() << std::endl;
  str1.println();
}

���������� ������ �Ͽ��ٸ�

Capacity : 30
String length : 26
very very very long string

�� ���� �� ������ �� �� �ִ�.

���������� �߰��� �Լ��� ������ ��ġ�� ���ڸ� �����ϴ� �Լ���, ���� C ���� [] �� �����Ǿ��� ���̴�. 
C ���ڿ��� ��� ������ �迭�� ������ ����� ��ġ�� ���� ���ڸ� �䱸�Ͽ��� �̸� ó���� �� �ۿ� �����µ� 
C++ �� ��� Ư�� ��ġ�� ���ڸ� ��� ���� �Լ��� ���� �ùٸ��� �ʴ� ��ġ�� ���� ������ ó���� �� �հ� �Ǿ���.

char MyString::at(int i) const 
{
  if (i >= string_length || i < 0)
    return NULL;
  else
    return string_content[i];
}

���� ���� i �� ���Ǵ� ������ �ʰ��Ѵٸ� NULL �� �����ϵ��� �Ѵ�.

�� �̰����� �ؼ�, �츮�� ���� ������ ���ڿ� Ŭ���� MyString �� �⺻���� �Լ����� ��� �����Ͽ��ٰ� �� �� �ִ�.

���� c Ȥ�� C ���� ���ڿ� str ���� ������ �� �ִ� �����ڿ� ���� ������
���ڿ��� ���̸� �����ϴ� �Լ�(length)
���ڿ� ���� �Լ�(assign)
���ڿ� �޸� �Ҵ� �Լ�(reserve) �� ���� �Ҵ�� ũ�⸦ �˾ƿ��� �Լ�(capacity)
Ư�� ��ġ�� ���ڸ� �����ϴ� �Լ�(at)

���� MyString �� ����ϴ� �ٸ� ���α׷��ӵ��� �� �ּ����� �������̽��� �̿��ؼ�, �������� ���ڿ��� ������ ��� �۾��� ������ �� �ְ� �ȴ�. 
������ ������ �������� MyString �Լ��� �θ� ���ϰ� ����ϰ� �ʹٸ�, �� ���� ����� ������ �� �־�� �ϰڴ�.
*/

/*
���ڿ� �����ϱ� (insert)

���ڿ� ó������ ���� ����ϰ� ���Ǵ� �۾�����, ���ڿ� �߰��� �ٸ� ���ڿ��� �����ϴ� �۾��� �� �� �ִ�. 
��� ���±��� ����� ���� �Լ��鸸�� ������ insert �۾��� ���� ������ �� �ְ�����, 
����ϰ� ���Ǵ� �۾��̴� ���ϱ� �̸� ����� ���Ƽ� �������̽��� �����ϴ� �͵� ������ ���� ���̶� �����ȴ�.

MyString& MyString::insert(int loc, const MyString& str);
MyString& MyString::insert(int loc, const char* str);
MyString& MyString::insert(int loc, char c);

�ϴ� ���� ��� insert �۾��� ���� �پ��� �뵵�� ����ϰ� ���Ǳ� ������ ���� ���� 3 ���� insert �Լ��� �غ��Ͽ���. 
����� loc �� ��� ������ �� �̸� ������ ���ؾ� �ϴµ�, �Ϲ������� insert �Լ����� �Է� ��ġ�� �޴� ���, �� �Է� ��ġ '��' �� ���ڸ� insert �ϴ� ��찡 ����.

���� �� abc ��� ���ڿ��� insert(1, "d") �� �ϰ� �ȴٸ�, 1 �� ��ġ�� �ִ� b �տ� (����� ��� ��ġ�� �迭�� �ε����� �����Ѵ�. �� a �� 0 �� ��ġ) d �� ���Եȴ�.

�� ���� MyString �� ���ڷ� �޴� �Լ� �ϳ��� ����, �ֳ��ϸ� �� �Լ��� ����� �����Ѵٸ� ������ �Ʒ��� �� �Լ���

MyString& MyString::insert(int loc, const char* str) 
{
  MyString temp(str);
  return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c) 
{
  MyString temp(c);
  return insert(loc, temp);
}

�� ���� �����ϰ� ó���� �� �ֱ� ����, ���� ����� ������ �� �Լ��� �� ���� MyString �� ���ڷ� �޴� �Լ���.
*/

/*
MyString& MyString::insert(int loc, const MyString& str) 
{
  // �̴� i �� ��ġ �ٷ� �տ� ���ڸ� �����ϰ� �ȴ�. ���� ��
  // abc ��� ���ڿ��� insert(1, "d") �� �ϰ� �ȴٸ� adbc �� �ȴ�.

  // ������ ����� �Է¿� ���ؼ��� ������ �������� �ʴ´�.
  if (loc < 0 || loc > string_length) return *this;

  if (string_length + str.string_length > memory_capacity) 
  {
    // ���� ���Ӱ� �������� �Ҵ��� �ؾ� �Ѵ�.
    memory_capacity = string_length + str.string_length;

    char* prev_string_content = string_content;
    string_content = new char[memory_capacity];

    // �ϴ� insert �Ǵ� �κ� ���������� ������ �����Ѵ�.
    int i;
    for (i = 0; i < loc; i++) 
    {
      string_content[i] = prev_string_content[i];
    }

    // �׸��� ���ӿ� insert �Ǵ� ���ڿ��� �ִ´�.
    for (int j = 0; j != str.string_length; j++) 
    {
      string_content[i + j] = str.string_content[j];
    }

    // ���� �ٽ� �� ���ڿ��� ������ �޺κ��� �����Ѵ�.
    for (; i < string_length; i++) 
    {
      string_content[str.string_length + i] = prev_string_content[i];
    }

    delete[] prev_string_content;

    string_length = string_length + str.string_length;
    return *this;
  }

  // ���� �ʰ����� �ʴ� ��� ���� �����Ҵ��� �� �ʿ䰡 ���� �ȴ�.
  // ȿ�������� insert �ϱ� ����, �и��� �κ��� ���� �ڷ� �о������.

  for (int i = string_length - 1; i >= loc; i--) 
  {
    // �ڷ� �б�. �� �� ������ ���ڿ� �����Ͱ� ������� �ʰ� ��
    string_content[i + str.string_length] = string_content[i];
  }
  // �׸��� insert �Ǵ� ���� �ٽ� ����ֱ�
  for (int i = 0; i < str.string_length; i++)
    string_content[i + loc] = str.string_content[i];

  string_length = string_length + str.string_length;
  return *this;
}

������ assign �Լ� ó�� ���� �޸𸮸� �Ҵ��ؾ� �� ����, ���� �Ҵ��� �ʿ䰡 ���� ��츦 ����� ó���ϵ��� �Ͽ�����. 
���� �� ���ڿ��� ���� + ���� ���ԵǴ� ���ڿ��� ���̰�, ������ �Ҵ�� �޸��� ũ�� ���� ũ�ٸ� �ݵ�� �޸𸮸� ���� �Ҵ��ؾ� �ϰ�����, 
���� ��쿡��, ���� �޸𸮸� �����ϰ� ���Ҵ��ϴµ� �ð��� ������ �ʿ䰡 ���� �ȴ�.

�޸𸮸� �ٽ� �Ҵ��ؾ� �ϴ� ���, �ϴ� string_content �� ���ο� �Ҵ�� �޸� �ּҰ� ���Ƿ�, 
������ �޸� �ּҸ� �����ϱ� ���� prev_string_content �Լ��� �̿��Ѵ�. 
���� �̸� �̿��ؼ�, string_content �� ���Ե� ���ڿ��� �ս��� ���� ���� �� �ִ�.

�ݸ鿡, �޸𸮸� �ٽ� �Ҵ��� �ʿ䰡 ���� ��� ������ ���ڿ� ������ �̿��ϸ� ���Ե� ���ڿ��� string_content �� �־�� �ϹǷ� �ణ�� Ʈ���� �̿��Ѵ�. 
�ٷ�, �ڸ��� �ٲ�� ���ڿ����� ���� �ڷ� �о������ ���̴�. 
�̹� �޸��� �Ҵ�� ������ ����ϱ� ������ �ڷ� �̴� ���� ���� ������ �� �ִ�.
*/

/*
for (int i = string_length - 1; i >= loc; i--) 
{
  // �ڷ� �б�. �� �� ������ ���ڿ� �����Ͱ� ������� �ʰ� ��
  string_content[i + str.string_length] = string_content[i];

���� �� �ռ� abc ���� d �� �����ϴ� ������, 1 �� ��ġ�� d �� �־����Ƿ�, �ڸ��� �ٲ�� �͵��� bc �� �ȴ�. 
���� ���� bc �� �ڷ� �о���� ����, ���� ������ d �� ���� ������ �Ǵ� ���̴�. 
��, �� �۾��� �����ϸ� abc �� abbc �� �ǰ�,

// �׸��� insert �Ǵ� ���� �ٽ� ����ֱ�
for (int i = 0; i < str.string_length; i++)
  string_content[i + loc] = str.string_content[i];

�� �����ϸ�, insert �Ǵ� ���ڰ� �и� ���ڿ� ������ ���鼭 abbc ���� adbc �� �ȴ�. 
������ �����غ��� �Ʒ��� ���� �� �۵����� �� �� �ִ�.
*/

/*
#include <iostream>
#include <string.h>

class MyString 
{
  char* string_content;
  int string_length;
  int memory_capacity;

 public:
  MyString(char c);
  MyString(const char* str);
  MyString(const MyString& str);
  ~MyString();

  int length() const;
  int capacity() const;
  void reserve(int size);

  void print() const;
  void println() const;

  MyString& assign(const MyString& str);
  MyString& assign(const char* str);

  char at(int i) const;

  MyString& insert(int loc, const MyString& str);
  MyString& insert(int loc, const char* str);
  MyString& insert(int loc, char c);
};

MyString::MyString(char c) 
{
  string_content = new char[1];
  string_content[0] = c;
  memory_capacity = 1;
  string_length = 1;
}

MyString::MyString(const char* str) 
{
  string_length = strlen(str);
  memory_capacity = string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) 
  {
    string_content[i] = str[i];
  }
}

MyString::MyString(const MyString& str) 
{
  string_length = str.string_length;
  memory_capacity = str.string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) 
  {
    string_content[i] = str.string_content[i];
  }
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void MyString::print() const 
{
  for (int i = 0; i != string_length; i++) 
  {
    std::cout << string_content[i];
  }
}

void MyString::println() const
{
  for (int i = 0; i != string_length; i++) 
  {
    std::cout << string_content[i];
  }

  std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) 
{
  if (str.string_length > memory_capacity) 
  {
    delete[] string_content;

    string_content = new char[str.string_length];
    memory_capacity = str.string_length;
  }

  for (int i = 0; i != str.string_length; i++) 
  {
    string_content[i] = str.string_content[i];
  }

  string_length = str.string_length;

  return *this;
}

MyString& MyString::assign(const char* str) 
{
  int str_length = strlen(str);
  if (str_length > memory_capacity) {
    // �׷��� �ٽ� �Ҵ��� ����߸� �Ѵ�.
    delete[] string_content;

    string_content = new char[str_length];
    memory_capacity = str_length;
  }
  for (int i = 0; i != str_length; i++) {
    string_content[i] = str[i];
  }

  string_length = str_length;

  return *this;
}

int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) 
{
  if (size > memory_capacity) {
    char* prev_string_content = string_content;

    string_content = new char[size];
    memory_capacity = size;

    for (int i = 0; i != string_length; i++)
      string_content[i] = prev_string_content[i];

    delete[] prev_string_content;
  }

  // ���� �����Ϸ��� size �� ���� capacity ���� �۴ٸ�
  // �ƹ��͵� ���ص� �ȴ�.
}

char MyString::at(int i) const 
{
  if (i >= string_length || i < 0) 
  {
    return 0;
  } 
  else 
  {
    return string_content[i];
  }
}

MyString& MyString::insert(int loc, const MyString& str) 
{
  if (loc < 0 || loc > string_length) 
  {
    return *this;
  }

  if (string_length + str.string_length > memory_capacity) 
  {
    // ���� ���Ӱ� �������� �Ҵ��� �ؾ� �Ѵ�.
    memory_capacity = string_length + str.string_length;

    char* prev_string_content = string_content;
    string_content = new char[memory_capacity];

    // �ϴ� insert �Ǵ� �κ� ���������� ������ �����Ѵ�.
    int i;
    for (i = 0; i < loc; i++) 
    {
      string_content[i] = prev_string_content[i];
    }

    // �׸��� ���ӿ� insert �Ǵ� ���ڿ��� �ִ´�.
    for (int j = 0; j != str.string_length; j++) 
    {
      string_content[i + j] = str.string_content[j];
    }

    // ���� �ٽ� �� ���ڿ��� ������ �޺κ��� �����Ѵ�.
    for (; i < string_length; i++) 
    {
      string_content[str.string_length + i] = prev_string_content[i];
    }

    delete[] prev_string_content;

    string_length = string_length + str.string_length;
    return *this;
  }

  // ���� �ʰ����� �ʴ� ��� ���� �����Ҵ��� �� �ʿ䰡 ���� �ȴ�.
  // ȿ�������� insert �ϱ� ����, �и��� �κ��� ���� �ڷ� �о������.

  for (int i = string_length - 1; i >= loc; i--) 
  {
    // �ڷ� �б�. �� �� ������ ���ڿ� �����Ͱ� ������� �ʰ� ��
    string_content[i + str.string_length] = string_content[i];
  }
  // �׸��� insert �Ǵ� ���� �ٽ� ����ֱ�
  for (int i = 0; i < str.string_length; i++)
    string_content[i + loc] = str.string_content[i];

  string_length = string_length + str.string_length;
  return *this;
}

MyString& MyString::insert(int loc, const char* str) 
{
  MyString temp(str);
  return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c) 
{
  MyString temp(c);
  return insert(loc, temp);
}

int main() 
{
  MyString str1("very long string");
  MyString str2("<some string inserted between>");
  str1.reserve(30);

  std::cout << "Capacity : " << str1.capacity() << std::endl;
  std::cout << "String length : " << str1.length() << std::endl;
  str1.println();

  str1.insert(5, str2);
  str1.println();
}
*/

/*
�Ǹ��� MyString Ŭ������ ����� ���ؼ�, �� ���� �� �� �����غ��ƾ� �� ������ �ִ�. 
���� insert �� ����ϴ� ���� ���� � ����ϱ��? ���� ��� insert �� ���� ���ڿ��� �� ������ ����ִ� ���� �ƴ϶�, ���� ũ���� ���ڿ����� ���� ����ִ� ��찡 ����.
��, ū ũ���� ���ڿ��� �� ���� insert �ϴ� �۾� ���ٴ� ���� ũ���� ���ڿ����� ������ insert �ϴ� ����� ���� �����Ѵٴ� ���ε�, ���� �̹� capacity �Ѱ迡 ���� ���ڿ� Ŭ������ ���� a �� ��� �߰��ϴ� ����� �����غ����� ����.

while (some_condition) 
{
  str.insert(some_location, 'a');
}

�̹� str �� capacity �Ѱ迡 �����ߴٰ� ���������Ƿ�, �� insert ���� �޸𸮸� �����ϰ�, 
1 ��ŭ ū �޸𸮸� �Ҵ��ϴ� �۾��� �ݺ��ϰ� �� ���̴�. 
�̴� str �� ũ�Ⱑ ũ�ٸ� ��û�� �۾��� ���� �ƴ� �� ����.

��, ¥���ϰ� ��� insert �ϴ� ��ɿ��� �޸� �Ҵ�� ������ �ݺ����� �ʵ��� �ϱ� ���ؼ����, �� ũ�� �޸𸮸� �̸� reserve �س��� ���� �ʿ��ϴ�. 
����, ���δ�� �̸� ��û�� ũ���� �޸𸮸� �Ҵ��� ���� �� �� ���� ���̴�. 
���� 10 ����Ʈ �ۿ� ������� �ʴµ�, �̿� ���� ¥���ϰ� insert �ϴ� ������ ���ϱ� ���� 1000 ����Ʈ�� �̸� �Ҵ��� ���´ٸ� ������ �ڿ��� ���� �� ���̴�.

���� 'insert �۾������� ���� �Ҵ�/������ ���ϱ� ���� �̸� �޸𸮸� �Ҵ��س���' �� '�޸𸮸� �Ҵ��� ����, ���� �ڿ��� �������� �ʴ´�' ��� �� ������ ��� �����ϴ� ����� ������? 
���� �ִ�. 
�޸𸮸� �̸� �Ҵ��� ���, ���� �޸� ũ���� �� �� ������ �Ҵ��� ���� �ٴ� ��.

MyString& MyString::insert(int loc, const MyString& str) 
{
  // �̴� i �� ��ġ �ٷ� �տ� ���ڸ� �����ϰ� �ȴ�. ���� ��
  // abc ��� ���ڿ��� insert(1, "d") �� �ϰ� �ȴٸ� adbc �� �ȴ�.

  // ������ ����� �Է¿� ���ؼ��� ������ �������� �ʴ´�.
  if (loc < 0 || loc > string_length) return *this;

  if (string_length + str.string_length > memory_capacity) 
  {
    // ���� ���Ӱ� �������� �Ҵ��� �ؾ� �Ѵ�.

    if (memory_capacity * 2 > string_length + str.string_length)
      memory_capacity *= 2;
    else
      memory_capacity = string_length + str.string_length;

�� ���� �Ҵ��ؾ� �� �޸� ũ��(string_length + str.string_length) �� ������ memory_capacity �� �� �� ���϶��, �ƿ� memory_capacity �� �� �迡 ���ϴ� ũ�⸦ �Ҵ��ع����� ���̴�.

�׸��� ���� insert �Ǵ� ���ڿ��� ũ�Ⱑ ��û Ŀ�� memory_capacity �� �� �踦 �پ� �Ѿ�����ٸ� �׳� ������ �������� �ʰ� �ʿ��� ��ŭ �Ҵ��ع����� �ȴ�. 
�̿� ���� ������� ó���Ѵٸ�, ����� �޸��� �Ҵ�/������ ���� �� �ְ� �� ���� �޸� ������ �������� ������ �ִ�.
*/

/*
#include <iostream>
#include <string.h>

class MyString 
{
  char* string_content;
  int string_length;
  int memory_capacity;

 public:
  MyString(char c);
  MyString(const char* str);
  MyString(const MyString& str);
  ~MyString();

  int length() const;
  int capacity() const;
  void reserve(int size);

  void print() const;
  void println() const;

  MyString& assign(const MyString& str);
  MyString& assign(const char* str);

  char at(int i) const;

  MyString& insert(int loc, const MyString& str);
  MyString& insert(int loc, const char* str);
  MyString& insert(int loc, char c);
};

MyString::MyString(char c) 
{
  string_content = new char[1];
  string_content[0] = c;
  memory_capacity = 1;
  string_length = 1;
}

MyString::MyString(const char* str) 
{
  string_length = strlen(str);
  memory_capacity = string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) {
    string_content[i] = str[i];
  }
}

MyString::MyString(const MyString& str) 
{
  string_length = str.string_length;
  memory_capacity = str.string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) {
    string_content[i] = str.string_content[i];
  }
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void MyString::print() const 
{
  for (int i = 0; i != string_length; i++) {
    std::cout << string_content[i];
  }
}

void MyString::println() const 
{
  for (int i = 0; i != string_length; i++) 
  {
    std::cout << string_content[i];
  }

  std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) 
{
  if (str.string_length > memory_capacity) 
  {
    delete[] string_content;

    string_content = new char[str.string_length];
    memory_capacity = str.string_length;
  }
  for (int i = 0; i != str.string_length; i++) 
  {
    string_content[i] = str.string_content[i];
  }

  string_length = str.string_length;

  return *this;
}

MyString& MyString::assign(const char* str) 
{
  int str_length = strlen(str);
  if (str_length > memory_capacity) {
    // �׷��� �ٽ� �Ҵ��� ����߸� �Ѵ�.
    delete[] string_content;

    string_content = new char[str_length];
    memory_capacity = str_length;
  }
  for (int i = 0; i != str_length; i++) {
    string_content[i] = str[i];
  }

  string_length = str_length;

  return *this;
}

int MyString::capacity() const { return memory_capacity; }

void MyString::reserve(int size) 
{
  if (size > memory_capacity) 
  {
    char* prev_string_content = string_content;

    string_content = new char[size];
    memory_capacity = size;

    for (int i = 0; i != string_length; i++)
      string_content[i] = prev_string_content[i];

    delete[] prev_string_content;
  }
}

char MyString::at(int i) const 
{
  if (i >= string_length || i < 0) 
  {
    return 0;
  } else {
    return string_content[i];
  }
}

MyString& MyString::insert(int loc, const MyString& str) 
{
  if (loc < 0 || loc > string_length) return *this;

  if (string_length + str.string_length > memory_capacity) 
  {
    if (memory_capacity * 2 > string_length + str.string_length)
      memory_capacity *= 2;
    else
      memory_capacity = string_length + str.string_length;

    char* prev_string_content = string_content;
    string_content = new char[memory_capacity];

    int i;
    for (i = 0; i < loc; i++) 
    {
      string_content[i] = prev_string_content[i];
    }

    for (int j = 0; j != str.string_length; j++) 
    {
      string_content[i + j] = str.string_content[j];
    }

    for (; i < string_length; i++) 
    {
      string_content[str.string_length + i] = prev_string_content[i];
    }

    delete[] prev_string_content;

    string_length = string_length + str.string_length;
    return *this;
  }

  for (int i = string_length - 1; i >= loc; i--) 
  {
    string_content[i + str.string_length] = string_content[i];
  }

  for (int i = 0; i < str.string_length; i++)
    string_content[i + loc] = str.string_content[i];

  string_length = string_length + str.string_length;
  return *this;
}

MyString& MyString::insert(int loc, const char* str) 
{
  MyString temp(str);
  return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c) 
{
  MyString temp(c);
  return insert(loc, temp);
}

int main() 
{
  MyString str1("very long string");
  MyString str2("<some string inserted between>");
  str1.reserve(30);

  std::cout << "Capacity : " << str1.capacity() << std::endl;
  std::cout << "String length : " << str1.length() << std::endl;
  str1.println();

  str1.insert(5, str2);
  str1.println();

  std::cout << "Capacity : " << str1.capacity() << std::endl;
  std::cout << "String length : " << str1.length() << std::endl;
  str1.println();
}
*/

/*
erase �Լ�

erase �Լ��� insert �Լ����� ����� �ξ� ���, �ֳ��ϸ� �⺻������ �������� ���� �پ� ��� ���̱� ������ �����ϰ� capacity �̷� �͵��� ������ �ʿ䰡 ���� �����̴�.

MyString& erase(int loc, int num);

erase �Լ��� ���� ���� �����, loc �� insert �� �����ϰ� loc �� �ش��ϴ� ���� ���� �ǹ��Ѵ�. 
�׸��� num �� ����� ������ ���� �ǹ� 
���� �� abcd ��� ���ڿ����� erase(1, 2); �� �ϰ� �ȴٸ�, 1 �� �ش��ϴ� ���� 'b' �� �տ��� ���� 2 ���ڸ� ����� �Ǿ�, bc �� �������� ad �� ���ϵȴ�.

MyString& MyString::erase(int loc, int num) 
{
  // loc �� �� ���� �����ؼ� num ���ڸ� �����.
  if (num < 0 || loc < 0 || loc > string_length) return *this;

  for (int i = loc + num; i < string_length; i++) 
  {
    string_content[i - num] = string_content[i];
  }

  string_length -= num;
  return *this;
}

���� ���� ������ ó���� �� �ִ�. 
string_length �� �����Ͽ��� ���� ���� ���� �����̳ĸ�, ������ string_length �ڿ� ��� ������ ������ ���� ���� �Ű��� �Ƚᵵ �ȴٴ� ���̴�. 
���� ���� ������ ���ڵ��� ���� ���鼭 ���� ���ڵ��� �ʱ�ȭ ���� �ʾ�����, string_length ���� ó���Ͽ��� ������ ���� ���ڵ鿡 �Ű� ���� �ʾƵ� �ȴ�.
*/

/*
find �Լ�

���� insert �� erase �̿ܿ� �ſ� ����ϰ� ���Ǵ� �� �ٸ� �۾����� find �Լ��� �ִ�. 
��� insert, erase, find �� ���ڿ� ������ ���� ���� ���ʶ�� �ҷ��� ������ �ƴ� ��ŭ �ʼ����� �Լ���. 
�׷��� ������ find �Լ� ��ü�� ��� �����ϴ��Ŀ� ���� ���ڿ� Ŭ������ �������� ������ �������� �Ǵ� ��쵵 �ִ�.

�ֳ��ϸ� insert �� erase �� ��� ���� �ð��� ũ�� ���� �ɸ����� ������ ���ڿ��� ũ�Ⱑ �ſ� ũ�ٸ� find ������ ��û���� ���� �ɸ� �� �ְ� �� �� �ִ�.

���ڿ��� �˻��ϴ� �˰����� �� ���� ������, � ��Ȳ�� ���ؼ��� ���� ������ �����ϴ� �˰����� ����. 
(���� ��� ª�� ���ڿ� �˻��� ����ȭ �� �˰���� �� ���ڿ� �˻��� ����ȭ �� �˰���� ���� ���̴�) 
�׷��⿡ Ư���� �˰����� ����ϴ� ��쿡�� �� Ŭ������ ��� ������ ��Ȯ�ؼ� �� �˰����� ���� ������ ������ �� �ִ� ��쿡�� ����ϴ� ���� �����̴�. 
���� MyString �� ���, ���� ������ ������� find �˰����� �����ϱ�� �Ͽ���.

int find(int find_from, MyString& str) const;

int find(int find_from, const char* str) const;
int find(int find_from, char c) const;

�ϴ� �츮�� �ռ� insert �Լ��� ������ ���ó��, �� ���� MyString �� ���ڷ� �޴� find �� ����� ������ �Ŀ�, 
�Ʒ� �� ���� find �� �� ���� �Լ��� �̿��ؼ� �����ϴ� ������� ó���Ͽ���.

����� find �Լ��� find_from ���� ���� �����ؼ� ���� ù ��° str �� ��ġ�� �����ϰ� �ȴ�. 
�׸��� str �� ���ڿ��� ���ԵǾ� ���� �ʴٸ�, -1 �� �����ϰ� �ȴ�. 
�̷��� �������, � ���ڿ� ���� �ִ� ��� str ���� ã�� �� �ִ� for ���� ������ �� �� ���� ���̴�.

int MyString::find(int find_from, MyString& str) const 
{
  int i, j;
  if (str.string_length == 0) return -1;
  for (i = find_from; i <= string_length - str.string_length; i++) 
  {
    for (j = 0; j < str.string_length; j++) 
    {
      if (string_content[i + j] != str.string_content[j]) break;
    }

    if (j == str.string_length) return i;
  }

  return -1;  // ã�� ������
}

find_from ���� �����ؼ� string_content �� str �� �Ϻ��� ��ġ�ϴ� �κ��� ����ٸ� �� ��ġ�� �����ϰ�, 
ã�� ���� ��� -1 �� ����
*/

/*
ũ�� �� �Լ� `compare`

���⼭ 'ũ��' �� ���Ѵٴ� �ǹ̴� ���������� �迭�ؼ� � ���ڿ��� �� �ڿ� ������ �Ǵ��Ѵٴ� �ǹ̰� �ȴ�. 
�� �Լ��� �̿��ؼ� ���ڿ� ��ü�� �����ϴ� �Լ������, ������ C ���� strcmp �Լ� ������ �����Ͽ��� �͵��� �״�� ����� �� �ְ� �ȴ�.

int compare(const MyString& str) const;

�ϴ� �Լ��� ������ ���� ���� *this �� str �� ���ϴ� ���·� �̷������.

int MyString::compare(const MyString& str) const 
{
  // (*this) - (str) �� �����ؼ� �� 1, 0, -1 �� �� ����� �����Ѵ�
  // 1 �� (*this) �� ���������� �� �ڿ� �´ٴ� �ǹ�. 0 �� �� ���ڿ�
  // �� ���ٴ� �ǹ�, -1 �� (*this) �� ���������� �� �տ� �´ٴ� �ǹ��̴�.

  for (int i = 0; i < std::min(string_length, str.string_length); i++) 
  {
    if (string_content[i] > str.string_content[i])
      return 1;

    else if (string_content[i] < str.string_content[i])
      return -1;
  }

  // ���� ���� �ߴµ� ������ �ʾҴٸ� �� �κ� ���� ��� �Ȱ��� ���� �ȴ�.
  // ���� ���ڿ� ���̰� ���ٸ� �� ���ڿ��� �ƿ� ���� ���ڿ��� �ȴ�.

  if (string_length == str.string_length) return 0;

  // ����� abc �� abcd �� ũ�� �񱳴� abcd �� �� �ڿ� ���� �ȴ�.
  else if (string_length > str.string_length)
    return 1;

  return -1;
}

����� ���ϸ� abc �� abcd �� ũ�⸦ ���ϸ� abc �� abcd ���� ���������� �� �տ� ���� �ȴ�. 
���� �̿� ���� ó���� �޺κп��� ���� �ϰ� �ȴ�. 
�׸��� �� ���� �� �����ڸ� std::min �� std::max �Լ��� iostream �� include �ϸ� ����� �� �ִ� �Լ��� �̹Ƿ�, ���� ������ ����� �ʿ�� ����.
*/

/*
#include <iostream>
#include <string.h>

class MyString 
{
  char* string_content;
  int string_length;
  int memory_capacity;

 public:
  MyString(char c);
  MyString(const char* str);
  MyString(const MyString& str);

  ~MyString();

  int length() const;
  int capacity() const;
  void reserve(int size);

  void print() const;
  void println() const;

  MyString& assign(const MyString& str);
  MyString& assign(const char* str);

  char at(int i) const;

  MyString& insert(int loc, const MyString& str);
  MyString& insert(int loc, const char* str);
  MyString& insert(int loc, char c);

  MyString& erase(int loc, int num);

  int find(int find_from, const MyString& str) const;
  int find(int find_from, const char* str) const;
  int find(int find_from, char c) const;

  int compare(const MyString& str) const;
};

MyString::MyString(char c) 
{
  string_content = new char[1];
  string_content[0] = c;
  memory_capacity = 1;
  string_length = 1;
}

MyString::MyString(const char* str) 
{
  string_length = strlen(str);
  memory_capacity = string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) {
    string_content[i] = str[i];
  }
}

MyString::MyString(const MyString& str) 
{
  string_length = str.string_length;
  memory_capacity = str.string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) {
    string_content[i] = str.string_content[i];
  }
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void MyString::print() const 
{
  for (int i = 0; i != string_length; i++) {
    std::cout << string_content[i];
  }
}

void MyString::println() const 
{
  for (int i = 0; i != string_length; i++) {
    std::cout << string_content[i];
  }

  std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) 
{
  if (str.string_length > memory_capacity) {
    // �׷��� �ٽ� �Ҵ��� ����߸� �Ѵ�.
    delete[] string_content;

    string_content = new char[str.string_length];
    memory_capacity = str.string_length;
  }

  for (int i = 0; i != str.string_length; i++) {
    string_content[i] = str.string_content[i];
  }

  // �׸��� ���� str.string_length + 1 ~ string_length �κ��� �ʱ�ȭ
  // ��ų �ʿ�� ����. �ֳ��ϸ� �ű� ������ �о������ �ʱ� �����̴�.

  string_length = str.string_length;

  return *this;
}

MyString& MyString::assign(const char* str) 
{
  int str_length = strlen(str);

  if (str_length > memory_capacity) 
  {
    // �׷��� �ٽ� �Ҵ��� ����߸� �Ѵ�.
    delete[] string_content;

    string_content = new char[str_length];
    memory_capacity = str_length;
  }
  for (int i = 0; i != str_length; i++) {
    string_content[i] = str[i];
  }

  string_length = str_length;

  return *this;
}

int MyString::capacity() const { return memory_capacity; }

void MyString::reserve(int size) 
{
  if (size > memory_capacity) {
    char* prev_string_content = string_content;

    string_content = new char[size];
    memory_capacity = size;

    for (int i = 0; i != string_length; i++)
      string_content[i] = prev_string_content[i];

    delete[] prev_string_content;
  }

  // ���� �����Ϸ��� size �� ���� capacity ���� �۴ٸ�
  // �ƹ��͵� ���ص� �ȴ�.
}

char MyString::at(int i) const 
{
  if (i >= string_length || i < 0) {
    return 0;
  } else {
    return string_content[i];
  }
}

MyString& MyString::insert(int loc, const MyString& str) 
{
  // �̴� i �� ��ġ �ٷ� �տ� ���ڸ� �����ϰ� �ȴ�. ���� ��
  // abc ��� ���ڿ��� insert(1, "d") �� �ϰ� �ȴٸ� adbc �� �ȴ�.

  // ������ ����� �Է¿� ���ؼ��� ������ �������� �ʴ´�.
  if (loc < 0 || loc > string_length) return *this;

  if (string_length + str.string_length > memory_capacity) {
    // ���� ���Ӱ� �������� �Ҵ��� �ؾ� �Ѵ�.

    if (memory_capacity * 2 > string_length + str.string_length)
      memory_capacity *= 2;
    else
      memory_capacity = string_length + str.string_length;

    char* prev_string_content = string_content;
    string_content = new char[memory_capacity];

    // �ϴ� insert �Ǵ� �κ� ���������� ������ �����Ѵ�.
    int i;
    for (i = 0; i < loc; i++) {
      string_content[i] = prev_string_content[i];
    }

    // �׸��� ���ӿ� insert �Ǵ� ���ڿ��� �ִ´�.
    for (int j = 0; j != str.string_length; j++) {
      string_content[i + j] = str.string_content[j];
    }

    // ���� �ٽ� �� ���ڿ��� ������ �޺κ��� �����Ѵ�.
    for (; i < string_length; i++) {
      string_content[str.string_length + i] = prev_string_content[i];
    }

    delete[] prev_string_content;

    string_length = string_length + str.string_length;
    return *this;
  }

  // ���� �ʰ����� �ʴ� ��� ���� �����Ҵ��� �� �ʿ䰡 ���� �ȴ�.
  // ȿ�������� insert �ϱ� ����, �и��� �κ��� ���� �ڷ� �о������.

  for (int i = string_length - 1; i >= loc; i--) {
    // �ڷ� �б�. �� �� ������ ���ڿ� �����Ͱ� ������� �ʰ� ��
    string_content[i + str.string_length] = string_content[i];
  }
  // �׸��� insert �Ǵ� ���� �ٽ� ����ֱ�
  for (int i = 0; i < str.string_length; i++)
    string_content[i + loc] = str.string_content[i];

  string_length = string_length + str.string_length;
  return *this;
}

MyString& MyString::insert(int loc, const char* str) 
{
  MyString temp(str);
  return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c) 
{
  MyString temp(c);
  return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num) 
{
  // loc �� �� ���� �����ؼ� num ���ڸ� �����.
  if (num < 0 || loc < 0 || loc > string_length) return *this;

  // ����ٴ� ���� �ܼ��� ���� ���ڵ��� ������ ���� �´ٰ�
  // �����ϸ� �˴ϴ�.

  for (int i = loc + num; i < string_length; i++) {
    string_content[i - num] = string_content[i];
  }

  string_length -= num;
  return *this;
}

int MyString::find(int find_from, const MyString& str) const 
{
  int i, j;
  if (str.string_length == 0) return -1;
  for (i = find_from; i <= string_length - str.string_length; i++) {
    for (j = 0; j < str.string_length; j++) {
      if (string_content[i + j] != str.string_content[j]) break;
    }

    if (j == str.string_length) return i;
  }

  return -1;  // ã�� ������
}

int MyString::find(int find_from, const char* str) const 
{
  MyString temp(str);
  return find(find_from, temp);
}

int MyString::find(int find_from, char c) const 
{
  MyString temp(c);
  return find(find_from, temp);
}

int MyString::compare(const MyString& str) const 
{
  // (*this) - (str) �� �����ؼ� �� 1, 0, -1 �� �� ����� �����Ѵ�
  // 1 �� (*this) �� ���������� �� �ڿ� �´ٴ� �ǹ�. 0 �� �� ���ڿ�
  // �� ���ٴ� �ǹ�, -1 �� (*this) �� ���������� �� �տ� �´ٴ� �ǹ��̴�.

  for (int i = 0; i < std::min(string_length, str.string_length); i++) {
    if (string_content[i] > str.string_content[i])
      return 1;

    else if (string_content[i] < str.string_content[i])
      return -1;
  }

  // ���� ���� �ߴµ� ������ �ʾҴٸ� �� �κ� ���� ��� �Ȱ��� ���� �ȴ�.
  // ���� ���ڿ� ���̰� ���ٸ� �� ���ڿ��� �ƿ� ���� ���ڿ��� �ȴ�.

  if (string_length == str.string_length) return 0;

  // ����� abc �� abcd �� ũ�� �񱳴� abcd �� �� �ڿ� ���� �ȴ�.
  else if (string_length > str.string_length)
    return 1;

  return -1;
}

int main() 
{
  MyString str1("abcdef");
  MyString str2("abcde");

  std::cout << "str1 and str2 compare : " << str1.compare(str2) << std::endl;
}

���� c Ȥ�� C ���� ���ڿ� str ���� ������ �� �ִ� �����ڿ� ���� ������
���ڿ��� ���̸� �����ϴ� �Լ�(length)
���ڿ� ���� �Լ�(assign)
���ڿ� �޸� �Ҵ� �Լ�(reserve) �� ���� �Ҵ�� ũ�⸦ �˾ƿ��� �Լ�(capacity)
Ư�� ��ġ�� ���ڸ� �����ϴ� �Լ�(at)
Ư�� ��ġ�� Ư�� ���ڿ��� �����ϴ� �Լ�(insert)
Ư�� ��ġ�� Ư�� ������ ���ڸ� ����� �Լ�(erase)
Ư�� ��ġ�� �������� Ư�� ���ڿ��� �˻��ϴ� �Լ�(find)
�� ���ڿ��� ������ ���ϴ� �Լ�(compare)
*/