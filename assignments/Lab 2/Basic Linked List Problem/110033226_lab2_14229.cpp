#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node *prev;
  Node *next;

  Node(int n):data(n), prev(nullptr), next(nullptr){};
};

class DLL{
public:
  void insert_head(int n);
  void insert_tail(int n);
  void remove_head();
  void remove_tail();
  void search(int n);
  void output();

  bool empty();

  DLL(): head(nullptr), tail(nullptr){};

private:
  Node *head, *tail;
};

DLL dll;

int main(){
  int n;
  cin >> n;

  string s;
  int num;

// cin 遇到空白會切斷並不讀取
  while(n-- && cin >> s){
    if(s == "IT"){
      cin >> num;
      dll.insert_tail(num);
    }
    else if(s == "IH"){
      cin >> num;
      dll.insert_head(num);
    }
    else if(s == "RH") dll.remove_head();
    else if(s == "RT") dll.remove_tail();
    else if(s == "S"){
      cin >> num;
      dll.search(num);
    }
    else if(s == "O") dll.output();
  }
  return 0;
}

void DLL::insert_head(int n){
  Node* newNode = new Node(n);
  // 如果head不存在，head->next語句會導致runtime error
  if(empty()) {
    head = tail = newNode;
    return;
  }
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
}

void DLL::insert_tail(int n){
  Node* newNode = new Node(n);
  if(empty()) {
    head = tail = newNode;
    return;
  }
  newNode->prev=tail;
  tail->next = newNode;
  tail = newNode;
}

void DLL::remove_head(){
  if(empty()) return;
  if(head == tail){
    delete head;
    head = tail = nullptr;
    return;
  }

  head = head->next;
  delete head->prev;
  head->prev = nullptr;
}

void DLL::remove_tail(){
  if(empty()) return;
  if(head == tail){
    delete tail;
    head = tail = nullptr;
    return;
  }

  tail = tail->prev;
  delete tail->next;
  tail->next = nullptr;
}

void DLL::search(int n){
  if(empty()){
    cout << "E\n";
    return;
  }

  Node* curr = head;
  while(curr){
    if(curr->data == n){
      cout << "Y\n";
      return;
    }
    else curr = curr->next;
  }
  cout << "N\n";
}

void DLL::output(){
  if(empty()){
    cout << "E\n";
    return;
  }

  Node* curr = head;
  while(curr){
    if(curr != tail) cout << curr->data << " ";
    else cout << curr->data << endl;
    curr = curr->next;
  }
}

bool DLL::empty(){
  return !head;
}