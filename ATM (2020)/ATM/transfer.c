#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientInfo.h"
#include "function.h"

int transfer(int client, int count) { // ��ü ����� ����ϴ� �Լ��̴�.

	char account[17], temp[17];
	// account : ��ü�� ���� ���¸� �Է¹��� ���ڿ��̴�.
	// temp : ���¹�ȣ ������ ���� ���� ���¹�ȣ ������ �ӽ÷� �Է¹��� ���ڿ��̴�.

	int i, j, end, money, receiver = 0, judge = 0;
	// end : �ʱ� ȭ������ �� �� �� �� �� ���� �� ���Ǵ� ����.
	// receiver : ����ü �迭 s���� ��ü���� ����� �ε���.
	// judge : �۱��� ����� �Է��� ���¹�ȣ�� ��й�ȣ�� �Ǵ��ϴµ� ���Ǵ� ����.

	printf("��ü�Ͻ� ���¹�ȣ�� �Է����ּ��� : ");
	scanf_s("%s", account, 17); // ��ü�� ���� ���¹�ȣ�� �Է¹޴´�.

	for (i = 0; i < count; i++)
	{
		for (j = 0; j < 16; j++)
		{
			temp[j] = s[i].acc[j + 5];
		}
		temp[16] = '\0';

		if (strncmp(account, temp, 17) == 0)
			judge = 1;
		// �Է¹��� ���� ��ȣ�� ���� ���¿� ���ٸ� judge�� 1�̴�.

		else
			judge = 0;
		// �Է¹��� �� ���� ���¿� �ٸ��ٸ� judge�� 0�̴�.

		if (judge == 1)
		{
			receiver = i; // ���¹�ȣ�� �´ٸ� ��ü���� ����� �ε��� receiver�� i�� �Ѵ�.
			break;
		}

		if (i == count - 1 && judge == 0) 
		{
			printf("\n");
			printf("���¹�ȣ�� �߸� �Է��ϼ̽��ϴ�.\n");
			return -1;
		}	
		// �ݺ����� ������ ���� judge�� 0�̶�� ���¹�ȣ�� �߸� �Է��� ���̶� �Ǵ� �� �Լ��� �����Ѵ�.
	}

	money = balanceModify(3, client); // ������ ���¿��� ����Ѵ�. �� �� ��°��� ��ݵ� ��ŭ�� ���̴�.
	
	balanceModify(money, receiver); // ��ü ���� ����� ���¿� �Ա��Ѵ�. �� �� balanceModify�� mode �Ű� ������ money�� ���Եȴ�.

	while (1)
	{
		printf("�ʱ� ȭ������ ���÷��� 0�� �Է����ּ��� : ");
		scanf_s("%d", &end);
		if (end == 0) // end�� 0�� �Է¹����� transfer() �Լ��� �����Ѵ�.
			return 0;
		else
			printf("\n�߸� �Է��ϼ̽��ϴ�.\n\n");
	}
}