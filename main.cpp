#include <iostream>


using namespace std;

template<typename T>
class list {
private:
    struct Node {
        T val; //значение, которое будет задавать пользователь
        Node* next; //указатель на следующий элемент (по умолчанию nul
        //Node* previous;
        Node(T _val) : val(_val), next(nullptr) {}
    };
    Node* first; //Указатель на первый узел
    Node* last; //Указатель на последний узел
public:
    list() : first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(T _val) {
         Node* p = new Node(_val); //в любом случае при добaвлении элемента
         //сначала создаем сам узел со значение, которое мы передали в эту функцию
         if(is_empty()) { //если лист пустой, присваиваем указателю на первый и последний указатель на новый узел и выходим
             first = p;
             last = p;
             return;
         }

         last->next = p;
         last = p;
    }

    void print() {
        if(is_empty()) {
            return;
        }
        Node* p = first;
        while(p) { //p != nullptr
            cout << p->val << " ";
            p = p->next;
        }

        cout << endl;
    }

    Node* find(T _val) {
         Node* p = first;
        while(p && p->val != _val) p = p->next;
        return (p && p->val == _val) ? p : nullptr;
    }

    void remove_first() {
        if(is_empty()) return;
        Node* p = first;
        first = p->next; //меняем значение первого узла на следующий
        delete p; //удаляем узел
    }

    void remove_last() {
        //когда конец списка одновременно и начало
        //и когда размер списка больше одного
        if(is_empty()) return;
        if(first == last) {
            remove_first();
            return;
        }
        Node* p = first;
        while(p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }

    void remove(T _val) {
        if(is_empty()) return;

        if(first->val == _val) {
            remove_first();
            return;
        } else if(last->val == _val) {
            remove_last();
            return;
        }
        Node* slow = first;
        Node* fast = first->next;
        while(fast && fast->val != _val) {
            fast = fast->next;
            slow = slow->next;
        }
        if(!fast) {
            cout << "This element does not exist" << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }

    Node* operator[] (const int index) {
        if(is_empty()) return nullptr;
        Node* p = first;
        for(int i = 0; i < index; i++) {
            p = p->next;
            if(!p) return nullptr;
        }
        return p;
    }
};

int main() {
    list<int> l;
    cout << l.is_empty() << endl; //1
    l.push_back(123);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.print();
    l.find(4);
    cout << l.find(4)->val << endl;
    l.remove(2);
    l.print();
    for(int i = 1; i < 3 + 1; i++)
    cout << l[i]->val << endl;
    return 0;
}
