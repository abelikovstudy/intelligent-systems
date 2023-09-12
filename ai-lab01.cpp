// ai-lab01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <deque>

struct Node {
    Node* parent;
    int value;
};

class Tree {

};

int main()
{
    int start = 2, end = 100;
    std::deque<Node> front;
    Node startNode;
    startNode.parent = NULL;
    startNode.value = 2;

    front.push_back(startNode);
    while (!front.empty()) {
        Node variant = front.front();
        front.pop_front();
        if (variant.value == end) {

            for (int i = front.size() - 1; i >= 0; i--) {
                std::cout << front[i].value << " ";
            }

            std::cout << front.size() << std::endl;
        }

        if (variant.value > end) {
            continue;
        }
        else {
            Node doubled;
            doubled.parent = &variant;
            doubled.value = variant.value * 2;

            Node plused;
            plused.parent = &variant;
            plused.value = variant.value + 3;

            front.push_back(doubled);
            front.push_back(plused);
        }
    }
}
