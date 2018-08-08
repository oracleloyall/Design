/*
 * author :zhaoxi 迪米特法则(谈论类间关系，致力于松耦合)
 * 核心理解：
 * 迪米特法则（最少知识原则）：如果两个类不必彼此直接通信，那么两个类就不应该发生直接的相互作用。如果其中一个类需要调用另一个类的某一个方法的话， 可以通过第三者转发这个调用
 （1），在类的结构设计上，每一个类都应当尽量降低成员的访问权限。
 （2），迪米特法则的根本思想是强调了类的松耦合。
 （3），类之间的耦合越弱，越有利于复用，一个处于弱耦合的类被修改，不会对有关系的类造成影响。
 *
 *典型消息通知模块：base 和A，B，C都存在依赖关系，任意一个变动都需要修改base，扩展性较差，不便于增加删除节点,
 *SECOND:改造，
 *SECOND:改造，通过引入一个专门用于控制对象间交互的中介类(Actor)来降低各对象之间的耦合度。
 *SECOND:改造，通过引入一个专门用于控制对象间交互的中介类(Actor)来降低各对象之间的耦合度。引入中间类之后，相关对象之间不再发生直接引用，而是将请求先转发给中间类，再由中间类来完成对其它对象的调用。
 */
class A;
class B;
class C;
class base {
public:
	base(A *a, B*b, C*c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
	void notiry(const char *message) {
		a->set(message);
		b->set(message);
		c->set(message);
	}
private:
	A *a;
	B *b;
	C *c;

};
class A {
public:
	void set(const char *message) {
		std::cout << "Get norify\n";
	}
};
class B {
public:
	void set(const char *message) {
		std::cout << "Get norify\n";
	}
};
class C {
public:
	void set(const char *message) {
		std::cout << "Get norify\n";
	}
};

#ifdef SECOND//改造
class base {
public:
	base() {

	}
	void notiry(const char *message) {

	}

};
class Actor {
public:
	Actor(base *base,A *a, B*b, C*c) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->base=base;
	}
	void run()
	{
		//监测事件源，产生事件执行以下代码
		{
			a->set(base->message);
			b->set(base->message);
			c->set(base->message);
		}
		//或者Actor作为base的成员，actor发生时间，调用base接口
	}
private:
A *a;
B *b;
C *c;
base *base;
};

class A {
public:
	void set(const char *message) {
		std::cout << "Get norify\n";
	}
};
class B {
public:
	void set(const char *message) {
		std::cout << "Get norify\n";
	}
};
class C {
public:
	void set(const char *message) {
		std::cout << "Get norify\n";
	}
};
#endif
