#include<boost/any.hpp>
#include<iostream>
#include<list>
#include<string>
void test_boost_any()
{
	std::list<boost::any> any_list;
	any_list.push_back(12);
	any_list.push_back(std::string("zhaoxi"));
	//typedef  std::list<boost::any>::const_iterator it;
	for(auto it=any_list.begin();it!=any_list.end();it++)
	{
    if(a.type()==typeid(int)){
			std::cout<<"data num:"<<boost::any_cast<int>(a)<<std::endl;
		}else if(a.type()==typeid(std::string)){
			std::cout<<"data string :"<<boost::any_cast<std::string>(a)<<std::endl;
		}
	}
	for(auto const &a : any_list)
	{
		if(a.type()==typeid(int)){
			std::cout<<"data num:"<<boost::any_cast<int>(a)<<std::endl;
		}else if(a.type()==typeid(std::string)){
			std::cout<<"data string :"<<boost::any_cast<std::string>(a)<<std::endl;
		}
	}
}
int main(int argc,char **argv)
{
	test_boost_any();
	return 0;
}
