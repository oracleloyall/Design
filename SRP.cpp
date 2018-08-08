/*
 * author :zhaoxi ��һְ��ԭ�����
 * ������⣺
 * ��Ҫ���ڶ���һ������������ԭ��ͨ�׵�˵����һ����ֻ����һ��ְ��
 * ְ���ǡ��仯��ԭ�򡱡�
 �ҵ�ԭ���ǣ�ֻ���߼��㹻�򵥣��ſ����ڴ��뼶����Υ����һְ��ԭ��ֻ�����з��������㹻�٣��ſ����ڷ���������Υ����һְ��ԭ��
 *
 */
/*
 * demo��first ��ǰdatabase��Ϊ�������ṩ��ͬ�Ŀͻ��˷��񣬽��ṩ��mysql�Ľӿڷ���
 * ��¶���⣺for oracle function is wrong�������������ݿ�Ľӿڶ�һ��
 * �޸ĳ�DIP second��������ѭ��SRPԭ�򣬵�����Ҫ�޸Ŀͻ��˲����Լ�ԭ����database��Ҫ�ֽ⡣
 *
 * ����һ�ַ�ʽ��database ���ӷ�֧�жϣ�Υ����һְ�ܣ����ǿͻ��˿������ڲ��Ķ���ͬʱҲ���������ķ��ա�
 * ����ͬһ�ӿڵ��麯����ͬʵ�֣���̬��
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
