#include "bengisuozdemir_ozdemir_bengisu_hw2_AVLclass.h"
template <class Comparable>
int AvlTree<Comparable>::height( AvlNode<Comparable> *t ) const
 {
	if (t == NULL)
		return -1;
	
	return t->height;
}
template <class Comparable>
int AvlTree<Comparable>::max( int lhs, int rhs ) const
{
	if (lhs > rhs)
		return lhs;

	return rhs;            
}
template <class Comparable>
 void AvlTree<Comparable>::insert ( const Comparable & x, AvlNode<Comparable> * & t ) const
 {
	if ( t == NULL )
	{
		t = new AvlNode<Comparable>( x, NULL, NULL );
	}

	else if ( x < t->element ) 
	{
		// X should be inserted to the left tree!
		insert( x, t->left );
           
	// Check if the left tree is out of balance (left subtree grew in height!)
		if ( height( t->left ) - height( t->right ) == 2 )
			if ( x < t->left->element )  // X was inserted to the left-left subtree!
					rotateWithLeftChild( t );
			else			     // X was inserted to the left-right subtree!
					doubleWithLeftChild( t );
	}
	else if( t->element < x )
    {    // Otherwise X is inserted to the right subtree
            insert( x, t->right );
            if ( height( t->right ) - height( t->left ) == 2 )
	// height of the right subtree increased
                if ( t->right->element < x )
		     	// X was inserted to right-right subtree
                    rotateWithRightChild( t );
            else // X was inserted to right-left subtree
                    doubleWithRightChild( t );
    }
    else
        ;  // Duplicate; do nothing
            
	// update the height the node
    t->height = max( height( t->left ), height( t->right ) ) + 1;
}

template <class Comparable>
void AvlTree<Comparable>::rotateWithLeftChild( AvlNode<Comparable> * & k2 ) const
{
    AvlNode<Comparable> *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
    k1->height = max( height( k1->left ), k2->height ) + 1;
    k2 = k1;
}

template <class Comparable>
void AvlTree<Comparable>::rotateWithRightChild( AvlNode<Comparable> * & k1 ) const
{
    AvlNode<Comparable> *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
    k2->height = max( height( k2->right ), k1->height ) + 1;
    k1 = k2;
}

template <class Comparable>
void AvlTree<Comparable>::doubleWithLeftChild( AvlNode<Comparable> * & k3 ) const
{
    rotateWithRightChild( k3->left );
    rotateWithLeftChild( k3 );
}

template <class Comparable>
void AvlTree<Comparable>::doubleWithRightChild( AvlNode<Comparable> * & k1 ) const
{
    rotateWithLeftChild( k1->right );
    rotateWithRightChild( k1 );
}
