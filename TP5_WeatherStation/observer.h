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
  /**
   * @brief ~Observable destructor, clear observer list
   */
  virtual ~Observable(){
    observants.clear();
  };
  /**
   * @brief addObserver - add an observer
   * @param observer the observer to add
   */
  void addObserver(Observer* observer){
    observants.append(observer);
  };
   /**
   * @brief removeObserver - remove an observer
   * @param observer the observer to remove
   */
  void removeObserver(Observer* observer){
    observants.removeAll(observer);
  };
  /**
   * @brief notifyObserver - call the update methode of all observer
   */
  void notifyObserver(){
    for(Observer* observer : observants){
        observer->update();
    }
  };
};

#endif // OBSERVER_H
