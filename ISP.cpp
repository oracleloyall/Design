/*
 * author :zhaoxi �ӿڸ���ԭ��(̸������ϵ�������������)
 * ������⣺��ʹ�ö��ר�ŵĽӿڱ�ʹ�õ�һ���ܽӿ�Ҫ�á���
 ��һ���������һ�����������Ӧ�ý�������С�Ľӿ��ϡ�
 *
 *demo: Door���Լ��������������ҿ��Ը�֪�Լ��ǿ����ǹأ�
 Door�ǳ�����࣬�ͻ�������������ڳ�������Ǿ����ʵ�֡�

 ��������Ҫ����һ�����ܣ�����Ŵ�ʱ����������ͻᱨ����������ݿͷ����ţ���
 ��ƣ�Ϊ��ʵ�������������ܣ�����Ҫ��Door��һ�����е�Timer������н�����
 ���һ������ϣ���õ���ʱ֪ͨ�������Ե���Timer��Register������
 �ú���������������һ���ǳ�ʱʱ�䣬��һ����ָ��TimerClient�����ָ�룬�˶����TimerOut�������ڳ�ʱʱ�����á�
 �������������ν�TimerClient��TimedDoor��ϵ������
 ����FISRT��Door�ӿ��м����µķ���(Timeout),�������⣬����ı䶯����Ϊ����������ô���û�����ӽӿڶ���Ҫ�Ķ�����ӿ�
 ����ӿڽ��ܿ���֣�Υ����һְ��ԭ�������滻ԭ��

 ����SECOND��������
 ����SECOND�����ؼ̳�
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
//���ӽӿڵ�time door ����
Class TimedDoor:public Door {
public:
	virtual void DoorTimeOut(int timeOutID);
};
//TimedDoor �������timeout����(ʵ�ָ����ԭ��Timer ��֧��TimerClient���Ͷ���)
class DoorTimeAdapter:public TimerClient {
	TimedDoor& itsTimedDoor;
public:
	DoorTimerAdapter(TimedDoor& theDoor):itsTimedDoor(theDoor) {}
	vitual void TimeOut(int timeOutId) {
		itsTimedDoor.DoorTimeOut(timeOutId);
	}
};
#endif
