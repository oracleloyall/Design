/*
 * author :zhaoxi 开闭原则
 * 核心理解：类的改动是通过增加代码进行的，而不是修改源代码。
 *demo:
 */
#ifdef FIRST
#include "iostream"
using namespace std;

/*
 如果需要增加新的功能，需要再次添加新的成员函数，会导致类越来越复杂
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
	 如果在后期需要增加网银开通、贷款等业务，则需要在此处继续添加函数。
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
	/*纯虚函数的设计用来抽象银行业务员的业务*/
	virtual void doBusiness() = 0;
};

/*创建存钱的银行员*/
class saveBankWorker: public BankWorker {
public:
	virtual void doBusiness() {
		cout << "save money." << endl;
	}
};

/*创建转账的银行员*/
class transferBankWorker: public BankWorker {
public:
	virtual void doBusiness() {
		cout << "transfer money." << endl;
	}
};

/*创建取钱的银行员*/
class payBankWorker: public BankWorker {
public:
	virtual void doBusiness() {
		cout << "pay money." << endl;
	}
};

/*后期如果需要增加新的功能，只需要再次集成一个新类实现业务函数即可*/
/*新增办理基金的银行员*/
class fundationBankWorker: public BankWorker {
	virtual void doBusiness() {
		cout << "fundation money." << endl;
	}
};

int main() {
	/*
	 C++产生多态的3个必要条件
	 1、有继承，如saveBankWorker继承了BankWorker
	 2、要有重写，这里的BankWorker类的doBusiness()函数是纯虚函数，
	 就会被重写，这个函数也称之为接口函数
	 3、父类指针指向子类对象
	 */

	BankWorker *bw = NULL;    //实例化一个父类指针

	bw = new saveBankWorker;  //将父类指针指向子类对象
	bw->doBusiness();         //调用业务函数
	delete bw;                //释放空间
	bw = NULL;                //将指针指向空，更加安全

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
