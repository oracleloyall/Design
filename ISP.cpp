/*
 * author :zhaoxi 接口隔离原则(谈论类间关系，致力于松耦合)
 * 核心理解：“使用多个专门的接口比使用单一的总接口要好”。
 “一个类对另外一个类的依赖性应该建立在最小的接口上”
 *
 *demo: Door可以加锁、解锁、而且可以感知自己是开还是关；
 Door是抽象基类，客户程序可以依赖于抽象而不是具体的实现。

 现在我们要增加一个功能：如果门打开时间过长，它就会报警（比如宾馆客房的门）。
 设计：为了实现上述新增功能，我们要求Door与一个已有的Timer对象进行交互。
 如果一个对象希望得到超时通知，它可以调用Timer的Register函数。
 该函数有两个参数，一个是超时时间，另一个是指向TimerClient对象的指针，此对象的TimerOut函数会在超时时被调用。
 问题出：我们如何将TimerClient和TimedDoor联系起来？
 方案FISRT：Door接口中加入新的方法(Timeout),带来问题，基类的变动仅仅为了子类带来好处，没次增加接口都需要改动基类接口
 基类接口将很快变胖，违反单一职能原则，里氏替换原则。

 方案SECOND：见代码
 方案SECOND：多重继承
 Class TimedDoor:public Door, public TimerClient{
 public:
 virtual void DoorTimeOut(int timeOutID);
 };
 */
#ifdef BASE
class Door {
public:
	virtual void Lock()=0;
	virtual void Unlock()=0;
	virtual bool IsDoorOpen()=0;
};
class TimerClient;
class Timer {
public:
	void Register(int timeout, TimerClient* client);
};

class TimerClient {
public:
	virtual void TimerOut();
};
#endif
#define FIRST//
class Base {
	virtual void TimerOut();
};
class TimerClient;
class Door: public Base {
public:
	virtual void Lock()=0;
	virtual void Unlock()=0;
	virtual bool IsDoorOpen()=0;
	virtual void TimerOut();
};

class Timer {
public:
	void Register(int timeout, Base* client);
};

class TimerClient: public Base {
public:
	virtual void TimerOut();
};
#ifdef FIRST
#else
//增加接口的time door 对象
Class TimedDoor:public Door {
public:
	virtual void DoorTimeOut(int timeOutID);
};
//TimedDoor 对象调用timeout方法(实现该类的原因，Timer 仅支持TimerClient类型对象)
class DoorTimeAdapter:public TimerClient {
	TimedDoor& itsTimedDoor;
public:
	DoorTimerAdapter(TimedDoor& theDoor):itsTimedDoor(theDoor) {}
	vitual void TimeOut(int timeOutId) {
		itsTimedDoor.DoorTimeOut(timeOutId);
	}
};
#endif
