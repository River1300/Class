/* �þ�Դ� C ++ - <4 - 6. Ŭ������ explicit �� mutable Ű����> https://modoocode.com/253 */

// explicit
// mutable

/*
explicit

#include <iostream>

class MyString 
{
  char* string_content;  // ���ڿ� �����͸� ����Ű�� ������
  int string_length;     // ���ڿ� ����

  int memory_capacity;

 public:
  MyString(int capacity);   // capacity ��ŭ �̸� �Ҵ���.
  MyString(const char* str);    // ���ڿ��� ���� ����
  MyString(const MyString& str);    // ���� ������

  ~MyString();

  int length() const;
};

MyString::MyString(int capacity) 
{
  string_content = new char[capacity];
  string_length = 0;
  memory_capacity = capacity;
  std::cout << "Capacity : " << capacity << std::endl;
}

MyString::MyString(const char* str) 
{
  string_length = 0;
  while (str[string_length++]) 
  {

  }

  string_content = new char[string_length];
  memory_capacity = string_length;

  for (int i = 0; i != string_length; i++) string_content[i] = str[i];
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

int main() { MyString s(3); }

���������� ������ �ϸ�

Capacity : 3
*/

/*
�츮�� �߰�����

MyString(int capacity); // capacity ��ŭ �̸� �Ҵ���.

�� �����ڰ� capacity �� �޾Ƽ� �� ��ŭ�� ������ �̸� �Ҵ��ϰ� �˴ϴ�. 
�׷��ٸ� �Ʒ��� ���� MyString �� ���ڷ� �޴� �Լ��� �����غ��ô�.

void DoSomethingWithString(MyString s) 
{
  // Do something...
}

�׷��ٸ� �ϴ� �Ʒ��� ���� �ڵ�� ������ �ɱ��?

DoSomethingWithString(MyString("abc"))

�翬�� �ǰ�����. MyString ��ü�� �����ؼ� �̸� ���ڷ� �����մϴ�. �׷��ٸ� MyString �� ��������� �������� ���� ���� ����?

DoSomethingWithString("abc")

�ϴ� DoSomethingWithString �Լ��� ���캸�� ���ڷ� MyString �� �ް� �ֽ��ϴ�. 
������ "abc" �� MyString Ÿ���� �ƴ�����. �׷��� C++ �����Ϸ��� �ϳ� �ȶ��ؼ� "abc" �� ��� �ϸ� MyString ���� �ٲ� �� �ִ��� �����غ��ϴ�. 
�׸��� �����̵� MyString �� �����ڵ� �߿�����

MyString(const char* str);  // ���ڿ��� ���� ����

���� ���� const char* �� ���� �����ϴ� ���� �־����ϴ�. ����, DoSomethingWithString("abc") �� �˾Ƽ�

DoSomethingWithString(MyString("abc"))

�� ��ȯ�Ǽ� ������ �˴ϴ�. 
���� ���� ��ȯ�� �Ͻ��� ��ȯ(implicit conversion) �̶�� �θ��ϴ�. ������ �Ͻ��� ��ȯ�� ������ ����ڿ��� ���� ���� �ƴմϴ�. 
���δ� ����ġ ���� ��쿡 �Ͻ��� ��ȯ�� �Ͼ �� �� �ֽ��ϴ�.

���� �� �Ʒ��� ���� ������ ����?

DoSomethingWithString(3)

�̴� �Ƹ��� ���� Ȯ���� �� �Լ��� ����ڰ� �߸� ������� ���ɼ��� �����ϴ�. 
�ֳ��ϸ� ���ڿ��� �޴� �Լ��� ���ڿ��� �����ؾ��� ���� �����͸� �����Ϸ��� ���� ���� ��������. 
������ �����Ϸ��� �� ������ ������ �Ǵ����� �ʽ��ϴ�. �ֳ��ϸ�;

MyString(int capacity); // capacity ��ŭ �̸� �Ҵ���.

���� ���� int ���ڸ� �޴� MyString �����ڰ� �ֱ� ������ �� �Լ���

DoSomethingWithString(MyString(3))

���� ��ȯ�Ǿ ������ �˴ϴ�. ��, ����ڰ� �ǵ����� ���� �Ͻ��� ��ȯ�� �Ͼ�� �˴ϴ�.
*/