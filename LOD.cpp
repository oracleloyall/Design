/*
 * author :zhaoxi �����ط���(̸������ϵ�������������)
 * ������⣺
 * �����ط�������֪ʶԭ�򣩣���������಻�ر˴�ֱ��ͨ�ţ���ô������Ͳ�Ӧ�÷���ֱ�ӵ��໥���á��������һ������Ҫ������һ�����ĳһ�������Ļ��� ����ͨ��������ת���������
 ��1��������Ľṹ����ϣ�ÿһ���඼Ӧ���������ͳ�Ա�ķ���Ȩ�ޡ�
 ��2���������ط���ĸ���˼����ǿ�����������ϡ�
 ��3������֮������Խ����Խ�����ڸ��ã�һ����������ϵ��౻�޸ģ�������й�ϵ�������Ӱ�졣
 *
 *������Ϣ֪ͨģ�飺base ��A��B��C������������ϵ������һ���䶯����Ҫ�޸�base����չ�Խϲ����������ɾ���ڵ�,
 *SECOND:���죬
 *SECOND:���죬ͨ������һ��ר�����ڿ��ƶ���佻�����н���(Actor)�����͸�����֮�����϶ȡ�
 *SECOND:���죬ͨ������һ��ר�����ڿ��ƶ���佻�����н���(Actor)�����͸�����֮�����϶ȡ������м���֮����ض���֮�䲻�ٷ���ֱ�����ã����ǽ�������ת�����м��࣬�����м�������ɶ���������ĵ��á�
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

#ifdef SECOND//����
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
		//����¼�Դ�������¼�ִ�����´���
		{
			a->set(base->message);
			b->set(base->message);
			c->set(base->message);
		}
		//����Actor��Ϊbase�ĳ�Ա��actor����ʱ�䣬����base�ӿ�
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
