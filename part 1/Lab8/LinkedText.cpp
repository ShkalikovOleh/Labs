#include "LinkedText.h"
#include <iostream>
#include <fstream>

#pragma region Iterator impl

LinkedText::iterator::iterator() {
	this->node = nullptr;	
}

LinkedText::iterator::iterator(LinkedTextItem* node) {
	this->node = node;
}

LinkedText::iterator::iterator(LinkedTextItem& node) {
	this->node = &node;
}

LinkedText::iterator::iterator(const iterator& iter) {
	this->node = iter.node;
}

LinkedText::iterator& LinkedText::iterator::operator=(const iterator& iter) {
	node = iter.node;
	return *this;
}

LinkedText::iterator& LinkedText::iterator::operator++() {
	node = node->next;	
	return *this;
}

LinkedText::iterator LinkedText::iterator::operator++(int) {
	auto res = iterator(node->next);
	return res;
}

LinkedText::iterator& LinkedText::iterator::operator--() {
	node = node->before;
	return *this;
}

LinkedText::iterator LinkedText::iterator::operator--(int) {
	auto res = iterator(node->before);
	return res;
}

LinkedText::iterator LinkedText::iterator::operator+(number offset) {	
	iterator res = *this;
	while (offset > 0) {
		res = res.node->next;
		offset--;
	}
	return res;
}

LinkedText::iterator& LinkedText::iterator::operator+=(number offset) {
	while (offset > 0) {
		node = node->next;
		offset--;
	}
	return *this;
}

LinkedText::iterator LinkedText::iterator::operator-(number offset) {
	iterator res = *this;
	while (offset > 0) {
		res = res.node->before;
		offset--;
	}
	return res;
}

LinkedText::iterator& LinkedText::iterator::operator-=(number offset) {
	while (offset > 0) {
		node = node->before;
		offset--;
	}
	return *this;
}

bool LinkedText::iterator::operator==(const iterator& iter) {
	return iter.node == this->node;
}

bool LinkedText::iterator::operator!=(const iterator& iter) {
	return !operator==(iter);
}

std::string& LinkedText::iterator::operator*() {
	return node->line;
}

std::string* LinkedText::iterator::operator->() {
	return &node->line;
}

#pragma endregion

#pragma region LinkedText impl

LinkedText::iterator LinkedText::begin() {	
	return iterator(firstItem);
}

LinkedText::iterator LinkedText::end() {
	return iterator(endItem);
}

LinkedText::LinkedText() {
	firstItem = new LinkedTextItem();
	endItem = new LinkedTextItem();	
	firstItem->next = endItem;
	endItem->line = "#";		//Task specific
	endItem->before = firstItem;
	size = 0;
}


LinkedText::~LinkedText() {
	LinkedTextItem *current = firstItem;
	while (current != endItem) {
		current = current->next;
		delete current->before;
	}
	delete endItem;
}

void LinkedText::Write(std::ostream& stream) {
	auto current = firstItem;
	while (current != endItem) {
		stream << current->line << std::endl;
		current = current->next;
	}
	stream << endItem->line << std::endl;
}

void LinkedText::Load(std::istream& stream) {
	std::string line;
	while (std::getline(stream, line)) {
		size_t pos = line.find_first_of("#");
		if (pos < line.size()) {
			if (pos > 0) {
				line = line.substr(0, pos);
				AddLine(line);
			}
			break;
		}
		AddLine(line);
	}
	if (firstItem->next != endItem) {
		RemoveLine(begin());
	}
}

void LinkedText::AddLine(std::string line) {
	LinkedTextItem *add = new LinkedTextItem();
	size_t pos = line.find_first_of('#');
	if (pos < line.size())
		line = line.substr(0, pos);
	add->line = line;
	add->before = endItem->before;
	endItem->before->next = add;
	endItem->before = add;
	add->next = endItem;
	size++;
}

void LinkedText::CopyLine(iterator what, iterator whereAfter) {
	if (!whereAfter.node || !what.node)
		throw std::invalid_argument("Iterator nodes do not exist");
	LinkedTextItem *newItem = new LinkedTextItem();
	newItem->line = *what;
	newItem->next = whereAfter.node->next;
	whereAfter.node->next->before = newItem;
	whereAfter.node->next = newItem;
	newItem->before = whereAfter.node;
	size++;
}

void LinkedText::RemoveLine(LinkedText::iterator rem) {
	if (!rem.node)
		throw std::invalid_argument("Remove elem does not exist");
	if(rem != begin())
		rem.node->before->next = rem.node->next;
	else
		firstItem = firstItem->next;
	rem.node->next->before = rem.node->before;
	delete rem.node;
	size--;
}

void LinkedText::FindLetter(char letter, number &row, number &column) {
	LinkedTextItem* temp = firstItem->next;
	number irow = 1;
	bool isFind = false;
	while (temp != endItem && !isFind) {
		number icolumn = 1;
		for (auto it = temp->line.cbegin(); it != temp->line.cend(); it++) {
			if (*it == letter) {
				row = irow;
				column = icolumn;
				isFind = true;
				break;
			}
			icolumn++;
		}
		temp = temp->next;
		irow++;
	}
}

LinkedText::iterator LinkedText::GetLineWithMaxLetterContains(char letter) {
	LinkedTextItem* temp = firstItem->next;
	number i = 1;
	std::pair<iterator, number> maxPair = std::make_pair(begin(), 0);
	number count;
	for (auto it = begin(); it != end(); ++it) {
		count = 0;
		for (auto strIt = it->begin(); strIt != it->end(); ++strIt) {
			if (*strIt == letter) {
				count++;
			}
		}
		if (count > maxPair.second) {
			maxPair.first = it;
			maxPair.second = count;
		}
	}
	if (maxPair.second == 0)
		throw std::invalid_argument("Letter does not contains");
	return maxPair.first;
}

std::string LinkedText::GetName() {
	return firstItem->line;
}

void LinkedText::SetName(std::string name) {
	firstItem->line = name;
}

number LinkedText::GetSize() {
	return size;
}

#pragma endregion