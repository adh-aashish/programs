#include <iostream>
#define max 2

struct Node {
	int data;
	int next;
};

class List {
  private:
	Node list[max];
	int avail;
	int head;

  public:
	List() {
		for (int i = 0; i < max; i++) {
			list[i] = Node{0, i + 1};
		}
		list[max - 1].next = -1;
		avail = 0;
		head = -1;
	}
	void insert_begin(int data) {
		if (avail == -1) {
			throw "Overflow";
		}
		int next_head = avail;
		list[avail].data = data;
		int temp = list[avail].next;
		list[avail].next = head;
		avail = temp;
		head = next_head;
	}
	void insert_end(int data) {
		if (avail == -1) {
			throw "Overflow";
		}
		if (head == -1) {
			insert_begin(data);
		} else {
			int temp = head;
			while (list[temp].next != -1) {
				temp = list[temp].next;
			}
			int next_avail = list[avail].next;
			list[avail].data = data;
			list[avail].next = -1;
			list[temp].next = avail;
			avail = next_avail;
		}
	}

	int delete_begin() {
		if (head == -1) {
			throw "Underflow";
		}
		int head_data = list[head].data;
		int head_next = list[head].next;
		list[head].next = avail;
		avail = head;
		head = head_next;
		return head_data;
	}
	int delete_end() {
		if (head == -1) {
			throw "Underflow";
		}
		int temp = head;
		int prev = -1;
		while (list[temp].next != -1) {
			prev = temp;
			temp = list[temp].next;
		}
		int data = list[temp].data;
		if (prev == -1) {
			avail = 0;
			head = -1;
		} else {
			list[prev].next = -1;
			list[temp].next = avail;
			avail = temp;
		}
		return data;
	}

	void insert_after(int value, int data) {
		if (avail == -1) {
			throw "Full list";
		}
		int temp = head;
		while (list[temp].data != value && temp != -1) {
			temp = list[temp].next;
		}
		if (temp == -1) {
			throw "Element not found";
		}
		int avail_next = list[avail].next;
		list[avail].data = data;
		list[avail].next = list[temp].next;
		list[temp].next = avail;
		avail = avail_next;
	}

	int delete_after(int value) {
		if (head == -1) {
			throw "Full list";
		}

		int temp = head;
		while (list[temp].data != value && temp != -1) {
			temp = list[temp].next;
		}
		if (temp == -1) {
			throw "Element not found";
		}
		if (list[temp].next == -1) {
			throw "Nothing after the given value";
		}
		int to_be_deleted = list[temp].next;
		int data = list[temp].data;
		list[temp].next = list[to_be_deleted].next;
		list[to_be_deleted].next = avail;
		avail = to_be_deleted;
		return data;
	}
	void print() {
		if (head == -1) {
			throw "Empty list.";
		}
		Node temp = list[head];
		while (temp.next != -1) {
			std::cout << temp.data << " ";
			temp = list[temp.next];
		}
		std::cout << temp.data << " ";
		std::cout << std::endl;
	}
};

int main() {
	List l;
	try {
		l.insert_begin(5);
		l.insert_end(20);
		l.insert_end(44);
		l.delete_after(5);
		l.print();
	} catch (const char *e) {
		std::cerr << e << std::endl;
	}
}
