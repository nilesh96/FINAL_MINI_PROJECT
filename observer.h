#ifndef OBSERVER_H
#define OBSERVER_H
class Iobserver
{
   public:
        Iobserver()  {  }
	virtual ~ Iobserver() {  }
	virtual void update (float ,char) = 0;

};
#endif
