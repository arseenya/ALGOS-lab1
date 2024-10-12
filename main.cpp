#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    int listLength;

public:
    LinkedList() {
        head = nullptr; // ������� Node*, ����� ���������������� ���� ������
        listLength = 0;
    }

    void push(int value) { // ��������� ������� � ������ ������
        Node* newValue = new Node;
        newValue->data = value;
        if (listLength > 0)
            newValue->next = head;
        else
            newValue->next = nullptr;
        head = newValue;
        listLength++;
    }

    void pop() { // ������� ������� �� ������ ������
        if (listLength > 0) {
            Node* currValue = head;
            head = currValue->next;
            delete currValue;
            listLength--; // ���������� ����� ������ ������ ��������
        }
        else {
            cout << "List is empty, you can't delete value!" << endl;
        }
    }

    int isEmpty() {
        return listLength == 0;
    }

    int peek() { // ���������� �������� ������� �������� ��� ��� ��������
        if (head != nullptr)
            return head->data;
        throw runtime_error("List is empty");
    }

    void printList() {
        cout << "Stack contains " << listLength << " element(s):\n";
        Node* currValue = head;
        for (int i = 0; i < listLength; i++) {
            cout << i + 1 << " - " << currValue->data << "\n";
            currValue = currValue->next; // ���������� ��������� �� ��������� �������
        }
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* currValue = head;
            head = head->next;
            delete currValue;
        }
    }
};

int main() {
    setlocale(0, "");
    LinkedList st;
    cout << st.isEmpty() << "\n";
    st.push(5);
    st.push(6);
    st.printList();
    st.pop();
    cout << st.peek() << "\n";

    return 0;
}