#include <stdio.h>
#include <string.h>
#include "clientInfo.h"
#include "function.h"

int admin(int count, int start) // ������ ��带 �ٷ�� �Լ�.
{
	// ���α׷��� �������� �� ���� ���� ����ȴ�. ���� ATM ������ �� �� ������ ���� ���ѵ� ����. �����ڰ� ������ �Ѵ� ���� ������ �Ѵ�.

	int i, finish, client, choice = 0;
	// finish : ���� ���θ� ���� �� ���Ǵ� ����.
	// client : ���� �� ����Ʈ���� �� ��°���� ������ ����.

	char password[5], input[5];
	// password : ���� ������ ��й�ȣ�� �о� �����Ѵ�.
	// input : �Է¹��� ��й�ȣ�� ����ȴ�.

	enum menu {
		user = 0, create, delete, end
	}; 
	// switch~case������ ���Ǵ� ������ �������� �����Ѵ�.

	FILE* rfp;

	fopen_s(&rfp, "admin_password.txt", "r");

	if (rfp == NULL) {
		printf("���� �߻�. �ʱ� ȭ������ ���ư��ϴ�.\n\n");
		return 0;
	} // ���� ó��

	fgets(password, 5, rfp);
	// ������ ��й�ȣ�� �о� password�� �����Ѵ�.

	password[4] = '\0';

	printf("��й�ȣ�� �Է����ּ��� : ");
	scanf_s("%s", input, 5); // ������ ��带 �� �ι����� ��й�ȣ�� �Է¹޴´�.
	input[4] = '\0';

	for (i = 0; i < 5; i++)
	{
		if (input[i] != password[i])
		{
			printf("\n��й�ȣ�� �߸� �Է��ϼ̽��ϴ�.\n\n");
			if (start == 1)
			{
				printf("��⸦ �����մϴ�.\n\n");
				return 1;
			}
			// main()�Լ� ������ �ݺ��� ���� �� ����� admin() �Լ����� ��й�ȣ�� Ʋ�ȴٸ� �ʱ� �޴��� ���ư��� ���� �ƴ϶� ���α׷��� �����Ѵ�.
			
			else
			{
				printf("���� ������ ȹ���� �� �����ϴ�.\n\n");
				printf("�ʱ� �޴��� ���ư��ϴ�.\n");
				return 0;
			}
			// main() �Լ� ������ �ݺ������� ����� admin() �Լ����� ��й�ȣ�� Ʋ���ٸ� ����� ���� �ٽ� ���ư���.
		}
	}

	while (1)
	{
		count = accountLoad(); // ���¸� ����, ������ �� ����� �� ������ �ٽ� �д´�.

		printf("\n-------------------------------------\n\n");
		printf("--- ������ ��忡 �����ϼ̽��ϴ�. ---\n\n");
		printf("<1> ���� ����\n\n");
		printf("<2> ���� ����\n\n");
		printf("<3> ��� ����\n\n");
		printf("<0> ����� ���\n\n");
		printf("������ �� �� ������ �ֽʽÿ� : ");
		scanf_s("%d", &choice);
		printf("\n-------------------------------------\n\n");

		switch (choice)
		{
		case user: // user = 0, admin()�� ����, �� ����� ���� ���ư���.
			printf("����� ���� ��ȯ�մϴ�.\n");
			return 0;
			break;

		case create: // ���� ���� �Լ��� createAccount()�� �����Ѵ�.
			createAccount(count);
			break;

		case delete: // ���� ���� �Լ��� deleteAccount()�� �����Ѵ�.
			client = accountJudge(count);
			deleteAccount(client);
			break;

		case end:
			printf("��⸦ �����Ͻðڽ��ϱ�? <Yes : 1, No : 0> : ");
			scanf_s("%d", &finish);
			printf("\n");

			if (finish == 1) // ��⸦ �����Ѵ�.
			{
				printf("��⸦ �����մϴ�.\n\n");
				return 1;
			}

			else // ������ ��� �ʱ� ȭ������ ���ư���.
			{
				printf("�ʱ� ȭ������ ���ư��ϴ�.\n");
				break;
			}

		default: // �߸��� ���� �Է¹޾Ҵٸ� switch~case���� ������ �� �ٽ� �����Ѵ�.
			printf("�޴� ������ �߸� �ϼ̽��ϴ�. �ٽ� �������ֽʽÿ�.\n");
			break;
		}
	}
}
