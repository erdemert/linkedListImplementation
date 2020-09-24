#include "Matrix.hpp"

Matrix::Matrix(int nor, int noc) {
    this->numberOfRows = nor;
    this->numberOfColumns = noc;

    // initializes matrix to all zeros.
    for (int i = 0 ; i < nor*noc ; ++i) {
        this->matrix.insertAtTheEnd(0);
    }
}

Matrix::Matrix(int nor, int noc, std::string elements) {
    // elements = element_1|element_2|element_3|...|element_(nor*noc)
    // For example, if nor is 2 and noc is 3, the elements string 1|2|3|4|5|6 represents the following matrix with 2 rows and 3 columns:
    // 1 2 3
    // 4 5 6

    this->numberOfRows = nor;
    this->numberOfColumns = noc;

    std::string delimiter = "|";

    std::string element;
    size_t pos = 0;

    while (true) {
        pos = elements.find(delimiter);

        bool breakTheLoop = (pos == std::string::npos);

        element = elements.substr(0, pos);
        elements.erase(0, pos + delimiter.length());

        this->matrix.insertAtTheEnd(std::atoi(element.c_str()));

        if (breakTheLoop) break;
    }
}

int Matrix::getElementByIndex(int rowIndex, int columnIndex) const {
    /* TODO */  
    Node<int> *node = this->matrix.getFirstNode();

    for (int r = 0 ; r < this->numberOfRows ; ++r) {
        for (int c = 0 ; c < this->numberOfColumns ; ++c) {
            if(r == rowIndex && c == columnIndex) return node->data;
            
            node = node->next;
        }
    }
    /*
    Node<int> *node = matrix.getFirstNode();
    int num = (rowIndex-1)*numberOfColumns + columnIndex;
    for(int i = 0; i<num; ++i){
        node = node->next;
    }
    return node->data;
    */
}

void Matrix::setElementByIndex(int rowIndex, int columnIndex, int element) {
    /* TODO */
           /* Node<int> *ptr;
            ptr = matrix.getFirstNode();
            for(int i=0; i!= (rowIndex+1)*numberOfRows + columnIndex ; i++){
                ptr=ptr->next;
            } ptr->data = element;*/
            
    
    Node<int> *node = this->matrix.getFirstNode();
    bool breaker = false;

    for (int r = 0 ; r < this->numberOfRows ; ++r) {
        for (int c = 0 ; c < this->numberOfColumns ; ++c) {
            if(r == rowIndex && c == columnIndex){
                node->data = element;
                break;
            }
            node = node->next;
        }
        if (breaker) break;
    }
    
    /*
    Node<int> *node = matrix.getFirstNode();
    int num = (rowIndex-1)*numberOfColumns + columnIndex;
    for(int i = 0; i<num; ++i){
        node = node->next;
    }
    node->data = element;
    */
}

Matrix Matrix::operator+(const Matrix &rhs) const {
    /* TODO */  /*LinkedList<int> *ptr = new LinkedList<int>(rhs.matrix);
                Node<int> *ptr2 = ptr->getFirstNode();
                Node<int> *node = this->matrix.getFirstNode();
                Node<int> *node2 = rhs.matrix.getFirstNode();
                
                 for (int r = 0 ; r < this->numberOfRows ; ++r) {
        for (int c = 0 ; c < this->numberOfColumns ; ++c) {
                ptr2->data = node->data + node2->data;
            ptr2 = ptr2-> next;
            node = node->next;
            node2 = node2-> next;
        }

        
    }
        Matrix *ptrfinal = new Matrix(this->numberOfRows, this->numberOfColumns, *ptr)
                return ptrfinal; */
Matrix mtrx(rhs.numberOfRows, rhs.numberOfColumns);
Node<int>* lefths = matrix.getFirstNode();
Node<int>* righths = rhs.matrix.getFirstNode();
/*
while(lefths != NULL || righths != NULL){
	mtrx.matrix.insertAtTheEnd((lefths->data + righths->data));
	lefths = lefths->next;
	righths = righths->next;
}
*/

for(int i = 0; i < numberOfRows; ++i){
    for(int j = 0; j < numberOfColumns; ++j){
        mtrx.setElementByIndex(i,j, ( getElementByIndex(i,j) + rhs.getElementByIndex(i,j) ));
    }
}

return mtrx;



}               

Matrix Matrix::operator*(const int &rhs) const {
    /* TODO */          Matrix mtrx(numberOfRows, numberOfColumns);
Node<int>* lefths = matrix.getFirstNode();

	
for(int i = 0; i < numberOfRows; ++i){
    for(int j = 0; j < numberOfColumns; ++j){
        mtrx.setElementByIndex(i,j, ( getElementByIndex(i,j) * rhs ));
    }
}

return mtrx;
}

Matrix Matrix::kroneckerProduct(const Matrix &rhs) const {
    /* TODO */
}

void Matrix::print() {
    Node<int> *node = this->matrix.getFirstNode();

    for (int r = 0 ; r < this->numberOfRows ; ++r) {
        for (int c = 0 ; c < this->numberOfColumns ; ++c) {
            std::cout << *node << " ";

            node = node->next;
        }

        std::cout << std::endl;
    }
}
