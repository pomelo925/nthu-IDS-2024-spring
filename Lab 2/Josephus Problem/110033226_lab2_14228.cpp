// https://acm.cs.nthu.edu.tw/contest/2956/

#include <iostream>
#include <queue>

int main() {
    int n;
    std::cin >> n;

    std::queue<int> children;
    for (int i = 1; i <= n; ++i) children.push(i);

    while (!children.empty()) {
        // Move the first child to the end of the queue.
        children.push(children.front());
        children.pop();

        // The next child is removed (every second child).
        std::cout << children.front();
        children.pop();

        if (!children.empty()) std::cout << " "; // Print a space after each number except the last on
    }
    return 0;
}