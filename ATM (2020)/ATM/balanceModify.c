#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientInfo.h"
#include "function.h"

int balanceModify(int mode, int client) { // 입출금을 담당하는 함수이다. mode가 1이면 입금, 2이면 출금, 3이면 이체 시 출금.
	int i, len, result;
	// len : 고객의 잔고의 길이를 저장할 변수이다.
	// result : 출금한 결과를 저장할 변수이다.

	char c_money[16], i_money[16], b_money[16], bal[21], str[21];
	// c_money : client_money(기존 잔고)
	// i_money : input_money(입력된 돈)
	// b_money : balance_money(수정된 잔고)
	// bal : 수정된 잔고에 패스워드를 합친 것을 파일에 입력하기 위해 사용되는 문자열.

	FILE* rfp;
	FILE* wfp;

	fopen_s(&rfp, "balance.txt", "r");
	fopen_s(&wfp, "balance_temp.txt", "w");

	if (rfp == NULL || wfp == NULL) {
		printf("오류 발생. 초기 화면으로 돌아갑니다.\n\n");
		return 0;
	} // 예외 처리

	for (i = 0; i < 16; i++)
	{
		c_money[i] = s[client].balance[i + 5];
	}	// 기존 잔고가 얼마인지 c_money에 저장한다.

	result = atoi(c_money); // result에 c_money를 정수로 변환한 값을 대입한다.

	if (mode < 4) {
		if (mode == 1)
			printf("입금하실 금액을 입력해주세요 : ");
		else if (mode == 2)
			printf("출금하실 금액을 입력해주세요 : ");
		else if (mode == 3)
			printf("\n이체하실 금액을 입력해주세요 : ");
		scanf_s("%s", i_money, 16); // 변경할 금액을 입력받는다.
	}

	if (mode == 1) // 입금
		result += atoi(i_money);

	else if (mode == 2 || mode == 3) { // 출금 & 이체 시 출금
		if (result < atoi(i_money)) // 출금할 금액이 잔고보다 많다면
		{
			printf("\n잔고가 부족합니다.\n");
			return 0;
		}
		else {
			result -= atoi(i_money);
		}
	}

	else // 이체 시 입금
		result = mode;
	// 이체 시 타인의 계좌에 입금할 때는 mode 변수에 본인의 계좌에 입금한 돈의 액수를 저장한다. 그것을 result에 대입한다.

	_itoa_s(result, b_money, sizeof(b_money), 10);
	// 출금 후 잔고 result를 문자열로 바꿔 b_money에 저장한다.

	for (i = 0; i < 16; i++)
		s[client].balance[i + 5] = b_money[i];
	// 고객의 기존 잔고에 b_money를 대입한다.

	len = strlen(s[client].balance);

	if (mode == 1)
		printf("\n입금이 완료되었습니다.\n\n");
	else if (mode == 2)
		printf("\n출금이 완료되었습니다.\n\n");
	else if (mode == 3)
		printf("\n이체가 완료되었습니다.\n\n");

	if (mode < 4) { // mode 변수가 3 이하일 때만 잔고를 출력한다.
		for (i = 5; i < 20; i++)
		{
			if (i == 5)
				printf("고객님의 계좌 잔고는 ");

			if (s[client].balance[i] != '\0')
				printf("%c", s[client].balance[i]);
			// 고객의 잔고를 한 글자씩 출력한다.

			if ((len - i + 2) % 3 == 0 && i != (len - 1))
				printf(",");
			// 3자리마다 ','로 끊어준다.

			if (i == (len - 1))
			{
				printf("원입니다.\n\n");
				break;
			} // 잔고를 모두 출력하면 맨 뒤에 붙여준다.
		}
	}

	for (i = 0; ; i++) // 수정된 잔고를 파일에 입력하는 for문이다.
	{
		if (i != client) // i번째 열이 client의 정보가 아니라면
		{
			fgets(bal, sizeof(bal), rfp);

			if (feof(rfp))
				break;

			bal[strlen(bal)] = '\0';

			fprintf(wfp, "%s", bal);
		}

		if (i == client) // i번째 열이 client의 정보라면
		{
			fgets(bal, sizeof(bal), rfp);
			// 여기서 읽지 않으면 파일엔 s[client].balance와 balance.txt에 읽히기 전의 문자열이 같이 쓰인다.

			fprintf(wfp, "%s\n", s[client].balance);
		}
	}

	fclose(rfp);
	fclose(wfp);

	fopen_s(&rfp, "balance_temp.txt", "r");
	fopen_s(&wfp, "balance.txt", "w");

	if (rfp == NULL || wfp == NULL) {
		printf("오류 발생. 초기 화면으로 돌아갑니다.\n\n");
		return 0;
	} // 예외 처리

	while (1)
	{
		fgets(str, sizeof(str), rfp); // balance_temp.txt를 한 줄씩 읽는다.

		if (feof(rfp)) // 파일의 끝이라면 종료한다.
			break;

		fprintf(wfp, "%s", str); // 읽어들인 내용을 balance.txt에 덮어쓴다.
	}

	fclose(rfp);
	fclose(wfp);

	if (mode == 3)
		return result;
	// 이체 시 본인의 계좌에서 출금한 금액을 출력한다.
}