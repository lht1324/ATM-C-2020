#include <stdio.h>
#include <stdlib.h>
#include <string.h.>
#include <malloc.h>
#include <time.h>
#include "function.h"
#include "clientInfo.h"
// acc.txt : 계좌번호를 저장하는 텍스트 파일.
// name.txt : 이름을 저장하는 텍스트 파일.
// balance.txt : 계좌 잔고를 저장하는 텍스트 파일.
// acc_temp.txt : acc.txt에 저장된 계좌번호를 덮어쓸 때 사용되는 텍스트 파일.
// name_temp.txt : name.txt에 저장된 이름을 덮어쓸 때 사용되는 텍스트 파일.
// balance_temp.txt : balance.txt에 저장된 계좌 잔고를 덮어쓸 때 사용되는 텍스트 파일.

int main()
{
	int count, client = 0, finish = 0, start = 1;
	// admin_finish = 관리자 모드에서 받는 종료 변수

	printf("GC OS ver.1.0.0 가동.\n\n");

	printf("GC은행 ATM 가동 시작합니다.\n\n");

	count = accountLoad(); 
	// admin()의 실행을 위해 accountLoad()를 실행해 총 고객수를 얻어 count에 대입한다.

	finish = admin(count, start);
	// 프로그램을 처음 실행할 때는 관리자 모드에서 시작한다. 

	if (finish == 1) // 처음 실행한 관리자 모드에서 비밀번호를 틀렸다면 프로그램이 종료된다.
		return 0;

	start = 0;
	// 처음 시작한 뒤 실행된 admin() 내부에서만 바로 종료되고, 이후 실행되는 admin()에서는
	// 비밀번호를 틀리면 프로그램이 종료되는 게 아니라 사용자 모드로 돌아온다. 이는 start를 매개 변수로 한다.
	
	kiosk();
}