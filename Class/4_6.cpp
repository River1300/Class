/* 씹어먹는 C ++ - <4 - 6. 클래스의 explicit 과 mutable 키워드> https://modoocode.com/253 */

// explicit
// mutable

/*
explicit

#include <iostream>

class MyString 
{
  char* string_content;  // 문자열 데이터를 가리키는 포인터
  int string_length;     // 문자열 길이

  int memory_capacity;

 public:
  MyString(int capacity);   // capacity 만큼 미리 할당함.
  MyString(const char* str);    // 문자열로 부터 생성
  MyString(const MyString& str);    // 복사 생성자

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

성공적으로 컴파일 하면

Capacity : 3
*/

/*
우리가 추가해준

MyString(int capacity); // capacity 만큼 미리 할당함.

위 생성자가 capacity 를 받아서 그 만큼의 공간을 미리 할당하게 됩니다. 
그렇다면 아래와 같이 MyString 을 인자로 받는 함수를 생각해봅시다.

void DoSomethingWithString(MyString s) 
{
  // Do something...
}

그렇다면 일단 아래와 같은 코드는 컴파일 될까요?

DoSomethingWithString(MyString("abc"))

당연히 되겠지요. MyString 객체를 생성해서 이를 인자로 전달합니다. 그렇다면 MyString 을 명시적으로 생성하지 않을 경우는 어떨까요?

DoSomethingWithString("abc")

일단 DoSomethingWithString 함수를 살펴보면 인자로 MyString 을 받고 있습니다. 
하지만 "abc" 는 MyString 타입이 아니지요. 그런데 C++ 컴파일러는 꽤나 똑똑해서 "abc" 를 어떻게 하면 MyString 으로 바꿀 수 있는지 생각해봅니다. 
그리고 다행이도 MyString 의 생성자들 중에서는

MyString(const char* str);  // 문자열로 부터 생성

위와 같이 const char* 로 부터 생성하는 것이 있었습니다. 따라서, DoSomethingWithString("abc") 는 알아서

DoSomethingWithString(MyString("abc"))

로 변환되서 컴파일 됩니다. 
위와 같은 변환을 암시적 변환(implicit conversion) 이라고 부릅니다. 하지만 암시적 변환이 언제나 사용자에게 편리한 것은 아닙니다. 
때로는 예상치 못한 경우에 암시적 변환이 일어날 수 도 있습니다.

예를 들어서 아래와 같은 문장은 어떨까요?

DoSomethingWithString(3)

이는 아마도 높은 확률로 위 함수를 사용자가 잘못 사용했을 가능성이 높습니다. 
왜냐하면 문자열을 받는 함수에 문자열을 전달해야지 정수 데이터를 전달하려는 일은 없기 때문이죠. 
하지만 컴파일러는 위 문장을 오류로 판단하지 않습니다. 왜냐하면;

MyString(int capacity); // capacity 만큼 미리 할당함.

위와 같이 int 인자를 받는 MyString 생성자가 있기 때문에 위 함수는

DoSomethingWithString(MyString(3))

으로 변환되어서 컴파일 됩니다. 즉, 사용자가 의도하지 않은 암시적 변환이 일어나게 됩니다.
*/