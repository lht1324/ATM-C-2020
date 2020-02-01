#include <stdio.h>
#include "function.h"

int menu();

int kiosk() // ������ �� �޴��� ����ϴ� �Լ��̴�.
{
	int count, choice, client = 0, finish = 0, start = 1;

	while (finish == 0)
	{
		count = accountLoad();

		choice = menu(); 
		// while�� ���� �ø��� �ʱ�ȭ������ ������ choice ���� �����ȴ�.
		// �Ա�, ���, ��ü, ���� ����, ���� �� �� ������ �ٲ�ų� ������ ������ �ٲ��
		// �Լ��� �����Ƿ� while���� �ݺ��� ������ ������ ������ �ٽ� �о� ����ü��
		// �����ϰ� �� ������ ���� ���Ѵ�.

		switch (choice) // choice�� �Ű� ������ �� �۵��ϴ� switch~case()���̴�.
		{
		case 0: // ������ ���.
			finish = admin(count, start); // admin()�� ������ finish�� �Է¹޴´�.

			while (1)
			{
				if (finish == 1) // admin()�� 1�� ����ϸ� ���α׷��� �����Ѵ�.
					return 0;
				else // 0�� ����ϸ� ����� ��� �ʱ� ȭ������ ���ƿ´�.
					break;
			}
			break;

		case 1: // �Ա�.
			client = accountJudge(count);
			// accountJudge�� �� ������ �Ű������� �־� ������ ���� �� ����Ʈ����
			// �� ��°���� ���� ��, ���� ������ client�� �����Ѵ�. �� �� ������ �ϻ����� 
			// ���ڰ� �ƴ�, ���α׷��ֿ��� ���Ǵ� 0���� �����ϴ� ���̴�.
			if (client != -1)
			{
				balanceModify(1, client);
				break;
			}
			else // client�� -1�̶�� �ʱ� ȭ������ ���ư���.
				break;
			// ������ return ���� 0���� ������, ���� ����Ʈ���� ù ��° ���̸� 0��
			// ��µǹǷ�, ���¹�ȣ�� ��й�ȣ�� �߸� �Է¹����� -1�� ����ϵ��� �ߴ�.
		
		case 2: // ���.
			client = accountJudge(count);
			// accountJudge()�� count�� �Ű������� �־� ������ ��°��� client�� �����Ѵ�.
			if (client != -1)
			{	// client�� -1�� �ƴ϶�� withdraw()�� client�� �Ű������� �־� �����Ѵ�.
				balanceModify(2, client);
				break;
			}
			else	// client�� -1�̶�� �ʱ� ȭ������ ���ư���.
				break;
		
		case 3: // ���� ��ü
			client = accountJudge(count);

			if (client != -1)
			{
				printf("10�� �̸��� ���� ��ü�� �� �����ϴ�.\n\n");
				transfer(client, count);
				break;
			}
			// ���¹�ȣ�� ��й�ȣ�� ��ġ�ϸ� transfer()�� ���� ������
			// �� ������ �Ű������� �־� �����Ѵ�.

			else
				break;

		case 4: // ���� ��ȸ
			client = accountJudge(count);

			if (client != -1)
			{
				accountView(client); // accountView()�� client�� �Ű� ������ �־� �����Ѵ�.
				break;
			}

			else
				break;
		
		default: // �޴��� �߸� �����ϸ� �ٽ� �ʱ� ȭ������ ���ư���.
			printf("�޴� ������ �߸� �ϼ̽��ϴ�. �ٽ� �������ֽʽÿ�.\n");
			break;
		}
	}
}

int menu() {
	int choice;

	printf("\n----------------------------------------------------\n\n");
	printf("--- � ���ʽÿ�, ����! GC���� ATM����Դϴ�. ---\n\n");
	printf("<1> �Ա�\n\n");
	printf("<2> ���\n\n");
	printf("<3> ���� ��ü\n\n");
	printf("<4> ���� ��ȸ\n\n");
	printf("<0> ������ ���\n\n");
	printf("���Ͻô� �ŷ��� �������ֽʽÿ� : ");
	scanf_s("%d", &choice);
	printf("\n----------------------------------------------------\n\n");
	
	return choice;
}