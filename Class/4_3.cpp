/* �þ�Դ� C++ - <4 - 3. ��Ÿũ����Ʈ�� ������ �� (���� ������, �Ҹ���)> https://modoocode.com/188 */

// ���� ������ (copy constructor) - ���� ����� ���� ����
// �Ҹ��� (destructor)

/*
��Ÿũ����Ʈ �����

��Ÿũ����Ʈ��� �Ŵ��� ������Ʈ�� �����ϱ⿡ �ռ��� �ϴ�, ���� �ϳ� ���� ����� ������ �� �����̴�. 
���� ������ ��Ÿũ����Ʈ ���� �߿��� ���� �ܼ��ϰ� �⺻�� �Ǵ� �����̶�� �� �� �ִ�.
*/

/*
#include <iostream>

class Marine 
{
  int hp;                // ���� ü��
  int coord_x, coord_y;  // ���� ��ġ
  int damage;            // ���ݷ�
  bool is_dead;

 public:
  Marine();              // �⺻ ������
  Marine(int x, int y);  // x, y ��ǥ�� ���� ����

  int attack();                       // ������ ��ȯ
  void be_attacked(int damage_earn);  // �޴� ������
  void move(int x, int y);            // ���ο� ��ġ

  void show_status();  // ���¸� �����ش�.
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

  std::cout << "\n���� 1 �� ���� 2 �� ����! \n";
  marine2.be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}

���������� ������ �Ͽ��ٸ�

 *** Marine ***
 Location : ( 2 , 3 )
 HP : 50
 *** Marine ***
 Location : ( 3 , 5 )
 HP : 50

���� 1 �� ���� 2 �� ����!
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
  int hp;                // ���� ü��
  int coord_x, coord_y;  // ���� ��ġ
  int damage;            // ���ݷ�
  bool is_dead;

 public:
  Marine();              // �⺻ ������
  Marine(int x, int y);  // x, y ��ǥ�� ���� ����

  int attack();                       // ������ ��ȯ
  void be_attacked(int damage_earn);  // �޴� ������
  void move(int x, int y);            // ���ο� ��ġ

  void show_status();  // ���¸� �����ش�.
};

���� ������ ������ Ŭ������. ��, �� Ŭ������ ��ü���� �ٷ� ������ �������� �Ǵ� ��. 
���� ��� ��ü�� ������ ����, ���� � ���õ� �������� ��� private ���ֿ� �ΰ�, 
�� ��ü�� �ܺο� �ϴ� �ൿ���� �Լ��ν� �����Ͽ� public �� �θ� �ȴٰ� �Ͽ���.

�׷��ٸ�, ������ ���, 
������ ���¿� ���õ� �͵� - ���� ��, ������ ���� hp �����, ��ġ, ���ݷ�, �׸��� ���� ���� ���� private ���ֿ� �ξ �����ϰ�, 
������ �ϴ� �ൿ�� - ��, �̵��Ѵ� ���� �����Ѵ� ����, Ȥ�� �ܺη� ���� ���� �޴� � ���õ� �͵��� �޼ҵ�� ���� public ���� ���ַ� �θ� ���� �� ����.
*/

/*
main �Լ��� �ڵ���� ���캸���� ����.

Marine marine1(2, 3);
Marine marine2(3, 5);

����, �� �ΰ��� marine1 �� marine2 ��� �̸��� Marine ��ü���� �����ߴ�. ������ �����ε��� ���� ���� (2,3), (3,5) �� ��ġ�� �������� �����ȴ�.

marine1.show_status();
marine2.show_status();

���� �� �Լ����� ���ؼ� ������ ������ ���¸� ����� �ڿ�,

std::cout << "\n���� 1 �� ���� 2 �� ����! \n";
marine2.be_attacked(marine1.attack());

���� 2 �� ���� 1 �� ���� ������ �޴� ��Ȳ�� �׷ȴ�.
�׷��� ��� �� �ڵ忡�� �ణ�� ������ �ִ�. ���࿡ ���� ���ӿ��� ó�� ���� ������ �������� ���� �ھ��� �ο��� �ϸ� ���?

�׷� ���� marine1, marine2 �� ���� ������ �̸� ���̱⵵ ���� �Ӵ���, 
����ڰ� �� ���� ������ ����ڴٶ�� ������ ������ ���ع����� �͵� �ƴϱ� ������ ���ʰ��� marine1, marine2... �� �̸� ���� �� �� ���� ���̴�. 
�׷� ��ұ�? ���� �ܼ��ϴ�. marine ���� �迭�� ���ع����� �ȴ�.

int main() 
{
  Marine* marines[100];

  marines[0] = new Marine(2, 3);
  marines[1] = new Marine(3, 5);

  marines[0]->show_status();
  marines[1]->show_status();

  std::cout << "\n���� 1 �� ���� 2 �� ����! \n";

  marines[0]->be_attacked(marines[1]->attack());

  marines[0]->show_status();
  marines[1]->show_status();

  delete marines[0];
  delete marines[1];
}

���������� ������ �Ͽ��ٸ�

 *** Marine ***
 Location : ( 2 , 3 )
 HP : 50
 *** Marine ***
 Location : ( 3 , 5 )
 HP : 50

���� 1 �� ���� 2 �� ����!
 *** Marine ***
 Location : ( 2 , 3 )
 HP : 50
 *** Marine ***
 Location : ( 3 , 5 )
 HP : 45

 �� �����ϰ� ���´�.
*/

/*
new �� ��� ��ü�� �������� �����ϸ鼭�� ���ÿ� �ڵ����� �����ڵ� ȣ�����ش�.

marines[0] = new Marine(2, 3);
marines[1] = new Marine(3, 5);

���� ���� Marine(2,3) �� Marine(3,5) ��� �����ڸ� �ڵ����� ȣ�����ش�. �̰��� �ٷ� C++ �� �´� ���ο� ���� �Ҵ��̶�� �� �� �ִ�.

marines[0]->show_status();
marines[1]->show_status();

���� Marine ���� �����͸� ����Ű�� �迭�̱� ������ �޼ҵ带 ȣ���� �� . �� �ƴ϶� -> �� �������� �ȴ�. 
����������, �������� �Ҵ��� �޸𸮴� ������ ������ �־�� �ȴٴ� ��Ģ�� ����

delete marines[0];
delete marines[1];

�� ���־�� �Ѵ�.
*/

/*
�Ҹ��� (Destructor)

�˰� ���� ������ �������� �̸��� ������ �� �־���. 
�׷���, �츮�� �������� Marine Ŭ������ name �̶�� �̸��� ������ �� �ִ� �Ǵٸ� �ν��Ͻ� ������ �߰��ϵ��� ����.
*/

/*
#include <string.h>
#include <iostream>

class Marine 
{
  int hp;                // ���� ü��
  int coord_x, coord_y;  // ���� ��ġ
  int damage;            // ���ݷ�
  bool is_dead;
  char* name;  // ���� �̸�

 public:
  Marine();                                       // �⺻ ������
  Marine(int x, int y, const char* marine_name);  // �̸����� ����
  Marine(int x, int y);  // x, y ��ǥ�� ���� ����

  int attack();                       // ������ ��ȯ
  void be_attacked(int damage_earn);  // �޴� ������
  void move(int x, int y);            // ���ο� ��ġ

  void show_status();  // ���¸� �����ش�.
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

  std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;

  marines[0]->be_attacked(marines[1]->attack());

  marines[0]->show_status();
  marines[1]->show_status();

  delete marines[0];
  delete marines[1];
}

���������� ������ �Ͽ��ٸ�

*** Marine : Marine 2 ***
Location : ( 2 , 3 )
HP : 50
*** Marine : Marine 1 ***
Location : ( 1 , 5 )
HP : 50

���� 1 �� ���� 2 �� ����!
*** Marine : Marine 2 ***
Location : ( 2 , 3 )
HP : 45
*** Marine : Marine 1 ***
Location : ( 1 , 5 )
HP : 50

�� ���� ������ �� �� �ִ�.

�׷��� ���, �� �ڵ忡�� �Ǵٸ� �������� �ִ�.

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

�츮�� �и��� �� �ڵ忡�� name �� �츮�� �����ϴ� ������ �̸��� �־��� ��, 
name �� �������� �����ؼ� ���ڿ��� �����Ͽ��µ�, �׷� �̷��� �������� �Ҵ�� char �迭�� ���� delete �� ���� �̷������ ���ΰ�?

��Ÿ���Ե�, �츮�� ��Ȯ�� delete �� �������� �ʴ� �� �ڵ����� delete �� �Ǵ� ���� ����. 
�ٽ� ���ؼ� �츮�� �������� �Ҵ��ߴ� �� name �� ������ �޸� ���� �ӿ��� �յ� ���ٴѴٴ� ��. 
��� �� ����Ʈ ���� �ۿ� ���� ���� �������� ���� ���� name ���� ���̰� ���̰� �Ǹ� �޸� ���� (Memory Leak) �̶�� �������� �߻��ϰ� �ȴ�. 

�׷��ٸ�, ���� main �Լ� ������ Marine �� delete �� ��, �� �츮�� �����ߴ� ��ü�� �Ҹ� �� �� �ڵ����� ȣ��Ǵ� �Լ�
��ġ ��ü�� ������ �� �ڵ����� ȣ�� �Ǿ��� ������ ó�� �Ҹ� �� �� �ڵ����� ȣ��Ǵ� �Լ��� �ִٸ� �󸶳� ������? 
����Ե� �̹� C++ ������ �� ����� �����ϰ� �ִ�. �ٷ� �Ҹ���(Destructor)��.
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
  std::cout << name << " �� �Ҹ��� ȣ�� ! \n";
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

  std::cout << "\n���� 1 �� ���� 2 �� ����! \n";

  marines[0]->be_attacked(marines[1]->attack());

  marines[0]->show_status();
  marines[1]->show_status();

  delete marines[0];
  delete marines[1];
}

���������� ������ �Ͽ��ٸ�

*** Marine : Marine 2 ***
Location : ( 2 , 3 )
HP : 50
*** Marine : Marine 1 ***
Location : ( 1 , 5 )
HP : 50

���� 1 �� ���� 2 �� ����!
*** Marine : Marine 2 ***
Location : ( 2 , 3 )
HP : 45
*** Marine : Marine 1 ***
Location : ( 1 , 5 )
HP : 50
Marine 2 �� �Ҹ��� ȣ�� !
Marine 1 �� �Ҹ��� ȣ�� !

�� ���� ������ �ȴ�.
�����ڰ� Ŭ���� �̸��� �Ȱ��� ����ٸ� �Ҹ��ڴ� �� �տ� ~ �� �ٿ��ָ� �ȴ�.

�츮�� Marine Ŭ������ �Ҹ����� ���

~Marine();

���� ���� �����. 
�����ڿ� �� ���� �ٸ� ����, �Ҹ��ڴ� ���ڸ� �ƹ��͵� ������ �ʴ´ٴ� ���̴�. �Ҹ��ڴ� �����ε��� ���� �ʴ´�.

�츮�� �Ҹ����� ������ ���캸�ڸ�

Marine::~Marine() 
{
  std::cout << name << " �� �Ҹ��� ȣ�� ! \n";
  if (name != NULL) {
    delete[] name;
  }
}

���� ���� name �� NULL �� �ƴ� ��쿡 (�� �������� �Ҵ��� �Ǿ��� ��쿡) �� delete �� name �� �����ϴ� ���� �� �� �ִ�. 
����� name ��ü�� char �� �迭�� �����Ҵ� �Ͽ��� ������ delete ���� delete [] name, �� [] �� �� ���־�߸� �Ѵ�.

delete marines[0];
delete marines[1];

��ü�� �Ҹ�� �� �Ҹ��ڰ� ȣ��ȴٰ� ����ϵ��� �ߴµ�, ������ �� �ڵ尡 ���� �� �Ҹ��� ȣ�� �޼����� ��ٴ� ���� Ȯ���� �� �ִ�.
*/

/*
// �Ҹ��� ȣ�� Ȯ���ϱ�
#include <string.h>
#include <iostream>

class Test 
{
  char c;

 public:
  Test(char _c) 
  {
    c = _c;
    std::cout << "������ ȣ�� " << c << std::endl;
  }
  ~Test() { std::cout << "�Ҹ��� ȣ�� " << c << std::endl; }
};

void simple_function() { Test b('b'); }

int main() 
{
  Test a('a');
  simple_function();
}

���������� ������ �Ͽ��ٸ�

������ ȣ�� a
������ ȣ�� b
�Ҹ��� ȣ�� b
�Ҹ��� ȣ�� a

�� ���� ���´�. �� �ڵ忡�� �������� '��ü�� �ı��� �� ȣ��Ǵ� �Ҹ���' �� Ȯ���ϰ� Ȯ���� �� �־��� ���̴�.

Test Ŭ������ �ſ� �����ѵ�, �����ڿ� �Ҹ��� ȣ�� �� � ��ü�� ���� ȣ��Ǵ��� Ȯ���ϱ� ���� char c �� �����Ͽ���.

int main() 
{
  Test a('a');
  simple_function();
}

�ϴ� ���� ���� main �Լ����� a ��ü�� �����Ͽ����Ƿ� a �� �����ڰ� ȣ��ȴ�. �׸��� simple_function �� �����ϰ� �Ǹ�,

void simple_function() { Test b('b'); }

simple_function �ȿ��� �� b ��ü�� �����ϹǷ� b �� �����ڰ� ȣ��Ǵµ�, 
������ b �� simple_function �� ���� ��ü�̱� ������ simple_function �� ����ʰ� ���ÿ� b ���� �Ҹ�ǰ� �ȴ�. 
���� ������ b �� �Ҹ��ڰ� ȣ��ȴ�.

int main() 
{
  Test a('a');
  simple_function();
}

simple_function ȣ�� ��, ���� main �Լ��� ����� �� ���������� main �Լ��� ���� ��ü���� a �� �Ҹ�Ǹ鼭 a �� �Ҹ��ڰ� ȣ��ȴ�. 
�� ������ ���� �� �󸶳� ����ϰ� ������ ���� ���� �߿��� ���� ����, ��ü�� �ٸ� �κп� ������ ��ġ�� �ʵ��� ����ϰ� �Ҹ�Ǵ� ���� �ſ� �߿��� ���̴�.
�Ҹ��ڰ� �ϴ� ���� ���� ������ �������� ��Ÿ�� ������, ��ü�� �������� �Ҵ���� �޸𸮸� �����ϴ� ���̶�� �� �� �ִ�. 
�� �ܿ��� ������ ���̿��� lock �� ���� Ǫ�� �����̶���� ���� ������ �����ϰ� �ȴ�.
*/

/*
���� ������

��� ��Ÿ ������� �����̳��� �غ� ����̶�� �Ʒ� �׸��� ���� '����ĳ�� ��ġ��' ������ �� �� ���غ�����.
����ĳ���� ����� �� ���� �ƴ϶� ���� ���� ����ĳ���� ���� ��ģ ����̴�. 
�ٽ� ���� ���� ����ĳ����� �� �鰳 '����' �Ǿ��ٰ� �� �� �ִ�. 
���� ���� ������ ����ĳ���� ����� ���� ����� ������ ����ĳ���� ������ �����ڷ� ���� �� �� �� ������, 1 ���� ������ ����, �� �� ���� ������ ������ ����ĳ����� '���� ����' �� �� �� �ִ� ���̴�.
*/

/*
// ����ĳ��
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
  std::cout << "���� ������ ȣ�� !" << std::endl;
  hp = pc.hp;
  shield = pc.shield;
  coord_x = pc.coord_x;
  coord_y = pc.coord_y;
  damage = pc.damage;
}

Photon_Cannon::Photon_Cannon(int x, int y) 
{
  std::cout << "������ ȣ�� !" << std::endl;
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

���������� ������ �Ͽ��ٸ�

������ ȣ�� !
���� ������ ȣ�� !
���� ������ ȣ�� !
Photon Cannon
Location : ( 3 , 3 )
HP : 100
Photon Cannon
Location : ( 3 , 3 )
HP : 100

�� ���� ���´�.

���� �츮�� ������ ���� ������ (copy constructor) ���� ���캸��.

Photon_Cannon(const Photon_Cannon& pc);

��� ���� ���� �������� ǥ������ ���Ƕ�� �� �� �ִ�. ��, ���� �����ڴ� � Ŭ���� T �� �ִٸ�

T(const T& a);

��� ���ǵȴ�. 
��, �ٸ� T �� ��ü a �� ��� ���۷����� �޴� �ٴ� �̾߱��. 
���⼭ a �� const �̱� ������ ���� ������ ���ο��� a �� �����͸� ������ �� ����, ���� ���Ӱ� �ʱ�ȭ �Ǵ� �ν��Ͻ� �����鿡�� '����' �� �� �� �ְ� �ȴ�. �ٽ� ����,

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) 
{
  std::cout << "���� ������ ȣ�� !" << std::endl;
  hp = pc.hp;
  shield = pc.shield;
  coord_x = pc.coord_x;
  coord_y = pc.coord_y;
  damage = pc.damage;
}

���� ���� ���� ������ ���ο��� pc �� �ν��Ͻ� �����鿡 �����ؼ� ��ü�� shield, coord_x, coord_y ���� �ʱ�ȭ �� �� �� ������

pc.coord_x = 3;

ó�� pc �� �� ��ü�� ������ �� ���ٴ� �̾߱��.
�� ���� �߿��� ���� �Լ� ���ο��� ���� ������ ���� ��ȭ��Ű�� ���� ���ٸ� �� const �� �ٿ��ֱ� �ٶ���. 
���� ���� ���� �������� ��쵵, ���ڷ� ���� pc �� ���� ������ ���� ���� ������ �ƿ� ó������ const ���ڷ� �޴´�. 
�̷��� �ȴٸ� �Ŀ� �߻� �� �� �ִ� �Ǽ����� ȿ�������� ���� �� �ִ�.
*/

/*
���� ���� ���� ���ǵ� ���� �����ڸ� ������ ��� �̿��ϴ��� ���캸���� ����.

Photon_Cannon pc1(3, 3);
Photon_Cannon pc2(pc1);

�ϴ� pc1 �� int x, int y �� ���ڷ� ������ �����ڰ� �����ε� �Ǿ���, 
pc2 �� ��� ���ڷ� pc1 �� �Ѱ����Ƿ� ���� �����ڰ� ȣ��Ǿ����� �� �� �ִ�.

Photon_Cannon pc3 = pc2;

�׷��ٸ� �� �ڵ�� ���? ����Ե�, �� �ڵ� ���� ���� �����ڰ� ȣ��ȴ�. 
C++ �����Ϸ��� �� ������ �Ʒ��� �����ϰ� �ؼ��Ѵ�.

Photon_Cannon pc3(pc2);

���� ���� �����ڰ� ȣ��ǰ� �Ǵ� ���̴�. ����, ���� ���־��� Ư���� ����. ���� �׳�

pc3 = pc2;

�� �ߴٸ� �̴� ����� ���� ���� �̰�����, ���� �ÿ� �����ϴ� ����, �� ���� ���� Photon_Cannon pc3 = pc2; �Ѵٸ�, 
���� �����ڰ� ȣ��ǰ� �Ǵ� ���̴�. 
�̷������� Photon_Cannon pc3 = pc2; �� �ؼ������ν� ����ڰ� ����� �������̰� ����� ���α׷����� �� �� �ִ�.

����� �� ���� �� �����ڸ�,

Photon_Cannon pc3 = pc2;

��

Photon_Cannon pc3;
pc3 = pc2;

�� ������ �ٸ� �����̴�. 
�ֳ��ϸ� ���� ���� �� �״�� ���� �����ڰ� 1 �� ȣ��Ǵ� ���̰�, �Ʒ� ���� �׳� �����ڰ� 1 �� ȣ��ǰ�, pc3 = pc2; ��� ����� ����Ǵ� ��. 
�ٽ� �� �� ����������, ���� �����ڴ� ���� '����' �ÿ� ȣ��ȴٴ� ���� ����ؾ� �Ѵ�.

�׷���, ��� ����Ʈ �����ڿ� ����Ʈ �Ҹ��� ó��, C++ �����Ϸ��� �̹� ����Ʈ ���� ������(Default copy constructor) �� ������ �ְ� �ִ�. 
�� �ڵ忡�� ���� �����ڸ� �� �� �������� �����غ���, ������ ��Ȯ�� ������ ����� ��Ÿ���� �� �� �ִ�. 
����Ʈ ���� �������� ��� ������ ����Ʈ �����ڿ� �Ҹ��ڰ� �ϴ� ���� �ƹ� �͵� ������ �Ͱ��� �޸� ������ '����' �� ���ش�.

���� �츮�� �� Photon_Cannon �� ����Ʈ ���� �������� ������ ������ ���ٸ�

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) 
{
  hp = pc.hp;
  shield = pc.shield;
  coord_x = pc.coord_x;
  coord_y = pc.coord_y;
  damage = pc.damage;
}

�� ���� ������ ���̴�. 
�����Ǵ� ���ҵ��� �� �״�� 1 �� 1 �������ְ� �ȴ�. 
���� ���� ���� ������ Ŭ������ ��� ������ ��������ڸ� ������ �ʰ� ����Ʈ ���� �����ڸ� �̿��ؼ� ���� ������ ���� ó���� �� �ִ�.
*/

/*
����Ʈ ���� �������� �Ѱ�

�̹����� ���� ���� ó�� ���� ĳ���� �̸��� ������ �� �ִٴ� ����� �˰� Ŭ���� Photon_Cannon �� char *name �� �߰� ���־���. 
�׸���, ���� �����ڴ� �׳� ������ ó�� ����Ʈ ���� �����ڸ� ����ϱ�� �ϸ�
*/

/*
// ����Ʈ ���� �������� �Ѱ�
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
  // 0 �� �ƴ� ���� if ������ true �� ó���ǹǷ�
  // 0 �ΰ� �ƴѰ��� ���� �� �׳� if(name) �ϸ�
  // if(name != 0) �� ������ �ǹ̸� ���� �� �ִ�.

  // ����� if �� ������ ������ 1 ���� �´ٸ�
  // �߰�ȣ�� ���� �����ϴ�.

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

������ �� �����غ��� �Ʒ��� ���� ������ ������ �� ���̴�.

���⼭ �츮�� ����Ʈ ���� �����ڰ� ��� ������� ���캸���� ����. 
�Ƹ��� ��������, �����Ϸ��� �����ϰ� 1 �� 1 ���縦 ���ִ� ����Ʈ ���� �����ڸ� �Ʒ��� ���� ����� �־��� ���̴�.

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) 
{
  hp = pc.hp;
  shield = pc.shield;
  coord_x = pc.coord_x;
  coord_y = pc.coord_y;
  damage = pc.damage;
  name = pc.name;
}

hp, shield, ... �׸��� name ���� ��� ���� ���� ���� �ȴ�. 
���⼭ name �� ���� �� - �� �� ���� �����Ͱ� ���� ���� ���� �ٴ� ���� ���� �ּ� ���� ����Ų�ٴ� ���� �ȴ�. 
��, �츮�� pc1 �� name �� �������� �Ҵ�޾Ƽ� ����Ű�� �ִ� �޸� ("Cannon" �̶�� ���ڿ��� ����� �޸�) �� pc2 �� name �� ���� ����Ű�� �Ǵ� ��.

���� �� ���¿����� �� ������ �ȵȴ�. ��, ���� �޸𸮸� �� ���� ���� �ٸ� �����Ͱ� �����ѵ� �Ǳ� �����ε�, ��¥ ������ �Ҹ��ڿ��� �Ͼ��.
main �Լ��� ����Ǳ� ������ �����Ǿ��� ��ü���� �ı��Ǹ鼭 �Ҹ��ڸ� ȣ���ϰ� �ȴ�. ���� ���� pc1 �� �ı��Ǿ��ٰ� �غ���.

Photon_Cannon::~Photon_Cannon() 
{
  if (name) delete[] name;
}

pc2 ���� �ϴ� name �� NULL �� �ƴϹǷ� (0x125ADD3 �̶�� �ּҰ��� ������ ����) delete [] name �� ����ǰ�, 
�̹� ������ �޸𸮿� �����ؼ� �ٽ� �����Ϸ��� �Ͽ��� ������ (��� ������ �� ��ü������ ����) �� �׸��� ���� ������ ��Ÿ�� ������ �߻��ϰ� �ȴ�. 
�׷��ٸ� �̷��� ������ �������� ��� �ؾ� �ұ�?

���� �����ڿ��� name �� �״�� �������� ���� ���� �ٸ� �޸𸮿� ���� �Ҵ��� �ؼ� �� ���븸 �����ϸ�?
�̷��� �޸𸮸� ���� �Ҵ��ؼ� ������ �����ϴ� ���� ���� ����(deep copy) ��� �θ��� �Ʊ� ó�� �ܼ��� ���� �� ���ִ� ���� ���� ����(shallow copy) ��� �θ���. 
�����Ϸ��� �����ϴ� ����Ʈ ���� �������� ��� ���� ���� �ۿ� �� �� �����Ƿ� ���� ���� ���� ���簡 �ʿ��� ��쿡�� ����ڰ� ���� ���� �����ڸ� ������ �Ѵ�.

�� ������ �׸����� �������ڸ� ���� �����ڿ��� hp, shield �� ���� ���� ���� ���� ���縦 ������, name �� ��� ���� �޸𸮸� �Ҵ��ؼ� �� ���븸 �����ϴ� ���� ���縦 �����ϰ� �Ǵ� ��. 
�׷��� �Ҹ��ڿ����� �޸� ������ ���� �ٸ� �޸𸮸� �����ϴ� ���̱� ������ ���� ������ �߻����� �ʴ´�. �̸� �������� ���� �����ڸ� ������ �Ʒ��� ����.
*/

/*
// ���� �������� �߿伺
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
  std::cout << "���� ������ ȣ��! " << std::endl;
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