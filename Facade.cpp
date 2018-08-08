/*
 * author:zhaoxi
 * disc:外观模式
 * demo:sql安全模块接口：SQL要经历一些列的过程，词法解析，语法解析，正则判断，关键字拦截，注入判断等
 * 我们不需要每一个类模块都由调用者依次调用，而只需要关心调用结构，这就是外观模式的用途
 * */
#include<iostream>
using namespace std;
class Scanner {
public:
	void Scan() {
		cout << "词法分析" << endl;
	}
};
class Parser {
public:
	void Parse() {
		cout << "语法分析" << endl;
	}
};
class GenMidCode {
public:
	void GenCode() {
		cout << "产生中间代码" << endl;
	}
};
class GenMachineCode {
public:
	void GenCode() {
		cout << "产生机器码" << endl;
	}
};
//高层接口  Fecade
class Compiler {
public:
	void Run() {
		Scanner scanner;
		Parser parser;
		GenMidCode genMidCode;
		GenMachineCode genMacCode;
		scanner.Scan();
		parser.Parse();
		genMidCode.GenCode();
		genMacCode.GenCode();
	}
};

//client
int main() {
	Compiler compiler;
	compiler.Run();
	return 0;
}
