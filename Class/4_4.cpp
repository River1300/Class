/* �þ�Դ� C++ - <4 - 4. ��Ÿũ����Ʈ�� ������ �� (const, static)> https://modoocode.com/197 */

// ������ �ʱ�ȭ ����Ʈ(initializer list)
// Ŭ������ const, static ����
// ���۷��� Ÿ���� �����ϴ� �Լ�
// this ������
// const ��� �Լ�

/*
�������� �ʱ�ȭ ����Ʈ(initializer list)

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

  int attack();                       // �������� �����Ѵ�.
  void be_attacked(int damage_earn);  // �Դ� ������
  void move(int x, int y);            // ���ο� ��ġ

  void show_status();  // ���¸� �����ش�.
};

Marine::Marine() : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {}

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), damage(5), is_dead(false) {}

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
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main() 
{
  Marine marine1(2, 3);
  Marine marine2(3, 5);

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

�� ���� �ȴ�.

������ ������� Marine Ŭ������ �޶��� ���� �� �ϳ��ε�, �ٷ� �����ڿ��� ���� Ư���� ���� �����ߴٴ� ��.
*/

/*
Marine::Marine() : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {}

����Ե� �Լ� ��ü���� �ƹ��͵� ����. 
����, ���� �߰��� �̻��� �͵��� ������ �����ڰ� �ߴ� �ϰ� ������ �۾��� �ϰ� ���� ���̴�. 
������ �����ڴ�

Marine::Marine() 
{
  hp = 50;
  coord_x = coord_y = 0;
  damage = 5;
  is_dead = false;
}
�� ����µ�, �� ���ο��� �ϴ� ��� �������� �ʱ�ȭ �۾����� ���Ӱ� �߰��� �͵��� ����ؼ� �ϰ� ���� ���̴�.

���� ���� ������ �̸� �ڿ�

: hp(50), coord_x(0), coord_y(0),
damage(5), is_dead(false) {}

�� ���� ���� �ʱ�ȭ ����Ʈ (initializer list) ��� �θ���, ������ ȣ��� ���ÿ� ��� �������� �ʱ�ȭ���ְ� �ȴ�.

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), damage(5), is_dead(false) {}

������ coord_x �� x �� �ʱ�ȭ �ǰ�, is_dead �� false �� �ʱ�ȭ �ǰ� �˴ϴ�.

��� �ʱ�ȭ ����Ʈ�� �Ϲ����� ���� �Ʒ��� ����.

(������ �̸�) : var1(arg1), var2(arg2) {}

���⼭ var ���� Ŭ������ ��� �������� ��Ī�ϰ�, arg �� �� ��� �������� �������� �ʱ�ȭ �� �� ��Ī�ϴ� ������ �Ѵ�. 
�� ���� ��̷ο� ���� var1 �� arg1 �� �̸��� ���Ƶ� �Ǵµ�, ������ �Ʒ��� ������

Marine::Marine(int coord_x, int coord_y)
    : coord_x(coord_x), coord_y(coord_y), hp(50), damage(5), is_dead(false) {}

���������� �۵��Ѵ�. �ֳ��ϸ� coord_x ( coord_x ) ���� �ٱ����� coord_x �� ������ ��� ������ ��Ī�ϰ� �Ǵµ�, 
�� ��� coord_x �� ��Ī�ϴ� ���̰�, ��ȣ ���� coord_x �� ��Ģ�� Marine �� ���ڷ� ���� coord_x �� �켱������ ��Ī�ϴ� ���̱� �����̴�.

���� ������, ���ڷ� ���� coord_x �� Ŭ������ ��� ���� coord_x �� �ʱ�ȭ �ϰ� �ȴ�. 
�Ʒ��� �翬�� ��� ������

Marine::Marine(int coord_x, int coord_y) 
{
  coord_x = coord_x;
  coord_y = coord_y;
  hp = 50;
  damage = 5;
  is_dead = false;
}

�����Ϸ��� �� coord_x ��� ���ڷ� ���� coord_x �� �����ؼ� ������ ����.

�׷��ٸ�, �� ����ü �ʱ�ȭ ����Ʈ�� ����ؾ� �ǳİ� ���� �� �ִ�. 
�ֳ��ϸ�

Marine::Marine() 
{
  hp = 50;
  coord_x = coord_y = 0;
  damage = 5;
  is_dead = false;
}

��

Marine::Marine() : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {}

�� �ϴ� ���� �Ȱ��� ���̱� �����̴�. 
������ ������ �ణ�� ���̰� �ִ�. 
�ʱ�ȭ ����Ʈ�� ����� ������ ��� ������ �ʱ�ȭ�� ���ÿ� �ϰ� �ȴ�.

�ݸ鿡 �ʱ�ȭ ����Ʈ�� ������� �ʴ´ٸ� ������ ���� �ϰ� �� ������ ���� �� �����ϰ� �ȴ�. 
���� ���ϸ� �ʱ�ȭ ����Ʈ�� ����ϴ� ����

int a = 10;

�̶� �ϴ� �Ͱ� ����, �׳� ���� ������ �����ڸ� ����ϴ� ����

int a;
a = 10;

�̶� �ϴ� �Ͱ� �����ϴٴ� ��. 
���࿡ int �� ��ſ� Ŭ���� ���ٸ�, ������ ��� ���� ������ �� ȣ��Ǵµ�, 
������ ��� ����Ʈ �����ڰ� ȣ��� �� ������ ����ȴٴ� �̾߱Ⱑ �ȴ�.

�� ���Ƶ� ���ڰ� ���� �� �ϴ� �۾��� ���� �ȴ�. 
���� �ʱ�ȭ ����Ʈ�� ����ϴ� ���� ���� �� ȿ������ �۾��̶�� ����� �� �� �ִ�. 
�� �Ӹ� �ƴ϶�, �츮 ����� �ݵ�� '������ ���ÿ� �ʱ�ȭ �Ǿ�� �ϴ� �͵�' �� �� ���� �ִ�. 
��ǥ������ ���۷����� ����� �ִ�.

�ռ� ��� �ٿ� ������ ����� ���۷������� ��� ������ ���ÿ� �ʱ�ȭ�� �Ǿ�� �Ѵ�.

��� ������ ������ �� �� �ִ�. 
���� ���࿡ Ŭ���� ���ο� ���۷��� ������ ����� �ְ� �ʹٸ� �̵��� �����ڿ��� ������ �ʱ�ȭ ����Ʈ�� ����ؼ� �ʱ�ȭ �����־�߸� �Ѵ�.
*/

/*
#include <iostream>

class Marine 
{
  int hp;                // ���� ü��
  int coord_x, coord_y;  // ���� ��ġ
  bool is_dead;

  const int default_damage;  // �⺻ ���ݷ�

 public:
  Marine();              // �⺻ ������
  Marine(int x, int y);  // x, y ��ǥ�� ���� ����

  int attack();                       // �������� �����Ѵ�.
  void be_attacked(int damage_earn);  // �Դ� ������
  void move(int x, int y);            // ���ο� ��ġ

  void show_status();  // ���¸� �����ش�.
};

Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {}

void Marine::move(int x, int y) 
{
  coord_x = x;
  coord_y = y;
}

int Marine::attack() { return default_damage; }

void Marine::be_attacked(int damage_earn) 
{
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;
}

void Marine::show_status() 
{
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main() 
{
  Marine marine1(2, 3);
  Marine marine2(3, 5);

  marine1.show_status();
  marine2.show_status();

  std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;
  marine2.be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}

���������� ������ �Ͽ��ٸ�

���� ���

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
�� �ȴ�.

�� ���� Ŭ������ ���α׷��ӵ��� �Ǽ��� ������ ���ݷ��� �̻��ϰ� ���ϴ� ���� ���� ���ؼ� �⺻ ���ݷ��̶�� ��� ����� �����ؼ�, 
�� ���� ���� ������ ���� ���ϰ� ���α׷��� �� �� �ֵ��� �Ͽ���. 
���� �̸� ���� �����ڿ��� �ʱ�ȭ ����Ʈ�� �����ؼ�

Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}

�� ����, default_damage �� ������ ���ÿ� �ʱ�ȭ �� �� �ֵ��� �Ͽ���. 
���� �츮�� ����� default_damage �� 5 �� �ʱ�ȭ �� �� �ְ�, �� ���� ������ �ٲ��� �ʰ� �ȴ�.

Marine marine1(2, 3);
Marine marine2(3, 5);

marine1.show_status();
marine2.show_status();

���� ���� Marine �� ��ü�� (marine1, marine2) �� �����ϸ鼭 ������ �����ε��� ���� Marine(int x, int y) �� ȣ��Ǵµ�, 
�̸� ���� ���� (2,3) �� (3,5) �� ��ġ�� �ִ� ���� ��ü���� ���� �� �ְ� �Ǿ���. 
�׸���, show_status �� ȣ���� ���� �̵��� ����� ���� �Ǿ� �ִٴ� ����� �� �� �ִ�.

std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;
marine2.be_attacked(marine1.attack());

���������� Marine ��ü���� ���� �����ϴ� ������ �� ����ǰ� ������ �� �� �ִ�.

���� ���� �߿��� ������ ����� ó���ϴ� ���� �ſ� ������ ���̴�. 
�ٸ� ���α׷��Ӱ� �� Ŭ������ ����ϸ鼭 �Ǽ��� marine �� default_damage �� �����ϴ� ����� ���� �ִ���� ������ ������ �߻��ϱ� ������ 
���α׷��� �����ؼ� ������ ����� ������ ���ļ� �˾� ���� �� ���� �ξ� ȿ�������� ������ �߰��� �� �ִ�.
*/

/*
#include <iostream>

class Marine 
{
  int hp;                // ���� ü��
  int coord_x, coord_y;  // ���� ��ġ
  bool is_dead;

  const int default_damage;  // �⺻ ���ݷ�

 public:
  Marine();              // �⺻ ������
  Marine(int x, int y);  // x, y ��ǥ�� ���� ����
  Marine(int x, int y, int default_damage);

  int attack();                       // �������� �����Ѵ�.
  void be_attacked(int damage_earn);  // �Դ� ������
  void move(int x, int y);            // ���ο� ��ġ

  void show_status();  // ���¸� �����ش�.
};

Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false) {}

void Marine::move(int x, int y) 
{
  coord_x = x;
  coord_y = y;
}

int Marine::attack() { return default_damage; }

void Marine::be_attacked(int damage_earn) 
{
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;
}

void Marine::show_status() 
{
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main() 
{
  Marine marine1(2, 3, 10);
  Marine marine2(3, 5, 10);

  marine1.show_status();
  marine2.show_status();

  std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;
  marine2.be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}

���������� ������ �Ͽ��ٸ�

���� ���

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
 HP : 40

�� ���������� ������ �ϳ��� ���� �� �߰��Ͽ��µ�

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false) {}

�������� default_damage �� �ʱ�ȭ ����Ʈ�� 5 �� �����Ͽ��µ�, 
�� �������� ��� � ���� ������ �� ���ڷ� ���� ������ �� ������ ����� �־��־���. 
���������� �̴�

const int default_damage = (���ڷ� ���� default_damage);

�� ������ �Ͱ� �������� �̱� ������ �� �۵����� �� �� �ִ�. 
�׸���, ������ 5 �� �ƴ� 10 �� HP �� ������ show_status �� ���� Ȯ�� �� �� �ִ�.
*/

/*
������ �� `Marine` �� ���� (static ����)

�̹����� ���±��� ��������� �� Marine �� ���� �˾Ƴ��� ���� �ڵ带 §�ٰ� �����غ���. 
�̸� ���ؼ��� ���� ����� �ְ����� ���� �ܼ��� �� ����� �����غ��ٸ�

��� �迭�� Marine �� ������ ����, ������ ������ ������ ��� ����.
� ������ ���� Marine �� �����ÿ� 1 �� �߰��ϰ�, �Ҹ�ÿ� 1 �� ����.

�� ������ �� ���� ���̴�. 
ù ��° ����� ���, ũ�Ⱑ ��������� ���� �� �ִ� �迭�� ���� ������ �ϴ� �������� �ְ�, 
�� ��°�� ���� ��� ���� ��� �Լ� ������ �̷� ������ �����Ͽ��ٸ� �ٸ� �Լ������� �� ���� �̿��ϱ� ���� ���ڷ� ��� �����ؾ� �ϴ� �������� �ִ�.

���� ���� ������ ����� ���� �ʰڳİ� ���� �� �� �ְ�����, 
���� ������ ��� ������Ʈ�� ũ�Ⱑ Ŀ�� �� �� ���α׷����� �Ǽ��� ���� ���� ���ļ� ������ �� ���ɼ��� �ٺ��ϱ⿡ 
�ݵ�� �ʿ��� ��찡 �ƴϸ� ����� ���� �ʴ´�.

������ C++ ������ ���� ���� ������ �����ϰ� �ذ� �� �� �ִ� ����� �����ϰ� �ִ�. 
��ġ ���� ���� ������ Ŭ���� �ϳ����� ���ӵǴ� ������ ���ε�, �ٷ� static ��� ������.

������ C ���� ��� �Լ��� static ���� (���� ����) �� ���� ������ ó�� �Լ��� ����� �� �Ҹ�Ǵ� ���� �ƴ϶� ���α׷��� ����� �� �Ҹ�Ǵ� �� ó��, 
� Ŭ������ static ��� ������ ���, ��� ������ ó��, ��ü�� �Ҹ�� �� �Ҹ�Ǵ� ���� �ƴ�, ���α׷��� ����� �� �Ҹ�ȴ�.

����, �� static ��� ������ ���, Ŭ������ ��� ��ü���� '����' �ϴ� �����ν� �� ��ü ���� ���� �����ϴ� ��� ��������� �޸� ��� ��ü���� '�ϳ���' static ��� ������ ����ϰ� �ȴ�. 
�׷� �ٷ� �Ʒ��� ������ ���� ����.

#include <iostream>

class Marine 
{
  static int total_marine_num;

  int hp;                // ���� ü��
  int coord_x, coord_y;  // ���� ��ġ
  bool is_dead;

  const int default_damage;  // �⺻ ���ݷ�

 public:
  Marine();              // �⺻ ������
  Marine(int x, int y);  // x, y ��ǥ�� ���� ����
  Marine(int x, int y, int default_damage);

  int attack();                       // �������� �����Ѵ�.
  void be_attacked(int damage_earn);  // �Դ� ������
  void move(int x, int y);            // ���ο� ��ġ

  void show_status();  // ���¸� �����ش�.

  ~Marine() { total_marine_num--; }
};

int Marine::total_marine_num = 0;

Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) 
{
  total_marine_num++;
}

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) 
{
  total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false)
{
  total_marine_num++;
}

void Marine::move(int x, int y) 
{
  coord_x = x;
  coord_y = y;
}

int Marine::attack() { return default_damage; }

void Marine::be_attacked(int damage_earn) 
{
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;
}

void Marine::show_status() 
{
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
  std::cout << " ���� �� ���� �� : " << total_marine_num << std::endl;
}

void create_marine() 
{
  Marine marine3(10, 10, 4);
  marine3.show_status();
}

int main() 
{
  Marine marine1(2, 3, 5);
  marine1.show_status();

  Marine marine2(3, 5, 10);
  marine2.show_status();

  create_marine();

  std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;
  marine2.be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}

���������� ������ �Ͽ��ٸ�

���� ���

 *** Marine ***
 Location : ( 2 , 3 )
 HP : 50
 ���� �� ���� �� : 1
 *** Marine ***
 Location : ( 3 , 5 )
 HP : 50
 ���� �� ���� �� : 2
 *** Marine ***
 Location : ( 10 , 10 )
 HP : 50
 ���� �� ���� �� : 3

���� 1 �� ���� 2 �� ����!
 *** Marine ***
 Location : ( 2 , 3 )
 HP : 50
 ���� �� ���� �� : 2
 *** Marine ***
 Location : ( 3 , 5 )
 HP : 45
 ���� �� ���� �� : 2

�� ���� ������ �ȴ�.

static int total_marine_num;

���� ���� ���� Ŭ���� static ������ �����Ͽ���. 
��� ���� �� static �������� ���ǿ� ���ÿ� ���� �ڵ����� 0 ���� �ʱ�ȭ �Ǳ� ������ �� ��� �츮�� ���� ���� 
�ʱ�ȭ ���� �ʾƵ� ������ Ŭ���� static �������� ��� �Ʒ��� ���� ������� �ʱ�ȭ �Ѵ�.

int Marine::total_marine_num = 0;

��Ȥ � ������� ��� Ŭ���� ���ο���

class Marine {
  static int total_marine_num = 0;

�� ���� �ʱ�ȭ �ص� ���� �ʳİ� ���� ��찡 �ִµ�, 
��� �������� ���� ���� �ʱ�ȭ ��Ű�� ���ϴ� ��ó�� static ���� ���� Ŭ���� ���ο��� ���� ���� �ʱ�ȭ �ϴ� ���� �Ұ��� �ϴ�. 
���� ���� ���� �Ǵ������� ���� const static ������ ���� �����ѵ�, ������

class Marine {
  const static int x = 0;

���� �� �� �ִ�.

�׷� ������ total_marine_sum �� �� �۵��ϰ� �ִ��� ���캸��. 
Ŭ������ ���� ���� �����ڿ� �Ҹ��ڸ� �����Ѵٴ� ���ε�, ���п� Marine �� ������ ��, 
�׸��� �Ҹ�� �� ���� ���� ó������ �ʰ�, 
�����ڿ� �Ҹ��� �ȿ� total_marine_num �� �����ϴ� ������ �־��ָ� ���ϰ� ó���� �� �ִ�. 
�� ���

Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) 
{
  total_marine_num++;
}

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) 
{
  total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false) 
{
  total_marine_num++;
}

�� �� ������ ȣ�� �ÿ� total_marine_num �� 1 �� ������Ű�� ������ �־���,

~Marine() { total_marine_num--; }

�Ҹ� �ɶ��� 1 ���ҽ�Ű�� ������ �ִ´�.

Marine marine1(2, 3, 5);
marine1.show_status();

Marine marine2(3, 5, 10);
marine2.show_status();

���� ���� �����ϸ� ������ �� Marine �� ���� 1, 2 �þ�� ���� Ȯ���� �� �ְ�, 
�� ������ create_marine �� �����Ͽ��� ��

void create_marine() 
{
  Marine marine3(10, 10, 4);
  marine3.show_status();
}

���� marine3 �� ���������ν� �� marine �� ���� 3 �� ���� Ȯ���� �� �ִµ�, marine3 �� create_marine �� ���� ��ü�̱� ������ create_marine �� ����� �� �Ҹ�ǰ� �˴ϴ�. ���� �ٽ� main �Լ��� ���ƿͼ�

std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;
marine2.be_attacked(marine1.attack());

marine1.show_status();

���� �� �������� ǥ���� �� 2 ������ ������ �ȴ�.

�׷��� Ŭ���� �ȿ� static ���� �� ���� �� �ִ� ���� �ƴϴ�. 
����Ե� Ŭ���� �ȿ��� static �Լ��� ������ �� �ִµ�, 
static ������ ��� ��ü�� ���ӵǴ� ���� �ƴ϶�, �׳� Ŭ���� ��ü�� �� 1 �� �����ϴ� ���� �� ó��, 
static �Լ� ���� � Ư�� ��ü�� ���ӵǴ� ���� �ƴ϶� Ŭ���� ��ü�� �� 1 �� �����ϴ� �Լ���.
*/

/*
��, static �� �ƴ� ��� �Լ����� ��� ��ü�� ���������� �� ��� �Լ����� ȣ���� �� ������ static �Լ��� ���, 
��ü�� ��� �׳� Ŭ���� ��ü���� ȣ���� �� �ְ� �ȴ�.

#include <iostream>

class Marine 
{
  static int total_marine_num;
  const static int i = 0;

  int hp;                // ���� ü��
  int coord_x, coord_y;  // ���� ��ġ
  bool is_dead;

  const int default_damage;  // �⺻ ���ݷ�

 public:
  Marine();              // �⺻ ������
  Marine(int x, int y);  // x, y ��ǥ�� ���� ����
  Marine(int x, int y, int default_damage);

  int attack();                       // �������� �����Ѵ�.
  void be_attacked(int damage_earn);  // �Դ� ������
  void move(int x, int y);            // ���ο� ��ġ

  void show_status();  // ���¸� �����ش�.
  static void show_total_marine();
  ~Marine() { total_marine_num--; }
};

int Marine::total_marine_num = 0;

void Marine::show_total_marine() {
  std::cout << "��ü ���� �� : " << total_marine_num << std::endl;
}

Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false) {
  total_marine_num++;
}

void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}

int Marine::attack() { return default_damage; }

void Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
  std::cout << " ���� �� ���� �� : " << total_marine_num << std::endl;
}

void create_marine() {
  Marine marine3(10, 10, 4);
  Marine::show_total_marine();
}

int main() 
{
  Marine marine1(2, 3, 5);
  Marine::show_total_marine();

  Marine marine2(3, 5, 10);
  Marine::show_total_marine();

  create_marine();

  std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;
  marine2.be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}

���������� ������ �Ͽ��ٸ�

���� ���

��ü ���� �� : 1
��ü ���� �� : 2
��ü ���� �� : 3

���� 1 �� ���� 2 �� ����!
 *** Marine ***
 Location : ( 2 , 3 )
 HP : 50
 ���� �� ���� �� : 2
 *** Marine ***
 Location : ( 3 , 5 )
 HP : 45
 ���� �� ���� �� : 2

�� ���� ���´�.

static �Լ��� �տ��� �̾߱� �� �Ͱ� ����, 
� ��ü�� ���ӵǴ� ���� �ƴ϶� Ŭ������ ���ӵǴ� ������, �̸� ȣ���ϴ� ����� (��ü).(��� �Լ�) �� �ƴ϶�,

Marine::show_total_marine();

�� ���� (Ŭ����)::(static �Լ�) �������� ȣ���ϰ� �ȴ�. 
�ֳ��ϸ� ��� ��ü�� �� �Լ��� �����ϰ� ���� �ʱ� �����̴�. 
�׷��ϱ⿡, static �Լ� �������� Ŭ������ static ���� ���� �̿��� �� �ۿ� ����. 
���� static �Լ� ������ �Ʒ�ó�� �׳� Ŭ������ ��� �������� �̿��Ѵٸ�

void Marine::show_total_marine() 
{
  std::cout << default_damage << std::endl;  // default_damage �� ��� ����
  std::cout << "��ü ���� �� : " << total_marine_num << std::endl;
}
default_damage �� ������ default_damage ���� �ƹ��� �𸣴� ��Ȳ�� �߻��Ѵ�. 
��, � ��ü�� default_damage ���� static ������ show_total_marine() �� �� �� ���Եȴ�. 
�ֳ��ϸ� �տ��� ��� ���ؿԵ��� � ��ü���� �������� �ʱ� �����̴ϱ�.
*/

/*
this

#include <iostream>

class Marine 
{
  static int total_marine_num;
  const static int i = 0;

  int hp;                // ���� ü��
  int coord_x, coord_y;  // ���� ��ġ
  bool is_dead;

  const int default_damage;  // �⺻ ���ݷ�

 public:
  Marine();              // �⺻ ������
  Marine(int x, int y);  // x, y ��ǥ�� ���� ����
  Marine(int x, int y, int default_damage);

  int attack();                          // �������� �����Ѵ�.
  Marine& be_attacked(int damage_earn);  // �Դ� ������
  void move(int x, int y);               // ���ο� ��ġ

  void show_status();  // ���¸� �����ش�.
  static void show_total_marine();
  ~Marine() { total_marine_num--; }
};

int Marine::total_marine_num = 0;

void Marine::show_total_marine() 
{
  std::cout << "��ü ���� �� : " << total_marine_num << std::endl;
}

Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y)
    : coord_x(x),
      coord_y(y),
      hp(50),

      default_damage(5),
      is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false) {
  total_marine_num++;
}

void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}

int Marine::attack() { return default_damage; }

Marine& Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;

  return *this;
}

void Marine::show_status() {
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
  std::cout << " ���� �� ���� �� : " << total_marine_num << std::endl;
}

int main() 
{
  Marine marine1(2, 3, 5);
  marine1.show_status();

  Marine marine2(3, 5, 10);
  marine2.show_status();

  std::cout << std::endl << "���� 1 �� ���� 2 �� �� �� ����! " << std::endl;
  marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}

���������� ������ �Ͽ��ٸ�

���� ���

 *** Marine ***
 Location : ( 2 , 3 )
 HP : 50
 ���� �� ���� �� : 1
 *** Marine ***
 Location : ( 3 , 5 )
 HP : 50
 ���� �� ���� �� : 2

���� 1 �� ���� 2 �� �� �� ����!
 *** Marine ***
 Location : ( 2 , 3 )
 HP : 50
 ���� �� ���� �� : 2
 *** Marine ***
 Location : ( 3 , 5 )
 HP : 40
 ���� �� ���� �� : 2
�� ���� ���ɴϴ�.

�ϴ� ���� ���� ���� ��� ���� �ٷ� ���۷����� �����ϴ� �Լ��� this

Marine& Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;

  return *this;
}

�ϴ� this ��� ���� C++ ��� �������� ���ǵǾ� �ִ� Ű���� �ε�, 
�̴� ��ü �ڽ��� ����Ű�� �������� ������ �Ѵ�. 
��, �� ��� �Լ��� ȣ���ϴ� ��ü �ڽ��� ����Ų�ٴ� ��. 
����, ������ �� ������

Marine& Marine::be_attacked(int damage_earn) {
  this->hp -= damage_earn;
  if (this->hp <= 0) this->is_dead = true;

  return *this;
}

�� ������ �ǹ̰� �ȴ�. 
������ ��� ��� �Լ� �������� this Ű���尡 ���ǵǾ� ������ Ŭ���� �ȿ��� ���ǵ� �Լ� �߿��� this Ű���尡 ���� �Լ��� static �Լ� ���̴�.

�׷��� ���� Marine& �� �����Ѵٴ� ���� ����ü �������� �����غ���. 
���� ���¿��� ��� �ٿ� ������ ���۷������ ���� � ������ �ٸ� �����̶�� �ߴ�. (������ ���۷����� ����(alias) ��� �θ��⵵ �Ѵ�)

�׷���, �� ������ �����Ѵٴ�, ���� ���ϱ�? 
'���۷����� �����ϴ� �Լ�' �� ���� �˾ƺ��� ���� �Ʒ��� ���� ©���� ���� Ŭ������ ���캸���� ����.
*/

/*
���۷����� �����ϴ� �Լ�

#include <iostream>

class A 
{
  int x;

 public:
  A(int c) : x(c) {}

  int& access_x() { return x; }
  int get_x() { return x; }
  void show_x() { std::cout << x << std::endl; }
};

int main() 
{
  A a(5);
  a.show_x();

  int& c = a.access_x();
  c = 4;
  a.show_x();

  int d = a.access_x();
  d = 3;
  a.show_x();

  // �Ʒ��� ����
  // int& e = a.get_x();
  // e = 2;
  // a.show_x();

  int f = a.get_x();
  f = 1;
  a.show_x();
}

���������� ������ �Ͽ��ٸ�

���� ���

5
4
4
4
�� ���� ���´�. 
�ϴ� �� Ŭ���� A �� �Ʒ��� ���� int �� int �� ���۷����� �����ϴ� �� ���� �Լ��� ������ �ִ�.

int& access_x() { return x; }
int get_x() { return x; }
access_x �� x �� ���۷����� �����ϰ� �ǰ�, get_x �� x �� '��' �� �����ϰ� �ȴ�. 
������ �̵��� ��� �۵��ϴ��� ���캸��.

int& c = a.access_x();
c = 4;
a.show_x();

���⼭ ���۷��� c �� x �� ���۷���, �� x �� ������ �޾Ҵ�. 
����, c �� x �� �������� ź���ϰ� �Ǵ� ���̴�.
���۷����� �����ϴ� �Լ��� �� �Լ� �κ��� ������ ������ ġȯ�ߴٰ� �����ص� ����� ����. 
�ٽ� ���ؼ�

int &c = x;  // ���⼭ x �� a �� x

�� ������ ���̶�� ���̴�. 
���� c �� ���� �ٲٴ� ���� a �� x �� ���� �ٲٴ� �Ͱ� ������ �ǹ��̹Ƿ� (c �� �ܼ��� x �� �ٸ� �̸��� �ٿ��� ���ϻ�!) 
show_x �� ���� �ÿ� x �� ���� 5 ���� 4 �� �ٲ������ �� �� �ִ�. 
�׷��ٸ� �Ʒ� ���� ���캼��.

int d = a.access_x();
d = 3;
a.show_x();

�̹����� int& �� �ƴ� �׳� int ������ 'x �� ����' �� �����Ͽ���. 
���� d �� int& ���ٸ� x �� ������ �޾Ƽ� d ���� �� �ٸ� x �� ������ �Ǿ�������, d �� �׳� int ���� �̹Ƿ�, 
���� ���簡 �Ͼ d ���� x �� ���� ���� �ȴ�. 
�׸��� �翬��, d �� x �� ������ �ƴ� �� �ٸ� �������� ���� �̱⿡, 
d = 3; �� �ص� x �� ���� �ٲ��� ���� ä, �׳� 4 �� ��µǰ� �ȴ�.

�׷� �ּ� ó���� �� ���� ���캾�ô�. �ּ��� Ǯ�� �������� �ȵǹǷ� �ּ� ó�� �� ���� ���ε�, ������ �ּ��� Ǯ�� �������� �غ���

error C2440: 'initializing' : cannot convert from 'int' to 'int &'

�Ʒ��� ���� ������ �߻��Ѵ�. 
�� ������ ���۷����� �ƴ� Ÿ���� �����ϴ� ���� '��' �� ���簡 �̷������ ������ �ӽ� ��ü�� �����Ǵµ�, �ӽð�ü�� ���۷����� ���� �� ���� �����̴�. 
(�ӽð�ü�� ������ ������ �Ǹ� �Ҹ�ȴ�)

get_x �� �������� ���� �ӽ÷� '�������' �� int �� a.get_x() �κ��� ��ü�ϸ� �� �׸��� ���

int &e = x
�� ���� �Ǵµ�, x' �� ������ ���� �� �ڵ����� �Ҹ�Ǵ� �ӽ� ��ü �̱� ������ ���۷����� ���� �� ����. 
���� ���۷����� ������ٰ� �ص� '�̹� �������� �ʴ� �Ϳ� ���� ����' �� �ǹǷ� �� ���۷����� �����ϴ� ���� ������ �ȴ�.

�̷��� ������ int �� �����ϴ� a.get_x �� ���ؼ��� ���۷����� ���� �� ����. 
(��Ȯ�� ������ ���ڸ� int& �� �������� ���� ���۷��� �̰�, a.get_x() �� ������ �̱� ������ ���۷����� ���� �� ����.)

int f = a.get_x();
f = 1;
a.show_x();

���������� �� �ڵ�� ���� ���Դ� �� ó��, 
�ӽ÷� ������ int ���� (�� �׸������� x') �� f �� ����Ǵµ�, ���� f = 1 �� ���� ���� ��ü a �� x ���Դ� �ƹ��� ������ ��ĥ �� ����. 
�� ���� ����ִ� ����

a.access_x() = 3;

�� ������ �� �۵��Ѵٴ� ���ε�, �տ����� �������� '���۷����� �����ϴ� �Լ��� �� �Լ� �κ��� �����ϴ� ���� ������ ġȯ�ص� �ȴ�' ��� ���� ��Ȯ�� ���´� �ٴ� ���̴�. 
��, �� ������ �ᱹ

a.x = 3;

�� ������ ���� �ȴ�. 
�� �� �ݸ�, �� �˰� �ֵ���

a.get_x() = 3;

�� ���� ������ ���� �Ǵµ�, 
�ֳ��ϸ� a.get_x() �� get_x() �� �����ϸ鼭 �����Ǵ� �ӽ� ��ü (x') ���� ġȯ�Ǹ� �ӽð�ü�� ������ �ϰ� �Ǵ� ������� ��Ȳ�� �߻��ϰ� �ȴ�.

Marine& Marine::be_attacked(int damage_earn) 
{
  this->hp -= damage_earn;
  if (this->hp <= 0) this->is_dead = true;

  return *this;
}

�� ��� be_attacked �Լ��� Marine& Ÿ���� �����ϰ� �Ǵµ�, 
�� ���, *this �� �����ϰ� �ȴ�. 
�տ����� �������� this �� ���� �� �Լ��� ȣ���� ��ü�� ����Ű�Ƿ� *this �� �� ��ü �ڽ��� �ǹ��ϰ� �ȴ�. 
����,

marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

������ ���, ���� marine2.be_attacked(marine1.attack()) �� ���� ����ǰ� ���ϵǴ� ���� 
�ٽ� marine2 �̹Ƿ� �� ������ �� �� ��marine2.be_attacked(marine1.attack()) �� ����ȴٰ� ������ �� �ִ�.

����, be_attacked �Լ��� ���� Ÿ���� Marine& �� �ƴ϶� �׳� Marine �̶�� �غ���. 
��, ���� be_attacked �Լ��� �Ʒ��� ���� �ٲ���ٰ� �����Ѵٸ�

MarineMarine::be_attacked(int damage_earn) {
  this->hp -= damage_earn;
  if (this->hp <= 0) this->is_dead = true;

  return *this;
}

���� �ٲ� �Լ��� ������

marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

�� �����غ��� marine2 �� ������ �� �� ������ �ƴ� 1 �� �������� ������ HP ���� ���δ�. 
(�� 40 �� �ƴ� 45 �� ����) �̴� �տ����� �����ߵ��� ����Ÿ���� Marine �̹Ƿ�, �ӽ� ��ü Marine �� �����ؼ�, 
*this �� �������� ���簡 �ǰ� (��, Marine �� ���� ������ ȣ��) �� �ӽ� ��ü�� ���� be_attacked �Լ��� ȣ��ǰ� �Ǵ� ���̴�.

���� �ᱹ �� ��° be_attacked �� marine2 �� �ƴ� ������ �ӽ� ��ü�� ���� ȣ��Ǵ� ���̹Ƿ� �ᱹ marine2 �� marine1 �� ������ 1 ���� �ް� �ȴ�.
*/

/*
const �Լ�

C++ ������ �������� ���� �ٲ��� �ʰ� �б� �� �ϴ�, 
��ġ ��� ���� ��� �Լ��� ��� �Լ� �ν� ������ �� �ִ�. 

#include <iostream>

class Marine 
{
  static int total_marine_num;
  const static int i = 0;

  int hp;                // ���� ü��
  int coord_x, coord_y;  // ���� ��ġ
  bool is_dead;

  const int default_damage;  // �⺻ ���ݷ�

 public:
  Marine();              // �⺻ ������
  Marine(int x, int y);  // x, y ��ǥ�� ���� ����
  Marine(int x, int y, int default_damage);

  int attack() const;                    // �������� �����Ѵ�.
  Marine& be_attacked(int damage_earn);  // �Դ� ������
  void move(int x, int y);               // ���ο� ��ġ

  void show_status();  // ���¸� �����ش�.
  static void show_total_marine();
  ~Marine() { total_marine_num--; }
};

int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
  std::cout << "��ü ���� �� : " << total_marine_num << std::endl;
}

Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y)
    : coord_x(x),
      coord_y(y),
      hp(50),

      default_damage(5),
      is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false) {
  total_marine_num++;
}

void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}

int Marine::attack() const { return default_damage; }

Marine& Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;

  return *this;
}

void Marine::show_status() {
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
  std::cout << " ���� �� ���� �� : " << total_marine_num << std::endl;
}

int main() 
{
  Marine marine1(2, 3, 5);
  marine1.show_status();

  Marine marine2(3, 5, 10);
  marine2.show_status();

  std::cout << std::endl << "���� 1 �� ���� 2 �� �� �� ����! " << std::endl;
  marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}

���������� ������ �Ͽ��ٸ�

���� ���

 *** Marine ***
 Location : ( 2 , 3 )
 HP : 50
 ���� �� ���� �� : 1
 *** Marine ***
 Location : ( 3 , 5 )
 HP : 50
 ���� �� ���� �� : 2

���� 1 �� ���� 2 �� �� �� ����!
 *** Marine ***
 Location : ( 2 , 3 )
 HP : 50
 ���� �� ���� �� : 2
 *** Marine ***
 Location : ( 3 , 5 )
 HP : 40
 ���� �� ���� �� : 2

�� ���� ���´�. 
��� �� �ҽ��� ���� �ٲ� ���� ����, �ܼ��� ���ø� ���� �Ʒ��� ���� attack �Լ��� ��¦ �ٲپ���.

int attack() const;  // �������� �����Ѵ�.

�ϴ� ��� �Լ��� ���� ���� ���·� ������ �ϰ� �ȴ�. 
��,

(������ �Լ��� ����) const;

�׸��� �Լ��� ���� ���� const Ű���带 �� �־��־�� �ϴµ�, �Ʒ��� ���� ���̴�.

int Marine::attack() const { return default_damage; }

�׷��� �Ͽ����� �� attack �Լ��� '��� ��� �Լ�' �� ���ǵ� ���̴�. 
�츮�� ��� �Լ��� �� �Լ��� ���������ν�, �� �Լ��� �ٸ� ������ ���� �ٲ��� �ʴ� �Լ���� �ٸ� ���α׷��ӿ��� ��� ��ų �� �ִ�. 
�翬�ϰԵ�, ��� �Լ� �������� ��ü���� '�б�' ���� ����Ǹ�, ��� �Լ� ������ ȣ�� �� �� �ִ� �Լ��δ� �ٸ� ��� �Լ� �ۿ� ����.

��� ���� ��� Ŭ������ ������ ��, ��� �������� ��� private �� �ְ�, 
�� �������� ���� �����ϴ� ������� get_x �Լ� ó�� �Լ��� public �� �־� �� �Լ��� �̿��ذ��� ���Ϲ޴� ������ ���� ����Ѵ�. 
�̷��� �ϸ� ��� �������� private �� �������ν� �Ժη� ������ �����ϴ� ���� ����, �� �� ���� �����Ӱ� ���� �� �ְ� �ȴ�.
*/