#include "container.h"


RedBlackTree::RedBlackTree(string N, char T) : name(N) {
	itSeq.push_back(data.insert(4).first);
	itSeq.push_back(data.insert(6).first);
	itSeq.push_back(data.insert(7).first);
	itSeq.push_back(data.insert(8).first);
}

RedBlackTree::RedBlackTree(int power, string N) : name(N) {
	for (int i = 0; i < power; ++i) {
		itSeq.push_back(data.insert(rand() % power).first);
	}
}

void RedBlackTree::OR(RedBlackTree val, RedBlackTree& res) {
	res.itSeq.clear();
	res.data.clear();

	set_union<set<int>::const_iterator, set<int>::const_iterator, insert_iterator<set<int>>>

		(data.cbegin(), data.cend(), val.data.cbegin(), val.data.cend(), inserter(res.data, res.data.begin()));

	for (auto it = res.data.cbegin(); it != res.data.cend(); ++it)
		res.itSeq.push_back(it);
}

void RedBlackTree::DIF(RedBlackTree val, RedBlackTree& res) {
	res.itSeq.clear();
	res.data.clear();

	set_difference<set<int>::const_iterator, set<int>::const_iterator, insert_iterator<set<int>>>

		(data.cbegin(), data.cend(), val.data.cbegin(), val.data.cend(), inserter(res.data, res.data.begin()));

	for (auto it = res.data.cbegin(); it != res.data.cend(); ++it)
		res.itSeq.push_back(it);
}




void RedBlackTree::MERGE(RedBlackTree val, RedBlackTree& res) {
	res.itSeq.clear();
	res.data.clear();
	vector<int> temp;

	merge(data.cbegin(), data.cend(), val.data.cbegin(), val.data.cend(), back_inserter(temp));

	for (auto it = temp.cbegin(); it != temp.cend(); ++it) {
		res.itSeq.push_back(res.data.insert(*it).first);
	}
}

void RedBlackTree::CONCAT(RedBlackTree val, RedBlackTree& res) {
	res.itSeq.clear();
	res.data.clear();

	for (auto st = data.cbegin(); st != data.cend(); st++) {
		res.itSeq.push_back(res.data.insert(*st).first);
	}

	for (auto st = val.data.cbegin(); st != val.data.cend(); st++) {
		res.itSeq.push_back(res.data.insert(*st).first);
	}
}

void RedBlackTree::MUL(int p, RedBlackTree& res) {
	res.itSeq.clear();
	res.data.clear();
	for (int i = 0; i < p; i++) {
		for (auto st = data.cbegin(); st != data.cend(); st++) {
			res.itSeq.push_back(res.data.insert(*st).first);
		}
	}
}

//Set output sorted by key
void RedBlackTree::printSet() {
	cout << "\n" << name << " = { ";
	for (auto it = data.cbegin(); it != data.cend(); ++it)
		cout << (*it) << ' ';
	cout << "}" << endl;
}

//Output set sorted by value
void RedBlackTree::printitSeq() {
	cout << "\n" << name << " = { ";
	for (auto it = itSeq.cbegin(); it != itSeq.cend(); ++it)
		cout << (*(*it)) << ' ';
	cout << "}" << endl;
}