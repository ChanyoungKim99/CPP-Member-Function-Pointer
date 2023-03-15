#include <iostream>

class MyClass
{
public:
	int SquareFunction(int x)		
	{
		return x * x;
	}
};

// �Ű����� int, ��ȯŸ�� int�� ������ �Լ� = int (*f) (int x)

// �������� �Ͻ��� ǥ����� Ŭ�������� �۵��� �� ����

int Sigma(MyClass& c, int (MyClass::*f)(int x), int m, int n)	
{						// ��ó�� ����Լ��� ǥ��
	int sum{};

	for (int i = m; i <= n; i++)
	{
		sum += (c.*f)(i);		// �����͸� ��������� ǥ��
		// f = MyClass ���� SquareFunction�� ����Ű�� ������ <�Ű��Լ�>
		// c.f = �ν��Ͻ� c�� �Ű��Լ� f ȣ��
		// c.*f = ������ f�� ����Ű�� �ν��Ͻ� c�� ����Լ� SquareFunction ����, ������
	}							

	return sum;
}

int main()
{
	MyClass c;
	std::cout << Sigma(c, &MyClass::SquareFunction, 1, 10) << std::endl;
							// �ּҸ� �ѱ��


}