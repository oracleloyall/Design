/*
 * author :zhaoxi 依赖倒置原则分析
 * 核心理解：
 * 高层模块不应该依赖低层模块，两者都应该依赖抽象，抽象不应该依赖细节， 细节应该依赖抽象
 */
/*
 * demo：当前需要支持两个数据库，分别提供接口，实现run方法。
 * 设计一：暴露问题（仅分析违背DIP的部分）
 * ServiceDatabase是直接给上层使用的，属于高层模块，高层模块直接依赖低层的postgresql,mysql
 * 这样如果增加删除一个数据库，势必需要修改高层模块，同时依赖高层模块的代码都需要改动。
 * 违背了高层模块依赖抽象的原则。
 * 设计二：遵循DIP原则
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
