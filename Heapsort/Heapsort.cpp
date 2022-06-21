#include <iostream>
#include <fstream>
#include <vector>

struct Heap {
    std::vector<int> tree;

    Heap() {
        tree.push_back(0);
    }

    void push(int x) {
        tree.push_back(x);
        sift_up(tree.size() - 1);
    }

    int max() {
        if (tree.size() > 1) {
            return tree[1];
        }
        else {
            return -1;
        }
    }

    void pop() {
        if (tree.size() > 1) {
            tree[1] = tree.back();
            tree.pop_back();
            sift_down(1);
        }
        else {
            std::cout << "куча пуста";
            return;
        }
    }


    void sift_up(int v) {
        if (v == 1) {
            return;
        }

        if (tree[v / 2] > tree[v]) {
            std::swap(tree[v], tree[v / 2]);
            sift_up(v / 2);
        }
    }


    void sift_down(int v) {
        if (v * 2 >= tree.size()) {
            return;
        }


        int max_idx;
        if (v * 2 + 1 == tree.size()) {
            max_idx = v * 2;
        }
        else if (tree[v * 2] >= tree[v * 2 + 1]) {
            max_idx = v * 2;
        }
        else {
            max_idx = v * 2 + 1;
        }

        if (tree[v] < tree[max_idx]) {
            std::swap(tree[v], tree[max_idx]);
            sift_down(max_idx);
        }
    }

    bool empty() {
        return tree.size() == 1;
    }
};

int main()
{
    std::ifstream inp("heapsort.in");
    std::ofstream out("heapsort.out");

    int n;
    inp >> n;

    std::vector<int> mas(n);

    Heap* heap = new Heap();

    for (int i = 1; i <= n; i++) {
        heap->tree.push_back(i);
    }

    for (int i = 2; i < heap->tree.size()-1; i++) {
        std::swap(heap->tree[1], heap->tree[i]);
        heap->sift_up(i);
    }
    std::swap(heap->tree[1], heap->tree[heap->tree.size() - 1]);

    for (int i = 1; i < heap->tree.size(); i++) {
        out << heap->tree[i] << ' ';
    }
}

