/*
 * author:zhaoxi
 * disc:������ģʽ
 * demo:������wifidog��������Ŀ
 * (wifidog�ǿ�Դ����֤Э�飬ͨ����֤�ֻ��նˣ�ʵ�������ĺ�̨����,�����ڰ�ȫ�����ܣ���Ʒ��Э�����˸��죬
 * ��Ҫ����ԭʼ��wifidog���볧�̣�ͬʱ��Ҫ֧�ֵ�ǰЭ��淶������������ģʽ���)
 * ��process����ָ��ָ���������࣬��ѭ�����滻ԭ��ԭ��ͬʱ��ѭ��������ԭ������������������ʵ��
 * ������������п��Խ��ʹ�ó��󹤳���
 */
#include<iostream>
//Ŀ��ӿ��࣬�ͻ���Ҫ�Ľӿ�
class process {
public:
	process() {
	}
	virtual ~process() {
	}
	virtual void Request() {
		std::cout << "New client request comming\n";
	} //�ýӿ����ڽ��������ģ��������ֲ�ͬ�ı������󣩣���Ӧ����
};

//��Ҫ�������
class Adaptee {
	typedef int WirelessType;
	WirelessType parse();
public:
	Adaptee() {
	}
	~Adaptee() {
	}
	void SpecificRequest() {
		WirelessType type = parse(); //->��ȡЭ������
		switch (type) {
		case 1:
			break;
		case 2:
			break;
		default:
			break;
		}
	} //��Ҫ���Э�����䴦��
};

//��ģʽ���������࣬ͨ��public�̳л�ýӿڼ̳е�Ч����ͨ��private�̳л��ʵ�ּ̳е�Ч��
class Adapter: public process, private Adaptee {
public:
	Adapter() {

	}
	~Adapter() {
	}
	virtual void Request() {
		this->SpecificRequest(); //ʵ��Target�����Request�ӿ�
	}
};

//����ģʽ���������࣬�̳�Target�࣬������ϵķ�ʽʵ��Adaptee�ĸ���
class Adapter1: public process {
public:
	Adapter1(Adaptee* adaptee) {
		this->_adaptee = _adaptee;
	}
	Adapter1() {

	}
	~Adapter1() {

	}
	virtual void Request() {
		_adaptee->SpecificRequest(); //ʵ��Target�����Request�ӿ�
	}
private:
	Adaptee* _adaptee; //����һ�ֹ�����ϵ
};


int main() {
	//��ģʽAdapter
	process* pTarget = new Adapter();
	pTarget->Request();

	//����ģʽAdapter1
	Adaptee* ade = new Adaptee();
	process* pTarget1 = new Adapter1(ade);
	pTarget1->Request();

	//����ģʽAdapter2
	process* pTarget2 = new Adapter1();
	pTarget2->Request();

	return 0;
}

