#ifndef SRC_TIMER_H_
#define SRC_TIMER_H_

class TimerAdapter {
public:
  virtual ~TimerAdapter();
  virtual void timeExpired();
};

class Timer {
public:
  enum RecurringType { IS_RECURRING };
  Timer(TimerAdapter*, RecurringType, unsigned long);
};

#endif // SRC_TIMER_H_ 