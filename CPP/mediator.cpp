

#include <iostream>
#include <string>
#include <memory>


using namespace std;
class BaseComponent;

class Mediator: public enable_shared_from_this<Mediator> {
 public:
  virtual void Notify(std::string event) const = 0;
};

class BaseComponent : public enable_shared_from_this<BaseComponent> {
 protected:
  weak_ptr<Mediator> mediator_;

 public:
  BaseComponent() : mediator_() {
  }
  void set_mediator(shared_ptr<Mediator> mediator) {
    mediator_ = mediator;
  }
};

class Component1 : public BaseComponent {
 public:
  void DoA() {
    std::cout << "Component 1 does A.\n";
    if(auto w_mediator_ = mediator_.lock())
      w_mediator_->Notify("A");
  }
  void DoB() {
    std::cout << "Component 1 does B.\n";
    if(auto w_mediator_ = mediator_.lock())
      w_mediator_->Notify("B");
  }
};

class Component2 : public BaseComponent {
 public:
  void DoC() {
    std::cout << "Component 2 does C.\n";
    if(auto w_mediator_ = mediator_.lock())
      w_mediator_->Notify("C");
  }
  void DoD() {
    std::cout << "Component 2 does D.\n";
    if(auto w_mediator_ = mediator_.lock())
      w_mediator_->Notify("D");
  }
};


class ConcreteMediator : public Mediator {
 private:
  shared_ptr<Component1> component1_;
  shared_ptr<Component2> component2_;

 public:
  ConcreteMediator(shared_ptr<Component1> c1, shared_ptr<Component2> c2) : component1_(c1), component2_(c2) {
   
  }

  void set_mediators() {
    component1_->set_mediator(shared_from_this());
    component2_->set_mediator(shared_from_this());
  }
  void Notify(std::string event) const override {
    if (event == "A") {
      std::cout << "Mediator reacts on A and triggers following operations:\n";
      component2_->DoC();
    }
    if (event == "D") {
      std::cout << "Mediator reacts on D and triggers following operations:\n";
      component1_->DoB();
      component2_->DoC();
    }
  }
};

void ClientCode() {
  auto c1 = make_shared<Component1>();
  auto c2 = make_shared<Component2>();
  auto mediator = make_shared<ConcreteMediator>(c1, c2);
  mediator->set_mediators();
  std::cout << "Client triggers operation A.\n";
  c1->DoA();
  std::cout << "\n";
  std::cout << "Client triggers operation D.\n";
  c2->DoD();

}

int main() {
  ClientCode();
  return 0;
}
