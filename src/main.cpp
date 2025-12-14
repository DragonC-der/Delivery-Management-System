#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string order_id;
    string customer_name;
    string delivery_address;
    Node* next;

    Node(string id, string name, string address)
    {
        order_id = id;
        customer_name = name;
        delivery_address = address;
        next = NULL;
    }
};

class Delivery_Management_System
{
    Node* start;
public:
    Delivery_Management_System()
    {
        start = NULL;
    }

    bool order_id_exists(string id)
    {
        Node* temp = start;
        while (temp!=NULL)
        {
            if (temp->order_id == id)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void add_order()
    {
        string id, name, address;
        cout << "Enter Order ID: ";
        cin >> id;
        while (order_id_exists(id))
        {
            cout << "Order ID already exists. Enter unique ID: ";
            cin >> id;
        }
        cout << "Enter customer name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears '\n'
        getline(cin, name);
        cout << "Enter delivery address: ";
        getline(cin, address);
        Node* newNode = new Node(id, name, address);
        if (start==NULL)
        {
            start = newNode;
        }
        else
        {
            Node* temp = start;
            while (temp->next!=NULL)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Order added successfully.\n";
    }

    void display()
    {
        if (start==NULL)
        {
            cout << "No delivery records.\n";
            return;
        }

        Node* temp = start;
        int sn = 1;
        cout << "\nPending Deliveries:\n";
        cout << "---------------------\n";
        while (temp!=NULL)
        {
            cout << "SN: " << sn++ << '\n';
            cout << "Order ID: " << temp->order_id << '\n';
            cout << "Customer: " << temp->customer_name << '\n';
            cout << "Address: " << temp->delivery_address << '\n';
            cout << "---------------------\n";
            temp = temp->next;
        }
    }

    void cancel_by_id()
    {
        if (start==NULL)
        {
            cout << "No orders to cancel.\n";
            return;
        }
        string id;
        cout << "Enter Order ID to cancel: ";
        cin >> id;
        if (start->order_id == id)
        {
            Node* del = start;
            start = start->next;
            delete del;
            cout << "Order cancelled successfully.\n";
            return;
        }
        Node* temp = start;
        while (temp->next!=NULL && temp->next->order_id != id)
        {
            temp = temp->next;
        }
        if (temp->next==NULL)
        {
            cout << "Order ID not found.\n";
            return;
        }
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "Order cancelled successfully.\n";
    }

    void reschedule_by_order_id()
    {
        if (start==NULL || start->next==NULL)
        {
            cout << "Not enough deliveries to reschedule.\n";
            return;
        }
        string move_id, after_id;
        cout << "Enter Order ID to reschedule: ";
        cin >> move_id;
        cout << "Enter Order ID after which order to be placed: ";
        cin >> after_id;
        if (move_id == after_id)
        {
            cout << "Same order ID provided. No changes made.\n";
            return;
        }
        Node* prevNode = NULL;
        Node* moveNode = start;
        while (moveNode!=NULL && moveNode->order_id != move_id)
        {
            prevNode = moveNode;
            moveNode = moveNode->next;
        }
        if (moveNode==NULL)
        {
            cout << "Order to reschedule not found.\n";
            return;
        }
        Node* afterNode = start;
        while (afterNode!=NULL && afterNode->order_id != after_id)
        {
            afterNode = afterNode->next;
        }
        if (afterNode==NULL)
        {
            cout << "Target order ID not found.\n";
            return;
        }
        if(prevNode==NULL){start = moveNode->next;}
        else{prevNode->next = moveNode->next;}
        moveNode->next = afterNode->next;
        afterNode->next = moveNode;
        cout << "Delivery rescheduled successfully.\n";
    }

    void ultimate_menu()
    {
        while (true)
        {
            int choice;
            cout << "\n1. Add order\n2. Cancel order\n3. Show deliveries\n4. Reschedule delivery (by Order ID)\n5. Exit\nChoose: ";
            cin >> choice;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Try again.\n";
                continue;
            }
            switch (choice)
            {
                case 1: add_order(); break;
                case 2: cancel_by_id(); break;
                case 3: display(); break;
                case 4: reschedule_by_order_id(); break;
                case 5:
                    cout << "Thank you for using the system.\n";
                    return;
                default:
                    cout << "Invalid choice.\n";
            }
        }
    }
};

int main()
{
    cout << "Delivery Management System\n";
    Delivery_Management_System dms;
    dms.ultimate_menu();
    return 0;
}