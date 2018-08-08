/*
 * author :zhaoxi 单一职能原则分析
 * 核心理解：
 * 不要存在多于一个导致类变更的原因。通俗的说，即一个类只负责一项职责。
 * 职责是“变化的原因”。
 我的原则是：只有逻辑足够简单，才可以在代码级别上违反单一职责原则；只有类中方法数量足够少，才可以在方法级别上违反单一职责原则；
 *
 */
/*
 * demo：first 当前database作为公共类提供不同的客户端服务，仅提供了mysql的接口方法
 * 暴露问题：for oracle function is wrong，不是所以数据库的接口都一致
 * 修改成DIP second方案：遵循了SRP原则，但是需要修改客户端部分以及原来的database需要分解。
 *
 * 还有一种方式：database 增加分支判断：违背单一职能，但是客户端看不见内部改动，同时也存在其他的风险。
 * 或者同一接口的虚函数不同实现（多态）
 */
#include<iostream>
using namespace std;
#define FIRST
#ifdef FIRST
class database {
public:
	bool run(const char *sql) {
		std::cout << "mysql run :" << sql << endl;
	}
};
#endif

int main(int argc, char **argv) {
	{
		//for mysql
		database data;
		data.run("select name,id from te group by id;");
	}
	{
		//for oracle function is wrong
		database data;
		data.run("select name,id from te group by id;");
	}
}
