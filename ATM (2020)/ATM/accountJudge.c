#include <stdio.h>
#include <string.h>
#include "function.h"
#include "clientInfo.h"

int accountJudge(int count) // ���� �Է��� ���¹�ȣ�� ������ ��й�ȣ�� �´��� �Ǻ��ϴ� �Լ�.
{	
	char account[17], password[5], temp_a[17], temp_p[3][5];
	// account : ���� �Է��� ���¹�ȣ. 
	// password : ���� �Է��� ��й�ȣ.
	// temp_a : �� �������� ���� ���¹�ȣ�� ����ȴ�.
	// temp_p : �������� Ű����� ��й�ȣ�� �о�� �����ϴ� ������ ���ڿ��̴�.
	
	int i, j, client = 0, judge = 0;
	// client : ���� �� ����Ʈ���� �� ��°���� ����Ǿ� �Լ��� ���� �� ��µǴ� ����.
	// judge : ���¹�ȣ�� ��й�ȣ�� ��� �´ٸ� 1�� �Ǵ� �����̴�. 0���� �ʱ�ȭ.
	
	printf("���¹�ȣ�� �Է����ּ��� : ");
	scanf_s("%s", account, 17); // ���¹�ȣ�� �Է¹޴´�.
	
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < 16; j++)
		{
			temp_a[j] = s[i].acc[j + 5]; // ������ ���� temp_a�� ���� ���¹�ȣ�� �����Ѵ�.
		}
		temp_a[16] = '\0';

		if (strncmp(account, temp_a, 17) == 0) // ���� �Է��� ���¹�ȣ�� temp_a�� ��ġ�ϸ�
			judge = 1;
		else
			judge = 0;
		
		if (judge == 1)
		{
			client = i;
			break;
		} // judge�� 1�̸� client�� i�� �����ϰ� ���¹�ȣ�� �����ϴ� for���� �����Ѵ�.

		if (i == count - 1 && judge == 0)
		{	
			printf("\n");
			printf("���¹�ȣ�� �߸� �Է��ϼ̽��ϴ�.\n");
			return -1;
		}	// for���� ������ ���� judge�� 0�̶�� ���¹�ȣ�� �߸� �Է��� ���̴�.
	}

	printf("\n��й�ȣ�� �Է����ּ��� : ");
	scanf_s("%s", password, 5); // ��й�ȣ�� �Է¹޴´�.
	printf("\n");
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (i == 0) // ���¹�ȣ�� �Բ� ����� ��й�ȣ�� temp_p[0]�� �Է��Ѵ�.
				temp_p[i][j] = s[client].acc[j]; 

			else if (i == 1) // �̸��� �Բ� ����� ��й�ȣ�� temp_p[1]�� �Է��Ѵ�.
				temp_p[i][j] = s[client].name[j];

			else // �ܰ�� �Բ� ����� ��й�ȣ�� temp_p[2]�� �Է��Ѵ�.
				temp_p[i][j] = s[client].balance[j];
		}
		temp_p[i][4] = '\0';
		
		if (strncmp(password, temp_p[i], 5) == 0) // temp_p[i]�� ���� �Է��� ��й�ȣ�� ������
			judge = 1;
		else
			judge = 0;
	}

	if (judge == 1) 
		return client;
	// ���¹�ȣ�� ��й�ȣ�� ��� �´ٸ� judge�� 1�̴�.
	// �� ����Ʈ���� ���� �� ��°���� �˷��ִ� ���� client�� ����Ѵ�.

	else
	{
		printf("��й�ȣ�� �߸� �Է��ϼ̽��ϴ�.\n");
		return -1; 
	}	// judge�� 1�� �ƴ϶�� ���¹�ȣ�� �°� �Է������� ��й�ȣ�� Ʋ�� ���̴�.
}
