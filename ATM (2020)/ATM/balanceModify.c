#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientInfo.h"
#include "function.h"

int balanceModify(int mode, int client) { // ������� ����ϴ� �Լ��̴�. mode�� 1�̸� �Ա�, 2�̸� ���, 3�̸� ��ü �� ���.
	int i, len, result;
	// len : ���� �ܰ��� ���̸� ������ �����̴�.
	// result : ����� ����� ������ �����̴�.

	char c_money[16], i_money[16], b_money[16], bal[21], str[21];
	// c_money : client_money(���� �ܰ�)
	// i_money : input_money(�Էµ� ��)
	// b_money : balance_money(������ �ܰ�)
	// bal : ������ �ܰ� �н����带 ��ģ ���� ���Ͽ� �Է��ϱ� ���� ���Ǵ� ���ڿ�.

	FILE* rfp;
	FILE* wfp;

	fopen_s(&rfp, "balance.txt", "r");
	fopen_s(&wfp, "balance_temp.txt", "w");

	if (rfp == NULL || wfp == NULL) {
		printf("���� �߻�. �ʱ� ȭ������ ���ư��ϴ�.\n\n");
		return 0;
	} // ���� ó��

	for (i = 0; i < 16; i++)
	{
		c_money[i] = s[client].balance[i + 5];
	}	// ���� �ܰ� ������ c_money�� �����Ѵ�.

	result = atoi(c_money); // result�� c_money�� ������ ��ȯ�� ���� �����Ѵ�.

	if (mode < 4) {
		if (mode == 1)
			printf("�Ա��Ͻ� �ݾ��� �Է����ּ��� : ");
		else if (mode == 2)
			printf("����Ͻ� �ݾ��� �Է����ּ��� : ");
		else if (mode == 3)
			printf("\n��ü�Ͻ� �ݾ��� �Է����ּ��� : ");
		scanf_s("%s", i_money, 16); // ������ �ݾ��� �Է¹޴´�.
	}

	if (mode == 1) // �Ա�
		result += atoi(i_money);

	else if (mode == 2 || mode == 3) { // ��� & ��ü �� ���
		if (result < atoi(i_money)) // ����� �ݾ��� �ܰ��� ���ٸ�
		{
			printf("\n�ܰ� �����մϴ�.\n");
			return 0;
		}
		else {
			result -= atoi(i_money);
		}
	}

	else // ��ü �� �Ա�
		result = mode;
	// ��ü �� Ÿ���� ���¿� �Ա��� ���� mode ������ ������ ���¿� �Ա��� ���� �׼��� �����Ѵ�. �װ��� result�� �����Ѵ�.

	_itoa_s(result, b_money, sizeof(b_money), 10);
	// ��� �� �ܰ� result�� ���ڿ��� �ٲ� b_money�� �����Ѵ�.

	for (i = 0; i < 16; i++)
		s[client].balance[i + 5] = b_money[i];
	// ���� ���� �ܰ� b_money�� �����Ѵ�.

	len = strlen(s[client].balance);

	if (mode == 1)
		printf("\n�Ա��� �Ϸ�Ǿ����ϴ�.\n\n");
	else if (mode == 2)
		printf("\n����� �Ϸ�Ǿ����ϴ�.\n\n");
	else if (mode == 3)
		printf("\n��ü�� �Ϸ�Ǿ����ϴ�.\n\n");

	if (mode < 4) { // mode ������ 3 ������ ���� �ܰ� ����Ѵ�.
		for (i = 5; i < 20; i++)
		{
			if (i == 5)
				printf("������ ���� �ܰ�� ");

			if (s[client].balance[i] != '\0')
				printf("%c", s[client].balance[i]);
			// ���� �ܰ� �� ���ھ� ����Ѵ�.

			if ((len - i + 2) % 3 == 0 && i != (len - 1))
				printf(",");
			// 3�ڸ����� ','�� �����ش�.

			if (i == (len - 1))
			{
				printf("���Դϴ�.\n\n");
				break;
			} // �ܰ� ��� ����ϸ� �� �ڿ� �ٿ��ش�.
		}
	}

	for (i = 0; ; i++) // ������ �ܰ� ���Ͽ� �Է��ϴ� for���̴�.
	{
		if (i != client) // i��° ���� client�� ������ �ƴ϶��
		{
			fgets(bal, sizeof(bal), rfp);

			if (feof(rfp))
				break;

			bal[strlen(bal)] = '\0';

			fprintf(wfp, "%s", bal);
		}

		if (i == client) // i��° ���� client�� �������
		{
			fgets(bal, sizeof(bal), rfp);
			// ���⼭ ���� ������ ���Ͽ� s[client].balance�� balance.txt�� ������ ���� ���ڿ��� ���� ���δ�.

			fprintf(wfp, "%s\n", s[client].balance);
		}
	}

	fclose(rfp);
	fclose(wfp);

	fopen_s(&rfp, "balance_temp.txt", "r");
	fopen_s(&wfp, "balance.txt", "w");

	if (rfp == NULL || wfp == NULL) {
		printf("���� �߻�. �ʱ� ȭ������ ���ư��ϴ�.\n\n");
		return 0;
	} // ���� ó��

	while (1)
	{
		fgets(str, sizeof(str), rfp); // balance_temp.txt�� �� �پ� �д´�.

		if (feof(rfp)) // ������ ���̶�� �����Ѵ�.
			break;

		fprintf(wfp, "%s", str); // �о���� ������ balance.txt�� �����.
	}

	fclose(rfp);
	fclose(wfp);

	if (mode == 3)
		return result;
	// ��ü �� ������ ���¿��� ����� �ݾ��� ����Ѵ�.
}