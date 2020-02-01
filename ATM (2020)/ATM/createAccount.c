#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "clientInfo.h"
#include "function.h"

int createAccount(int count) // ���¸� ���� �����ϴ� �Լ��̴�.
{	
	int i, account_check = 0, end;
	// account_check : ���¹�ȣ ���� �� ���� ���¹�ȣ �� ���� ��ȣ�� �ִ��� ������ Ȯ���� �� ���Ǵ� �����̴�.
	// end : end == 0�̸� �Լ��� ����ȴ�.
	
	char str_a[22], str_n[18], str_b[21], password[5], name[13], fp[17];
	// str_a : str_account, ���¸� ������ �ӽ÷� �����ϱ� ���� ���ڿ��̴�.
	// str_n : str_name, �̸��� �Է¹��� �� �ӽ÷� �����ϱ� ���� ���ڿ��̴�.
	// str_b : str_balance, �ܰ� �ӽ÷� �����ϱ� ���� ���ڿ��̴�.
	// fp : ȭ�鿡 ���¹�ȣ�� ����ϱ� ���� �ӽ÷� ���¹�ȣ�� ����Ǵ� ���ڿ��̴�.
	
	// �̸�, ���¹�ȣ, �ܰ� ���Ͽ� ������ �� ���� 5�ڸ��� ��й�ȣ 4�ڸ��� ���� 1�ڸ��� ���δ�. 3���� ���Ͽ� ���� ��й�ȣ�� ��� �´ٸ� ������ �������� ���� ���̴�.

	FILE *afp1;
	FILE *afp2;
	FILE *afp3;
	
	fopen_s(&afp1, "acc.txt", "a");
	fopen_s(&afp2, "name.txt", "a");
	fopen_s(&afp3, "balance.txt", "a");

	if (afp1 == NULL || afp2 == NULL || afp3 == NULL) {
		printf("���� �߻�. �ʱ� ȭ������ ���ư��ϴ�.\n\n");
		return 0;
	} // ���� ó��

	printf("������ �Է����ּ��� : ");
	scanf_s("%s", name, 13); // �̸��� �Է¹޴´�.
	name[strlen(name)] = '\0';

	printf("\n4�ڸ��� ��й�ȣ�� �����ּ��� : ");
	scanf_s("%s", password, 5); // ��й�ȣ�� �Է¹޴´�.
	password[4] = '\0';
	
	printf("\n");

	
	for (i = 0; i < 5; i++)
	{
		str_a[i] = password[i];
		str_n[i] = password[i];
		str_b[i] = password[i];
		
		if (i == 4)
		{
			str_a[4] = ' ';
			str_n[4] = ' ';
			str_b[4] = ' ';
		}
	}	// ���¹�ȣ, �̸�, �ܰ��� �� 5�ڸ��� ��й�ȣ�� ���� 1�ڸ��� �ִ´�.

	for (i = 0; i < 17; i++)
	{
		str_n[i + 5] = name[i];
	}	
	// ��й�ȣ�� ������ str_n[i + 5]�� name[i]�� �����Ѵ�.
	// <��й�ȣ 5�ڸ� + �̸�> �� ������ �ȴ�.

	srand((unsigned)time(NULL));
	
	while (account_check == 0)
	{
		for (i = 5; i < 21; i++)
		{
			str_a[i] = (char)((rand() % 10) + 48);
			fp[i - 5] = str_a[i];

			if (i == 11 || i == 14)
			{
				str_a[i] = '-';
				fp[i - 5] = '-';
			}
		}	// ���¸� �������� �����ϴ� for���̴�.
		
		str_a[21] = '\0';
		fp[16] = '\0';
		
		for (i = 0; i < count; i++)
		{
			if (strncmp(fp, s[i].acc, 17) == 0)
				account_check = 0;
			else
				account_check = 1;
		}	
		// ����ü ���¹�ȣ �׸��� �Ⱦ� ���� ������ ���¹�ȣ�� ���� ��ȣ�� �ִٸ� 
		// ���¹�ȣ�� �ٽ� �����Ѵ�.
	}
	str_b[5] = '0'; // ó�� ��������� �����̴� �ܰ�� 0���� �Ѵ�.
	str_b[6] = '\0';

	fprintf(afp1, "%s\n", str_a);
	fprintf(afp2, "%s\n", str_n);
	fprintf(afp3, "%s\n", str_b);
	// str_a, str_n, str_b�� ���� acc.txt, name.txt, balance.txt�� �߰��� ����.
	
	fclose(afp1);
	fclose(afp2);
	fclose(afp3);
	
	printf("���°� �����Ǿ����ϴ�. %s ������ ���¹�ȣ�� %s�Դϴ�.\n\n", name, fp);
	
	while (1)
	{
		printf("�ʱ� ȭ������ ���÷��� 0�� �Է����ּ��� : ");
		scanf_s("%d", &end);
		if (end == 0) // end�� 0�� �Է¹����� createAccount() �Լ��� �����Ѵ�.
			return 0;
		else
			printf("\n�߸� �Է��ϼ̽��ϴ�.\n\n");
	}
}