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

/*
하지만 다행이도 C++ 에서는 원하지 않는 암시적 변환을 할 수 없도록 컴파일러에게 명시할 수 있습니다. 
바로 explicit 키워드를 통해 말이지요.

#include <iostream>

class MyString 
{
  char* string_content;  // 문자열 데이터를 가리키는 포인터
  int string_length;     // 문자열 길이

  int memory_capacity;

 public:
  explicit MyString(int capacity);  // capacity 만큼 미리 할당함. (explicit 키워드에 주목)

  // 문자열로 부터 생성
  MyString(const char* str);

  // 복사 생성자
  MyString(const MyString& str);

  ~MyString();

  int length() const;
  int capacity() const;
};

// .. (생략) ..

void DoSomethingWithString(MyString s) 
{
  // Do something...
}

int main() 
{
  DoSomethingWithString(3);
}

컴파일 오류

위와 같이 DoSomethingWithString(3) 부분에서 컴파일 오류가 발생함을 알 수 있습니다. 
그 이유는 int capacity 를 인자로 받는 생성자가

// capacity 만큼 미리 할당함. (explicit 키워드에 주목)
explicit MyString(int capacity);

위와 같이 explicit 으로 되어 있기 때문이지요. 
explicit 은 implicit 의 반대말로, 명시적 이라는 뜻을 가지고 있습니다.

컴파일러에서 이 MyString 생성자를 explicit 으로 선언한다면 이 생성자를 이용한 암시적 변환을 수행하지 못하게 막을 수 있습니다. 
실제 컴파일 오류 메세지를 보아도, int 에서 MyString 으로 변환할 수 없다고 나옵니다.

explicit 은 또한 해당 생성자가 복사 생성자의 형태로도 호출되는 것을 막게 됩니다. 예를 들어서;

MyString s = "abc";  // MyString s("abc")
MyString s = 5;      // MyString s(5)

MyString(int capacity); 에 explicit 이 없을 경우, 위 코드는 잘 작동합니다. 
왜냐하면 컴파일러가 알아서 적당한 생성자를 골라서 호출되기 때문이지요. 하지만 생각해보면

MyString s = 5;  // MyString s(5)

는 마치 s 에 5 를 대입하고 있다는 의미를 전달하게 됩니다. 
실제로는 capacity 를 5 로 해주는 것인대도 말이지요. 
따라서, explicit 으로 MyString(int capacity) 를 설정하면

MyString s(5);   // 허용
MyString s = 5;  // 컴파일 오류!

위와 같이 명시적으로 생성자를 부를 때 에만 허용할 수 있게 됩니다.
*/

/*
mutable

const 함수 내부에서는 멤버 변수들의 값을 바꾸는 것이 불가능 합니다. 
하지만, 만약에 멤버 변수를 mutable 로 선언하였다면 const 함수에서도 이들 값을 바꿀 수 있습니다.

#include <iostream>

class A 
{
  int data_;

 public:
  A(int data) : data_(data) {}
  void DoSomething(int x) const 
  {
    data_ = x;  // 불가능!
  }

  void PrintData() const { std::cout << "data: " << data_ << std::endl; }
};

int main() 
{
  A a(10);
  a.DoSomething(3);
  a.PrintData();
}

위와 같이 const 함수 안에서 멤버 변수에 값을 대입한다는 오류를 볼 수 있습니다. 
하지만 data_ 를 mutable 로 선언하면 어떨까요.

#include <iostream>

class A 
{
  mutable int data_;

 public:
  A(int data) : data_(data) {}
  void DoSomething(int x) const 
  {
    data_ = x;  // 가능!
  }

  void PrintData() const { std::cout << "data: " << data_ << std::endl; }
};

int main() 
{
  A a(10);
  a.DoSomething(3);
  a.PrintData();
}

위 처럼 data_ 의 값이 const 함수 안에서 바뀐 것을 알 수 있습니다.
그런데 생각해보면 mutable 을 쓸 바에는 차라리 그냥 DoSomething() 에서 const 를 떼어버리는게 낫지 않을까요? 왜 mutable 키워드를 만들었을까요?
*/

/*
먼저 멤버 함수를 왜 const 로 선언하는지 부터 생각해봅시다. 
클래스의 멤버 함수들은 이 객체는 이러이러한 일을 할 수 있습니다 라는 의미를 나타내고 있습니다.

그리고 멤버 함수를 const 로 선언하는 의미는 이 함수는 객체의 내부 상태에 영향을 주지 않습니다 를 표현하는 방법 입니다. 
대표적인 예로 읽기 작업을 수행하는 함수들을 들 수 있습니다.

대부분의 경우 의미상 상수 작업을 하는 경우, 실제로도 상수 작업을 하게 됩니다. 
하지만, 실제로 꼭 그렇지만은 않습니다. 
예를 들어서 아래와 같은 서버 프로그램을 만든다고 해봅시다.

class Server 
{
  // .... (생략) ....

  // 이 함수는 데이터베이스에서 user_id 에 해당하는 유저 정보를 읽어서 반환한다.
  User GetUserInfo(const int user_id) const 
  {
    // 1. 데이터베이스에 user_id 를 검색
    Data user_data = Database.find(user_id);

    // 2. 리턴된 정보로 User 객체 생성
    return User(user_data);
  }
};

이 서버에는 GetUserInfo 라는 함수가 있는데 입력 받은 user_id 로 데이터베이스에서 해댱 유저를 조회해서 그 유저의 정보를 리턴하는 함수 입니다. 
당연히도 데이터베이스를 업데이트 하지도 않고, 무언가 수정하는 작업도 당연히 없기 때문에 const 함수로 선언되어 있습니다.

그런데 대개 데이터베이스에 요청한 후 받아오는 작업은 꽤나 오래 걸립니다. 
그래서 보통 서버들의 경우 메모리에 캐쉬(cache)를 만들어서 자주 요청되는 데이터를 굳이 데이터베이스까지 가서 찾지 않아도 메모리에서 빠르게 조회할 수 있도록 합니다.

물론 캐쉬는 데이터베이스만큼 크지 않기 때문에 일부 유저들 정보 밖에 포함하지 않습니다. 
따라서 캐쉬에 해당 유저가 없다면 (이를 캐쉬 미스-cache miss 라고 합니다), 데이터베이스에 직접 요청해야겠지요. 
대신 데이터베이스에서 유저 정보를 받으면 캐쉬에 저장해놓아서 다음에 요청할 때는 빠르게 받을 수 있게 됩니다.

class Server 
{
  // .... (생략) ....

  Cache cache; // 캐쉬!

  // 이 함수는 데이터베이스에서 user_id 에 해당하는 유저 정보를 읽어서 반환한다.
  User GetUserInfo(const int user_id) const {
    // 1. 캐쉬에서 user_id 를 검색
    Data user_data = cache.find(user_id);

    // 2. 하지만 캐쉬에 데이터가 없다면 데이터베이스에 요청
    if (!user_data) {
      user_data = Database.find(user_id);

      // 그 후 캐쉬에 user_data 등록
      cache.update(user_id, user_data); // <-- 불가능
    }

    // 3. 리턴된 정보로 User 객체 생성
    return User(user_data);
  }
};

그런데 문제는 GetUserInfo 가 const 함수라는 점입니다. 따라서

cache.update(user_id, user_data);  // <-- 불가능

위 처럼 캐쉬를 업데이트 하는 작업을 수행할 수 없습니다. 
왜냐하면 캐쉬를 업데이트 한다는 것은 케쉬 내부의 정보를 바꿔야 된다는 뜻이기 때문이죠. 
따라서 저 update 함수는 const 함수가 아닐 것입니다.

그렇다고 해서 GetUserInfo 에서 const 를 떼기도 좀 뭐한것이, 이 함수를 사용하는 사용자의 입장에선 당연히 const 로 정의되어야 하는 함수 이기 때문이지요. 
따라서 이 경우, Cache 를 mutable 로 선언해버리면 됩니다.

mutable Cache cache;  // 캐쉬!

위 처럼 말이지요. 
이렇듯, mutable 키워드는 const 함수 안에서 해당 멤버 변수에 const 가 아닌 작업을 할 수 있게 만들어줍니다.
*/