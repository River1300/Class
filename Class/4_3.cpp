/* 씹어먹는 C++ - <4 - 3. 스타크래프트를 만들자 ① (복사 생성자, 소멸자)> https://modoocode.com/188 */

// 복사 생성자 (copy constructor) - 깊은 복사와 얕은 복사
// 소멸자 (destructor)

/*
스타크래프트 만들기

스타크래프트라는 거대한 프로젝트를 진행하기에 앞서서 일단, 유닛 하나 부터 만들어 보도록 할 예정이다. 
마린 유닛은 스타크래프트 유닛 중에서 가장 단순하고 기본이 되는 유닛이라고 할 수 있다.
*/

/*
#include <iostream>

class Marine 
{
  int hp;                // 마린 체력
  int coord_x, coord_y;  // 마린 위치
  int damage;            // 공격력
  bool is_dead;

 public:
  Marine();              // 기본 생성자
  Marine(int x, int y);  // x, y 좌표에 마린 생성

  int attack();                       // 데미지 반환
  void be_attacked(int damage_earn);  // 받는 데미지
  void move(int x, int y);            // 새로운 위치

  void show_status();  // 상태를 보여준다.
};

Marine::Marine() 
{
  hp = 50;
  coord_x = coord_y = 0;
  damage = 5;
  is_dead = false;
}

Marine::Marine(int x, int y) 
{
  coord_x = x;
  coord_y = y;
  hp = 50;
  damage = 5;
  is_dead = false;
}

void Marine::move(int x, int y) 
{
  coord_x = x;
  coord_y = y;
}

int Marine::attack() { return damage; }

void Marine::be_attacked(int damage_earn) 
{
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;
}

void Marine::show_status() 
{
  std::cout << " *** Marine *** \n";
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) \n";
  std::cout << " HP : " << hp << std::endl;
}

int main() 
{
  Marine marine1(2, 3);
  Marine marine2(3, 5);

  marine1.show_status();
  marine2.show_status();

  std::cout << "\n마린 1 이 마린 2 를 공격! \n";
  marine2.be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}

성공적으로 컴파일 하였다면

 *** Marine ***
 Location : ( 2 , 3 )
 HP : 50
 *** Marine ***
 Location : ( 3 , 5 )
 HP : 50

마린 1 이 마린 2 를 공격!
 *** Marine ***
 Location : ( 2 , 3 )
 HP : 50
 *** Marine ***
 Location : ( 3 , 5 )
 HP : 45
*/

/*
class Marine 
{
  int hp;                // 마린 체력
  int coord_x, coord_y;  // 마린 위치
  int damage;            // 공격력
  bool is_dead;

 public:
  Marine();              // 기본 생성자
  Marine(int x, int y);  // x, y 좌표에 마린 생성

  int attack();                       // 데미지 반환
  void be_attacked(int damage_earn);  // 받는 데미지
  void move(int x, int y);            // 새로운 위치

  void show_status();  // 상태를 보여준다.
};

위는 마린을 구현한 클래스다. 즉, 위 클래스의 객체들이 바로 개개의 마린들이 되는 것. 
보통 어떠한 객체의 내부적 성질, 상태 등에 관련된 변수들은 모두 private 범주에 두고, 
그 객체가 외부에 하는 행동들은 함수로써 구현하여 public 에 두면 된다고 하였다.

그렇다면, 마린의 경우, 
마린의 상태에 관련된 것들 - 예를 들어서, 마린의 현재 hp 라던지, 위치, 공격력, 그리고 생존 여부 등은 private 범주에 두어서 관리하고, 
마린이 하는 행동들 - 즉, 이동한다 던지 공격한다 던지, 혹은 외부로 부터 공격 받는 등에 관련된 것들은 메소드로 만들어서 public 에서 범주로 두면 좋을 것 같다.
*/

/*
main 함수의 코드들을 살펴보도록 하자.

Marine marine1(2, 3);
Marine marine2(3, 5);

먼저, 위 두개의 marine1 과 marine2 라는 이름의 Marine 객체들을 생성했다. 생성자 오버로딩에 의해 각각 (2,3), (3,5) 에 위치한 마린들이 생성된다.

marine1.show_status();
marine2.show_status();

이제 위 함수들을 통해서 각각의 마린의 상태를 출력한 뒤에,

std::cout << "\n마린 1 이 마린 2 를 공격! \n";
marine2.be_attacked(marine1.attack());

마린 2 가 마린 1 로 부터 공격을 받는 상황을 그렸다.
그런데 사실 위 코드에는 약간의 문제가 있다. 만약에 실제 게임에서 처럼 수십 마리의 마린들이 서로 뒤엉켜 싸우기라도 하면 어떨까?

그럴 때는 marine1, marine2 와 같이 일일히 이름 붙이기도 벅찰 뿐더러, 
사용자가 몇 개의 마린을 만들겠다라고 컴파일 시점에 정해버리는 것도 아니기 때문에 수십개의 marine1, marine2... 를 미리 만들 수 도 없는 격이다. 
그럼 어떡할까? 답은 단순하다. marine 들을 배열로 정해버리면 된다.

int main() 
{
  Marine* marines[100];

  marines[0] = new Marine(2, 3);
  marines[1] = new Marine(3, 5);

  marines[0]->show_status();
  marines[1]->show_status();

  std::cout << "\n마린 1 이 마린 2 를 공격! \n";

  marines[0]->be_attacked(marines[1]->attack());

  marines[0]->show_status();
  marines[1]->show_status();

  delete marines[0];
  delete marines[1];
}

성공적으로 컴파일 하였다면

 *** Marine ***
 Location : ( 2 , 3 )
 HP : 50
 *** Marine ***
 Location : ( 3 , 5 )
 HP : 50

마린 1 이 마린 2 를 공격!
 *** Marine ***
 Location : ( 2 , 3 )
 HP : 50
 *** Marine ***
 Location : ( 3 , 5 )
 HP : 45

 로 동일하게 나온다.
*/

/*
new 의 경우 객체를 동적으로 생성하면서와 동시에 자동으로 생성자도 호출해준다.

marines[0] = new Marine(2, 3);
marines[1] = new Marine(3, 5);

위와 같이 Marine(2,3) 과 Marine(3,5) 라는 생성자를 자동으로 호출해준다. 이것이 바로 C++ 에 맞는 새로운 동적 할당이라고 볼 수 있다.

marines[0]->show_status();
marines[1]->show_status();

물론 Marine 들의 포인터를 가리키는 배열이기 때문에 메소드를 호출할 때 . 이 아니라 -> 를 사용해줘야 된다. 
마지막으로, 동적으로 할당한 메모리는 언제나 해제해 주어야 된다는 원칙에 따라

delete marines[0];
delete marines[1];

를 해주어야 한다.
*/

/*
소멸자 (Destructor)

알고 보니 각각의 마린에도 이름을 지정할 수 있었다. 
그래서, 우리는 만들어놓은 Marine 클래스에 name 이라는 이름을 저장할 수 있는 또다른 인스턴스 변수를 추가하도록 하자.
*/

/*
#include <string.h>
#include <iostream>

class Marine 
{
  int hp;                // 마린 체력
  int coord_x, coord_y;  // 마린 위치
  int damage;            // 공격력
  bool is_dead;
  char* name;  // 마린 이름

 public:
  Marine();                                       // 기본 생성자
  Marine(int x, int y, const char* marine_name);  // 이름까지 지정
  Marine(int x, int y);  // x, y 좌표에 마린 생성

  int attack();                       // 데미지 반환
  void be_attacked(int damage_earn);  // 받는 데미지
  void move(int x, int y);            // 새로운 위치

  void show_status();  // 상태를 보여준다.
};

Marine::Marine() 
{
  hp = 50;
  coord_x = coord_y = 0;
  damage = 5;
  is_dead = false;
  name = NULL;
}

Marine::Marine(int x, int y, const char* marine_name) 
{
  name = new char[strlen(marine_name) + 1];
  strcpy(name, marine_name);

  coord_x = x;
  coord_y = y;
  hp = 50;
  damage = 5;
  is_dead = false;
}

Marine::Marine(int x, int y) 
{
  coord_x = x;
  coord_y = y;
  hp = 50;
  damage = 5;
  is_dead = false;
  name = NULL;
}

void Marine::move(int x, int y) 
{
  coord_x = x;
  coord_y = y;
}

int Marine::attack() { return damage; }

void Marine::be_attacked(int damage_earn) 
{
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;
}

void Marine::show_status() 
{
  std::cout << " *** Marine : " << name << " ***" << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main() 
{
  Marine* marines[100];

  marines[0] = new Marine(2, 3, "Marine 2");
  marines[1] = new Marine(1, 5, "Marine 1");

  marines[0]->show_status();
  marines[1]->show_status();

  std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;

  marines[0]->be_attacked(marines[1]->attack());

  marines[0]->show_status();
  marines[1]->show_status();

  delete marines[0];
  delete marines[1];
}

성공적으로 컴파일 하였다면

*** Marine : Marine 2 ***
Location : ( 2 , 3 )
HP : 50
*** Marine : Marine 1 ***
Location : ( 1 , 5 )
HP : 50

마린 1 이 마린 2 를 공격!
*** Marine : Marine 2 ***
Location : ( 2 , 3 )
HP : 45
*** Marine : Marine 1 ***
Location : ( 1 , 5 )
HP : 50

와 같이 나옴을 알 수 있다.

그런데 사실, 위 코드에는 또다른 문제점이 있다.

Marine::Marine(int x, int y, const char* marine_name) 
{
  name = new char[strlen(marine_name) + 1];
  strcpy(name, marine_name);
  coord_x = x;
  coord_y = y;
  hp = 50;
  damage = 5;
  is_dead = false;
}

우리는 분명히 위 코드에서 name 에 우리가 생성하는 마린의 이름을 넣어줄 때, 
name 을 동적으로 생성해서 문자열을 복사하였는데, 그럼 이렇게 동적으로 할당된 char 배열에 대한 delete 는 언제 이루어지는 것인가?

안타깝게도, 우리가 명확히 delete 를 지정하지 않는 한 자동으로 delete 가 되는 경우는 없다. 
다시 말해서 우리가 동적으로 할당했던 저 name 은 영원히 메모리 공간 속에서 둥둥 떠다닌다는 말. 
사실 몇 바이트 정도 밖에 되지 않을 것이지만 위와 같은 name 들이 쌓이고 쌓이게 되면 메모리 누수 (Memory Leak) 이라는 문제점이 발생하게 된다. 

그렇다면, 만일 main 함수 끝에서 Marine 이 delete 될 때, 즉 우리가 생성했던 객체가 소멸 될 때 자동으로 호출되는 함수
마치 객체가 생성될 때 자동으로 호출 되었던 생성자 처럼 소멸 될 때 자동으로 호출되는 함수가 있다면 얼마나 좋을까? 
놀랍게도 이미 C++ 에서는 이 기능을 지원하고 있다. 바로 소멸자(Destructor)다.
*/

/*
#include <string.h>
#include <iostream>

class Marine 
{
  int hp;
  int coord_x, coord_y;
  int damage;
  bool is_dead;
  char* name;

 public:
  Marine();
  Marine(int x, int y, const char* marine_name);
  Marine(int x, int y);
  ~Marine();

  int attack();
  void be_attacked(int damage_earn);
  void move(int x, int y);

  void show_status();
};

Marine::Marine() {
  hp = 50;
  coord_x = coord_y = 0;
  damage = 5;
  is_dead = false;
  name = NULL;
}

Marine::Marine(int x, int y, const char* marine_name) 
{
  name = new char[strlen(marine_name) + 1];
  strcpy(name, marine_name);

  coord_x = x;
  coord_y = y;
  hp = 50;
  damage = 5;
  is_dead = false;
}

Marine::Marine(int x, int y) 
{
  coord_x = x;
  coord_y = y;
  hp = 50;
  damage = 5;
  is_dead = false;
  name = NULL;
}

void Marine::move(int x, int y) 
{
  coord_x = x;
  coord_y = y;
}

int Marine::attack() { return damage; }

void Marine::be_attacked(int damage_earn) 
{
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;
}

void Marine::show_status() 
{
  std::cout << " *** Marine : " << name << " ***\n";
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) \n";
  std::cout << " HP : " << hp << std::endl;
}

Marine::~Marine() 
{
  std::cout << name << " 의 소멸자 호출 ! \n";
  if (name != NULL) {
    delete[] name;
  }
}

int main() 
{
  Marine* marines[100];

  marines[0] = new Marine(2, 3, "Marine 2");
  marines[1] = new Marine(1, 5, "Marine 1");

  marines[0]->show_status();
  marines[1]->show_status();

  std::cout << "\n마린 1 이 마린 2 를 공격! \n";

  marines[0]->be_attacked(marines[1]->attack());

  marines[0]->show_status();
  marines[1]->show_status();

  delete marines[0];
  delete marines[1];
}

성공적으로 컴파일 하였다면

*** Marine : Marine 2 ***
Location : ( 2 , 3 )
HP : 50
*** Marine : Marine 1 ***
Location : ( 1 , 5 )
HP : 50

마린 1 이 마린 2 를 공격!
*** Marine : Marine 2 ***
Location : ( 2 , 3 )
HP : 45
*** Marine : Marine 1 ***
Location : ( 1 , 5 )
HP : 50
Marine 2 의 소멸자 호출 !
Marine 1 의 소멸자 호출 !

와 같이 나오게 된다.
생성자가 클래스 이름과 똑같이 생겼다면 소멸자는 그 앞에 ~ 만 붙여주면 된다.

우리의 Marine 클래스의 소멸자의 경우

~Marine();

위와 같이 생겼다. 
생성자와 한 가지 다른 점은, 소멸자는 인자를 아무것도 가지지 않는다는 것이다. 소멸자는 오버로딩도 되지 않는다.

우리의 소멸자의 내용을 살펴보자면

Marine::~Marine() 
{
  std::cout << name << " 의 소멸자 호출 ! \n";
  if (name != NULL) {
    delete[] name;
  }
}

위와 같이 name 이 NULL 이 아닐 경우에 (즉 동적으로 할당이 되었을 경우에) 만 delete 로 name 을 삭제하는 것을 알 수 있다. 
참고로 name 자체가 char 의 배열로 동적할당 하였기 때문에 delete 역시 delete [] name, 즉 [] 를 꼭 써주어야만 한다.

delete marines[0];
delete marines[1];

객체가 소멸될 때 소멸자가 호출된다고 출력하도록 했는데, 실제로 위 코드가 실행 시 소멸자 호출 메세지가 뜬다는 것을 확인할 수 있다.
*/

/*
// 소멸자 호출 확인하기
#include <string.h>
#include <iostream>

class Test 
{
  char c;

 public:
  Test(char _c) 
  {
    c = _c;
    std::cout << "생성자 호출 " << c << std::endl;
  }
  ~Test() { std::cout << "소멸자 호출 " << c << std::endl; }
};

void simple_function() { Test b('b'); }

int main() 
{
  Test a('a');
  simple_function();
}

성공적으로 컴파일 하였다면

생성자 호출 a
생성자 호출 b
소멸자 호출 b
소멸자 호출 a

와 같이 나온다. 위 코드에서 여러분은 '객체가 파괴될 때 호출되는 소멸자' 를 확실하게 확인할 수 있었을 것이다.

Test 클래스는 매우 간단한데, 생성자와 소멸자 호출 때 어떤 객체의 것이 호출되는지 확인하기 위해 char c 를 도입하였다.

int main() 
{
  Test a('a');
  simple_function();
}

일단 가장 먼저 main 함수에서 a 객체를 생성하였으므로 a 의 생성자가 호출된다. 그리고 simple_function 을 실행하게 되면,

void simple_function() { Test b('b'); }

simple_function 안에서 또 b 객체를 생성하므로 b 의 생성자가 호출되는데, 
하지만 b 는 simple_function 의 지역 객체이기 때문에 simple_function 이 종료됨과 동시에 b 역시 소멸되게 된다. 
따라서 끝에서 b 의 소멸자가 호출된다.

int main() 
{
  Test a('a');
  simple_function();
}

simple_function 호출 후, 이제 main 함수가 종료될 때 마찬가지로 main 함수의 지역 객체였던 a 가 소멸되면서 a 의 소멸자가 호출된다. 
이 세상을 떠날 때 얼마나 깔끔하게 떠나는 지가 더욱 중요한 일이 듯이, 객체가 다른 부분에 영향을 끼치지 않도록 깔끔하게 소멸되는 일은 매우 중요한 일이다.
소멸자가 하는 가장 흔한 역할은 위에서도 나타나 있지만, 객체가 동적으로 할당받은 메모리를 해제하는 일이라고 볼 수 있다. 
그 외에도 쓰레드 사이에서 lock 된 것을 푸는 역할이라던지 등의 역할을 수행하게 된다.
*/

/*
복사 생성자

사실 스타 유즈맵을 조금이나마 해본 사람이라면 아래 그림과 같은 '포토캐논 겹치기' 정도는 한 번 접해봤을것.
포토캐논의 모습은 한 개가 아니라 수십 개의 포토캐논이 서로 겹친 모습이다. 
다시 말해 같은 포토캐논들이 수 백개 '복사' 되었다고 볼 수 있다. 
위와 같이 동일한 포토캐논을 만들어 내는 방법은 각각의 포토캐논을 일일히 생성자로 생성 할 수 도 있지만, 1 개만 생성해 놓고, 그 한 개를 가지고 나머지 포토캐논들은 '복사 생성' 할 수 도 있는 것이다.
*/

/*
// 포토캐논
#include <string.h>
#include <iostream>

class Photon_Cannon 
{
  int hp, shield;
  int coord_x, coord_y;
  int damage;

 public:
  Photon_Cannon(int x, int y);
  Photon_Cannon(const Photon_Cannon& pc);

  void show_status();
};

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) 
{
  std::cout << "복사 생성자 호출 !" << std::endl;
  hp = pc.hp;
  shield = pc.shield;
  coord_x = pc.coord_x;
  coord_y = pc.coord_y;
  damage = pc.damage;
}

Photon_Cannon::Photon_Cannon(int x, int y) 
{
  std::cout << "생성자 호출 !" << std::endl;
  hp = shield = 100;
  coord_x = x;
  coord_y = y;
  damage = 20;
}

void Photon_Cannon::show_status() 
{
  std::cout << "Photon Cannon " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main() 
{
  Photon_Cannon pc1(3, 3);
  Photon_Cannon pc2(pc1);
  Photon_Cannon pc3 = pc2;

  pc1.show_status();
  pc2.show_status();
}

성공적으로 컴파일 하였다면

생성자 호출 !
복사 생성자 호출 !
복사 생성자 호출 !
Photon Cannon
Location : ( 3 , 3 )
HP : 100
Photon Cannon
Location : ( 3 , 3 )
HP : 100

와 같이 나온다.

먼저 우리가 제작한 복사 생성자 (copy constructor) 부터 살펴보자.

Photon_Cannon(const Photon_Cannon& pc);

사실 위는 복사 생성자의 표준적인 정의라고 볼 수 있다. 즉, 복사 생성자는 어떤 클래스 T 가 있다면

T(const T& a);

라고 정의된다. 
즉, 다른 T 의 객체 a 를 상수 레퍼런스로 받는 다는 이야기다. 
여기서 a 가 const 이기 때문에 복사 생성자 내부에서 a 의 데이터를 변경할 수 없고, 오직 새롭게 초기화 되는 인스턴스 변수들에게 '복사' 만 할 수 있게 된다. 다시 말해,

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) 
{
  std::cout << "복사 생성자 호출 !" << std::endl;
  hp = pc.hp;
  shield = pc.shield;
  coord_x = pc.coord_x;
  coord_y = pc.coord_y;
  damage = pc.damage;
}

위와 같이 복사 생성자 내부에서 pc 의 인스턴스 변수들에 접근해서 객체의 shield, coord_x, coord_y 등을 초기화 할 수 는 있지만

pc.coord_x = 3;

처럼 pc 의 값 자체는 변경할 수 없다는 이야기다.
한 가지 중요한 점은 함수 내부에서 받은 인자의 값을 변화시키는 일이 없다면 꼭 const 를 붙여주기 바란다. 
위와 같이 복사 생성자의 경우도, 인자로 받은 pc 의 값을 변경할 일이 없기 때문에 아예 처음부터 const 인자로 받는다. 
이렇게 된다면 후에 발생 할 수 있는 실수들을 효과적으로 막을 수 있다.
*/

/*
이제 위와 같이 정의된 복사 생성자를 실제로 어떻게 이용하는지 살펴보도록 하자.

Photon_Cannon pc1(3, 3);
Photon_Cannon pc2(pc1);

일단 pc1 은 int x, int y 를 인자로 가지는 생성자가 오버로딩 되었고, 
pc2 의 경우 인자로 pc1 을 넘겼으므로 복사 생성자가 호출되었음을 알 수 있다.

Photon_Cannon pc3 = pc2;

그렇다면 위 코드는 어떻까? 놀랍게도, 위 코드 역시 복사 생성자가 호출된다. 
C++ 컴파일러는 위 문장을 아래와 동일하게 해석한다.

Photon_Cannon pc3(pc2);

따라서 복사 생성자가 호출되게 되는 것이다. 물론, 위는 아주아주 특별한 경우다. 만일 그냥

pc3 = pc2;

를 했다면 이는 평범한 대입 연산 이겠지만, 생성 시에 대입하는 연산, 즉 위에 같이 Photon_Cannon pc3 = pc2; 한다면, 
복사 생성자가 호출되게 되는 것이다. 
이런식으로 Photon_Cannon pc3 = pc2; 를 해석함으로써 사용자가 상당히 직관적이고 깔끔한 프로그래밍을 할 수 있다.

참고로 한 가지 더 말하자면,

Photon_Cannon pc3 = pc2;

와

Photon_Cannon pc3;
pc3 = pc2;

는 엄연히 다른 문장이다. 
왜냐하면 위의 것은 말 그대로 복사 생성자가 1 번 호출되는 것이고, 아래 것은 그냥 생성자가 1 번 호출되고, pc3 = pc2; 라는 명령이 실행되는 것. 
다시 한 번 강조하지만, 복사 생성자는 오직 '생성' 시에 호출된다는 것을 명심해야 한다.

그런데, 사실 디폴트 생성자와 디폴트 소멸자 처럼, C++ 컴파일러는 이미 디폴트 복사 생성자(Default copy constructor) 를 지원해 주고 있다. 
위 코드에서 복사 생성자를 한 번 지워보고 실행해보면, 이전과 정확히 동일한 결과가 나타남을 알 수 있다. 
디폴트 복사 생성자의 경우 기존의 디폴트 생성자와 소멸자가 하는 일이 아무 것도 없었던 것과는 달리 실제로 '복사' 를 해준다.

만일 우리가 위 Photon_Cannon 의 디폴트 복사 생성자의 내용을 추정해 본다면

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) 
{
  hp = pc.hp;
  shield = pc.shield;
  coord_x = pc.coord_x;
  coord_y = pc.coord_y;
  damage = pc.damage;
}

와 같이 생겼을 것이다. 
대응되는 원소들을 말 그대로 1 대 1 복사해주게 된다. 
따라서 위와 같이 간단한 클래스의 경우 귀찮게 복사생성자를 써주지 않고도 디폴트 복사 생성자만 이용해서 복사 생성을 쉽게 처리할 수 있다.
*/

/*
디폴트 복사 생성자의 한계

이번에도 위의 마린 처럼 포토 캐논의 이름을 지어줄 수 있다는 사실을 알고 클래스 Photon_Cannon 에 char *name 을 추가 해주었다. 
그리고, 복사 생성자는 그냥 위에서 처럼 디폴트 복사 생성자를 사용하기로 하면
*/

/*
// 디폴트 복사 생성자의 한계
#include <string.h>
#include <iostream>

class Photon_Cannon 
{
  int hp, shield;
  int coord_x, coord_y;
  int damage;

  char *name;

 public:
  Photon_Cannon(int x, int y);
  Photon_Cannon(int x, int y, const char *cannon_name);
  ~Photon_Cannon();

  void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y) 
{
  hp = shield = 100;
  coord_x = x;
  coord_y = y;
  damage = 20;

  name = NULL;
}

Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name) 
{
  hp = shield = 100;
  coord_x = x;
  coord_y = y;
  damage = 20;

  name = new char[strlen(cannon_name) + 1];
  strcpy(name, cannon_name);
}

Photon_Cannon::~Photon_Cannon() 
{
  // 0 이 아닌 값은 if 문에서 true 로 처리되므로
  // 0 인가 아닌가를 비교할 때 그냥 if(name) 하면
  // if(name != 0) 과 동일한 의미를 가질 수 있다.

  // 참고로 if 문 다음에 문장이 1 개만 온다면
  // 중괄호를 생략 가능하다.

  if (name) delete[] name;
}

void Photon_Cannon::show_status() 
{
  std::cout << "Photon Cannon :: " << name << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main() 
{
  Photon_Cannon pc1(3, 3, "Cannon");
  Photon_Cannon pc2 = pc1;

  pc1.show_status();
  pc2.show_status();
}

컴파일 후 실행해보면 아래와 같은 오류를 만나게 될 것이다.

여기서 우리의 디폴트 복사 생성자가 어떻게 생겼는지 살펴보도록 하자. 
아마도 추정컨대, 컴파일러는 솔직하게 1 대 1 복사를 해주는 디폴트 복사 생성자를 아래와 같이 만들어 주었을 것이다.

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) 
{
  hp = pc.hp;
  shield = pc.shield;
  coord_x = pc.coord_x;
  coord_y = pc.coord_y;
  damage = pc.damage;
  name = pc.name;
}

hp, shield, ... 그리고 name 까지 모두 같은 값을 갖게 된다. 
여기서 name 이 같은 값 - 즉 두 개의 포인터가 같은 값을 가진 다는 것은 같은 주소 값을 가리킨다는 말이 된다. 
즉, 우리는 pc1 의 name 이 동적으로 할당받아서 가리키고 있던 메모리 ("Cannon" 이라는 문자열이 저장된 메모리) 를 pc2 의 name 도 같이 가리키게 되는 것.

물론 이 상태에서는 별 문제가 안된다. 뭐, 같은 메모리를 두 개의 서로 다른 포인터가 가리켜도 되기 때문인데, 진짜 문제는 소멸자에서 일어난다.
main 함수가 종료되기 직전에 생성되었던 객체들은 파괴되면서 소멸자를 호출하게 된다. 만일 먼저 pc1 이 파괴되었다고 해보자.

Photon_Cannon::~Photon_Cannon() 
{
  if (name) delete[] name;
}

pc2 에서 일단 name 은 NULL 이 아니므로 (0x125ADD3 이라는 주소값을 가지고 있음) delete [] name 이 수행되고, 
이미 해제된 메모리에 접근해서 다시 해제하려고 하였기 때문에 (사실 접근한 것 자체만으로 오류) 위 그림과 같이 무서운 런타임 오류가 발생하게 된다. 
그렇다면 이러한 문제를 막으러면 어떻게 해야 할까?

복사 생성자에서 name 을 그대로 복사하지 말고 따로 다른 메모리에 동적 할당을 해서 그 내용만 복사하면?
이렇게 메모리를 새로 할당해서 내용을 복사하는 것을 깊은 복사(deep copy) 라고 부르며 아까 처럼 단순히 대입 만 해주는 것을 얕은 복사(shallow copy) 라고 부른다. 
컴파일러가 생성하는 디폴트 복사 생성자의 경우 얕은 복사 밖에 할 수 없으므로 위와 같이 깊은 복사가 필요한 경우에는 사용자가 직접 복사 생성자를 만들어야 한다.

위 과정을 그림으로 설명하자면 복사 생성자에서 hp, shield 와 같은 변수 들은 얕은 복사를 하지만, name 의 경우 따로 메모리를 할당해서 그 내용만 복사하는 깊은 복사를 수행하게 되는 것. 
그러면 소멸자에서도 메모리 해제시 각기 다른 메모리를 해제하는 것이기 때문에 전혀 문제가 발생하지 않는다. 이를 바탕으로 복사 생성자를 만들어보면 아래와 같다.
*/

/*
// 복사 생성자의 중요성
#include <string.h>
#include <iostream>

class Photon_Cannon 
{
  int hp, shield;
  int coord_x, coord_y;
  int damage;

  char *name;

 public:
  Photon_Cannon(int x, int y);
  Photon_Cannon(int x, int y, const char *cannon_name);
  Photon_Cannon(const Photon_Cannon &pc);
  ~Photon_Cannon();

  void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y) 
{
  hp = shield = 100;
  coord_x = x;
  coord_y = y;
  damage = 20;

  name = NULL;
}

Photon_Cannon::Photon_Cannon(const Photon_Cannon &pc) 
{
  std::cout << "복사 생성자 호출! " << std::endl;
  hp = pc.hp;
  shield = pc.shield;
  coord_x = pc.coord_x;
  coord_y = pc.coord_y;
  damage = pc.damage;

  name = new char[strlen(pc.name) + 1];
  strcpy(name, pc.name);
}

Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name) 
{
  hp = shield = 100;
  coord_x = x;
  coord_y = y;
  damage = 20;

  name = new char[strlen(cannon_name) + 1];
  strcpy(name, cannon_name);
}

Photon_Cannon::~Photon_Cannon() 
{
  if (name) delete[] name;
}

void Photon_Cannon::show_status() 
{
  std::cout << "Photon Cannon :: " << name << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main() 
{
  Photon_Cannon pc1(3, 3, "Cannon");
  Photon_Cannon pc2 = pc1;

  pc1.show_status();
  pc2.show_status();
}
*/