#include <iostream>

// 예외는 대부분 힙을 사용하게 되므로 오버헤드가 있습니다.
// => 심각한 오류에 대한 처리만 사용하고
// => 간단한 오류는 반환값으로 하는 것이 좋습니다.

void f2()
{
	throw 1; // 과연 "던져진 예외 객체(지금은 1)"은 어디에 있을까요 ?
			// new int 로 힙에 올려놓고  => 여기서 오버헤드가 있습니다.
			// catch 로 이동 합니다.
			// 1. 힙에 생성
			// 2. mov 약속된레지스터, 주소

	return 10;
}
void f1()
{
	f2();
}
int main()
{
	try
	{
		f1();
	}
	catch(int e)
	{	
		// delete e가 가리키는 메모리(e는 사실 내부적으로는 포인터로 관리리)
	}
}