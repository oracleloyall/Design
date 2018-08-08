/*
 * author :zhaoxi ��������ԭ�����
 * ������⣺
 * �߲�ģ�鲻Ӧ�������Ͳ�ģ�飬���߶�Ӧ���������󣬳���Ӧ������ϸ�ڣ� ϸ��Ӧ����������
 */
/*
 * demo����ǰ��Ҫ֧���������ݿ⣬�ֱ��ṩ�ӿڣ�ʵ��run������
 * ���һ����¶���⣨������Υ��DIP�Ĳ��֣�
 * ServiceDatabase��ֱ�Ӹ��ϲ�ʹ�õģ����ڸ߲�ģ�飬�߲�ģ��ֱ�������Ͳ��postgresql,mysql
 * �����������ɾ��һ�����ݿ⣬�Ʊ���Ҫ�޸ĸ߲�ģ�飬ͬʱ�����߲�ģ��Ĵ��붼��Ҫ�Ķ���
 * Υ���˸߲�ģ�����������ԭ��
 * ��ƶ�����ѭDIPԭ��
 */
#include<iostream>
#ifdef FIRST
class postgresql {
public:
	void run(const char *sql) {
		std::cout << "postgresql run\n";
	}
};
class mysql {
public:
	void run(const char *sql) {
		std::cout << "mysql run\n";
	}
};

class ServiceDatabase {
private:
	postgresql *pg;
	mysql *ml;
public:
	ServiceDatabase() {
		pg = new postgresql();
		ml = new mysql();
	}
	enum DataType {
		postgresql, mysql
	};
	void run(DataType type, const char * sql) {
		switch (type) {
			case postgresql:
			pg->run(sql);
			break;
			case mysql:
			ml->run(sql);
			break;
			default:
			break;
		}
	}
private:
	DataType type;
	void AutoDatabase(DataType type) {
		this->type = type;
	}

};
#else
class DataBase {
public:
	void virtual run();
};
class mysql: DataBase {
public:
	void run(const char * sql) {
	}
};
class postgresql: DataBase {
public:
	void run() {

	}

};
class ServiceDatabase {
private:
	DataBase dataservice;
public:
	ServiceDatabase(DataBase &base) {
		this->dataservice = base;
	}
	void run() {
		dataservice.run();
	}
};
#endif
