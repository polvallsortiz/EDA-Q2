//
// Created by Pol Valls Ortiz on 02/04/2017.
//
#include "BST.hh"
#include <iostream>
using namespace std;

int main() {
	BST b;
	b.insert_elem(6);
	b.insert_elem(8);
	b.insert_elem(4);
	b.delete_elem(4);
	b.insert_elem(5);
	b.insert_elem(-1);
	b.delete_elem(6);
	b.insert_elem(10);
	b.insert_elem(20);
	b.insert_elem(0);
	b.insert_elem(15);
	b.insert_elem(16);
	b.insert_elem(22);
	b.escriure();
}