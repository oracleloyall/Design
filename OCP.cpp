/*
 * author :zhaoxi ����ԭ��
 * ������⣺��ĸĶ���ͨ�����Ӵ�����еģ��������޸�Դ���롣
 *demo:
 */
#ifdef FIRST
#include "iostream"
using namespace std;

/*
 �����Ҫ�����µĹ��ܣ���Ҫ�ٴ�����µĳ�Ա�������ᵼ����Խ��Խ����
 */

class BankWorker {

public:
	void save() {
		cout << "save money." << endl;
	}

	void transter() {
		cout << "transfer money." << endl;
	}

	void pay() {
		cout << "pay money." << endl;
	}
	/*
	 ����ں�����Ҫ����������ͨ�������ҵ������Ҫ�ڴ˴�������Ӻ�����
	 */
};

int main()
{
	BankWorker *bw = new BankWorker;

	bw->pay();
	bw->transter();
	bw->save();

	delete bw;
	system("pause");
	return 0;
}
#else
#include "iostream"
using namespace std;

class BankWorker {
public:
	/*���麯�������������������ҵ��Ա��ҵ��*/
	virtual void doBusiness() = 0;
};

/*������Ǯ������Ա*/
class saveBankWorker: public BankWorker {
public:
	virtual void doBusiness() {
		cout << "save money." << endl;
	}
};

/*����ת�˵�����Ա*/
class transferBankWorker: public BankWorker {
public:
	virtual void doBusiness() {
		cout << "transfer money." << endl;
	}
};

/*����ȡǮ������Ա*/
class payBankWorker: public BankWorker {
public:
	virtual void doBusiness() {
		cout << "pay money." << endl;
	}
};

/*���������Ҫ�����µĹ��ܣ�ֻ��Ҫ�ٴμ���һ������ʵ��ҵ��������*/
/*����������������Ա*/
class fundationBankWorker: public BankWorker {
	virtual void doBusiness() {
		cout << "fundation money." << endl;
	}
};

int main() {
	/*
	 C++������̬��3����Ҫ����
	 1���м̳У���saveBankWorker�̳���BankWorker
	 2��Ҫ����д�������BankWorker���doBusiness()�����Ǵ��麯����
	 �ͻᱻ��д���������Ҳ��֮Ϊ�ӿں���
	 3������ָ��ָ���������
	 */

	BankWorker *bw = NULL;    //ʵ����һ������ָ��

	bw = new saveBankWorker;  //������ָ��ָ���������
	bw->doBusiness();         //����ҵ����
	delete bw;                //�ͷſռ�
	bw = NULL;                //��ָ��ָ��գ����Ӱ�ȫ

	bw = new transferBankWorker;
	bw->doBusiness();
	delete bw;
	bw = NULL;

	bw = new payBankWorker;
	bw->doBusiness();
	delete bw;
	bw = NULL;

	return 0;
}
#endif
