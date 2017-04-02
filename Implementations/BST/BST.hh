//
// Created by Pol Valls Ortiz on 02/04/2017.
//

#ifndef PROJECT_BST_HH
#define PROJECT_BST_HH

struct node {
	int x;
	node *left;
	node *right;
	int nivell;
};

class BST {
private:
	//ESTRUCTURA DE DADES
	node *root;
	int size;
	//FUNCIONS PRIVADES
    node* search_position_ant(node* actual, int elem);
	void escriure_fills(node* actual);

public:
	BST();
    void insert_elem(int elem);
    void delete_elem(int elem);
    void escriure();

};
#endif //PROJECT_BST_HH
