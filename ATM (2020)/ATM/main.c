#include <stdio.h>
#include <stdlib.h>
#include <string.h.>
#include <malloc.h>
#include <time.h>
#include "function.h"
#include "clientInfo.h"
// acc.txt : ���¹�ȣ�� �����ϴ� �ؽ�Ʈ ����.
// name.txt : �̸��� �����ϴ� �ؽ�Ʈ ����.
// balance.txt : ���� �ܰ� �����ϴ� �ؽ�Ʈ ����.
// acc_temp.txt : acc.txt�� ����� ���¹�ȣ�� ��� �� ���Ǵ� �ؽ�Ʈ ����.
// name_temp.txt : name.txt�� ����� �̸��� ��� �� ���Ǵ� �ؽ�Ʈ ����.
// balance_temp.txt : balance.txt�� ����� ���� �ܰ� ��� �� ���Ǵ� �ؽ�Ʈ ����.

int main()
{
	int count, client = 0, finish = 0, start = 1;
	// admin_finish = ������ ��忡�� �޴� ���� ����

	printf("GC OS ver.1.0.0 ����.\n\n");

	printf("GC���� ATM ���� �����մϴ�.\n\n");

	count = accountLoad(); 
	// admin()�� ������ ���� accountLoad()�� ������ �� ������ ��� count�� �����Ѵ�.

	finish = admin(count, start);
	// ���α׷��� ó�� ������ ���� ������ ��忡�� �����Ѵ�. 

	if (finish == 1) // ó�� ������ ������ ��忡�� ��й�ȣ�� Ʋ�ȴٸ� ���α׷��� ����ȴ�.
		return 0;

	start = 0;
	// ó�� ������ �� ����� admin() ���ο����� �ٷ� ����ǰ�, ���� ����Ǵ� admin()������
	// ��й�ȣ�� Ʋ���� ���α׷��� ����Ǵ� �� �ƴ϶� ����� ���� ���ƿ´�. �̴� start�� �Ű� ������ �Ѵ�.
	
	kiosk();
}