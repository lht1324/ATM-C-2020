#include <stdio.h>
#include "function.h"

int menu();

int kiosk() // 고객들이 볼 메뉴를 출력하는 함수이다.
{
	int count, choice, client = 0, finish = 0, start = 1;

	while (finish == 0)
	{
		count = accountLoad();

		choice = menu(); 
		// while문 시작 시마다 초기화해주지 않으면 choice 값이 고정된다.
		// 입금, 출금, 이체, 계좌 생성, 제거 등 총 고객수가 바뀌거나 파일의 내용이 바뀌는
		// 함수가 많으므로 while문을 반복할 때마다 파일의 내용을 다시 읽어 구조체에
		// 저장하고 총 고객수를 새로 구한다.

		switch (choice) // choice를 매개 변수로 해 작동하는 switch~case()문이다.
		{
		case 0: // 관리자 모드.
			finish = admin(count, start); // admin()을 실행해 finish를 입력받는다.

			while (1)
			{
				if (finish == 1) // admin()이 1을 출력하면 프로그램을 종료한다.
					return 0;
				else // 0을 출력하면 사용자 모드 초기 화면으로 돌아온다.
					break;
			}
			break;

		case 1: // 입금.
			client = accountJudge(count);
			// accountJudge에 총 고객수를 매개변수로 넣어 실행해 고객이 고객 리스트에서
			// 몇 번째인지 구한 뒤, 고객의 순서를 client에 대입한다. 이 때 순서는 일상적인 
			// 숫자가 아닌, 프로그래밍에서 사용되는 0부터 시작하는 수이다.
			if (client != -1)
			{
				balanceModify(1, client);
				break;
			}
			else // client가 -1이라면 초기 화면으로 돌아간다.
				break;
			// 보통은 return 값을 0으로 하지만, 고객이 리스트에서 첫 번째 고객이면 0이
			// 출력되므로, 계좌번호나 비밀번호를 잘못 입력받으면 -1을 출력하도록 했다.
		
		case 2: // 출금.
			client = accountJudge(count);
			// accountJudge()에 count를 매개변수로 넣어 실행해 출력값을 client에 대입한다.
			if (client != -1)
			{	// client가 -1이 아니라면 withdraw()에 client를 매개변수로 넣어 실행한다.
				balanceModify(2, client);
				break;
			}
			else	// client가 -1이라면 초기 화면으로 돌아간다.
				break;
		
		case 3: // 계좌 이체
			client = accountJudge(count);

			if (client != -1)
			{
				printf("10원 미만의 돈은 이체할 수 없습니다.\n\n");
				transfer(client, count);
				break;
			}
			// 계좌번호와 비밀번호가 일치하면 transfer()에 고객의 순서와
			// 총 고객수를 매개변수로 넣어 실행한다.

			else
				break;

		case 4: // 계좌 조회
			client = accountJudge(count);

			if (client != -1)
			{
				accountView(client); // accountView()에 client를 매개 변수로 넣어 실행한다.
				break;
			}

			else
				break;
		
		default: // 메뉴를 잘못 선택하면 다시 초기 화면으로 돌아간다.
			printf("메뉴 선택을 잘못 하셨습니다. 다시 선택해주십시오.\n");
			break;
		}
	}
}

int menu() {
	int choice;

	printf("\n----------------------------------------------------\n\n");
	printf("--- 어서 오십시오, 고객님! GC은행 ATM기기입니다. ---\n\n");
	printf("<1> 입금\n\n");
	printf("<2> 출금\n\n");
	printf("<3> 계좌 이체\n\n");
	printf("<4> 계좌 조회\n\n");
	printf("<0> 관리자 모드\n\n");
	printf("원하시는 거래를 선택해주십시오 : ");
	scanf_s("%d", &choice);
	printf("\n----------------------------------------------------\n\n");
	
	return choice;
}