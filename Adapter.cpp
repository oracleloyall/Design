/*
 * author:zhaoxi
 * disc:适配器模式
 * demo:曾经的wifidog适配器项目
 * (wifidog是开源的认证协议，通过认证手机终端，实现上网的后台服务,但由于安全，性能，产品对协议做了改造，
 * 需要兼容原始的wifidog接入厂商，同时需要支持当前协议规范，采用适配器模式解决)
 * 用process基类指针指向适配器类，遵循里氏替换原则原则，同时遵循依赖倒置原则，依赖抽象不依赖具体实现
 * （在适配过程中可以结合使用抽象工厂）
 */
#include<iostream>
//目标接口类，客户需要的接口
class process {
public:
	process() {
	}
	virtual ~process() {
	}
	virtual void Request() {
		std::cout << "New client request comming\n";
	} //该接口用于接收请求报文（存在两种不同的报文请求），做应答处理
};

//需要适配的类
class Adaptee {
	typedef int WirelessType;
	WirelessType parse();
public:
	Adaptee() {
	}
	~Adaptee() {
	}
	void SpecificRequest() {
		WirelessType type = parse(); //->获取协议类型
		switch (type) {
		case 1:
			break;
		case 2:
			break;
		default:
			break;
		}
	} //需要拆分协议适配处理
};

//类模式，适配器类，通过public继承获得接口继承的效果，通过private继承获得实现继承的效果
class Adapter: public process, private Adaptee {
public:
	Adapter() {

	}
	~Adapter() {
	}
	virtual void Request() {
		this->SpecificRequest(); //实现Target定义的Request接口
	}
};

//对象模式，适配器类，继承Target类，采用组合的方式实现Adaptee的复用
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
		_adaptee->SpecificRequest(); //实现Target定义的Request接口
	}
private:
	Adaptee* _adaptee; //属于一种关联关系
};


int main() {
	//类模式Adapter
	process* pTarget = new Adapter();
	pTarget->Request();

	//对象模式Adapter1
	Adaptee* ade = new Adaptee();
	process* pTarget1 = new Adapter1(ade);
	pTarget1->Request();

	//对象模式Adapter2
	process* pTarget2 = new Adapter1();
	pTarget2->Request();

	return 0;
}

