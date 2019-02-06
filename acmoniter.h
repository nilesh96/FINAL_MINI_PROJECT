#ifndef acmoniter_h
#define acmoniter_h
#include"observer.h"
class CAcmoniter:public Iobserver
{
   private:
      float value ;
      char temp_state;
      int id;	
   public:
        CAcmoniter() = default;
        CAcmoniter(int);
	void update(float,char)override;
	void check();
	static void * Thread2(void *);
};
#endif
