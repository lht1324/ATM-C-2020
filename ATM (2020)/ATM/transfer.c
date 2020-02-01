#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientInfo.h"
#include "function.h"

int transfer(int client, int count) { // 이체 기능을 담당하는 함수이다.

	char account[17], temp[17];
	// account : 이체할 고객의 계좌를 입력받을 문자열이다.
	// temp : 계좌번호 판정을 위해 고객의 계좌번호 정보를 임시로 입력받을 문자열이다.

	int i, j, end, money, receiver = 0, judge = 0;
	// end : 초기 화면으로 갈 지 안 갈 지 물을 때 사용되는 변수.
	// receiver : 구조체 배열 s에서 이체받을 사람의 인덱스.
	// judge : 송금할 사람이 입력한 계좌번호와 비밀번호를 판단하는데 사용되는 변수.

	printf("이체하실 계좌번호를 입력해주세요 : ");
	scanf_s("%s", account, 17); // 이체할 고객의 계좌번호를 입력받는다.

	for (i = 0; i < count; i++)
	{
		for (j = 0; j < 16; j++)
		{
			temp[j] = s[i].acc[j + 5];
		}
		temp[16] = '\0';

		if (strncmp(account, temp, 17) == 0)
			judge = 1;
		// 입력받은 계좌 번호가 기존 계좌와 같다면 judge는 1이다.

		else
			judge = 0;
		// 입력받은 게 기존 계좌와 다르다면 judge는 0이다.

		if (judge == 1)
		{
			receiver = i; // 계좌번호가 맞다면 이체받을 사람의 인덱스 receiver를 i라 한다.
			break;
		}

		if (i == count - 1 && judge == 0) 
		{
			printf("\n");
			printf("계좌번호를 잘못 입력하셨습니다.\n");
			return -1;
		}	
		// 반복문이 끝나기 직전 judge가 0이라면 계좌번호를 잘못 입력한 것이라 판단 후 함수를 종료한다.
	}

	money = balanceModify(3, client); // 본인의 계좌에서 출금한다. 이 때 출력값은 출금된 만큼의 돈이다.
	
	balanceModify(money, receiver); // 이체 받을 사람의 계좌에 입금한다. 이 때 balanceModify의 mode 매개 변수는 money로 삽입된다.

	while (1)
	{
		printf("초기 화면으로 가시려면 0을 입력해주세요 : ");
		scanf_s("%d", &end);
		if (end == 0) // end에 0을 입력받으면 transfer() 함수를 종료한다.
			return 0;
		else
			printf("\n잘못 입력하셨습니다.\n\n");
	}
}