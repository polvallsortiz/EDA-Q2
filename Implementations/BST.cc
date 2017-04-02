//
// Created by Pol Valls Ortiz on 02/04/2017.
//

#include "BST.hh"
#include <iostream>

using namespace std;

node* BST::search_position_ant(node* actual, int elem) {
    if(actual->x < elem) { // A LA DRETA
        if(actual->right == nullptr or actual->right->x == elem) return actual;
        else return search_position_ant(actual->right,elem);
    }
    else if(actual->x > elem) { //A L'ESQUERRA
        if(actual->left == nullptr or actual->left->x == elem) return actual;
        else return search_position_ant(actual->left,elem);
    }
	else if(actual->x == elem) return actual; //ROOT
}

BST::BST() {
	root = nullptr;
	size = 0;
}

void BST::insert_elem(int elem) {
    node* n;
    n = new node;
    n->x = elem;
	n->left = nullptr;
	n->right = nullptr;
    if(size == 0) {
	    root = n;
	    n->nivell = 0;
    }
    else {
        node* aux = search_position_ant(root,elem);
        if(aux->x > elem) {
	        aux->left = n;
	        n->nivell = aux->nivell+1;
        } //A ESQUERRA
        else if(aux->x < elem) {
	        aux->right = n;
	        n->nivell = aux->nivell+1;
        } //A DRETA
        else {
		        delete n;
		        --size;
	        }
    }
	++size;
}

void BST::delete_elem(int elem) {
    node* n;
    n=search_position_ant(root,elem);
	if(n->left->x == elem) {
		node* aux = n->left;
		n->left = nullptr;
		delete aux;
		--size;
	}
	else if(n->right->x == elem) {
		node* aux = n->right;
		n->right = nullptr;
		delete aux;
		--size;
	}
	else if(n == root) {
		root = nullptr;
		delete n;
		size = 0;
		size = 0;
		--size;
	}
}

void BST::escriure_fills(node *actual) {
	cout << actual->x << " amb nivell " << actual->nivell << endl;
	if(actual->left) {
		cout << "FILL ESQUERRA DE " << actual->x << " ";
		escriure_fills(actual->left);
	}
	if(actual -> right) {
		cout << "FILL DRET DE " << actual->x << " ";
		escriure_fills(actual->right);
	}
}

void BST::escriure () {
	if(root)escriure_fills(root);
	else cout << "BST Empty" << endl;
}