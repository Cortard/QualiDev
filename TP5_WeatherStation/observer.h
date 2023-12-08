#ifndef OBSERVER_H
#define OBSERVER_H

#include <QList>

/**
 * @brief The Observer class
 */
class Observer {
public:
  virtual ~Observer() =default;
  virtual void update() = 0;
};

/**
 * @brief The Observable class
 */
class Observable {
protected :
  QList<Observer*> observants;

public:
  virtual ~Observable(){
    observants.clear();
  };
  void addObserver(Observer* observer){
    observants.append(observer);
  };
  void removeObserver(Observer* observer){
    observants.removeAll(observer);
  };
  void notifyObserver(){
    for(Observer* observer : observants){
        observer->update();
    }
  };
};

#endif // OBSERVER_H
