﻿/* 씹어먹는 C++ - <4 - 2. 클래스의 세계로 오신 것을 환영합니다. (함수의 오버로딩, 생성자)> https://modoocode.com/173 */

// 생성자 (constructor)
// 디폴트 생성자 (default constructor)

/*
함수의 오버로딩 (Overloading)

'함수의 오버로딩' 이라고 하는 것, 사실 오버로드를 사전에서 찾아보면 다음과 같은 뜻이 나온다.

과적하다
sb (with sth) 너무 많이 주다[부과하다]
(컴퓨터・전기 시스템 등에) 과부하가 걸리게 하다

함수의 오버로딩이라는 것은 '함수에 과부하를 주는 것' 인가, 사실 맞는 말이다. 
사실 C 언어 에서는 하나의 이름을 가지는 함수는 딱 1 개만 존재할 수 밖에 없기에 과부하라는 말 자체가 성립이 안됐다.

printf 는 C 라이브러리에 단 한 개 존재하고, scanf 도 C 라이브러리에 단 1 개 만 존재한다. 
하지만 C++ 에서는 같은 이름을 가진 함수가 여러개 존재해도 된다. 즉, 함수의 이름에 과부하 가 걸려도 상관이 없다는 것!

그렇다면 도대체 C++ 에서는 같은 이름의 함수를 호출했을 때 구분을 어떻게 하는 것일까. 
물론 단순하다. 함수를 호출 하였을 때 사용하는 인자를 보고 결정하게 된다.
*/

/*
함수의 오버로딩

#include <iostream>

void print(int x) { std::cout << "int : " << x << std::endl; }
void print(char x) { std::cout << "char : " << x << std::endl; }
void print(double x) { std::cout << "double : " << x << std::endl; }

int main() {
	int a = 1;
	char b = 'c';
	double c = 3.2f;

	print(a);
	print(b);
	print(c);

	return 0;
}

성공적으로 컴파일 하였다면

int : 1
char : c
double : 3.2

일단 위 소스를 보게 된다면 이름이 print 인 함수 3 개가 정의가 되었음을 알 수 있다. 
고전적인 C 컴파일러에서는 오류가 발생했겠지만 C++ 에서는 함수의 이름이 같더라도 인자가 다르면 
다른 함수 라고 판단하기 때문에 오류가 발생하지 않는 것이다.

void print(int x);
void print(char x);
void print(double x);

위와 같이 정의된 함수들을 main 에서 아래와 같이 호출하게 된다.

int a = 1;
char b = 'c';
double c = 3.2f;

print(a);
print(b);
print(c);

여기서 한 가지 눈여겨 보아야 할 점은 a 는 int, b 는 char, c 는 double 타입이라는 것인데, 
이에 따라 각각의 타입에 맞는 함수들, 
예를 들어 print(b) 는 b 가 char 이므로 char 형의 인자를 가지는 두 번째 print 가 호출 된 것이다.

C 언어였을 경우 int, char, double 타입에 따라 함수의 이름을 제각각 다르게 만들어서 호출해 주어야 했던 반면에 
C++ 에서는 컴파일러가 알아서 적합한 인자를 가지는 함수 를 찾아서 호출해 준다.

#include <iostream>

void print(int x) { std::cout << "int : " << x << std::endl; }
void print(double x) { std::cout << "double : " << x << std::endl; }

int main() {
	int a = 1;
	char b = 'c';
	double c = 3.2f;

	print(a);
	print(b);
	print(c);

	return 0;
}

성공적으로 컴파일 하였다면

int : 1
int : 99
double : 3.2

이번에는 조금 특이한 경우 입니다. 일단 함수는

void print(int x)
void print(double x)

int 타입의 인자나 double 타입의 인자를 하나 받는 함수 하나 밖에 없다. 
하지만 main 에서 각기 다른 타입의 인자들 (int, char, double) 로 print 함수를 호출하게 된다. 
물론 a 나 c 의 경우 각자 자기를 인자로 하는 정확한 함수들이 있어서 성공적으로 호출 될 수 있겠지만,
char 의 경우 자기와 정확히 일치하는 인자를 가지는 함수가 없기 때문에 '자신과 최대로 근접한 함수'를 찾게 된다.
*/

/*
C++ 컴파일러에서 함수를 오버로딩하는 과정은 다음과 같다.

1 단계
자신과 타입이 정확히 일치하는 함수를 찾는다.
2 단계
정확히 일치하는 타입이 없는 경우 아래와 같은 형변환을 통해서 일치하는 함수를 찾아본다.
Char, unsigned char, short 는 int 로 변환된다.
Unsigned short 는 int 의 크기에 따라 int 혹은 unsigned int 로 변환된다.
Float 은 double 로 변환된다.
Enum 은 int 로 변환된다.
3 단계
위와 같이 변환해도 일치하는 것이 없다면 아래의 좀더 포괄적인 형변환을 통해 일치하는 함수를 찾는다.
임의의 숫자(numeric) 타입은 다른 숫자 타입으로 변환된다. (예를 들어 float -> int)
Enum 도 임의의 숫자 타입으로 변환된다. (예를 들어 Enum -> double)
0 은 포인터 타입이나 숫자 타입으로 변환된 0 은 포인터 타입이나 숫자 타입으로 변환된다.
포인터는 void 포인터로 변환된다.
4 단계
유저 정의된 타입 변환으로 일치하는 것을 찾는다.
만약에 컴파일러가 위 과정을 통하더라도 일치하는 함수를 찾을 수 없거나 
같은 단계에서 두 개 이상이 일치하는 경우에 모호하다 (ambiguous) 라고 판단해서 오류를 발생하게 된다.
*/

/*
그렇다면 우리의 소스 코드에서

print(b);

는 어떻게 될까. 
1 단계에서는 명백하게도 char 타입의 인자를 가진 print 가 없기에 2 단계로 넘어오게 된다. 
그런데 2 단계에서는 char 이 int 로 변환된다면 print (int x) 를 호출할 수 있기 때문에 결국 print (int x) 가 호출되게 되는 것이다.

#include <iostream>

void print(int x) { std::cout << "int : " << x << std::endl; }
void print(char x) { std::cout << "double : " << x << std::endl; }

int main() {
  int a = 1;
  char b = 'c';
  double c = 3.2f;

  print(a);
  print(b);
  print(c);

  return 0;
}

위 소스를 컴파일 하였다면 오류가 발생함을 알 수 있습니다. 오류를 살짝 보자면

error C2668: 'print' : ambiguous call to overloaded function
could be 'void print(char)'
 or       'void print(int)'
while trying to match the argument list '(double)'

와 같이 나오는데, 일단 위 소스에서는 함수가 print (int x) 와 print (char x) 밖에 없으므로 관건은 print(c); 
를 했을 때 어떠한 함수가 호출되어야 하는지 결정하는 것인데, print(c) 를 했을 때 1 단계에서는 명백하게 일치하는 것이 없다.

2 단계에서는 마찬가지로 double 의 캐스팅에 관련한 내용이 없기에 일치하는 것이 없고 비로소 3 단계로 넘어오게 된다. 
3 단계에서는 '임의의 숫자 타입이 임의의 숫자 타입' 으로 변환되서 생각되기 때문에 double 은 char 도, 
int 도 변환 될 수 있게 되는 것이다.

따라서 같은 단계에 두 개 이상의 가능한 일치가 존재하므로 오류가 발생하게 되는 것이다.
위와 같은 C++ 오버로딩 규칙을 머리속에 숙지 하는 일은 매우 중요한 일이다. 
왜냐하면 나중에 복잡한 함수를 오버로딩할 때 여러가개 중복되서 나온다면 눈물없이 볼 수 없는 오류의 향연을 만날 수 있을 것이다!
*/

/*
Date 클래스

include<iostream>

class Date 
{
  int year_;
  int month_;  // 1 부터 12 까지.
  int day_;    // 1 부터 31 까지.

 public:
  void SetDate(int year, int month, int date);
  void AddDay(int inc);
  void AddMonth(int inc);
  void AddYear(int inc);

  // 해당 월의 총 일 수를 구한다.
  int GetCurrentMonthTotalDays(int year, int month);

  void ShowDate();
};

void Date::SetDate(int year, int month, int day)
{
  year_ = year;
  month_ = month;
  day_ = day;
}

int Date::GetCurrentMonthTotalDays(int year, int month) 
{
  static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month != 2) {
    return month_day[month - 1];
  } else if (year % 4 == 0 && year % 100 != 0) {
    return 29;  // 윤년
  } else {
    return 28;
  }
}

void Date::AddDay(int inc) 
{
  while (true) {
    // 현재 달의 총 일 수
    int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

    // 같은 달 안에 들어온다면;
    if (day_ + inc <= current_month_total_days) {
      day_ += inc;
      return;
    } else {
      // 다음달로 넘어가야 한다.
      inc -= (current_month_total_days - day_ + 1);
      day_ = 1;
      AddMonth(1);
    }
  }
}

void Date::AddMonth(int inc) 
{
  AddYear((inc + month_ - 1) / 12);
  month_ = month_ + inc % 12;
  month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::AddYear(int inc) { year_ += inc; }

void Date::ShowDate() 
{
  std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
            << " 일 입니다 " << std::endl;
}

int main() 
{
  Date day;
  day.SetDate(2011, 3, 1);
  day.ShowDate();

  day.AddDay(30);
  day.ShowDate();

  day.AddDay(2000);
  day.ShowDate();

  day.SetDate(2012, 1, 31);  // 윤년
  day.AddDay(29);
  day.ShowDate();

  day.SetDate(2012, 8, 4);
  day.AddDay(2500);
  day.ShowDate();
  return 0;
}

성공적으로 컴파일 하였다면

오늘은 2011 년 3 월 1 일 입니다
오늘은 2011 년 3 월 31 일 입니다
오늘은 2016 년 9 월 20 일 입니다
오늘은 2012 년 2 월 29 일 입니다
오늘은 2019 년 6 월 9 일 입니다

위의 코드는 간단히 만들어본 Date 클래스다. 그런데, 이상한 것? 클래스 내부에 아래 코드와 같이

  void SetDate(int year, int month, int date);
  void AddDay(int inc);
  void AddMonth(int inc);
  void AddYear(int inc);

  // 해당 월의 총 일 수를 구한다.
  int GetCurrentMonthTotalDays(int year, int month);

  void ShowDate();

함수의 정의만 나와 있고, 함수 전체 몸통은

void Date::ShowDate() 
{
  std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
            << " 일 입니다 " << std::endl;
}

처럼 밖에 나와 있다. 
Date:: 을 함수 이름 앞에 붙여주게 되면 이 함수가 "Date 클래스의 정의된 함수" 라는 의미를 부여하게 된다. 만일 그냥

void ShowDate() { // ...

와 같이 작성하였다면 위 함수는 클래스의 멤버 함수가 아니라 그냥 일반적인 함수가 된다. 
보통 간단한 함수를 제외하면 대부분의 함수들은 클래스 바깥에서 위와 같이 정의하게 된다. 
왜냐하면 클래스 내부에 쓸 경우 클래스 크기가 너무 길어져서 보기 좋지 않기 때문이다.

  Date day;
  day.SetDate(2011, 3, 1);
  day.ShowDate();

  day.AddDay(30);
  day.ShowDate();

그럼 이제 main 함수를 살펴 보자. 
위 처럼 day 인스턴스를 생성해서 SetDate 로 초기화 한 다음에 ShowDate 로 내용을 한 번 보여주고, 
또 AddDay 을 해서 30일을 증가 시킨뒤 다시 새로운 날짜를 출력하도록 하였다. 
여기서 가장 중요한 부분은 무엇일까? 
당연하게도, 처음의 SetDate 부분 이다. 
만일 SetDate 를 하지 않았더라면 초기화 되지 않은 값들에 덧셈 과 출력 명령이 내려져서
이상한 쓰레기 값이 출력되게 된다. 
그런데 문제는 이렇게 SetDate 함수를 사람들이 꼭 뒤에 써주지 않는 다는 말이다. 
물론 훌륭한 프로그래머들은 생성 후 초기화 를 항상 숙지하고 있겠지만 
간혹 실수로 생성한 객체를 초기화 하는 과정을 빠트린다면 끔찍한 일이 벌어지게 된다.

다행이도 C++ 에서는 이를 언어 차원에서 도와주는 장치가 있는데 바로 생성자(constructor)다.
*/

/*
생성자 (Constructor)

#include <iostream>

class Date 
{
  int year_;
  int month_;  // 1 부터 12 까지.
  int day_;    // 1 부터 31 까지.

 public:
  void SetDate(int year, int month, int date);
  void AddDay(int inc);
  void AddMonth(int inc);
  void AddYear(int inc);

  // 해당 월의 총 일 수를 구한다.
  int GetCurrentMonthTotalDays(int year, int month);

  void ShowDate();

  Date(int year, int month, int day) {
    year_ = year;
    month_ = month;
    day_ = day;
  }
};

// 생략

void Date::AddYear(int inc) { year_ += inc; }

void Date::ShowDate() 
{
  std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
            << " 일 입니다 " << std::endl;
}
int main() 
{
  Date day(2011, 3, 1);
  day.ShowDate();

  day.AddYear(10);
  day.ShowDate();

  return 0;
}

성공적으로 컴파일 하였다면

오늘은 2011 년 3 월 1 일 입니다
오늘은 2021 년 3 월 1 일 입니다

위와 같이 초기화가 잘 되서 출력됨을 알 수 있다.

생성자는 기본적으로 "객체 생성시 자동으로 호출되는 함수" 라고 볼 수 있다. 
이 때 자동으로 호출 되면서 객체를 초기화 해주는 역할을 담당하게 된다. 
생성자는 아래와 같이 정의한다.

// 객체를 초기화 하는 역할을 하기 때문에 리턴값이 없다!
// 클래스 이름(인자) {}

예를 들어서 위 경우 아래와 같이 Date 의 생성자를 정의하였다.

 Date(int year, int month, int day)

이렇게 정의가 된 생성자는 객체를 생성할 때 다음과 같이 위 함수에서 정의한 인자에 맞게마치 함수를 호출하듯이써준다면 
위 생성자를 호출하며 객체를 생성할 수 있게 된다. 즉, 우리의 경우 아래와 같이 객체를 생성

Date day(2011, 3, 1);

이는 곧 Date 클래스의 day 객체를 만들면서 생성자 Date(int year, int month, int day) 를 호출한다 라는 의미가 된다. 
따라서 Date 의 객체를 생성할 때 생성자의 인자 year, month, day 에 각각 2011, 3, 1 을 전달하며 객체를 생성하게 되는 것이다. 
참고로

Date day = Date(2012, 3, 1);

위 문장 역시 생성자 Date(2012, 3, 1) 을 호출해서 이를 토대로 객체를 생성하라는 의미다. 각각의 방식에 대해 이름이 붙어 있는데,

Date day(2011, 3, 1);         // 암시적 방법 (implicit)
Date day = Date(2012, 3, 1);  // 명시적 방법 (explicit)

마치 함수를 호출하듯이 사용하는 것이 암시적 방법, 
명시적으로 생성자를 호출한다는 것을 보여주는 것이 명시적 방법 인데 많은 경우 암시적 방법으로 축약해서 쓸 수 있으므로 
이를 선호하는 편이다.
*/

/*
디폴트 생성자 (Default constructor)

그런데 한 가지 궁금증이 생겼다. 
맨 처음에 단순히 SetDate 함수를 이용해서 객체를 초기화 하였을 때 우리는 생성자를 명시하지 않았다. 
즉 처음에 생성자 정의를 하지 않은 채 (SetDate 함수를 사용했던 코드)

Date day;

로 했을 때 과연 생성자가 호출 될 까? 
답은 Yes 다. 생성자가 호출된다. 
그런데, 우리가 생성자를 정의하지도 않았는데 어떤 생성자가 호출이 될까? 
바로 디폴트 생성자(Default Constructor) 다. 
디폴트 생성자는 인자를 하나도 가지지 않는 생성자인데, 
클래스에서 사용자가 어떠한 생성자도 명시적으로 정의하지 않았을 경우에 컴파일러가 자동으로 추가해주는 생성자다.

물론 컴파일러가 자동으로 생성할 때에는 아무런 일도 하지 않게 된다. 
그렇기에 맨 처음에 SetDate 를 하지 않았을 때 쓰레기 값이 나왔던 것이다.
물론 여러분이 직접 디폴트 생성자를 정의할 수 도 있다. 아래와 같이

#include <iostream>

class Date 
{
  int year_;
  int month_;  // 1 부터 12 까지.
  int day_;    // 1 부터 31 까지.

 public:
  void ShowDate();

  Date() 
  {
    year_ = 2012;
    month_ = 7;
    day_ = 12;
  }
};

void Date::ShowDate() 
{
  std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
            << " 일 입니다 " << std::endl;
}

int main() 
{
  Date day = Date();
  Date day2;

  day.ShowDate();
  day2.ShowDate();

  return 0;
}

성공적으로 컴파일 하였다면

오늘은 2012 년 7 월 12 일 입니다
오늘은 2012 년 7 월 12 일 입니다

와 같이 나오게 된다. 아래와 같이 디폴트 생성자 Date() 를 정의하였다.

Date() 
{
  year = 2012;
  month = 7;
  day = 12;
}

즉 year 에는 2012, month 에는 7, day 에는 12 를 대입한다.

Date day = Date();
Date day2;

그래서 사용하게 되면 위와 같이 디폴트 생성자를 이용해서 day 와 day2 를 추가할 수 있게 되는 것이다. 
한 가지 주의할 점은 위에서 인자가 있는 생성자에서 적용했던 것 처럼

Date day3();

와 하면 day3 객체를 디폴트 생성자를 이용해서 초기화 하는 것이 아니라, 
리턴값이 Date 이고 인자가 없는 함수 day3 을 정의하게 된 것으로 인식한다. 
이는 암시적 표현으로 객체를 선언할 때 반드시 주의해 두어야 할 사항이다.

절대로 인자가 없는 생성자를 호출하기 위해서 A a() 처럼 하면 안된다. 
해당 문장은 A 를 리턴하는 함수 a 를 정의한 문장 이다. 반드시 그냥 A a 와 같이 써야 한다.

명시적으로 디폴트 생성자 사용하기

C++ 11 이전에는 디폴트 생성자를 사용하고 싶을 경우 그냥 생성자를 정의하지 않는 방법 밖에 없었다. 
하지만 이 때문에 그 코드를 읽는 사용자 입장에서 개발자가 깜빡 잊고 생성자를 정의를 안한 것인지, 
아니면 정말 디폴트 생성자를 사용하고파서 이런 것인지 알길이 없다.

다행이도 C++ 11 부터 명시적으로 디폴트 생성자를 사용하도록 명시할 수 있다.

class Test {
 public:
  Test() = default;  // 디폴트 생성자를 정의해라
};

바로 위처럼 생성자의 선언 바로 뒤에 = default 를 붙여준다면, 
Test 의 디폴트 생성자를 정의하라고 컴파일러에게 명시적으로 알려줄 수 있다.
*/

/*
생성자 오버로딩

앞서 함수의 오버로딩에 대해 잠깐 짚고 넘어갔는데, 생성자 역시 함수 이기 때문에 마찬가지로 함수의 오버로딩이 적용될 수 있다. 
쉽게 말해 해당 클래스의 객체를 여러가지 방식으로 생성할 수 있게 되겠다.

#include <iostream>

class Date 
{
  int year_;
  int month_;  // 1 부터 12 까지.
  int day_;    // 1 부터 31 까지.

 public:
  void ShowDate();

  Date() 
  {
    std::cout << "기본 생성자 호출!" << std::endl;
    year_ = 2012;
    month_ = 7;
    day_ = 12;
  }

  Date(int year, int month, int day) 
  {
    std::cout << "인자 3 개인 생성자 호출!" << std::endl;
    year_ = year;
    month_ = month;
    day_ = day;
  }
};

void Date::ShowDate() 
{
  std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
            << " 일 입니다 " << std::endl;
}
int main() 
{
  Date day = Date();
  Date day2(2012, 10, 31);

  day.ShowDate();
  day2.ShowDate();

  return 0;
}

성공적으로 컴파일 하였다면

기본 생성자 호출!
인자 3 개인 생성자 호출!
오늘은 2012 년 7 월 12 일 입니다
오늘은 2012 년 10 월 31 일 입니다

와 같이 적절히 오버로딩이 되서 사용자가 원하는 생성자를 호출할 수 있게 된다.
*/