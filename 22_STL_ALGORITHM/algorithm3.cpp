// 6_알고리즘1
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

// 단항 함수(unary  function) : 인자가 1개인 함수
// 이항 함수(binary function) : 인자가 2개인 함수

// 조건자(predicator)
// => 반환 타입이 bool 또는 bool 로 변환 가능한 타입인 함수

// std::find_if 의 3번째 인자는 단항 조건자를 전달해야 합니다.

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,9,4,3,6,7,3,9,10 };

	// 주어진 구간에서 처음 나오는 "3" 을 찾아라
	auto ret1 = std::find(v.begin(), v.end(), 3); 


	// 주어진 구간에서 처음 나오는 "3의배수" 을 찾아라
	// std::find    : 값 검색, 3번째 인자 "값"
	// std::find_if : 조건 검색, 3번째 인자 "함수"

//	auto ret2 = std::find_if(v.begin(), v.end(), 함수 ); 
	auto ret2 = std::find_if(v.begin(), v.end(), foo ); 

	if ( ret2 == v.end())
	{
		std::cout << "요소없음\n";
	}
	else 
	{
		std::cout << *ret2 << std::endl;
	}
}