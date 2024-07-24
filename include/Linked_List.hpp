#ifndef __Linked_List__
#define __Linked_List__
#include <iostream>
#include <vector>
#include <utility>

namespace ll
{
    template <class T>
    struct Node
    {
        T val;
        Node<T>* next;
        Node(T a) : val(a), next(nullptr) {}
    };

    template <class T>
    class Linked_List
    {
        private:
        Node<T>* head;

        public:
        Linked_List();
        ~Linked_List();
        void insert_at_start(T);
        void insert_at_end(T);
        void insert_at_pos(T, int);
        void delete_at_start();
        void delete_at_end();
        void delete_at_pos(int);
        Node<T>* search(T);
        int list_length();
        Node<T>& operator[](int);
        void print();
        void add_circularity(int); //connects end node to the node position given, not zero indexed
        std::pair<int, bool> check_circularity_vector();
    };

    template <class T>
    Linked_List<T>::Linked_List() : head(nullptr) {}

    template <class T>
    Linked_List<T>::~Linked_List()
    {
        std::pair<int, bool> pair = check_circularity_vector();
        if(head == NULL)
        {
            return;
        }
        else if(!pair.second)
        {
            Node<T>* temp = NULL;
            while(head != NULL)
            {
                temp = head;
                head = head->next;
                delete temp;
            }
        }
        else
        {
            Node<T>* temp = head, *temp1;
            for(int i=1; i<pair.first; i++)
                temp = temp->next;
            while(head->next != temp)
            {
                temp1 = head;
                head = head->next;
                delete temp1;
            }
        }
    }

    template <class T>
    void Linked_List<T>::insert_at_start(T new_data)
    {
        Node<T>* temp = new Node<T>(new_data);
        temp->next = head;
        head = temp;
    }

    template <class T>
    void Linked_List<T>::insert_at_end(T new_data)
    {
        if(head == NULL)
        {
            Node<T>* temp = new Node<T>(new_data);
            temp->next = head;
            head = temp;
        }
        else
        {
            Node<T>* temp = head; 
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = new Node<T>(new_data);
        }
    }

    template <class T>
    void Linked_List<T>::insert_at_pos(T new_data, int pos)
    {
        if(head == NULL)
        {
            Node<T>* temp = new Node<T>(new_data);
            temp->next = head;
            head = temp;
        }
        else if(pos == 0)
        {
            insert_at_start(new_data);
        }
        else if(pos > 0)
        {
            Node<T>* temp = head; 
            for(int i = 1; i < pos; i++)
                temp = temp->next;
            Node<T>* temp1 = temp->next;
            temp->next = new Node<T>(new_data);
            (temp->next)->next = temp1;
        }
    }

    template <class T>
    void Linked_List<T>::delete_at_start()
    {
        if(head == NULL)
            return;
        else
        {
            Node<T>* temp = head->next;
            delete head;
            head = temp;
        }
    }

    template <class T>
    void Linked_List<T>::delete_at_end()
    {
        if(head == NULL)
            return;
        else if(head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node<T>* temp = head;
            while((temp->next)->next != NULL)
                temp = temp->next;
            delete temp->next;
            temp->next = NULL;
        }
    }

    template <class T>
    void Linked_List<T>::delete_at_pos(int pos)
    {
        if(head == NULL)
            return;
        else if(pos == 0)
        {
            delete_at_start();
        }
        else
        {
            Node<T>* temp = head;
            for(int i = 1; i < pos; i++)
                temp = temp->next;
            Node<T>* temp1 = temp->next;
            temp->next = temp1->next;
            delete temp1;
        }
    }

    template <class T>
    Node<T>* Linked_List<T>::search(T search_val)
    {
        if(head == NULL)
        {
            return NULL;
        }
        else
        {
            Node<T>* temp = head;
            while(temp->next != NULL)
            {
                if(temp->val == search_val)
                    return temp;
                temp = temp->next;
            }
            return NULL;
        }
    }

    template <class T>
    int Linked_List<T>::list_length()
    {
        int length = 0;
        Node<T>* temp = head;
        while(temp != NULL)
        {
            temp = temp->next;
            length++;
        }
        return length;
    }

    template<class T>
    Node<T>& Linked_List<T>::operator[](int index)
    {
        Node<T>* temp = head;
        for(int i = 0; i < index; i++)
            temp = temp->next;
        return *temp;
    }

    template <class T>
    void Linked_List<T>::print()
    {
        Node<T>* temp = head;
        while(temp != NULL)
        {
            std::cout << temp->val << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    template <class T>
    void Linked_List<T>::add_circularity(int pos)
    {
        if(list_length() < pos || pos < 1)
            return;

        Node<T> *end_node, *node_to_attach = head;
        for(int i=1; i<pos; i++)
            node_to_attach = node_to_attach->next;
        end_node = node_to_attach;
        while(end_node->next != NULL)
            end_node = end_node->next;
        end_node->next = node_to_attach;    
    }

    template <class T>
    std::pair<int, bool> Linked_List<T>::check_circularity_vector()
    {
        std::vector<Node<T>*> pointer_list;
        Node<T>* it = head;
        while(it != NULL)
        {
            for(int i=0; i<pointer_list.size(); i++)
            {
                if(it == pointer_list[i])
                    return std::make_pair(++i,true);
            }
            pointer_list.push_back(it);
            it = it->next;
        }
        return std::make_pair(0,false);
    }
}

namespace dll
{
    template <class T>
    struct Node
    {
        T val;
        Node<T>* next;
        Node<T>* prev;
        Node(T a) : val(a), next(nullptr), prev(nullptr) {}
    };

    template <class T>
    class Doubly_Linked_List
    {
        private:
        Node<T>* head;

        public:
        Doubly_Linked_List();
        ~Doubly_Linked_List();
        void insert_at_start(T);
        void insert_at_end(T);
        void insert_at_pos(T, int);
        void delete_at_start();
        void delete_at_end();
        void delete_at_pos(int);
        Node<T>* search(T);
        int list_length();
        Node<T>& operator[](int);
        void print();
    };

    template <class T>
    Doubly_Linked_List<T>::Doubly_Linked_List() : head(nullptr) {}

    template <class T>
    Doubly_Linked_List<T>::~Doubly_Linked_List()
    {
        if(head == NULL)
            return;
        else
        {
            Node<T>* temp = head;
            while(head != NULL)
            {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
    }

    template <class T>
    void Doubly_Linked_List<T>::insert_at_start(T new_val)
    {
        if(head == NULL)
            head = new Node<T>(new_val);
        else
        {
            Node<T>* temp = new Node<T>(new_val);
            temp->next = head;
            head = temp;
        }
    }

    template <class T>
    void Doubly_Linked_List<T>::insert_at_end(T new_val)
    {
        if(head == NULL)
            head = new Node<T>(new_val);
        else
        {
            Node<T>* temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = new Node<T>(new_val);
            (temp->next)->prev = temp;
        }
    }

    template <class T>
    void Doubly_Linked_List<T>::insert_at_pos(T new_val, int pos)
    {
        if(head == NULL)
            head = new Node<T>(new_val);
        else
        {
            Node<T>* temp = head;
            for(int i = 1; i < pos; i++)
                temp = temp->next;
            Node<T>* temp1 = new Node<T>(new_val);
            temp1->next = temp->next;
            temp1->prev = temp;
            temp->next = temp1;
        }
    }

    template <class T>
    void Doubly_Linked_List<T>::delete_at_start()
    {
        if(head == NULL)
            return;
        else
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    template <class T>
    void Doubly_Linked_List<T>::delete_at_end()
    {
        if(head == NULL)
            return;
        else if(head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node<T>* temp = head;
            while((temp->next)->next != NULL)
                temp = temp->next;
            delete temp->next;
            temp->next = NULL;
        }
    }

    template <class T>
    void Doubly_Linked_List<T>::delete_at_pos(int pos)
    {
        if(head == NULL)
            return;
        else if(pos == 0)
        {
            delete_at_start();
        }
        else
        {
            Node<T>* temp = head;
            for(int i = 1; i < pos; i++)
                temp = temp->next;
            Node<T>* temp1 = temp->next;
            temp->next = temp1->next;
            delete temp1;
        }
    }

    template <class T>
    Node<T>* Doubly_Linked_List<T>::search(T search_val)
    {
        if(head == NULL)
        {
            return NULL;
        }
        else
        {
            Node<T>* temp = head;
            while(temp->next != NULL)
            {
                if(temp->val == search_val)
                    return temp;
                temp = temp->next;
            }
            return NULL;
        }
    }

    template <class T>
    int Doubly_Linked_List<T>::list_length()
    {
        int length = 0;
        Node<T>* temp = head;
        while(temp != NULL)
        {
            temp = temp->next;
            length++;
        }
        return length;
    }

    template<class T>
    Node<T>& Doubly_Linked_List<T>::operator[](int index)
    {
        Node<T>* temp = head;
        for(int i = 0; i < index; i++)
            temp = temp->next;
        return *temp;
    }

    template <class T>
    void Doubly_Linked_List<T>::print()
    {
        Node<T>* temp = head;
        while(temp != NULL)
        {
            std::cout << temp->val << " <--> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
}

#endif