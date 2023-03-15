#include <iostream>

class MyClass
{
public:
	int SquareFunction(int x)		
	{
		return x * x;
	}
};

// 매개변수 int, 반환타입 int인 포인터 함수 = int (*f) (int x)

// 포인터의 암시적 표기법은 클래스에서 작동할 수 없다

int Sigma(MyClass& c, int (MyClass::*f)(int x), int m, int n)	
{						// 위처럼 멤버함수로 표기
	int sum{};

	for (int i = m; i <= n; i++)
	{
		sum += (c.*f)(i);		// 포인터를 명시적으로 표기
		// f = MyClass 안의 SquareFunction을 가리키는 포인터 <매개함수>
		// c.f = 인스턴스 c의 매개함수 f 호출
		// c.*f = 포인터 f가 가리키는 인스턴스 c의 멤버함수 SquareFunction 접근, 역참조
	}							

	return sum;
}

int main()
{
	MyClass c;
	std::cout << Sigma(c, &MyClass::SquareFunction, 1, 10) << std::endl;
							// 주소를 넘기기


}