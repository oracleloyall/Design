/*
 * author :zhaoxi 里氏替换原则分析(谈论继承和多态)
 * 核心理解：
 * 子类能够扩展父类的功能。 但不能改变父类原有的功能
 它包括下面4层含义：
 子类能够实现父类的抽象方法， 但不能覆盖父类的非抽象方法.
 子类中能够添加自己特有的方法.
 当子类的方法重载父类的方法时，方法的前置条件（即方法的形參） 要比父类方法的输入參数更宽松.
 当子类的方法实现父类的抽象方法时，方法的后置条件（即方法的返回值）要比父类更严格.
 里氏替换原则的定义是，所有引用基类的地方必须能透明地使用其子类的对象。
 通俗来讲是只要父类能出现的地方子类就可以出现，而且替换为子类也不会产生任何错误和异常。
 */
/*
 * demo：(两个典型案例)
 * 1：长方体,正方体（正方体继承长方体）问题根源是：设置长度，设置宽度的方法不一致（不能作为公有接口）
 * 2：鸵鸟不会飞行，没有速度
 */
#ifdef FIRST
int main() {
	//LSP原则：父类出现的地方必须能用子类替换
	Rectangle* r = new Rectangle(); //Square *r = new Square();

	r->setWidth(5);
	r->setHeight(4);

	printf("Area = %d\n", r->getArea()); //当用子类时，结果是16。用户就不
										 //明白为什么长5，宽4的结果不是20，而是16.
										 //所以正方形不能代替长方形。即正方形不能
										 //继承自长方形的子类
	return 0;
}
#else
//长方形和正方形求面积方法一致 抽象QuadRangle类
int main() {
	//LSP原则：父类出现的地方必须能用子类替换
	QuadRangle* q = new Rectangle(5, 4); //Rectangle* q = new Rectangle(5, 4);或Square *q = new Square(5);

	printf("Area = %d, Perimeter = %d\n", q->getArea(), q->getPerimeter());

	return 0;
}
#endif



