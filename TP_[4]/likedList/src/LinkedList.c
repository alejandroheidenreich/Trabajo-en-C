#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this!=NULL){
    	this->pFirstNode=NULL;
    	this->size=0;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){
    	returnAux=this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* nodo;
	int largo;
	nodo = NULL;
	largo = ll_len(this);

	if(this != NULL && (nodeIndex >= 0 && nodeIndex < largo)){
		nodo = this->pFirstNode;
		for(int i=0; i < nodeIndex; i++){
			nodo = nodo->pNextNode;
		}
	}

	return nodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
	Node* nodo;
	Node* aux;
	int check=-1;

	if(this != NULL ){ //&& pElement != NULL
		nodo = (Node*) malloc(sizeof(Node));
		if(nodo != NULL){
			if(nodeIndex == 0){
				nodo->pNextNode = this->pFirstNode;
				this->pFirstNode = nodo;
				nodo->pElement = pElement;
				this->size++;
				check = 0;
			}
			else {
				aux = getNode(this, nodeIndex-1);
				if(aux != NULL){
					nodo->pNextNode = aux->pNextNode;
					aux->pNextNode = nodo;
					nodo->pElement = pElement;
					this->size++;
					check = 0;
				}
			}

		}
	}
	return check;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int verify;
    int largo;

    if(this != NULL ){ //&& pElement != NULL
    	largo = ll_len(this);
    	verify = addNode(this, largo, pElement);
    	if(verify==0){
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodo;

    nodo = getNode(this, index);

    if (nodo != NULL){
    	returnAux = nodo->pElement;
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodo;

    nodo = getNode(this, index);

    if (nodo != NULL){
    	nodo->pElement = pElement;
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodoEliminado;
	Node* aux;

	if(this != NULL){
		nodoEliminado = getNode(this,index);
		if(nodoEliminado != NULL){
			if(index == 0){
				this->pFirstNode = nodoEliminado->pNextNode;
			}
			else {
				aux = getNode(this, index-1);
				if(aux != NULL){
					aux->pNextNode = nodoEliminado->pNextNode;
				}
			}
			returnAux = 0;
			free(nodoEliminado);
			this->size--;
		}
	}

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int verify;
    int largo;

    if (this != NULL){
    	largo = ll_len(this);
    	for(int i=0; i< largo; i++){
    		verify = ll_remove(this,0);
    		if(verify==-1){
    			returnAux = -1;
    			break;
    		}
    		returnAux = 0;
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    int verify;
    if (this != NULL){
    	verify = ll_clear(this);
    	if(verify==0){
    		returnAux = 0;
    		free(this);
    	}
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    void* pElementFinder;
    int largo;

    if(this != NULL){
    	largo = ll_len(this);
    	for(int i=0; i<largo; i++){
    		pElementFinder = ll_get(this, i);
    		if(pElementFinder == pElement){ // pElementFinder != NULL
    			returnAux = i;
    			break;
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int largo;
    if(this !=NULL){
    	largo = ll_len(this);
    	if(largo!=0){
    		returnAux = 0;
    	}
    	else{
    		returnAux = 1;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
	int returnAux = -1;
	int verify;

	if(this != NULL ){ //&& pElement != NULL
	    	verify = addNode(this, index, pElement);
	    	if(verify==0){
	    		returnAux = 0;
	    	}
	}

	return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* nodoEliminado;
    Node* aux;

    if(this != NULL){
    	nodoEliminado = getNode(this,index);
    	if(nodoEliminado != NULL){
    		if(index == 0){
    			this->pFirstNode = nodoEliminado->pNextNode;
    		}
    		else {
    			aux = getNode(this, index-1);
    			if(aux != NULL){
    				aux->pNextNode = nodoEliminado->pNextNode;
    			}
    		}
    		returnAux = 0;
    		returnAux =nodoEliminado->pElement;
    		this->size--;
    	}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int verify;

    if (this != NULL){
    	verify = ll_indexOf(this,pElement);
    	if(verify != -1){
    		returnAux = 1;
    	}
    	else{
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int verify;
    int largo;
    void* pElement;

    if(this != NULL && this2 != NULL){
    	largo = ll_len(this2);
    	returnAux = 1;
    	for(int i=0; i<largo ; i++){
    		pElement = ll_get(this2, i);
    		if(pElement != NULL){
    			verify = ll_contains(this, pElement);
    			if(verify != 1){
    				returnAux = 0;
    				break;
    			}
    		}
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElementSub;
    int largo;
    int verify;

    if(this != NULL){
    	largo = ll_len(this);
    	if(from >= 0 && to <= largo && to > from && from < to){
    		cloneArray = ll_newLinkedList();
    		if(cloneArray != NULL){
				for(int i=from; i<to ; i++){
					pElementSub = ll_get(this, i);
					if(pElementSub != NULL){
						verify = ll_add(cloneArray, pElementSub);
						if(verify == -1){
							cloneArray = NULL;
							break;
						}
					}
				}
    		}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int largo;

    if(this != NULL){
    	largo = ll_len(this);
    	cloneArray = ll_subList(this, 0, largo);
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int largo;
    void* aux1;
    void* aux2;
    void* swapper;
    int cmp;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0)){
    	largo = ll_len(this);
    	for(int i=0; i<largo-1; i++){
    		for(int j=i+1; j<largo; j++){
    			aux1 = ll_get(this,i);
    			aux2 = ll_get(this,j);
    			if(aux1 != NULL && aux2 != NULL){
					cmp = pFunc(aux1 ,aux2);
					if(cmp < 0 && order == 0){
						swapper = aux1;
						ll_set(this, i, aux2);
						ll_set(this, j, swapper);
					}
					else if (cmp > 0 && order == 1){
						swapper = aux1;
						ll_set(this, i, aux2);
						ll_set(this, j, swapper);
					}
    			}
    		}
    	}
    	returnAux = 0;
    }
    return returnAux;
}

